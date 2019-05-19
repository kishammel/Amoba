#ifndef COLOUR_H
#define COLOUR_H
#include<iostream>


class colour
{
public:
    colour(std::string nev,unsigned int r,unsigned int g,unsigned int b);
    virtual ~colour();
    int get_red();
    int get_green();
    int get_blue();


protected:

private:
    unsigned  int red;
    unsigned int green;
    unsigned int blue;
    std::string nev;
};

#endif // COLOUR_H
