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
    
    Direction direction;
    Taille taille; 

public:
    ElementJeu(/* args */);
    ~ElementJeu();
    Point getPosition() const {return position;}
    Taille getTaille() const {return taille;}
    void setPosition(Point p){position = p;}
    Direction getDirection() const {return direction;}
    void setDirection(Direction d){direction = d;}
    void setTaille(Taille t){taille = t;}
    float distance(const ElementJeu& b)const;
    bool contact(const ElementJeu& b) const;
    ElementJeu& operator=(std::nullptr_t);
    bool operator!=(std::nullptr_t);
    ElementJeu& operator=(const ElementJeu& b);
};

#endif // ELEMENTJEU_HH