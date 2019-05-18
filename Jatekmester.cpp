#include "Jatekmester.h"

Jatekmester::Jatekmester(int n,int X,int Y)
{
    this->X=X;
    this->Y=Y;
    this->n=n;
    for (int i=0; i<30; ++i)
    {
        for (int j=0; j<30; ++j)
        {
            this->board[i][j]=new tictacgomb(X/n,Y/n,i,j);
        }

    }


}

Jatekmester::~Jatekmester()
{
    //dtor
}



void Jatekmester::draw()
{
    for (int i=0; i<n; ++i)

    {
        for (int j=0; j<n; ++j)
        {
            this->board[i][j]->draw();

            // std::cout<<"["<<i<<","<<j<<"]"<<std::endl;

        }

    }
}

void Jatekmester::set_coloro(colour*c)
{
    this->coloro=c;

}

void Jatekmester::set_colorx(colour*c)
{
    this->colorx=c;
}

void Jatekmester::set_n(int n)
{
    this->n=n;
    for (int i=0; i<30; ++i)
    {
        for (int j=0; j<30; ++j)
        {
            this->board[i][j]=new tictacgomb(X/n,Y/n,i+1,j+1);
        }

    }
}
void Jatekmester::event(genv::event ev)
{




    using namespace genv;
    for (int i=0; i<30; ++i)
    {
        for (int j=0; j<30; ++j)
        {
            this->board[i][j]->event(ev);
            if(board[i][j]->is_aktiv())
            {
                board[i][j]->deactivate();
                if(board[i][j]->get_text()==" ")
                {



                    std::stringstream dd;




                }

            }
        }
    }
}








