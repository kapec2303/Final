#ifndef OBJECT_H
#define OBJECT_H
#include <QString>
class Object
{
public:
    Object();
    void setN(QString n);
    void setHM(uint num);
    void setV(uint val);
    int getV();
    int getHM();
    QString getN();


private:
    QString NAME;
    int value;
    int how_many;
};

#endif // OBJECT_H
