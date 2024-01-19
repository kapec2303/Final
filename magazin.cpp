#include "magazin.h"
#include "ch.h"
#include "ui_magazin.h"
#include "object.h"
#include <QFile>

magazin::magazin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::magazin)
{
    ui->setupUi(this);
}

magazin::~magazin()
{
    delete ui;
}


void magazin::setName(QString name){
    Name = name;

}

void magazin::RowColums(int a, int b){
    for(int k = 0; k < a ; k++ ){
        ui->sklad->setColumnWidth(k,170);
        ui->sklad->setRowHeight(k,47);
    }
    for(int k = 0; k < a ; k++ ){
        ui->check->setColumnWidth(k,250);
        ui->check->setRowHeight(k,47);
    }
    ui->sklad->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setWindowTitle("Магазин");
    this->list =ch();
    readFile();

    for(int g = 0;g < a;g++){
        auto h = this->shit[g].getN();
        QTableWidgetItem *item  = new QTableWidgetItem(h);
        ui->sklad->setItem(g,0,item);
    }

    for(int g = 0;g < a;g++){
        auto h = this->shit[g].getN();
        QTableWidgetItem *item  = new QTableWidgetItem(h);
        ui->check->setItem(g,0,item);
    }

    for(int g = 0;g < a;g++){
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(0));
        ui->check->setItem(g,1,item);
    }

    for(int g = 0;g < a;g++){
        auto h = this->shit[g].getV();
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(h));
        ui->sklad->setItem(g,1,item);
    }

    for(int g = 0;g < a;g++){
        auto h = this->shit[g].getHM();
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(h));
        ui->sklad->setItem(g,2,item);
    }


}


void magazin::AddToList(Object t1){
    this->shit.push_back(t1);
}

QString magazin::getNAME(){
    return this->Name;
}

void magazin::readFile(){

    QFile file("C:/Users/terme/FinalDz/prod.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString str;
        QString Data_str;
        Object t;
        while (!file.atEnd())
        {

            str = file.readLine();
            int j = 0;
            while(str[j]!='#'){
                Data_str+=str[j];
                j++;
            }
            j++;
            t.setN(Data_str);
            Data_str = "";
            while(str[j]!='#'){
                Data_str+=str[j];
                j++;
            }
            j++;
            t.setV(Data_str.toInt());
            Data_str = "";
            while(j<str.size()){
                Data_str+=str[j];
                j++;
            }
            t.setHM(Data_str.toInt());
            Data_str = "";
            AddToList(t);



        }
    }

}

void magazin::on_t1_clicked()
{
    if(shit[0].getV()!=0){
        list.setT(0);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->list.getT(0)));
        ui->check->setItem(0,1,item);
        shit[0].setV(shit[0].getV()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(shit[0].getV()));
        ui->sklad->setItem(0,1,item2);
    }
}


void magazin::on_t2_clicked()
{
    if(shit[1].getV()!=0){
        list.setT(1);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->list.getT(1)));
        ui->check->setItem(1,1,item);
        shit[1].setV(shit[1].getV()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(shit[1].getV()));
        ui->sklad->setItem(1,1,item2);
    }
}


void magazin::on_t3_clicked()
{
    if(shit[2].getV()!=0){
        list.setT(2);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->list.getT(2)));
        ui->check->setItem(2,1,item);
        shit[2].setV(shit[2].getV()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(shit[2].getV()));
        ui->sklad->setItem(2,1,item2);
    }
}


void magazin::on_t4_clicked()
{
    if(shit[3].getV()!=0){
        list.setT(3);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->list.getT(3)));
        ui->check->setItem(3,1,item);
        shit[3].setV(shit[3].getV()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(shit[3].getV()));
        ui->sklad->setItem(3,1,item2);
    }
}

void magazin::WriteCheck(){

    QFile file("C:/Users/terme/FinalDz/list.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream stream(&file);
        stream << "               ИМЯ            "<< getNAME() << "\n";
        stream<<"\n\n";
        for(int i = 0; i < 4;i++){
            stream<<shit[i].getN()<<" - "<<list.getT(i)<<" -Total- "<<list.getT(i)*shit[i].getHM()<<"\n";
        }
        int SumCost = 0;
        for(int i = 0; i < 4;i++){
            SumCost+=shit[i].getHM()*list.getT(i);
        }
        stream<<"\n\n\n";
        stream << "GLOBAL TOTAL = "<< QString::number(SumCost) << "\n";

    }

    file.close();
}


void magazin::on_toPay_clicked()
{
    WriteCheck();
    this->close();
}

