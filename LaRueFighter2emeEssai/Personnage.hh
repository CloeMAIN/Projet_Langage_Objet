#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH

#include <string>
#include "ElementJeu.hh"

enum Action {
    Droite,Gauche,Rien
};
class Personnage {

private:
    int vie;
    std::string cheminImage;  // Ajout du chemin de l'image
    sf::Texture texture;     // Ajout de la texture
    sf::Sprite sprite;       // Ajout du sprite
    Point position;
    sf::Vector2f taille;
public:
    // Constructeurs et destructeur
    Personnage();
    Personnage(Point position, int vie, std::string cheminImage);
    ~Personnage();

    // Méthodes d'accès
    Point getPosition() const { return position; }
    int getVie() const { return vie; }
    std::string getCheminImage() const { return cheminImage; }
    sf::Sprite getSprite() const { return sprite; }
    sf::Texture getTexture() const { return texture; }

    // Méthodes de modification
    void setVie(int vie) { this->vie = vie; }
    

    /* Méthode */
    void maj(Action action);
};



#endif // PERSONNAGE_HH
