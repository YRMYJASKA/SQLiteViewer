#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dbloader.h>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void update_data_table(QSqlTableModel *model);
    void on_btn_load_clicked();
private:
    Ui::MainWindow *ui;
    SQLManager *manager;
};

#endif // MAINWINDOW_H
