#ifndef DBLOADER_H
#define DBLOADER_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QSqlTableModel>

class SQLManager : public QObject
{
    Q_OBJECT
public:
    explicit SQLManager(QObject *parent = 0);
private:
    QSqlDatabase db;
signals:
    void table_update(QSqlTableModel *model);
public slots:
    void load_db(QString path);
};

#endif // DBLOADER_H
