#include "Personnage.hh"
#include <iostream>

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(Point position, int vie, std::vector<std::string> vecteurChemin, Direction direction, Taille taille)
                        : ElementJeu(position, direction, taille),  vie(vie)
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

    // affiches tous les etat du joueur
    // for (auto const& x : etatPlusChemin) {
    //     std::cout << x.first << " : " << x.second.first << x.second.second << std::endl;
    // }
    
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
        //update();
    }

    // Si l'état du personnage est "Saut"
    if(etatPlusChemin["Saut"].first){ 
        std::cout<<"Saut" << std::endl;
        // Charge l'image correspondante
        if (!texture.loadFromFile(etatPlusChemin["Saut"].second)) 
            throw std::runtime_error("Erreur de chargement de l'image : " + etatPlusChemin["Saut"].second);
        sprite.setTexture(texture);
        sprite.setScale(i*2.f, 2.f); // Ajuste l'échelle en fonction de la direction
        int xTexture = (int)position.x / 35 % 8; // Calcul de la position X de la texture à afficher
        xTexture = xTexture * 35;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, 35, 82));
        sprite.move(0,VITESSE_JOUEUR1_SAUT);
        position = {sprite.getPosition().x,sprite.getPosition().y}; 
        // mettre saut à false;
        //update();
        //appliquerGravite();
        //update(); // Appelle la fonction de mise à jour du personnage
        // à la fin du saut, remettre sau tà false
        if(position.y + TAILLE_JOUEUR1_SPRITE.hauteur >= POSITION_SOL.y){
            etatPlusChemin["Saut"].first = false;
        }
        
    }
}

void Personnage::update(){
    // std::cout << " Velocity " << " x: "<< velocity.x <<" y: "<<velocity.y << std::endl;
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
    // std::cout << "Attaque 1:" << etatPlusChemin["Attaque1"].first << " Attaque 2: " << etatPlusChemin["Attaque2"].first << std::endl;
    if (!blockAtt){
        if(etatPlusChemin["Attaque1"].first){
            // std::cout << "Attaque 1 début" << std::endl;
            element.setTaille(TAILLE_ATTAQUE1);
            element.setDirection(direction);
            element.setPosition({position.x + i*TAILLE_ATTAQUE1.largeur, position.y + DECALAGE_Y_POING});
            clockAtt.restart();
            blockAtt = true;
            // etatPlusChemin["Attaque1"].first = false;
            // std::cout << "Fin attaque 1" << std::endl;
        }
        else if(etatPlusChemin["Attaque2"].first){
            // std::cout << "Attaque2 début" << std::endl;
            element.setTaille(TAILLE_ATTAQUE2);
            element.setDirection(direction);
            element.setPosition({position.x + i*TAILLE_ATTAQUE2.largeur, position.y + DECALAGE_Y_PIED});
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
            attaque.setPosition({position.x + i*TAILLE_ATTAQUE2.largeur, position.y + DECALAGE_Y_PIED});
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
    std::cout << "Entrée contact" << std::endl;
    contact_projectile(personnage);
    contact_projectile();
    contact_attaque(personnage);

    if(vie <= 0){
        position = {position.x, POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.largeur};
        taille = {TAILLE_JOUEUR1_SPRITE.hauteur, TAILLE_JOUEUR1_SPRITE.largeur};
    }
    
}

//On vérifie que les projectiles du joueur this ont touché le joueur personnage
void Personnage::contact_projectile(Personnage& personnage){
    std::cout << "Entrée contact_projectile" << std::endl;
    //On test que this n'est pas en contact avec un projectile de personnage en utilisant la fonction contact de ElementJeu
    for (auto it = listeProjectiles.begin(); it != listeProjectiles.end(); ) {
        Projectile* projectile = *it;
        //Si le projectile touche le personnage, on le supprime de la liste et on libère la mémoire
        if (projectile->contact(personnage)){
            std::cout << "Contact" << std::endl;
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
    std::cout << "Entrée contact_projectile" << std::endl;
    //On test que this n'est pas en contact avec un projectile de personnage en utilisant la fonction contact de ElementJeu
    for (auto it = listeProjectiles.begin(); it != listeProjectiles.end(); ) {
        Projectile* projectile = *it;
        //Si le projectile touche le personnage, on le supprime de la liste et on libère la mémoire
        if (projectile->contact(*this)){
            std::cout << "Contact" << std::endl;
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
            personnage.setPosition({personnage.getPosition().x + i*TAILLE_ATTAQUE1.largeur, personnage.getPosition().y});
        }
        else if(etatPlusChemin["Attaque2"].first){
            personnage.setVie(personnage.getVie() - DEGAT_ATTAQUE2);
            etatPlusChemin["Attaque2"].first = false;
            personnage.setPosition({personnage.getPosition().x + i*TAILLE_ATTAQUE2.largeur, personnage.getPosition().y});
        }
        
            
    attaque = nullptr;

    }
}