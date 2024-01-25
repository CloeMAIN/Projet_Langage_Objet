#include "Personnage.hh"
#include <iostream>

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(Point position, int vie, std::vector<std::pair<std::string, std::string>> vecteurChemin, Direction direction, Taille taille, std::string cheminActuel)
                        : ElementJeu(position, direction, taille), vie(vie), cheminImageActuelle(cheminActuel)
{
    int i = 0;
    // Mettre les vecteurs de chemin dans etatPlusChemin
    
    etatPlusChemin["Rien"].second = vecteurChemin[0];
    etatPlusChemin["Avancer"].second = vecteurChemin[1];
    etatPlusChemin["Saut"].second = vecteurChemin[2];
    etatPlusChemin["Attaque1"].second = vecteurChemin[3];
    etatPlusChemin["Attaque2"].second = vecteurChemin[4];
    etatPlusChemin["Projectile"].second = vecteurChemin[5];


    //afficher le chemin actuel
    //std::cout << "Chemin actuel : " << cheminImageActuelle << std::endl;

    // Charger la texture à partir du chemin actuel
    sf::Texture texture;
    if (!texture.loadFromFile(cheminImageActuelle)) {
        throw std::runtime_error("Erreur de chargement de l'image : " + cheminImageActuelle);
    }

    // Créer le sprite et lui attribuer la texture
    sprite.setTexture(texture);

    // Découper l'image en 6 colonnes et 1 ligne
    int nombreImages = 6;
    int largeurImage = texture.getSize().x / nombreImages;
    sprite.setTextureRect(sf::IntRect(0, 0, largeurImage, texture.getSize().y));

    // Ajuster l'échelle (2.0f signifie 2 fois plus grand)
    sprite.setScale(2.0f, 2.0f);

    // Positionner le sprite
    sprite.setPosition({position.x, position.y});

    // Définir la taille du sprite
    taille.largeur = largeurImage; 
    taille.hauteur = texture.getSize().y;

    // // Affichage des attributs du joueur
    // std::cout << "Position du joueur : " << position.x << " " << position.y << std::endl;
    // std::cout << "Vie du joueur : " << vie << std::endl;
}




Personnage::~Personnage()
{
}

void Personnage::mouvement(){
    int i = 1; // Variable pour gérer la direction du personnage (1 pour droite, -1 pour gauche)
    appliquerGravite(); // Appelle la fonction pour appliquer la gravité au personnage

    // affiches tous les etat du joueur
    // for (auto const& x : etatPlusChemin) {
    //     std::cout << std::endl;
    //     std::cout << x.first << " : " << x.second.first<< std::endl;
    //     std::cout << std::endl;
    // }
    
    // Vérifie la direction du personnage
    if(direction == Direction::GAUCHE){
        bool gauche = true;
        i = -1;
    }

    // Si l'état du personnage est "Rien"
    if(etatPlusChemin["Rien"].first){
        // // Charge l'image correspondante
        // if (!texture.loadFromFile(etatPlusChemin["Rien"].second))
        //     throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Rien"].second);
        // sprite.setTexture(texture);
        // sprite.setTextureRect(sf::IntRect(0, 0,35, 81));
        // sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
        // modifie le cheminImageActuelle avec le chemin de Rien
        // si c'est gauche alors avec le deuxieme
        // sinon avec le premier
        //std::cout << "On ne fait rien"<< std::endl;
        nbImageSprite = NB_IMAGE_SPRITE_RIEN;
        if(direction == Direction::GAUCHE){
            cheminImageActuelle = etatPlusChemin["Rien"].second.second;
            // std::cout << "Chemin Rien :" << etatPlusChemin["Rien"].second.second << std::endl;
            // std::cout << "Chemin actuel :" << cheminImageActuelle << std::endl;
        }
        else{
            cheminImageActuelle = etatPlusChemin["Rien"].second.first;
            //std::cout << "Chemin actuel :" << cheminImageActuelle << std::endl;
        }
    } else if(etatPlusChemin["Avancer"].first){// Si l'état du personnage est "Avancer"
        // // Charge l'image correspondante
        // if (!texture.loadFromFile(etatPlusChemin["Avancer"].second)) 
        //     throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Droite"].second);
        // sprite.setTexture(texture);
        // sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
        // int xTexture = (int)position.x / 35 % 8; // Calcul de la position X de la texture à afficher
        // xTexture = xTexture * 35;
        // sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        //sprite.move(i*VITESSE_JOUEUR1,0); // Déplacement du personnage
        // modifie le cheminImageActuelle avec le chemin de Avancer
        // si c'est gauche alors avec le deuxieme
        // sinon avec le premier
        nbImageSprite = NB_IMAGE_SPRITE_AVANCER;
        if(direction == Direction::GAUCHE){
            cheminImageActuelle = etatPlusChemin["Avancer"].second.second;
        }
        else{
            cheminImageActuelle = etatPlusChemin["Avancer"].second.first;
        }
        position.x = position.x + i*VITESSE_JOUEUR1; 
        sprite.setPosition(position.x,position.y);
        //update();
    }

    // Si l'état du personnage est "Saut"
    if(etatPlusChemin["Saut"].first){ 

        // std::cout<<"Saut" << std::endl;
        // // Charge l'image correspondante
        // if (!texture.loadFromFile(etatPlusChemin["Saut"].second)) 
        //     throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Saut"].second);
        // sprite.setTexture(texture);
        // sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
        // int xTexture = (int)position.x / 35 % 8; // Calcul de la position X de la texture à afficher
        // xTexture = xTexture * 35;
        // sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        nbImageSprite = NB_IMAGE_SPRITE_SAUT;
        if(direction == Direction::GAUCHE){
            cheminImageActuelle = etatPlusChemin["Saut"].second.second;
        }
        else{
            cheminImageActuelle = etatPlusChemin["Saut"].second.first;
        }
        
        sprite.move(0,VITESSE_JOUEUR1_SAUT);
        position = {sprite.getPosition().x,sprite.getPosition().y}; 

        

        if(position.y + TAILLE_JOUEUR1_SPRITE.hauteur >= POSITION_SOL.y){ // tant qu'il n'a pas touché le sol
            etatPlusChemin["Saut"].first = false;
        }
        
    }
}

void Personnage::update(){
    //std::cout << " Velocity " << " x: "<< velocity.x <<" y: "<<velocity.y << std::endl;
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
        s += x.first + " : " + std::to_string(x.second.first) + x.second.second.first + x.second.second.second + "\n";
    }
    return s; // Renvoie la chaîne de caractères représentant l'état du personnage
};


void Personnage::update_attaque(){
    int i = 1;
    if(direction == Direction::GAUCHE)
        i= -1;
    ElementJeu element;
    // std::cout << "Attaque 1:" << etatPlusChemin["Attaque1"].first << " Attaque 2: " << etatPlusChemin["Attaque2"].first << std::endl;
    if (!blockAtt){
        if(etatPlusChemin["Attaque1"].first){
            
            
            nbImageSprite = NB_IMAGE_ATTAQUE1;
            if(direction == Direction::GAUCHE){
                cheminImageActuelle = etatPlusChemin["Attaque1"].second.second;
            }
            else{
                cheminImageActuelle = etatPlusChemin["Attaque1"].second.first;
            }

            // std::cout << "Attaque 1 début" << std::endl;
            element.setTaille(TAILLE_COUP_POING);
            element.setDirection(direction);
            element.setPosition({position.x + i*TAILLE_COUP_POING.largeur, position.y + DECALAGE_Y_POING});
            clockAtt.restart();
            blockAtt = true;
            // etatPlusChemin["Attaque1"].first = false;
            // std::cout << "Fin attaque 1" << std::endl;
        }
        else if(etatPlusChemin["Attaque2"].first){

            nbImageSprite = NB_IMAGE_ATTAQUE2;
            if(direction == Direction::GAUCHE){
                cheminImageActuelle = etatPlusChemin["Attaque2"].second.second;
            }
            else{
                cheminImageActuelle = etatPlusChemin["Attaque2"].second.first;
            }

            // std::cout << "Attaque2 début" << std::endl;
            element.setTaille(TAILLE_COUP_PIED);
            element.setDirection(direction);
            element.setPosition({position.x + i*TAILLE_COUP_PIED.largeur, position.y + DECALAGE_Y_PIED});
            // etatPlusChemin["Attaque2"].first = false;
            clockAtt.restart();
            blockAtt = true;
            // std::cout << "Fin attaque 2" << std::endl;
        }
        attaque = element;
    }
        // std::cout << "Attaque 1:" << etatPlusChemin["Attaque1"].first << " Attaque 2: " << etatPlusChemin["Attaque2"].first << std::endl;

    else{
        if((clockAtt.getElapsedTime() > sf::seconds(TEMPS_BLOCAGE_ATTAQUE)) or (etatPlusChemin["Rien"].first)){
                attaque = nullptr;
                blockAtt = false;
                etatPlusChemin["Attaque1"].first = false;
                etatPlusChemin["Attaque2"].first = false;
            }
        else{
            // std::cout << "Attaque : " << position.x << " " << position.y << std::endl;
            attaque.setPosition({position.x + i*TAILLE_COUP_PIED.largeur, position.y + DECALAGE_Y_PIED});
        }
    }
    
    
     
    };

void Personnage::appliquerGravite(){
    if (position.y + TAILLE_JOUEUR1_SPRITE.hauteur < POSITION_SOL.y) {
        velocity.y += GRAVITE;
        update();
    }

}

void Personnage::GestionProjectileZigZag(){
    if(etatPlusChemin["Projectile"].first){
        Projectile* projectile = new ProjectileZigZag({position.x+35, position.y + 41}, VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG, direction);
        listeProjectiles.push_back(projectile);
        block = true;
        clockProj.restart();
        etatPlusChemin["Projectile"].first = false;
    }

    if (block && clockProj.getElapsedTime() > sf::seconds(TEMPS_BLOCAGE_PROJECTILE)){
        block = false;
    }
}

void Personnage::GestionProjectileLineaire(){
    if (etatPlusChemin["Projectile"].first){
        Projectile* projectile = new ProjectileLineaire({position.x+35, position.y + 41}, VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_ZIGZAG, direction);
        listeProjectiles.push_back(projectile);
        block = true;
        clockProj.restart();
        etatPlusChemin["Projectile"].first = false;
    }

    if (block && clockProj.getElapsedTime() > sf::seconds(TEMPS_BLOCAGE_PROJECTILE)){
        block = false;
    }
}


void Personnage::majProjectiles(double deltaTime){
    // Utilisez un itérateur pour parcourir la liste
    for (auto it = listeProjectiles.begin(); it != listeProjectiles.end(); ) {
        Projectile* projectile = *it;
        projectile->deplacement(deltaTime);

        // Si le projectile doit être détruit, supprimez-le de la liste et libérez la mémoire
        if (projectile->getADetruire()) {
            it = listeProjectiles.erase(it);  // La fonction erase() retourne le prochain itérateur valide
            delete projectile;
        } else {
            ++it;
        }
    }
}