#include "ProjectileZigZag.hh"
#include <math.h>


ProjectileZigZag::ProjectileZigZag(Point position, float vitesse, float degat, float rayon, std::string chemin_image, double amplitude, double angle_tir, double frequence, Direction direction){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
    this->amplitude = amplitude;
    this->angle_tir = angle_tir;
    this->frequence = frequence;
    this->temps_de_vie = 0;
    this->direction = direction;
}

void ProjectileZigZag::deplacement(double deltaTime)
{

    float dir = (direction == Direction::DROITE) ? 1 : -1;
    double launchAngleRad = angle_tir * M_PI / 180.0;

    double angle = launchAngleRad + frequence * temps_de_vie; // Modulation en fonction du temps
    double x = dir * vitesse * deltaTime;        // Composante horizontale
    double y = amplitude * sin(angle) * deltaTime;                  // Composante verticale

    float newX = static_cast<float>(position.x + x);
    float newY = static_cast<float>(position.y + y);
    setPosition({newX , newY});  // Mettre à jour la position du projectile
    setTempsDeVie(temps_de_vie + deltaTime);         // Mettre à jour le temps écoulé

    // Vérifier si le projectile est en dehors des limites de la fenêtre
    if (newX < 0 || newX > TAILLE_FENETRE.x || newY < 0 ) { 
        // Le projectile est en dehors de la fenêtre, détruire le projectile
        a_detruire = true;
    }
}
