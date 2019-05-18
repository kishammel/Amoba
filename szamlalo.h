

#ifndef SZAMLALO_H
#define SZAMLALO_H
#include "graphics.hpp"
#include "widget.h"
#include <string>

class szamlalo : public widget
{
public:

    szamlalo(unsigned int width,unsigned int height,unsigned int x,unsigned int y, int mini, int maxi);
    virtual ~szamlalo();
    virtual void event(genv::event ev);
    virtual void draw();
    int ertekes();
    void fel();
    void le();
    void feljebb();
    void lejjebb();
    virtual std::string wertek();


protected:
    virtual bool csekkolo(int px, int py);

private:
    int maxi;
    int mini;
    int ertek;

};

#endif // SZAMLALO_H
