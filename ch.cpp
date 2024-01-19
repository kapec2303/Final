#include "ch.h"

ch::ch() {
    t1 = 0;
    t2 = 0;
    t3 = 0;
    t4 = 0;
}

int ch::getT(int t){
    if(t == 0)
        return t1;
    if(t == 1)
        return t2;
    if(t == 2)
        return t3;
    if(t == 3)
        return t4;
    else return 0;
}
void ch::setT(int t){
    if(t == 0)
        t1++;
    if(t == 1)
     t2++;
    if(t == 2)
        t3++;
    if(t == 3)
       t4++;

}
