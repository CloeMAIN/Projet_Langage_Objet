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
    int i = 1; // Variable pour gérer la direction du personnage (1 pour droite, -1 pour gauche)
    appliquerGravite(); // Appelle la fonction pour appliquer la gravité au personnage

    // Vérifie la direction du personnage
    if(direction == Direction::GAUCHE){
        i =-1; // Si la direction est gauche, la variable i est mise à -1
    }

    // Si l'état du personnage est "Rien"
    if(etatPlusChemin["Rien"].first){
        // Charge l'image correspondante
        if (!texture.loadFromFile(etatPlusChemin["Rien"].second))
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Rien"].second);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0,35, 81));
        sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
    }
    // Si l'état du personnage est "Avancer"
    else if(etatPlusChemin["Avancer"].first){
        // Charge l'image correspondante
        if (!texture.loadFromFile(etatPlusChemin["Avancer"].second)) 
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Droite"].second);
        sprite.setTexture(texture);
        sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
        int xTexture = (int)position.x / 35 % 8; // Calcul de la position X de la texture à afficher
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        sprite.move(i*VITESSE_JOUEUR1,0); // Déplacement du personnage
        position.x = position.x + i*VITESSE_JOUEUR1; 
    }

    // Si l'état du personnage est "Saut"
    if(etatPlusChemin["Saut"].first){ 
        // Charge l'image correspondante
        if (!texture.loadFromFile(etatPlusChemin["Saut"].second)) 
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Saut"].second);
        sprite.setTexture(texture);
        sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
        int xTexture = (int)position.x / 35 % 8; // Calcul de la position X de la texture à afficher
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        update(); // Appelle la fonction de mise à jour du personnage
    }
}

void Personnage::update(){
    sprite.move(velocity); // Déplace le personnage en fonction de sa vélocité
    position.x += velocity.x; // Met à jour la position X du personnage
    position.y += velocity.y; // Met à jour la position Y du personnage
}

std::string Personnage::toString(){
    // Crée une chaîne de caractères décrivant l'état du personnage
    std::string s = "Position du joueur : " + std::to_string(position.x) + " " + std::to_string(position.y) + "\n" + "Vie du joueur : " + std::to_string(vie) + "\n" + "Direction du joueur : " + std::to_string(direction) + "\n" + "Taille du joueur : " + std::to_string(taille.largeur) + " " + std::to_string(taille.hauteur) + "\n";
    s += "Etat du joueur : \n";
    
    // Ajoute les informations sur chaque état du personnage à la chaîne de caractères
    for (auto const& x : etatPlusChemin) {
        s += x.first + " : " + std::to_string(x.second.first) + x.second.second + "\n";
    }
    return s; // Renvoie la chaîne de caractères représentant l'état du personnage
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