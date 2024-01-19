#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_magazin.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shop = new magazin();
    this->setWindowTitle("Вход в магазин");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GoTo_clicked()
{
    if(ui->usPass->text()!=ui->usPassRepeat->text() || ui->usPass->text().isEmpty() || ui->usPassRepeat->text().isEmpty()){
        QMessageBox::information(this,"ERROR", "Пароли не совпадают или пусты");
        return;
    }
    if(ui->usName->text().isEmpty()){
        QMessageBox::information(this,"ERROR", "Имя не ввели");
        return;
    }
    shop->RowColums(4,4);

    shop->setName(ui->usName->text());
    shop->show();
    this->close();

}

