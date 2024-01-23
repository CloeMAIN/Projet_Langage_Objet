#ifndef ELEMENTJEU_HH
#define ELEMENTJEU_HH
#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>

struct Point {
    float x;
    float y;
};

struct HitBox {
    Point GaucheHaut;
    Point DroiteBas;
};

struct Taille {
    float largeur;
    float hauteur;
};

enum Direction {
    GAUCHE,
    DROITE
};

class ElementJeu 
{
protected:
    Point position; 
    std::string chemin_image;
    Direction direction;
    Taille taille; 

public:
    ElementJeu(/* args */);
    ~ElementJeu();
    Point getPosition() const {return position;}
    Taille getTaille() const {return taille;}
    void setPosition(Point p){position = p;}
    std::string getCheminImage() const {return chemin_image;}
    Direction getDirection() const {return direction;}
    void setDirection(Direction d){direction = d;}
    void setTaille(Taille t){taille = t;}
    float distance(const ElementJeu& b)const;
    bool contact(const ElementJeu& b) const;
};

#endif // ELEMENTJEU_HH