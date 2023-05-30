#include <iostream>


 

class gamesetting 
{
    int width;
    int height;
    static gamesetting *inst_g;
    public:
    gamesetting(): width(10), height(20){};
    static gamesetting *getinstance() {
        if(inst_g == NULL)
            inst_g = new gamesetting();
        return inst_g;
    }

    void setheight(int x) {height = x;}
    void setweight(int x) {width =x;}

    void display() {std::cout << width <<' '<<height << std::endl;} 
};

gamesetting *gamesetting::inst_g=NULL;

int main()
{
    gamesetting *g_sett;
    g_sett = gamesetting::getinstance();
    g_sett->display();
    g_sett->setheight(50);

    gamesetting *g_sett1;
    g_sett1= gamesetting::getinstance();
     g_sett1->display();



}