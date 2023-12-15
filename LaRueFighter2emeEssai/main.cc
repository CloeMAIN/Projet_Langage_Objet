#include "Menu.hh"
#include "Jeu.hh"
#include "Afficheur.hh"
#include "InputUser.hh"
#include "Personnage.hh"


int main{

    // lancer le menu

    Menu menu;
    menu.lancer();
    //Initialise un jeu
    Jeu jeu;
    //Le jeu lance la partie
    jeu.lancer();

    return 0; 
}