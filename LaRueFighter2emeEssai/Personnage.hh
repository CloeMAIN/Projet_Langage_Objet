#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH

#include <string>
#include "ElementJeu.hh"

class Personnage {

private:
    int vie;
    std::string cheminImage;  // Ajout du chemin de l'image
    sf::Texture texture;     // Ajout de la texture
    sf::Sprite sprite;       // Ajout du sprite
    sf::Vector2f position;
public:
    // Constructeurs et destructeur
    Personnage();
    Personnage(sf::Vector2f position, int vie, std::string cheminImage);
    ~Personnage();

    // Méthodes d'accès
    sf::Vector2f getPosition() const { return position; }
    int getVie() const { return vie; }
    std::string getCheminImage() const { return cheminImage; }
    sf::Sprite getSprite() const { return sprite; }
    sf::Texture getTexture() const { return texture; }

    // Méthodes de modification
    void setVie(int vie) { this->vie = vie; }
};



#endif // PERSONNAGE_HH
