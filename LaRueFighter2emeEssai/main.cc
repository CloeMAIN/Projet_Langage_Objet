#include "Menu.hh"
#include "Jeu.hh"
#include "Afficheur.hh"
#include "ElementJeu.hh"
#include "Personnage.hh"

int main(int argc, char const *argv[])
{
    //lancer le menu
    Afficheur afficheur;

    Menu menu; // Remove the parentheses here
    int test = 0;
    test  = menu.lancer(&afficheur);
    
    //Initialise un jeu
    Jeu jeu;
    if (test == 0){
    //Le jeu lance la partie
    jeu.lancer(&afficheur);
    }

   

    return 0;
}