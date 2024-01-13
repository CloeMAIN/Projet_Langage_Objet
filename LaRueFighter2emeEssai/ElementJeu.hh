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

class ElementJeu 
{
protected:
    Point position; 
    std::string chemin_image;

public:
    ElementJeu(/* args */);
    ~ElementJeu();
    Point getPosition() const {return position;}
    void setPosition(Point p){position = p;}
    std::string getCheminImage() const {return chemin_image;}
};

#endif // ELEMENTJEU_HH