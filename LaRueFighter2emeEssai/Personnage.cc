#include "Personnage.hh"
#include "constant.hh"
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
    sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    sprite.setScale(5.0f, 5.0f);  // Ajuster l'échelle (5.0f signifie 2 fois plus grand)
    sprite.setPosition(position);
    taille = sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    // Affichage de sattribut du joueur
    std::cout << "Position du joueur : " << position.x << " " << position.y << std::endl;
    std::cout << "Vie du joueur : " << vie << std::endl;
    std::cout << "Chemin de l'image du joueur : " << cheminImage << std::endl;

}


Personnage::~Personnage()
{
}

void Personnage::maj(Action action){
    if(action==Action::Droite){
        cheminImage = CHEMIN_IMAGE_JOUEUR1_DROITE;
        if (!texture.loadFromFile(cheminImage)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
        }

        sprite.setTexture(texture);
        int xTexture = (int)sprite.getPosition().x / 128 % 8;
        xTexture = xTexture * 128;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 128, 128));
        sprite.move(VITESSE_JOUEUR1,0);
        position.x = position.x + VITESSE_JOUEUR1; 

    } else if(action==Action::Gauche){
        cheminImage = CHEMIN_IMAGE_JOUEUR1_GAUCHE;
        if (!texture.loadFromFile(cheminImage)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
        }
        sprite.setTexture(texture);
        int xTexture = (int)sprite.getPosition().x / 128 % 8;
        xTexture = xTexture * 128;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 128, 128));
        sprite.move(-VITESSE_JOUEUR1,0);
        position.x = position.x - VITESSE_JOUEUR1;  
    }else{
        cheminImage = CHEMIN_IMAGE_JOUEUR1_RIEN;
        if (!texture.loadFromFile(cheminImage)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));

    }
}