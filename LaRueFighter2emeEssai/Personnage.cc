#include "Personnage.hh"
#include <iostream>

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(Point position, int vie, std::string chemin_image, Direction direction, Taille taille)
    : vie(vie)

{
    if (!texture.loadFromFile(chemin_image)) {
        throw std::runtime_error("Erreur de chargement de l'image : " + chemin_image);
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 35, 81)); // Découper l'image en 8 colonnes et 1 ligne
    sprite.setScale(2.f, 2.f); // Ajuster l'échelle (5.0f signifie 2 fois plus grand)
    sprite.setPosition({position.x, position.y});
    taille.largeur = 35; 
    taille.hauteur = 81;

    // Affichage des attributs du joueur
    std::cout << "Position du joueur : " << position.x << " " << position.y << std::endl;
    std::cout << "Vie du joueur : " << vie << std::endl;
    std::cout << "Chemin de l'image du joueur : " << chemin_image << std::endl;

}


Personnage::~Personnage()
{
}

void Personnage::maj(Action action){
    
    if(action==Action::Droite){
        chemin_image = CHEMIN_IMAGE_JOUEUR1_DROITE;
        if (!texture.loadFromFile(chemin_image)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + chemin_image);
        }

        sprite.setTexture(texture);
        int xTexture = (int)sprite.getPosition().x / 35 % 8;
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        sprite.move(VITESSE_JOUEUR1,0);
        position.x = position.x + VITESSE_JOUEUR1; 
        setDirection(Direction::DROITE);

    }else if(action==Action::Gauche){
        chemin_image = CHEMIN_IMAGE_JOUEUR1_GAUCHE;
        if (!texture.loadFromFile(chemin_image)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + chemin_image);
        }
        sprite.setTexture(texture);
        int xTexture = (int)sprite.getPosition().x / 35 % 8;
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        sprite.move(-VITESSE_JOUEUR1,0);
        //std::cout << "Avant maj Gauche:" << position.x  << "\n" ;
        position.x = position.x - VITESSE_JOUEUR1;
        //std::cout << "Apres maj Gauche:" << position.x <<"\n" ;
        setDirection(Direction::GAUCHE);


    }else if(action==Action::Rien){
        if(direction == Direction::DROITE)
            chemin_image = CHEMIN_IMAGE_JOUEUR1_RIEN_DROITE;
        else
            chemin_image = CHEMIN_IMAGE_JOUEUR1_RIEN_GAUCHE;
        if (!texture.loadFromFile(chemin_image)) {
            throw std::runtime_error("Erreur de chargement de l'image : " + chemin_image);
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0,35, 81));

    }else if(action==Action::SautDroit){
        //tant que y <500 on augmente 

    }else if(action==Action::SautGauche){

    }

}

void Personnage::update(sf::Vector2f velocity){
        sprite.move(velocity);
        position.x += velocity.x;
        position.y += velocity.y;
    }

std::string Personnage::toString(){
        std::string s = "Position du joueur : " + std::to_string(position.x) + " " + std::to_string(position.y) + "\n" + "Vie du joueur : " + std::to_string(vie) + "\n" + "Chemin de l'image du joueur : " + chemin_image + "\n" + "Direction du joueur : " + std::to_string(direction) + "\n" + "Taille du joueur : " + std::to_string(taille.largeur) + " " + std::to_string(taille.hauteur) + "\n";
        return s;
    };