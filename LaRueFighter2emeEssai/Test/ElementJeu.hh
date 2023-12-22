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
    sf::Texture texture;
    sf::Sprite sprite;
    std::string cheminImage;
    Point position;
public:
    ElementJeu(/* args */);
    ElementJeu(Point position, std::string cheminImage);
    ~ElementJeu();

    /*Getter*/
    sf::Texture getTexture(){return texture;}
    sf::Sprite getSprite(){return sprite;}
};

#endif // ELEMENTJEU_HH