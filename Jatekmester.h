#ifndef JATEKMESTER_H
#define JATEKMESTER_H
#include<iostream>
#include<sstream>
#include <tictacgomb.h>
#include <colour.h>


class Jatekmester
{
    public:
        Jatekmester(int n,int X,int Y);
        virtual ~Jatekmester();
        virtual void event(genv::event ev);
        std::string getcolorx();
        std::string getcoloro();
        void torles();
        void draw();
        void set_coloro(colour*c);
        void set_colorx(colour*c);
        void set_n(int n);

    protected:

    private:
        colour* coloro;
        colour* colorx;
        tictacgomb* board [30][30];
        int n;
        int X;
        int Y;


};

#endif // JATEKMESTER_H
