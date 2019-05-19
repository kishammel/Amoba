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
    colour* get_aktjatekos_szin();
    char get_aktjatekos_jele();
    void next_player();
    bool ellenoriz(int x,int y);
    bool check_poz(int a,int b);
    void full_table();
    bool get_dontetlen();
    bool get_jatek();

protected:

private:
    colour* coloro;
    colour* colorx;
    tictacgomb* board [30][30];
    int n;
    int X;
    int Y;
    char aktjatekos;
    bool jatek;
    int uresek;
    bool dontetlen;


};

#endif // JATEKMESTER_H
