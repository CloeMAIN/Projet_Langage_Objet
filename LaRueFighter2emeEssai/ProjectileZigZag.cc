#include "ProjectileZigZag.hh"
#include <math.h>


ProjectileZigZag::ProjectileZigZag(Point position, float vitesse, float degat, float rayon, std::string chemin_image, double amplitude, double angle_tir, double frequence){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
    this->amplitude = amplitude;
    this->angle_tir = angle_tir;
    this->frequence = frequence;
    this->temps_de_vie = 0;
}

void ProjectileZigZag::deplacement(double deltaTime){
    double launchAngleRad = angle_tir * M_PI / 180.0;

    double vx = VITESSE_ZIGZAG * cos(launchAngleRad);
    double vy = VITESSE_ZIGZAG * sin(launchAngleRad) ;

    position.x += vx * deltaTime;
    position.y += vy * deltaTime + amplitude * sin(2 * M_PI * frequence * deltaTime);
    setTempsDeVie(temps_de_vie + deltaTime);

}
