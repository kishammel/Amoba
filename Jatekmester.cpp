#include "Jatekmester.h"

Jatekmester::Jatekmester(int n,int X,int Y)
{
    this->X=X;
    this->Y=Y;
    this->n=n;
    for (int i=0;i<30;++i)
{
   for (int j=0;j<30;++j)
    {
        this->board[i][j]=new tictacgomb(X/n,Y/n,i,j);
    }

}
 this->aktjatekos='x';
 this->jatek=true;
}

Jatekmester::~Jatekmester()
{
    //dtor
}



void Jatekmester::draw()
{
    for (int i=0;i<n;++i)

    {
       for (int j=0;j<n;++j)
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
    for (int i=0;i<30;++i)
        {
            for (int j=0;j<30;++j)
            {
                this->board[i][j]=new tictacgomb(X/n,Y/n,i+1,j+1);
            }

        }
}
void Jatekmester::event(genv::event ev)
{
    if(this->jatek)
    {


    using namespace genv;
     for (int i=0;i<30;++i)
        {
            for (int j=0;j<30;++j)
            {
                this->board[i][j]->event(ev);
                if(board[i][j]->is_aktiv())
                {
                    board[i][j]->deactivate();
                    if(board[i][j]->get_text()==" ")
                    {



                     std::stringstream dd;
                     dd<< this->aktjatekos;
                   board[i][j]->set_text(dd.str());
                    board[i][j]->setbackground(get_aktjatekos_szin());
                    if(ellenoriz(i,j))
                    {
                       this->jatek=false;
                       gout<<move_to(10,this->Y+20)<<color(255,215,0)<<genv::text("Gratulálok "+dd.str()+" te nyertél!");
                    }

                    this->next_player();
                    }
                }
            }

        }
}

}

 colour* Jatekmester::get_aktjatekos_szin()
{
    if(this->aktjatekos=='x')
    {
        return this->colorx;
    }
if(this->aktjatekos=='o')
    {
        return this->coloro;
    }

}
char Jatekmester::get_aktjatekos_jele()
{
    return this->aktjatekos;
}

void Jatekmester::next_player()
{


    if(this->aktjatekos=='x')
    {

        this->aktjatekos='o';

    }
    else if(this->aktjatekos=='o')
    {
        this->aktjatekos='x';
    }
}

bool Jatekmester::ellenoriz(int x,int y)
{
    // vízszintes
    int db=1;
    for (int i=1;i<5&&check_poz(x-i,y);++i)
    {
        db++;
    }
    for (int i=1;i<5&&check_poz(x+i,y);++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db = 1;
    //függõleges
    for (int i=1;i<5&&check_poz(x,y+i);++i)
    {
        db++;
    }
    for (int i=1;i<5&&check_poz(x,y-i);++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db = 1;

    //jobbrale,fel
    for (int i=1;i<5&&check_poz(x+i,y+i);++i)
    {
        db++;
    }
    for (int i=1;i<5&&check_poz(x-i,y-i);++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db = 1;

    //balrafel,le
    for (int i=1;i<5&&check_poz(x+i,y-i);++i)
    {
        db++;
    }
    for (int i=1;i<5&&check_poz(x-i,y+i);++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db=1;

std::cout<<board[x][y]->get_text()[0]<<std::endl;
return false;


}
bool Jatekmester::check_poz(int b,int a)
{
    if(0 <= b && b < this->n && 0 <= a && a < this->n )
    {
        return board[b][a]->get_text()[0] == this->aktjatekos;
    }
    else {
       return false;
    }
}








