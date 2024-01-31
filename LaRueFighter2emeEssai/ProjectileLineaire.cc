#include "ProjectileLineaire.hh"


ProjectileLineaire::ProjectileLineaire(Point position, float vitesse, float degat, float rayon, std::string chemin_image, Direction direction){
    this->position = position;
    this->vitesse = vitesse;
    this->degat = degat;
    this->rayon = rayon;
    this->chemin_image = chemin_image;
    this->temps_de_vie = 0;
    this->direction = direction;

}

void ProjectileLineaire::deplacement(double deltaTime)
{
    float dir = (direction == Direction::DROITE) ? 1 : -1;
    float newX = static_cast<float>(vitesse * deltaTime * dir) + position.x;
    setPosition({newX, position.y});
    setTempsDeVie(temps_de_vie + deltaTime);
    // Vérifier si le projectile est en dehors des limites de la fenêtre
    if (position.x < 0 || position.x > TAILLE_FENETRE.x || position.y < 0 || position.y > TAILLE_FENETRE.y - HAUTEUR_SOL) {
        // Le projectile est en dehors de la fenêtre, détruire le projectile
        a_detruire = true;
    }
}

std::string ProjectileLineaire::toString(){
    std::string str = "ProjectileLineaire : ";
    str += "position : " + std::to_string(position.x) + " " + std::to_string(position.y) +" ";
    str += "vitesse : " + std::to_string(vitesse) + " ";
    str += "degat : " + std::to_string(degat) + " ";
    str += "rayon : " + std::to_string(rayon) + " ";
    str += "temps_de_vie : " + std::to_string(temps_de_vie) + " ";
    str += "a_detruire : " + std::to_string(a_detruire) + " ";
    str += "direction : " + std::to_string(direction) + " ";
    return str;
}