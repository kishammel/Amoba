#include "widget.h"

#include<iostream>

widget::widget(unsigned int width,unsigned int height,unsigned int x,unsigned int y)
{

    this->x = x;
    this->y=y;
    this->width=width;
    this->height=height;


}

widget::~widget()
{

}

bool widget::is_aktiv()
{
    return this->aktiv;
}

bool widget::csekkolo(int px,int py)
{
    return px > this->x && px < this->x + width && py > this->y && py < this->y + height;
}

bool widget::focuscheck(int px, int py)
{
    if(csekkolo(px,py))
    {
        aktiv=true;
    }
    else
    {
        aktiv=false;
    }
    return aktiv;
}


bool widget::clickCheck (int px1, int px2, int py1, int py2, int x, int y)
{
    int wx=x-this->x;
    int wy=y-this->y;

    if (wx>=px1 && wx<=px2 && wy>=py1 && wy<=py2)
    {
        return true;
    }
    else
    {

        return false;
    }


}

void widget::deactivate()
{
    this->aktiv=false;
}







