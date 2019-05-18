#include "tictacgomb.h"

tictacgomb::tictacgomb(unsigned int w,unsigned int h,unsigned int sor,unsigned int oszlop) :gomb(w,h,(oszlop-1)*w,(sor-1)*h)
{
   this->sor=sor;
   this->oszlop=oszlop;
   this->hatter=new colour("feher",255,255,255);
   this->text=" ";
}

tictacgomb::~tictacgomb()
{
delete this->hatter;
}

void tictacgomb::setbackground(colour *c)
{
this->hatter=c;
}


void tictacgomb::draw()
{
    using namespace genv;
    gout<<move_to(this->x+1,this->y+1)<<color(this->hatter->get_red(),this->hatter->get_green(),this->hatter->get_blue())<<box_to(this->x+this->width-2, this->y+this->height-2);
    /*std::stringstream dd;
    dd<< this->sor <<"," << this->oszlop;*/
    gout<<move_to(this->x,this->y+this->height*2/3)<<color(0,0,0)<<genv::text(this->text);
}


void tictacgomb::event(genv::event ev)
{
    using namespace genv;
    if (ev.type==ev_mouse && ev.button== btn_left)
    {
        if(clickCheck(2,width-2,2,height-2,ev.pos_x, ev.pos_y)== true)
        {
            aktiv=true;
        }
    }
}



