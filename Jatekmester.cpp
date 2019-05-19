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
    this->aktjatekos='x';
    this->jatek=true;
    this->uresek=n*n-1;
    this->dontetlen=false;
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
    if(this->jatek)
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
                        dd<< this->aktjatekos;
                        board[i][j]->set_text(dd.str());
                        board[i][j]->setbackground(get_aktjatekos_szin());

                        if(ellenoriz(i,j))
                        {
                            this->jatek=false;
                            gout<<move_to(10,this->Y+20)<<color(255,215,0)<<genv::text("Gratulálok "+dd.str()+", te nyertél! Bezáráshoz nyomj esc-et.");
                        }


                        full_table();

                        this->next_player();
                        this->uresek-=1;

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
    for (int i=1; i<5&&check_poz(x-i,y); ++i)
    {
        db++;
    }
    for (int i=1; i<5&&check_poz(x+i,y); ++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db = 1;
    //függõleges
    for (int i=1; i<5&&check_poz(x,y+i); ++i)
    {
        db++;
    }
    for (int i=1; i<5&&check_poz(x,y-i); ++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db = 1;

    //jobbrale,fel
    for (int i=1; i<5&&check_poz(x+i,y+i); ++i)
    {
        db++;
    }
    for (int i=1; i<5&&check_poz(x-i,y-i); ++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db = 1;

    //balrafel,le
    for (int i=1; i<5&&check_poz(x+i,y-i); ++i)
    {
        db++;
    }
    for (int i=1; i<5&&check_poz(x-i,y+i); ++i)
    {
        db++;
    }
    if(db>4)
    {
        return true;
    }
    db=1;


    return false;


}
bool Jatekmester::check_poz(int a,int b)
{
    if(0 <= a && a < this->n && 0 <= b && b < this->n )
    {
        return board[a][b]->get_text()[0] == this->aktjatekos;
    }
    else
    {
        return false;
    }
}

void Jatekmester::full_table()
{
    if (this->uresek==0)
    {
        jatek=false;
        dontetlen=true;
        genv::gout<<genv::move_to(10,this->Y+20)<<genv::color(255,215,0)<<genv::text("A játék döntetlennel végzödött! Bezáráshoz nyomj esc-et.");
    }

}

bool Jatekmester::get_dontetlen()
{
    if (this->dontetlen==true)
    {
        return true;
    }

}
bool Jatekmester::get_jatek()
{
    if(this->jatek==false)
    {
        return true;
    }
}







