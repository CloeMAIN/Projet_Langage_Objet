#ifndef ELEMENTJEU_HH
#define ELEMENTJEU_HH

#include <string>
#include <SFML/Graphics.hpp>

struct Point {
    int x;
    int y;
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
    Point getPosition(){return position;}
    void setPosition(Point p){position = p;}
    std::string getCheminImage(){return chemin_image;}
};

#endif // ELEMENTJEU_HH