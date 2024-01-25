#include "Afficheur.hh"
#include "Jeu.hh"  // Ajoutez cette ligne pour inclure la définition complète de la classe Jeu
#include <iostream>


Afficheur::Afficheur(/* args */) : window(sf::VideoMode::getDesktopMode(), "Jeu", sf::Style::Fullscreen)
{
    // créer une fenêtre SFLM
    window.setFramerateLimit(60); // Limiter le taux de rafraîchissement à 60 images par seconde


}

Afficheur::~Afficheur() 
{
}

void Afficheur::afficher(const Personnage& joueur, const sf::Color& couleur) {
    // Met le personnage à sa position dans la window
    // joueur.getSprite().setPosition({joueur.getPosition().x, joueur.getPosition().y});
    // // Affiche le personnage
    // window.draw(joueur.getSprite());

    sf::RectangleShape pers(sf::Vector2f(joueur.getTaille().largeur, joueur.getTaille().hauteur)); // Utilisation de Vector2f pour la taille
    pers.setPosition(joueur.getPosition().x, joueur.getPosition().y); // Positionné au bas au milieu
    pers.setFillColor(couleur);
    window.draw(pers);
    if(DEBUGGING_MODE){
    //On affiche le point position du joueur sous la forme d'un cercle
    sf::CircleShape cercle(10);
    cercle.setPosition(joueur.getPosition().x, joueur.getPosition().y);
    cercle.setFillColor(sf::Color::Red);
    window.draw(cercle);
    }
    for (Projectile* projectile : joueur.getListeProjectiles()) {
        afficher(*projectile);
    }

    if(joueur.getEtat()["Attaque1"].first){
        afficher(joueur.getAttaque(), couleur);
    }
    else if(joueur.getEtat()["Attaque2"].first){
        afficher(joueur.getAttaque(), couleur);
    }
    
}

void Afficheur::afficher(const ElementJeu& element, const sf::Color& couleur) {
    // Je fais un rectangle
    // sf::RectangleShape rectangle(sf::Vector2f(element.getTaille().largeur, element.getTaille().hauteur)); // Utilisation de Vector2f pour la taille
    // rectangle.setPosition(element.getPosition().x, element.getPosition().y); // Positionné au bas au milieu
    // rectangle.setFillColor(sf::Color::Black);
    // window.draw(rectangle);
    // sf::CircleShape cercle(10);
    // cercle.setPosition(element.getPosition().x, element.getPosition().y);
    // cercle.setFillColor(sf::Color::Black);
    // window.draw(cercle);

    sf::RectangleShape test(sf::Vector2f(element.getTaille().largeur, element.getTaille().hauteur)); // Utilisation de Vector2f pour la taille
    test.setPosition(element.getPosition().x, element.getPosition().y); // Positionné au bas au milieu
    test.setFillColor(couleur);
    window.draw(test);
}

void Afficheur::afficher(const Projectile& projectile) {
    //Créer un sprite pour le projectile
    sf::Sprite spriteProjectile;
    sf::Texture textureProjectile;
    textureProjectile.loadFromFile(projectile.getCheminImage());
    spriteProjectile.setTexture(textureProjectile);
    // Met le projectile à sa position dans la window
    spriteProjectile.setPosition({projectile.getPosition().x, projectile.getPosition().y});
    spriteProjectile.setScale(0.1f, 0.1f); 
    // Affiche le projectile
    window.draw(spriteProjectile);
}


void Afficheur::afficher(Jeu& jeu) {
    // inclut le nom du personnage au-dessus et une pdp du perso
    // la barre de vie
    window.clear(sf::Color::Green); // enlever le menu
    afficherSol();
    afficherBarreVieJ1(jeu.getJoueur1().getVie());
    afficherBarreVieJ2(jeu.getJoueur2().getVie());
    afficher(jeu.getJoueur1(), COULEUR_BARRE_J1); // Affiche le joueur 1
    afficher(jeu.getJoueur2(), COULEUR_BARRE_J2); // Affiche le joueur 2
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
    afficher(CHEMIN_BOUTON_COMMANDES, POSITION_BOUTON_COMMANDES, TAILLE_BOUTON_COMMANDES);
    afficher(CHEMIN_BOUTON_QUITTER, POSITION_BOUTON_QUITTER, TAILLE_BOUTON_QUITTER);
    window.display();
}


void Afficheur::afficherBarreVieJ1(int vie){
    sf::RectangleShape barreVie(sf::Vector2f(vie*10, 50));
    barreVie.setPosition(POSITION_BARRE_J1.x, POSITION_BARRE_J1.y);
    barreVie.setFillColor(COULEUR_BARRE_J1);
    sf::RectangleShape barreVieFond(sf::Vector2f(1000, 50));
    barreVieFond.setPosition(POSITION_BARRE_J1.x, POSITION_BARRE_J1.y);
    barreVieFond.setFillColor(sf::Color::Black);
    if(vie<=0){
        window.draw(barreVieFond); 
    }else{
            window.draw(barreVieFond);
        window.draw(barreVie);
    }

};

void Afficheur::afficherBarreVieJ2(int vie) {
    sf::RectangleShape barreVie(sf::Vector2f(vie * 10, 50));
    barreVie.setPosition(POSITION_BARRE_J2.x + (1000 - vie * 10), POSITION_BARRE_J2.y);
    barreVie.setFillColor(COULEUR_BARRE_J2);
    sf::RectangleShape barreVieFond(sf::Vector2f(1000, 50));
    barreVieFond.setPosition(POSITION_BARRE_J2.x, POSITION_BARRE_J2.y);
    barreVieFond.setFillColor(sf::Color::Black);

    if (vie <= 0) {
        window.draw(barreVieFond);
    } else {
        window.draw(barreVieFond);
        window.draw(barreVie);
    }
}
