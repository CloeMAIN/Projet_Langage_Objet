#include "Menu.hh"
#include "Jeu.hh"
#include "Afficheur.hh"
#include "ElementJeu.hh"
#include "Personnage.hh"
#include "Projectile.hh"
#include "ProjectileZigZag.hh"
#include "InputUser.hh"
#include "constant.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
    //Initialise un jeu
    Jeu jeu;
    Afficheur afficheur;
    Menu menu; // Remove the parentheses here
    int test = 0;
    test  = menu.lancer(&afficheur);
    
    
    if (test == 0){
    //Le jeu lance la partie
    jeu.lancer(&afficheur);
    }

   

    return 0;
}