#include "ProjectileLineaire.hh"


ProjectileLineaire::ProjectileLineaire(Point position, float vitesse, float degat, float rayon, std::string chemin_image){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
    this->temps_de_vie = 0;

}

void ProjectileLineaire::deplacement(double deltaTime)
{
    float newX = static_cast<float>(vitesse * deltaTime) + position.x;
    setPosition({newX, position.y});
    setTempsDeVie(temps_de_vie + deltaTime);
}