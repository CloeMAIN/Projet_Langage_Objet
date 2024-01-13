#include "ProjectileLineaire.hh"


ProjectileLineaire::ProjectileLineaire(Point position, float vitesse, float degat, float rayon, std::string chemin_image){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
    this->temps_de_vie = 0;

}

void ProjectileLineaire::deplacement(double deltaTime){
    setPosition({vitesse*deltaTime + position.x, position.y}); 
    setTempsDeVie(temps_de_vie + deltaTime);

    // Vérifier si le projectile est en dehors des limites de la fenêtre
    if (position.x < 0 || position.x > TAILLE_FENETRE.x || position.y < 0 || position.y > TAILLE_FENETRE.y - HAUTEUR_SOL) {
        // Le projectile est en dehors de la fenêtre, détruire le projectile
        a_detruire = true;
    }
}