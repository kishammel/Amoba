
#ifndef LEGORDULO_H
#define LEGORDULO_H
#include "graphics.hpp"
#include "widget.h"
#include <string>
#include<vector>


class legordulo : public widget
{
public:
    legordulo(unsigned int width,unsigned int height,unsigned int x,unsigned int y);
    virtual ~legordulo();
    virtual void event(genv::event ev);
    virtual void draw();
    virtual std::string wertek();
    void hozzaad(std::string s);
    int get_selected_index();


protected:
    virtual bool csekkolo(int px, int py);
private:
    int kivalasztott;
    int elso;
    int maxi;
    int mini;
    int meret;

    std::vector<std::string> lista;

};

#endif // LEGORDULO_H
