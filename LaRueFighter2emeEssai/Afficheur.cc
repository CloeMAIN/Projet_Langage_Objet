#include "Afficheur.hh"
#include "Jeu.hh"  // Ajoutez cette ligne pour inclure la définition complète de la classe Jeu
#include <iostream>
#include "constant.hh"

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
    // inclut le nom du personnage au-dessus et une pdp du perso
    // la barre de vie
    window.clear(sf::Color::Green); // enlever le menu
    afficherSol();
    afficher(jeu.getJoueur1()); // Affiche le joueur 1
    afficher(jeu.getJoueur2()); // Affiche le joueur 2
    // Ajoutez d'autres éléments à afficher en fonction de l'objet Jeu
    window.display();
}


void Afficheur:: afficher(std::string cheminbouton, Point position, HitBox taille){
sf::Texture texture;
    texture.loadFromFile(cheminbouton);
    sf::Sprite bouton;
    bouton.setTexture(texture);
    bouton.setPosition(position.x, position.y);
    bouton.setScale((taille.DroiteBas.x - taille.GaucheHaut.x) / bouton.getLocalBounds().width, (taille.DroiteBas.y - taille.GaucheHaut.y) / bouton.getLocalBounds().height);
    window.draw(bouton);
}


// Afficheur:: afficher(Bouton){
//     en fonction image
// }

void Afficheur:: afficher(std::string cheminBackground){
    sf::Texture texture;
    texture.loadFromFile(cheminBackground);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(static_cast<float>(TAILLE_FENETRE.x) / static_cast<float>(sprite.getLocalBounds().width), static_cast<float>(TAILLE_FENETRE.y) / static_cast<float>(sprite.getLocalBounds().height));
    window.draw(sprite);
}

void Afficheur::afficherSol() {
    sf::RectangleShape sol(sf::Vector2f(TAILLE_FENETRE.x, HAUTEUR_SOL)); // Utilisation de Vector2f pour la taille
    sol.setPosition(0, TAILLE_FENETRE.y-HAUTEUR_SOL); // Positionné au bas au milieu
    sol.setFillColor(sf::Color::Blue);
    window.draw(sol);
}

// Afficheur:: afficher(Texte){

// }

// Afficher:: afficher(Barre de vie){

//     // inclue le nom du personnage au dessus et une pdp du perso

//     // la barre de vie

// }    

void Afficheur::afficherMenu(){
    /* Affichage du background */
    afficher(CHEMIN_BACKGROUND_MENU);
    
    /*Affichage des différents boutons*/
    afficher(CHEMIN_BOUTON_JOUER, POSITION_BOUTON_JOUER, TAILLE_BOUTON_JOUER);
    // afficher(CHEMIN_BOUTON_COMMANDES, POSITION_BOUTON_COMMANDES, TAILLE_BOUTON_COMMANDES);
    afficher(CHEMIN_BOUTON_QUITTER, POSITION_BOUTON_QUITTER, TAILLE_BOUTON_QUITTER);
    window.display();
}

// Afficheur::afficherCommande(){
    
//         // affiche les commandes
// }