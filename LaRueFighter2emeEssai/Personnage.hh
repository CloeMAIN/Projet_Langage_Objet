#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH
#pragma once
#include <string>
#include "ElementJeu.hh"
#include "constant.hh"
#include <map>

enum Action {
    Droite,Gauche,SautGauche,SautDroit,Rien, Poing, Pied
};
class Personnage : public ElementJeu {

private:
    int vie;
    sf::Texture texture;     // Ajout de la texture
    sf::Sprite sprite;       // Ajout du sprite
    std::map<std::string , bool> etat {
        {"Haut", false},
        {"Droite", false},
        {"Gauche", false},
        {"Attaque1", false},
        {"Attaque2", false},
        {"Projectile", false}
    };// Etat du personnage
    sf::Vector2f velocity;
public:
    // Constructeurs et destructeur
    Personnage();
    Personnage(Point position, int vie, std::string cheminImage,  Direction direction, Taille taille);
    ~Personnage();

    // Méthodes d'accès
    int getVie() const { return vie; }
    sf::Sprite getSprite() const { return sprite; }
    sf::Texture getTexture() const { return texture; }
    sf::Vector2f getVelocity() const { return velocity; }

    // Méthodes de modification
    void setVie(int vie) { this->vie = vie; }
    void setVelocityX(float x){ this->velocity.x = x;}
    void setVelocityY(float y){ this->velocity.y = y;}
    void update();

    /* Méthode */
    void maj(Action action);

    std::string toString();
    ElementJeu attaque(Action action);

    
};



#endif // PERSONNAGE_HH
