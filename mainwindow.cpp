#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new SQLManager(this);

    connect(manager, SIGNAL(table_update(QSqlTableModel*)), this, SLOT(update_data_table(QSqlTableModel*)));
}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}

void MainWindow::on_btn_load_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, tr("Open Database"), "", "DB files (*.db)");
    qDebug() << "Path: " << filepath;

    if(!filepath.isEmpty()){
        manager->load_db(filepath);
    }
}
void MainWindow::update_data_table(QSqlTableModel *model){
    this->ui->table_data->setModel(model);
}
