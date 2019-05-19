#ifndef TICTACGOMB_H
#define TICTACGOMB_H
#include "gomb.h"
#include "colour.h"
#include<iostream>
#include<sstream>

class tictacgomb :public gomb
{
public:
    tictacgomb(unsigned int w,unsigned int h,unsigned int sor,unsigned int oszlop);
    virtual ~tictacgomb();
    void setbackground(colour *c);
    virtual void event(genv::event ev);
    virtual void draw();
    int get_sor();
    int get_oszlop();




protected:

private:
    int sor;
    int oszlop;
    colour* hatter;
    char allapot=' ';


};

#endif // TICTACGOMB_H
