#include "object.h"

Object::Object() {}


void Object::setN(QString n){
    this->NAME = n;
}
void Object::setHM(uint num){
    this->how_many = num;
}
void Object::setV(uint val){
    this->value = val;
}
int Object::getV(){
    return value;
}
int Object::getHM(){
    return how_many;
}
QString Object::getN(){
    return NAME;
}
