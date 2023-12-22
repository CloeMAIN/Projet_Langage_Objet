#include "ElementJeu.hh"

ElementJeu::ElementJeu(/* args */)
{
    
}

ElementJeu::ElementJeu(Point position, std::string cheminImage)
{
    if (!texture.loadFromFile(cheminImage)) {
            // Gestion d'erreur si le chargement de l'image échoue
            // Assurez-vous que l'image est dans le même répertoire que votre programme
            // ou spécifiez le chemin correct
            throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
        }

    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(position.x, position.y));
    this->position = position;
    this->cheminImage = cheminImage;
}

ElementJeu::~ElementJeu()
{
}