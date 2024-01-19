#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <QDialog>
#include "object.h"
#include "ch.h"

namespace Ui {
class magazin;
}

class magazin : public QDialog
{
    Q_OBJECT

public:
    QString getNAME();
    void WriteCheck();
    void readFile();
    void AddToList(Object t1);
    void setName(QString name);
    void RowColums(int a, int b);
    explicit magazin(QWidget *parent = nullptr);
    ~magazin();

private slots:
    void on_t1_clicked();

    void on_t2_clicked();

    void on_t3_clicked();

    void on_t4_clicked();

    void on_toPay_clicked();

private:
    Ui::magazin *ui;
    QString Name;
    QList<Object> shit;
    ch list;

};

#endif // MAGAZIN_H
