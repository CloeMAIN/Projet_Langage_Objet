#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH
#pragma once
#include <string>
#include "ElementJeu.hh"
#include "constant.hh"
#include <map>
#include <vector>

enum Action {
    Droite,Gauche,SautGauche,SautDroit,Rien, Poing, Pied
};
class Personnage : public ElementJeu {

private:
    int vie;
    sf::Texture texture;     // Ajout de la texture
    sf::Sprite sprite;       // Ajout du sprite
    ElementJeu attaque ;
    std::map<std::string , std::pair<bool, std::string>> etatPlusChemin {
        {"Rien", {true, ""}},
        {"Saut", {false, ""}},
        {"Avancer", {false, ""}},
        {"Attaque1", {false, ""}},
        {"Attaque2", {false, ""}},
        {"Projectile", {false, ""}}
    };// Etat du personnage
public:
    // Constructeurs et destructeur
    Personnage();
    Personnage(Point position, int vie, std::vector<std::string> cheminsImages,  Direction direction, Taille taille);
    ~Personnage();

    // Méthodes d'accès
    int getVie() const { return vie; }
    sf::Sprite getSprite() const { return sprite; }
    sf::Texture getTexture() const { return texture; }
    ElementJeu getAttaque() const { return attaque; }
    std::map<std::string , std::pair< bool, std::string>> getEtat() const { return etatPlusChemin; }

    // Méthodes de modification
    void setVie(int vie) { this->vie = vie; }
    void update(sf::Vector2f velocity);
    void setEtat(std::string cle, bool new_val) { this->etatPlusChemin[cle].first = new_val; }
    void setCheminImage(std::string cle, std::string new_val) { this->etatPlusChemin[cle].second = new_val; }
    /* Méthode */
    void mouvement(sf::Vector2f velocity);

    std::string toString();
    void update_attaque();

    
};



#endif // PERSONNAGE_HH
