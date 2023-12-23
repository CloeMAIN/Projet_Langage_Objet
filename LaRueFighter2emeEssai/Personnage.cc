#include "Personnage.hh"
#include <iostream>

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(sf::Vector2f position, int vie, std::string cheminImage)
    : position(position), vie(vie), cheminImage(cheminImage)
{
    if (!texture.loadFromFile(cheminImage)) {
        throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 80, 40, 40));
    sprite.setScale(5.0f, 5.0f);  // Ajuster l'échelle (5.0f signifie 2 fois plus grand)
    sprite.setPosition(position);

    // Affichage de sattribut du joueur
    std::cout << "Position du joueur : " << position.x << " " << position.y << std::endl;
    std::cout << "Vie du joueur : " << vie << std::endl;
    std::cout << "Chemin de l'image du joueur : " << cheminImage << std::endl;

}


Personnage::~Personnage()
{
}
