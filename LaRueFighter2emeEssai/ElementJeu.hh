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
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string cheminImage;
    Point position;
public:
    ElementJeu(/* args */);
    ~ElementJeu();
    void chargerTexture();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // Dessinez le sprite de l'élément
        target.draw(sprite, states);
    }
};

#endif // ELEMENTJEU_HH