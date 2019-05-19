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
    szinek.push_back(new colour("Kék",0,255,255));
    szinek.push_back(new colour("Zöld",0,250,0));
    szinek.push_back(new colour("Narancs",255,170,0));

    std::vector<widget*>widgetek;

    legordulo * l1 = new legordulo(70,100,350,250);
    gout<<move_to(355,225)<<color(255,255,255)<<genv::text("Player O");
    l1->hozzaad("PINK");
    l1->hozzaad("Piros");
    l1->hozzaad("Kék");
    l1->hozzaad("Zöld");
    l1->hozzaad("Narancs");

    legordulo * l2 = new legordulo(70,100,100,250);
    gout<<move_to(105,225)<<color(255,255,255)<<genv::text("Player X");
    l2->hozzaad("PINK");
    l2->hozzaad("Piros");
    l2->hozzaad("Kék");
    l2->hozzaad("Zöld");
    l2->hozzaad("Narancs");

    gomb * g1 =new gomb(50,50,230,250);

    szamlalo * s1=new szamlalo(70,50,215,150,15, 30);
    gout<<move_to(210,145)<<color(255,255,255)<<genv::text("Pálya méret");

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

                    if(g1->wertek() == "1"&&l1->wertek()!=""&&l2->wertek()!="")
                    {
                        Jatek->set_coloro(szinek[l1->get_selected_index()]);
                        Jatek->set_colorx(szinek[l2->get_selected_index()]);
                        Jatek->set_n(s1->ertekes());
                        page = 1;

                    }
                    if(g1->wertek()=="1"&&page==0)
                    {
                        gout<<move_to(160,100)<<color(255,0,0)<<genv::text("Valassz szineket a folytatashoz!");
                    }

                }
            }


            break;
        case 1:   //jatek
            gout<<move_to(0,0)<<color(0,0,0)<<box_to(X,Y);
            Jatek->draw();
            Jatek->event(ev);
            if(Jatek->get_jatek() || Jatek->get_dontetlen())
            {

                if (ev.type==ev_key && ev.keycode== key_escape)
                {
                    return 0;
                }
            }



            break;

        }





        gout<<refresh;


    }

    return 0;
}
