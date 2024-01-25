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
    ElementJeu();
    ElementJeu(Point position, Direction direction, Taille taille);
    ~ElementJeu(){};

    //Operateur
    ElementJeu& operator=(std::nullptr_t);
    bool operator!=(std::nullptr_t);
    ElementJeu& operator=(const ElementJeu& b);

    // Méthodes d'accès
    Point getPosition() const {return position;}
    Taille getTaille() const {return taille;}
    Direction getDirection() const {return direction;}

    // Méthodes de modification
    void setPosition(Point p){position = p;}
    void setDirection(Direction d){direction = d;}
    void setTaille(Taille t){taille = t;}

    // Méthodes
    float distance(const ElementJeu& b)const;
    bool contact(const ElementJeu& b) const;
   
};

#endif // ELEMENTJEU_HH