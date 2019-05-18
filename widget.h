
#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"
#include<string>
#include<vector>


class widget
{
public:
    widget(unsigned int width,unsigned int height,unsigned int x,unsigned int y);
    virtual ~widget();
    virtual void draw() = 0;
    virtual std::string wertek() = 0;
    virtual void event(genv::event ev)=0;
    bool is_aktiv();
    void deactivate();


protected:
    unsigned int width;
    unsigned int height;
    unsigned int x;
    unsigned int y;
    bool aktiv;
    bool clickCheck(int px1, int px2, int py1, int py2, int x, int y);
    virtual bool csekkolo(int px, int py) ;
    bool focuscheck(int px, int py);
    void unfocus();


private:



};



#endif // WIDGET_H
