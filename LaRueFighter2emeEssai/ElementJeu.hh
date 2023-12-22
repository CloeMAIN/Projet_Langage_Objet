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

class ElementJeu : public sf::Drawable
{
private:
public:
    ElementJeu(/* args */);
    ~ElementJeu();
    
};

#endif // ELEMENTJEU_HH