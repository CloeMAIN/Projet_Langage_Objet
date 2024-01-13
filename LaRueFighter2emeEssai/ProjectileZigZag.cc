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

    double angle = launchAngleRad + frequence * temps_de_vie; // Modulation en fonction du temps
    double x = vitesse* deltaTime ;        // Composante horizontale
    double y = amplitude * sin(angle)* deltaTime;                  // Composante verticale

    setPosition({position.x + x, position.y + y});  // Mettre à jour la position du projectile
    setTempsDeVie(temps_de_vie + deltaTime);         // Mettre à jour le temps écoulé

    // Vérifier si le projectile est en dehors des limites de la fenêtre
    if (position.x < 0 || position.x > TAILLE_FENETRE.x || position.y < 0 || position.y > TAILLE_FENETRE.y -HAUTEUR_SOL) {
        // Le projectile est en dehors de la fenêtre, détruire le projectile
        a_detruire = true;
    }
}
