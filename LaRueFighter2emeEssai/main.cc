#include "Menu.hh"
#include "Jeu.hh"
#include "Afficheur.hh"
// #include "InputUser.hh"
// #include "Personnage.hh"

int main(int argc, char const *argv[])
{
    // lancer le menu

    Afficheur afficheur;

    Menu menu; // Remove the parentheses here

    menu.lancer(&afficheur);
    
    // //Initialise un jeu
    Jeu jeu;
    // //Le jeu lance la partie
    jeu.lancer(&afficheur);

    return 0;
}