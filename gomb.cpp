#include "gomb.h"
#include "graphics.hpp"
#include<iostream>


gomb::gomb(unsigned int width,unsigned int height,unsigned int x,unsigned int y) : widget(width,height,x,y)

{
    this->text="";
}

gomb::~gomb()
{
    //dtor
}

void gomb::draw()
{
    using namespace genv;

    gout<< move_to(x,y)<<color(255,255,0)<<box_to(x+width,y+height);
    gout<<move_to(x+this->paddingleft,y+this->paddingtop)<<color(0,0,250)<<genv::text(this->text);



}

std::string gomb::wertek()
{
    if (state == 1)
    {
        return "1";
    }
    else
    {
        return "0";
    }

}

void gomb::event(genv::event ev)
{
    using namespace genv;

    if (ev.type==ev_mouse && ev.button== btn_left)
    {
        if(clickCheck(0,width,0,height,ev.pos_x, ev.pos_y)== true)
        {
            state = 1;

        }
    }



}

void gomb::set_padding(int x, int y)

{
    this->paddingleft=x;
    this->paddingtop=y;
}


void gomb::set_text(std::string s)

{
    this->text=s;
}

std::string gomb::get_text()
{
    return this->text;
}

