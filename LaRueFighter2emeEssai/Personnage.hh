#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH
#pragma once
#include <string>
#include "ElementJeu.hh"
#include "constant.hh"
#include "Projectile.hh"
#include <map>
#include <vector>
#include <list>
#include "ProjectileZigZag.hh"
#include "ProjectileLineaire.hh"

enum Action {
    Droite,Gauche,SautGauche,SautDroit,Rien, Poing, Pied
};
class Personnage : public ElementJeu {

private:
    int vie;
    sf::Texture texture;     // Ajout de la texture
    sf::Sprite sprite;       // Ajout du sprite
    ElementJeu attaque ;
    std::list<Projectile*> listeProjectiles;
    std::map<std::string , std::pair<bool, std::string>> etatPlusChemin {
        {"Rien", {true, ""}},
        {"Saut", {false, ""}},
        {"Avancer", {false, ""}},
        {"Attaque1", {false, ""}},
        {"Attaque2", {false, ""}},
        {"Projectile", {false, ""}}
    };// Etat du personnage
    sf::Vector2f velocity;
    bool block = false;
    sf::Clock clockProj ;
    sf::Clock clockAtt;
public:
    // Constructeurs et destructeur
    Personnage();
    Personnage(Point position, int vie, std::vector<std::string> cheminsImages,  Direction direction, Taille taille);
    ~Personnage();

    // Méthodes d'accès
    int getVie() const { return vie; }
    sf::Sprite getSprite() const { return sprite; }
    sf::Texture getTexture() const { return texture; }
    sf::Vector2f getVelocity() const { return velocity; }
    ElementJeu getAttaque() const { return attaque; }
    std::map<std::string , std::pair< bool, std::string>> getEtat() const { return etatPlusChemin; }
    bool getBlock() const { return block; }
    sf::Clock getClockProj(){return clockProj;}
    sf::Clock getClockAtt(){return clockAtt;}
    std::list<Projectile*> getListeProjectiles() const {return listeProjectiles;}

    // Méthodes de modification
    void setEtat(std::string cle, bool new_val) { this->etatPlusChemin[cle].first = new_val; }
    void setCheminImage(std::string cle, std::string new_val) { this->etatPlusChemin[cle].second = new_val; }

    // Méthodes de modification
    void setVie(int vie) { this->vie = vie; }
    void setVelocityX(float x){ this->velocity.x = x;}
    void setVelocityY(float y){ this->velocity.y = y;}
    void setBlock(bool b){ this->block = b;}
    void setClockProj(sf::Time c){this->clockProj.restart();}
    void setClockAtt(sf::Time c){this->clockAtt.restart();}
    void update();

    /* Méthode */
    void mouvement();
    void appliquerGravite();
    void chargerEtAfficherImage(const std::string& etat, int largeur, int hauteur, int directionMultiplier);
    void deplacerPersonnage(float deplacementX, float deplacementY);
    void GestionProjectileZigZag();
    void GestionProjectileLineaire();
    void majProjectiles(double deltaTime);

    std::string toString();
    void update_attaque();

    
};



#endif // PERSONNAGE_HH
