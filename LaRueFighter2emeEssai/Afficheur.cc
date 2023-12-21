#include "Afficheur.hh"
#include "Jeu.hh"  // Ajoutez cette ligne pour inclure la définition complète de la classe Jeu



Afficheur::Afficheur(/* args */) : window(sf::VideoMode::getDesktopMode(), "Jeu", sf::Style::Fullscreen)
{
    // créer une fenêtre SFLM

}

Afficheur::~Afficheur() 
{
}

void Afficheur:: afficher(Personnage joueur){

    // met le personnage à sa position dans la window
    joueur.setPosition(joueur.Personnage::getPosition()); // Important de preciser qu'il s'agit de la fonction de la classe Personnage car sf::drawable en ont une aussi
    joueur.chargerTexture();
    window.draw(joueur);
    // e n fonction de l'action du personnage, on affiche une image différente

}

void Afficheur:: afficher(Jeu* jeu){

    // inclue le nom du personnage au dessus et une pdp du perso

    // la barre de vie
    window.clear(sf::Color::Green); 

    // Dessiner le contenu du jeu ici
    window.display();

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