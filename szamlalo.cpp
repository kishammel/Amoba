#include "szamlalo.h"
#include "graphics.hpp"
#include<iostream>
#include<sstream>

szamlalo::szamlalo(unsigned int width,unsigned int height,unsigned int x,unsigned int y, int mini, int maxi) : widget(width,height,x,y)
{
    this->mini=mini;
    this->maxi=maxi;
    this->ertek =mini;
    this->aktiv=false;
}

szamlalo::~szamlalo()
{

}

std:: string szamlalo::wertek()
{
    std::stringstream s;
    s<<this->ertek;
    return  s.str();
}

bool szamlalo::csekkolo(int px,int py)
{
    return px > this->x && px < this->x + width && py > this->y && py < this->y + height;
}

void szamlalo::draw()
{

    using namespace genv;


    genv::gout<<genv::move_to(x,y)<<genv::color(212,0,0)<<genv::box_to(x+width,y+height);

    gout<<move_to(x,y)<< color(255,156,0)<<box_to(x+width*0.25,y+height);
    gout<<move_to(x+width*0.75,y)<< color(255,156,0)<<box_to(x+width,y+height);
    if(aktiv)
    {
        gout<<move_to(x+width*0.25,y)<< color(0,212,0)<<box_to(x+width*0.75,y+height);
    }

    gout<<move_to(x+width*0.1,y+height*0.55)<<color(0,0,0)<<text("-");
    gout<<move_to(x+width*0.87,y+height*0.55)<<color(0,0,0)<<text("+");

    std::stringstream ss;
    ss<< this->ertekes();
    gout<<move_to(x+width*0.4,y+height*0.55)<<color(255,255,255)<<text(ss.str());
}

int szamlalo::ertekes()
{

    return this->ertek;
}

void szamlalo::fel()
{
    if (this->ertek+1<=this->maxi)
    {
        this->ertek++;
    }
}

void szamlalo::le()
{
    if (this->ertek-1>=this->mini)
    {
        this->ertek--;
    }
}
void szamlalo::feljebb()
{
    if (this->ertek+10<=this->maxi)
    {
        this->ertek+=10;

    }
}

void szamlalo::lejjebb()
{
    if (this->ertek-10>=this->mini)
    {
        this->ertek-=10;
    }
}

void szamlalo::event(genv::event ev)

{
    using namespace genv;
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        this->focuscheck(ev.pos_x,ev.pos_y);
    }
    if (ev.type == ev_key && ev.keycode == key_up&&aktiv )
    {
        this->fel();
    }
    if (ev.type == ev_key && ev.keycode == key_down&&aktiv )
    {
        this->le();
    }

    if (ev.type == ev_key && ev.keycode == key_pgup&&aktiv )
    {
        this->feljebb();
    }
    if (ev.type == ev_key && ev.keycode == key_pgdn&&aktiv )
    {
        this->lejjebb();

    }
    if (ev.type==ev_mouse && ev.button== btn_left)
    {
        if (clickCheck(width*0.75, width, 0, height, ev.pos_x, ev.pos_y)== true)
        {
            this->fel();
        }
        if (clickCheck(0, width*0.25, 0, height, ev.pos_x, ev.pos_y)== true)
        {
            this->le();
        }
    }
}





