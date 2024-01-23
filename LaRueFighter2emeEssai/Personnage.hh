#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH
#pragma once
#include <string>
#include "ElementJeu.hh"
#include "constant.hh"

enum Action {
    Droite,Gauche,SautGauche,SautDroit,Rien, Poing, Pied
};
class Personnage : public ElementJeu {

private:
    int vie;
    sf::Texture texture;     // Ajout de la texture
    sf::Sprite sprite;       // Ajout du sprite
public:
    // Constructeurs et destructeur
    Personnage();
    Personnage(Point position, int vie, std::string cheminImage,  Direction direction, Taille taille);
    ~Personnage();

    // Méthodes d'accès
    int getVie() const { return vie; }
    sf::Sprite getSprite() const { return sprite; }
    sf::Texture getTexture() const { return texture; }

    // Méthodes de modification
    void setVie(int vie) { this->vie = vie; }
    void update(sf::Vector2f velocity);

    /* Méthode */
    void maj(Action action);

    std::string toString();
    ElementJeu attaque(Action action);

    
};



#endif // PERSONNAGE_HH
