#ifndef GOMB_H
#define GOMB_H
#include "graphics.hpp"
#include "widget.h"
#include <string>

class gomb: public widget

{
    public:
        gomb(unsigned int width,unsigned int height,unsigned int x,unsigned int y);
        virtual ~gomb();
        virtual void draw();
        virtual std::string wertek();
        virtual void event(genv::event ev);
        void set_padding(int x, int y);
        void set_text(std::string s);
        std::string get_text();


    protected:

      std::string text;

    private:
        int paddingleft = 0;
        int paddingtop = 0;

        int state = 0;
};

#endif // GOMB_H
