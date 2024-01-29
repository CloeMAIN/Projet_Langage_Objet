#include "Personnage.hh"
#include <iostream>

Personnage::Personnage(Point position, float vie, std::vector<std::pair<std::string, std::string>> vecteurChemin, Direction direction, Taille taille, std::string cheminActuel)
                        : ElementJeu(position, direction, taille), vie(vie), cheminImageActuelle(cheminActuel)
{
    // Mettre les vecteurs de chemin dans etatPlusChemin
    etatPlusChemin["Rien"].second = vecteurChemin[0];
    etatPlusChemin["Avancer"].second = vecteurChemin[1];
    etatPlusChemin["Saut"].second = vecteurChemin[2];
    etatPlusChemin["Attaque1"].second = vecteurChemin[3];
    etatPlusChemin["Attaque2"].second = vecteurChemin[4];
    etatPlusChemin["Projectile"].second = vecteurChemin[5];

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
    
}

bool Personnage::surPlateforme(std::vector<ElementJeu> plateformes){
    for (int i = 0; i < NB_PLATEFORMES;){
        if(position.x > plateformes[i].getPosition().x && position.x < plateformes[i].getPosition().x + plateformes[i].getTaille().largeur){
            if(position.y + TAILLE_JOUEUR_SPRITE.hauteur >plateformes[i].getPosition().y && position.y + TAILLE_JOUEUR_SPRITE.hauteur < plateformes[i].getPosition().y + plateformes[i].getTaille().hauteur){
                position = {position.x, plateformes[i].getPosition().y - TAILLE_JOUEUR_SPRITE.hauteur};
                setEtat("Saut", false);
                setVelocityY(VITESSE_JOUEUR_SAUT);
                return true;
            }
        }
        i++;
    }
    return false;
}

void Personnage::mouvement(std::vector<ElementJeu> Plateformes){
    int i = 1; // Variable pour gérer la direction du personnage (1 pour droite, -1 pour gauche)
    appliquerGravite(Plateformes); // Appelle la fonction pour appliquer la gravité au personnage
    
    // Vérifie la direction du personnage
    if(direction == Direction::GAUCHE){
        bool gauche = true;
        i = -1;
    }

    // Si l'état du personnage est "Rien"
    if(etatPlusChemin["Rien"].first){
        nbImageSprite = NB_IMAGE_SPRITE_RIEN;
        if(direction == Direction::GAUCHE){
            cheminImageActuelle = etatPlusChemin["Rien"].second.second;
        }
        else{
            cheminImageActuelle = etatPlusChemin["Rien"].second.first;
        }
    } else if(etatPlusChemin["Avancer"].first){// Si l'état du personnage est "Avancer"
        nbImageSprite = NB_IMAGE_SPRITE_AVANCER;
        if(direction == Direction::GAUCHE){
            cheminImageActuelle = etatPlusChemin["Avancer"].second.second;
        }
        else{
            cheminImageActuelle = etatPlusChemin["Avancer"].second.first;
        }
        position.x = position.x + i*VITESSE_JOUEUR; 
        sprite.setPosition(position.x,position.y);
    }

    // Si l'état du personnage est "Saut"
    if(etatPlusChemin["Saut"].first){ 
        nbImageSprite = NB_IMAGE_SPRITE_SAUT;
        if(direction == Direction::GAUCHE){
            cheminImageActuelle = etatPlusChemin["Saut"].second.second;
        }
        else{
            cheminImageActuelle = etatPlusChemin["Saut"].second.first;
        }
        sprite.move(0,VITESSE_JOUEUR_SAUT);
        position = {sprite.getPosition().x,sprite.getPosition().y}; 

        if (position.y + TAILLE_JOUEUR_SPRITE.hauteur >= POSITION_SOL.y ) {
            etatPlusChemin["Saut"].first = false;
        }
    }
}

void Personnage::gestionSaut(std::vector<ElementJeu> Plateformes){

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
        s += x.first + " : " + std::to_string(x.second.first) + x.second.second.first + x.second.second.second + "\n";
    }
    return s; // Renvoie la chaîne de caractères représentant l'état du personnage
};


void Personnage::update_attaque(){
    int i= 1, j =1;
    if(direction == Direction::GAUCHE){
        i= -1; j=0;}
    ElementJeu element;

    if (!blockAtt){
        if(etatPlusChemin["Attaque1"].first){     
            gestionattaque1(i);
        }

        else if(etatPlusChemin["Attaque2"].first){
            gestionattaque2(j);
        }
    }
    else{
        gestionBlocageAttaque(i,j);
    }
}

void Personnage::gestionattaque1(int i){
    ElementJeu element;    
    nbImageSprite = NB_IMAGE_ATTAQUE1;
    if(direction == Direction::GAUCHE){
        cheminImageActuelle = etatPlusChemin["Attaque1"].second.second;
    }
    else{
        cheminImageActuelle = etatPlusChemin["Attaque1"].second.first;
    }
    element.setTaille(TAILLE_ATTAQUE1);
    element.setDirection(direction);
    element.setPosition({position.x + taille.largeur/2 +i*TAILLE_ATTAQUE1.largeur, position.y + DECALAGE_Y_POING});
    clockAtt.restart();
    blockAtt = true;
    attaque = element;
}

void Personnage::gestionattaque2(int j){
    ElementJeu element;
    nbImageSprite = NB_IMAGE_ATTAQUE2;
    if(direction == Direction::GAUCHE){
        cheminImageActuelle = etatPlusChemin["Attaque2"].second.second;
    }
    else{
        cheminImageActuelle = etatPlusChemin["Attaque2"].second.first;
    }

    element.setTaille(TAILLE_ATTAQUE2);
    element.setDirection(direction);
    element.setPosition({position.x + taille.largeur/2 + j*TAILLE_ATTAQUE2.largeur, position.y + DECALAGE_Y_PIED});
    clockAtt.restart();
    blockAtt = true;
    attaque = element;
}

void Personnage::gestionBlocageAttaque(int i, int j){
    if((clockAtt.getElapsedTime() > sf::seconds(TEMPS_BLOCAGE_ATTAQUE)) or (etatPlusChemin["Rien"].first)){
                attaque = nullptr;
                blockAtt = false;
                etatPlusChemin["Attaque1"].first = false;
                etatPlusChemin["Attaque2"].first = false;
            }
        else{
            if(etatPlusChemin["Attaque1"].first){
                attaque.setPosition({position.x + taille.largeur/2 + i*TAILLE_ATTAQUE1.largeur, position.y + DECALAGE_Y_POING});
            }
            else if(etatPlusChemin["Attaque2"].first){
                attaque.setPosition({position.x + j*TAILLE_ATTAQUE2.largeur, position.y + DECALAGE_Y_PIED});
            }
        }
}

void Personnage::appliquerGravite(std::vector<ElementJeu> Plateformes){
    if (position.y + TAILLE_JOUEUR_SPRITE.hauteur < POSITION_SOL.y ) {
        velocity.y += GRAVITE;
        update();
    }


}

void Personnage::GestionProjectileZigZag(){
    if(etatPlusChemin["Projectile"].first){
        int i =1 ;
        if(direction == Direction::GAUCHE)i=-1;
        Projectile* projectile = new ProjectileZigZag({position.x+taille.largeur/2 * (i+1) + i*3, position.y + taille.hauteur/2}, VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG, direction);
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
        int i =1 ;
        if(direction == Direction::GAUCHE)i=-1;
        Projectile* projectile = new ProjectileLineaire({position.x+taille.largeur/2 * (i+1) + i*3, position.y + taille.hauteur/2}, VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_ZIGZAG, direction);
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
        } 
    else {
        ++it;
        }
    }
}




void Personnage::update_contact(Personnage& personnage){
    contact_projectile(personnage);
    contact_projectile();
    contact_attaque(personnage);

    if(vie <= 0){
        position = {position.x, POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.largeur};
        taille = {TAILLE_JOUEUR_SPRITE.hauteur, TAILLE_JOUEUR_SPRITE.largeur};
    }
    
}

//On vérifie que les projectiles du joueur this ont touché le joueur personnage
void Personnage::contact_projectile(Personnage& personnage){
    //On test que this n'est pas en contact avec un projectile de personnage en utilisant la fonction contact de ElementJeu
    for (auto it = listeProjectiles.begin(); it != listeProjectiles.end(); ) {
        Projectile* projectile = *it;
        //Si le projectile touche le personnage, on le supprime de la liste et on libère la mémoire
        if (projectile->contact(personnage)){
            personnage.setVie(personnage.getVie() - projectile->getDegat());
            it = listeProjectiles.erase(it);  // La fonction erase() retourne le prochain itérateur valide
            delete projectile;
        } 
        else {
            ++it;
        }
    }
   
}

//On vérifie que les projectiles du joueur this ont touché le joueur this
void Personnage::contact_projectile(){
    //On test que this n'est pas en contact avec un projectile de personnage en utilisant la fonction contact de ElementJeu
    for (auto it = listeProjectiles.begin(); it != listeProjectiles.end(); ) {
        Projectile* projectile = *it;
        //Si le projectile touche le personnage, on le supprime de la liste et on libère la mémoire
        if (projectile->contact(*this)){
            vie = vie - projectile->getDegat();
            it = listeProjectiles.erase(it);  // La fonction erase() retourne le prochain itérateur valide
            delete projectile;
        } 
        else {
            ++it;
        }
    }
   
}

void Personnage::contact_attaque(Personnage& personnage){
    if (attaque.contact(personnage)){
        int i = 1;
        if(direction == Direction::GAUCHE)i=-1;
        if(etatPlusChemin["Attaque1"].first){
            personnage.setVie(personnage.getVie() - DEGAT_ATTAQUE1);
            etatPlusChemin["Attaque1"].first = false;
            personnage.setPosition({personnage.getPosition().x + i*RECUL_ATTAQUE1, personnage.getPosition().y});
        }
        else if(etatPlusChemin["Attaque2"].first){
            personnage.setVie(personnage.getVie() - DEGAT_ATTAQUE2);
            etatPlusChemin["Attaque2"].first = false;
            personnage.setPosition({personnage.getPosition().x + i*RECUL_ATTAQUE2, personnage.getPosition().y});
        }
        
            
    attaque = nullptr;

    }
}


