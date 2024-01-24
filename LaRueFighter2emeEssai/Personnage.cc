#include "Personnage.hh"
#include <iostream>

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(Point position, int vie, std::vector<std::string> vecteurChemin, Direction direction, Taille taille)
                        : vie(vie)
{
    //On enregistre les chemins des images dans map etat
    int i = 0;
    for(auto& chemin : etatPlusChemin){
        chemin.second.second = vecteurChemin[i] ;
        i++;
    }

    if (!texture.loadFromFile(etatPlusChemin["Rien"].second)) {
        throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Rien"].second);
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 35, 81)); // Découper l'image en 8 colonnes et 1 ligne
    if (direction == Direction::GAUCHE){
        sprite.setScale(-2.f, 2.f); // Ajuster l'échelle (5.0f signifie 2 fois plus grand)
    }
    else{
        sprite.setScale(2.f, 2.f); // Ajuster l'échelle (5.0f signifie 2 fois plus grand)
    }
    sprite.setPosition({position.x, position.y});
    taille.largeur = 35; 
    taille.hauteur = 81;

    // Affichage des attributs du joueur
    std::cout << "Position du joueur : " << position.x << " " << position.y << std::endl;
    std::cout << "Vie du joueur : " << vie << std::endl;
}


Personnage::~Personnage()
{
}

void Personnage::mouvement(){
    int i = 1;
    appliquerGravite();
    if(direction == Direction::GAUCHE){
        i =-1;
    }

    if(etatPlusChemin["Rien"].first){
        if (!texture.loadFromFile(etatPlusChemin["Rien"].second))
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Rien"].second);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0,35, 81));
        sprite.setScale(i*2.f, 2.f);
    }
    //FAIRE LES CONSTANTE DE TAILLE ET DE NOMBRE D4IMAGE SELON L'ACTION
    else if(etatPlusChemin["Avancer"].first){
        if (!texture.loadFromFile(etatPlusChemin["Avancer"].second)) 
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Droite"].second);
        sprite.setTexture(texture);
        sprite.setScale(i*2.f, 2.f);
        int xTexture = (int)position.x / 35 % 8;
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        sprite.move(i*VITESSE_JOUEUR1,0);
        position.x = position.x + i*VITESSE_JOUEUR1; 
    }

    if(etatPlusChemin["Saut"].first){ 
        if (!texture.loadFromFile(etatPlusChemin["Saut"].second)) 
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Saut"].second);
        sprite.setTexture(texture);
        sprite.setScale(i*2.f, 2.f);
        int xTexture = (int)position.x / 35 % 8;
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        update();
    }
}

void Personnage::update(){
        sprite.move(velocity);
        position.x += velocity.x;
        position.y += velocity.y;
    }

std::string Personnage::toString(){
        std::string s = "Position du joueur : " + std::to_string(position.x) + " " + std::to_string(position.y) + "\n" + "Vie du joueur : " + std::to_string(vie) + "\n" + "Direction du joueur : " + std::to_string(direction) + "\n" + "Taille du joueur : " + std::to_string(taille.largeur) + " " + std::to_string(taille.hauteur) + "\n";
        s += "Etat du joueur : \n";
        for (auto const& x : etatPlusChemin) {
            s += x.first + " : " + std::to_string(x.second.first) + x.second.second + "\n";
        }
        return s;
    };

void Personnage::update_attaque(){
    int i = 1;
    if(direction == Direction::GAUCHE)
        i= -1;
    ElementJeu element;
        if(etatPlusChemin["Attaque1"].first){
            element.setTaille(TAILLE_COUP_POING);
            element.setDirection(direction);
            if (direction == Direction::GAUCHE)
                element.setPosition({position.x + i*TAILLE_COUP_POING.largeur, position.y + DECALAGE_Y_POING});
            sprite.setTexture(texture);
            sprite.setScale(i*2.f, 2.f);
            int xTexture = (int)sprite.getPosition().x / 35 % 4; 
            xTexture = xTexture * 35;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
            sprite.move(i*VITESSE_JOUEUR1,0);
        }
        else if(etatPlusChemin["Attaque2"].first){
            element.setTaille(TAILLE_COUP_PIED);
            element.setDirection(direction);
            if (direction == Direction::GAUCHE)
                element.setPosition({position.x + i*TAILLE_COUP_PIED.largeur, position.y + DECALAGE_Y_PIED});
            sprite.setTexture(texture);
            sprite.setScale(i*2.f, 2.f);
            int xTexture = (int)sprite.getPosition().x / 35 % 4; 
            xTexture = xTexture * 35;
            sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
            sprite.move(i*VITESSE_JOUEUR1,0);
        }                           
        else if(etatPlusChemin["Rien"].first){
            element = nullptr;
        }    
        attaque = element;
    };

void Personnage::appliquerGravite(){
    if (position.y + TAILLE_JOUEUR1_SPRITE.hauteur < POSITION_SOL.y) {
        velocity.y += GRAVITE;
        update();
    }
}