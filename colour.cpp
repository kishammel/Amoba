#include "colour.h"


colour::colour(std::string nev,unsigned int r,unsigned int g,unsigned int b)
{
    this->nev=nev;
    this->red=r;
    this->blue=b;
    this->green=g;
}
colour::~colour()

{
    //dtor
}
int colour::get_red()
{
    return this->red;
}
int colour::get_green()
{
    return this->green;
}
int colour::get_blue()
{
    return this->blue;
}
