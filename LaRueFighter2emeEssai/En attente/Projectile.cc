#include "Projectile.hh"

Projectile::Projectile(Point position, float vitesse, float degat, float rayon, std::string chemin_image){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
}

Projectile::~Projectile()
{
}

std::string Projectile::toString(){
    std::string s = "Projectile : \n";
    s += "Position : (" + std::to_string(position.x) + "," + std::to_string(position.y) + ")\n";
    s += "Vitesse : " + std::to_string(vitesse) + "\n";
    s += "Degat : " + std::to_string(degat) + "\n";
    s += "Rayon : " + std::to_string(rayon) + "\n";
    s += "Chemin image : " + chemin_image + "\n";
    return s;
}