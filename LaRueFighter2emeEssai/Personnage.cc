#include "Personnage.hh"
#include "constant.hh"
#include <iostream>

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(Point position, int vie, std::string cheminImage)
    : position(position), vie(vie), cheminImage(cheminImage)
{
    if (!texture.loadFromFile(cheminImage)) {
        throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    sprite.setScale(5.0f, 5.0f);  // Ajuster l'échelle (5.0f signifie 2 fois plus grand)
    sprite.setPosition({position.x, position.y});
    taille = sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

    // Affichage des attributs du joueur
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

    }else if(action==Action::Gauche){
        cheminImage = CHEMIN_IMAGE_JOUEUR1_GAUCHE;
        if (!texture.loadFromFile(cheminImage)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
        }
        sprite.setTexture(texture);
        int xTexture = (int)sprite.getPosition().x / 128 % 8;
        xTexture = xTexture * 128;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 128, 128));
        sprite.move(-VITESSE_JOUEUR1,0);
        //std::cout << "Avant maj Gauche:" << position.x  << "\n" ;
        position.x = position.x - VITESSE_JOUEUR1;
        //std::cout << "Apres maj Gauche:" << position.x <<"\n" ;


    }else if(action==Action::Rien){
        cheminImage = CHEMIN_IMAGE_JOUEUR1_RIEN;
        if (!texture.loadFromFile(cheminImage)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + cheminImage);
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));

    }else if(action==Action::SautDroit){

    }else if(action==Action::SautGauche){

    }

}

std::string Personnage::toString(){
        std::string s = "Position du joueur : " + std::to_string(position.x) + " " + std::to_string(position.y) + "\n" + "Vie du joueur : " + std::to_string(vie) + "\n" + "Chemin de l'image du joueur : " + cheminImage;
        return s;
    };