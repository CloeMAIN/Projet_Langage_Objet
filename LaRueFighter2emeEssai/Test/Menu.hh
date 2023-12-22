#ifndef MENU_HH
#define MENU_HH

#include "Afficheur.hh"

class Menu
{
private:
    /* data */
public:
    Menu(/* args */);
    ~Menu();
    int lancer(Afficheur* afficheur);
};

#endif // MENU_HH
