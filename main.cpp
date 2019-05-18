#include "graphics.hpp"
#include "widget.h"
#include "szamlalo.h"
#include "legordulo.h"
#include "tictacgomb.h"
#include "gomb.h"
#include "colour.h"
#include "Jatekmester.h"
#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<cstdlib>
#include<fstream>

using namespace genv;

const int X=600;
const int Y=600;

int main()
{

    gout.open(X+41,Y+41);

    event ev;
    std::vector<colour*>szinek;
    szinek.push_back(new colour("PINK",255,105,180));
    szinek.push_back(new colour("Piros",250,0,0));
    szinek.push_back(new colour("Zöld",0,250,0));
    szinek.push_back(new colour("Kék",0,255,255));
    std::vector<widget*>widgetek;
        legordulo * l1 = new legordulo(40,100,100,100);
    l1->hozzaad("PINK");
    l1->hozzaad("Piros");
    l1->hozzaad("Zöld");
    l1->hozzaad("Kék");

        legordulo * l2 = new legordulo(40,100,100,250);
    l2->hozzaad("PINK");
    l2->hozzaad("Piros");
    l2->hozzaad("Zöld");
    l2->hozzaad("Kék");

    gomb * g1 =new gomb(50,50,400,400);
    szamlalo * s1=new szamlalo(70,50,180,200, 15, 30);
    Jatekmester *Jatek=new Jatekmester(atoi(s1->wertek().c_str()),X,Y);
    g1->set_padding(5,28);
    g1->set_text("Start");
    widgetek.push_back(l1);
    widgetek.push_back(l2);
    widgetek.push_back(g1);
    widgetek.push_back(s1);




int page =0;
 while(gin >> ev)
    {

switch (page)
{
case 0:  //menu
    for(int i=0; i<widgetek.size(); ++i)
        {

            {

                widgetek[i]->event (ev);
                widgetek[i]->draw();

                if(g1->wertek() == "1")
                {
                    Jatek->set_coloro(szinek[l1->get_selected_index()]);
                    Jatek->set_colorx(szinek[l2->get_selected_index()]);
                    Jatek->set_n(s1->ertekes());
                    page = 1;


                }

            }
        }

    break;
case 1:   //jatek
 gout<<move_to(0,0)<<color(0,0,0)<<box_to(X,Y);
Jatek->draw();
Jatek->event(ev);



    break;
case 2:


    break;   //GameOver
}






        gout<<refresh;


    }

    return 0;
}
