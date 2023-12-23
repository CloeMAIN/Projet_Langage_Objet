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

void Afficheur:: afficher(std::string cheminbouton, Point position, HitBox taille){
sf::Texture texture;
    texture.loadFromFile(cheminbouton);
    sf::Sprite bouton;
    bouton.setTexture(texture);
    bouton.setPosition(position.x, position.y);
    bouton.setScale((taille.DroiteBas.x - taille.GaucheHaut.x) / bouton.getLocalBounds().width, (taille.DroiteBas.y - taille.GaucheHaut.y) / bouton.getLocalBounds().height);
    window.draw(bouton);
}

void Afficheur:: afficher(std::string cheminBackground){
    sf::Texture texture;
    texture.loadFromFile(cheminBackground);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(static_cast<float>(TAILLE_FENETRE.x) / static_cast<float>(sprite.getLocalBounds().width), static_cast<float>(TAILLE_FENETRE.y) / static_cast<float>(sprite.getLocalBounds().height));
    window.draw(sprite);
}

// Afficheur:: afficher(Sol){

// }

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
    afficher(CHEMIN_BOUTON_COMMANDES, POSITION_BOUTON_COMMANDES, TAILLE_BOUTON_COMMANDES);
    afficher(CHEMIN_BOUTON_QUITTER, POSITION_BOUTON_QUITTER, TAILLE_BOUTON_QUITTER);
    window.display();
}

// Afficheur::afficherCommande(){
    
//         // affiche les commandes
// }