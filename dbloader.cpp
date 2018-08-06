#include "dbloader.h"

SQLManager::SQLManager(QObject *parent) : QObject(parent)
{

}

void SQLManager::load_db(QString path)
{
    qDebug() << "Available drivers: "<< QSqlDatabase::drivers();

    db = QSqlDatabase::addDatabase("QSQLITE", "SQLITE");

    db.setDatabaseName(path);

    if(db.open())
    {
        qDebug() << "Database  at " << path << " opened!";

        QStringList tables = db.tables();
        QString table;
        qDebug() << "Tables: " << tables;
        if(tables.length() > 1)
        {
            bool ok;
            QString text = QInputDialog::getText((QWidget*)this->parent(), tr("Choose Table"),
                                                 "Tables: " + tables.join(" "), QLineEdit::Normal,
                                                 QDir::home().dirName(), &ok);
            if (ok && !text.isEmpty() && tables.contains(text)){
                table = text.trimmed();
            } else {
                qDebug() << text << ": No such table!";
                QMessageBox::critical((QWidget*)this->parent(), "Incorrect table!", "No table \"" + text + "\" Exists");
                return;
            }
        } else {
            table = tables.at(0);
        }
        qDebug() << "Table chosen: " << table;


        // Load data into a table model
        QSqlTableModel *model = new QSqlTableModel(this, db);
        model->setTable(table);
        model->setEditStrategy(QSqlTableModel::OnFieldChange);  // Enable editing also
        model->select();

        // Adjust the model
        QSqlRecord record = db.driver()->record(table);
        for (int i = 0; i < record.count(); i++)
        {
            qDebug() << record.fieldName(i);
            model->setHeaderData(i, Qt::Horizontal, record.fieldName(i));
        }

        // Display data on the main window's QTableView
        table_update(model);

        qDebug() << "Database Closed!";
    } else
    {
        // Error happened
        QString error = db.lastError().text();
        qDebug() << "Error! " << db.lastError();
        QMessageBox::critical((QWidget*)this->parent(), "Database couldn't be opened!", error);
    }
};
