#include "ProjectileLineaire.hh"


ProjectileLineaire::ProjectileLineaire(Point position, float vitesse, float degat, float rayon, std::string chemin_image){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
}

ProjectileLineaire::~ProjectileLineaire()
{
}

bool ProjectileLineaire::contact(){
    return false;
}

void ProjectileLineaire::deplacement(secondes temps){
    //on récupère le temps avec C++ :
    sf::Time deltaTime = clock.restart();
    while(position.x < TAILLE_FENETRE.x || contact())
    {
        setPosition({vitesse*temps + position.x, position.y});    
    }   
}