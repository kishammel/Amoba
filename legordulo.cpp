#include "legordulo.h"
#include "graphics.hpp"
#include<iostream>



legordulo::legordulo(unsigned int width,unsigned int height,unsigned int x,unsigned int y) : widget(width,height,x,y)
{
    this->mini=0;
    this->maxi=0;
    this->kivalasztott=-1;
    this->aktiv=false;
    this->elso=0;
    this->meret=3;
}

legordulo::~legordulo()
{

}

std::string legordulo::wertek()
{
    if(this->kivalasztott > -1)
    {
        return this->lista[this->kivalasztott];
    }
    else
    {
    return "";
    }

}

int legordulo::get_selected_index()
{
return this->kivalasztott;
}


bool legordulo::csekkolo(int px,int py)
{
    return px > this->x && px < this->x + width && py > this->y && py < this->y + height;
}

void legordulo::draw()
{

    using namespace genv;



    gout<<move_to(x,y)<<color(245,0,0)<<box_to(x+width,y+height);



    if(kivalasztott-elso==0)
    {
        gout<<move_to(x,y)<< color(0,212,0)<<box_to(x+width*0.95,y+height/3);
    }
    if(kivalasztott-elso==1)
    {
        gout<<move_to(x,y+height/3)<< color(0,212,0)<<box_to(x+width*0.95,y+height/3*2);
    }
    if(kivalasztott-elso==2)
    {
        gout<<move_to(x,y+height/3*2)<< color(0,212,0)<<box_to(x+width*0.95,y+height);
    }


 gout<<move_to(x,y+height/3)<< color(255,255,255)<<line_to(x+width*0.95,y+height/3);


    gout<<move_to(x,y+height/3*2)<< color(255,255,255)<<line_to(x+width*0.95,y+height/3*2);

    gout<<move_to(x+width*0.8,y)<< color(255,156,0)<<box_to(x+width,y+height*0.5);
    gout<<move_to(x+width*0.8,y+height*0.5)<< color(255,156,0)<<box_to(x+width,y+height);
    gout<<move_to(x+width*0.8,y+height*0.50)<<color(0,0,0)<<line_to(x+width,y+height*0.5);
    gout<<move_to(x+width*0.8,y+height*0.75)<<color(0,0,0)<<text("v");
    gout<<move_to(x+width*0.8,y+height*0.25)<<color(0,0,0)<<text((char)94);
    gout<<move_to(x,y)<<color(255,255,255)<<box_to(x+width,y+height*(-0.2));

    if(this->kivalasztott>=0)
       {
           gout<<move_to(x+width*0.4,y+height*(-0.05))<<color(0,0,0)<<text(this->lista[this->kivalasztott]);
       }

   for (int i=0; i<this->meret; ++i)
    {
        gout<<move_to(x,y+height*0.20+((i*height)/3))<<color(255,255,255)<<text(lista[elso+i]);
    }

}

void legordulo::event(genv::event ev)
{
    using namespace genv;
    if (ev.type==ev_mouse && ev.button== btn_left)
    {
        this->focuscheck(ev.pos_x,ev.pos_y);


        if (clickCheck(0,width*0.8,0, height/3, ev.pos_x, ev.pos_y)== true)
        {
            this->kivalasztott=0+this->elso;

        }
        if (clickCheck(0,width*0.8, height/3, height/3*2, ev.pos_x, ev.pos_y)== true)
        {
            this->kivalasztott=1+this->elso;

        }
        if (clickCheck(0,width*0.8, height/3*2, height, ev.pos_x, ev.pos_y)== true)
        {
            this->kivalasztott=2+this->elso;

        }


    }
    if (ev.type==ev_mouse && ev.button== btn_wheelup &&aktiv)
    {


        if(elso-1>=this->mini)
        {
            this->elso=this->elso-1;
        }
    }
    if (ev.type==ev_mouse && ev.button== btn_wheeldown &&aktiv)
    {

        if(elso+this->meret<=this->maxi)
        {
            this->elso=this->elso+1;
        }
    }


    if (ev.type==ev_mouse && ev.button== btn_left)
    {
        if(clickCheck(width*0.8, width, 0, height*0.5, ev.pos_x, ev.pos_y)== true)
        {

            if(elso-1>=this->mini)
            {
                this->elso=this->elso-1;
            }
        }
    }

    if (ev.type==ev_mouse && ev.button== btn_left)
    {
        if(clickCheck(width*0.8, width, height*0.5, height, ev.pos_x, ev.pos_y)== true)
        {
            if(elso+this->meret<=this->maxi)
            {
                this->elso=this->elso+1;
            }

        }
    }
}
void legordulo::hozzaad(std::string s)
{
    this->lista.push_back(s);
    this->maxi++;
}








