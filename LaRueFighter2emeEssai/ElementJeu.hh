#ifndef ELEMENTJEU_HH
#define ELEMENTJEU_HH

#include <string>
#include <SFML/Graphics.hpp>

struct Point {
    float x;
    float y;
};

struct HitBox {
    Point GaucheHaut;
    Point DroiteBas;
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

public:
    ElementJeu(/* args */);
    ~ElementJeu();
    Point getPosition() const {return position;}
    void setPosition(Point p){position = p;}
    std::string getCheminImage() const {return chemin_image;}
    Direction getDirection() const {return direction;}
    void setDirection(Direction d){direction = d;}
    // float distance(const ElementJeu& b)const;
};

#endif // ELEMENTJEU_HH