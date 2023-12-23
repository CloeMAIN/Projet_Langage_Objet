#include "Afficheur.hh"
#include "Jeu.hh"  // Ajoutez cette ligne pour inclure la définition complète de la classe Jeu
#include <iostream>

Afficheur::Afficheur(/* args */) : window(sf::VideoMode::getDesktopMode(), "Jeu", sf::Style::Fullscreen)
{
    // créer une fenêtre SFLM

}

Afficheur::~Afficheur() 
{
}

void Afficheur::afficher(const Personnage& joueur) {
    // Met le personnage à sa position dans la window
    joueur.getSprite().setPosition(joueur.getPosition());
    // Affiche le personnage
    window.draw(joueur.getSprite());
}



void Afficheur::afficher(Jeu& jeu) {

        // inclue le nom du personnage au dessus et une pdp du perso
        // la barre de vie
        afficher(jeu.getJoueur1()); // Affiche le joueur 1
        afficher(jeu.getJoueur2()); // Affiche le joueur 2
        // Ajoutez d'autres éléments à afficher en fonction de l'objet Jeu
}


// Afficheur:: afficher(Bouton){
//     en fonction image
// }

// Afficheur:: afficher(Background){

// }

// Afficheur:: afficher(Sol){
    
// }

// Afficheur:: afficher(Texte){

// }

// Afficher:: afficher(Barre de vie){

//     // inclue le nom du personnage au dessus et une pdp du perso

//     // la barre de vie

// }

// Afficheur::afficherMenu(){

//     // en fonction du nom du bouton, on affiche une image différente
//     //On utilisera background et bouton.


// }

// Afficheur::afficherCommande(){
    
//         // affiche les commandes
// }