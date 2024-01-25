#pragma once
#include "Projectile.hh"
#include "constant.hh"

class ProjectileLineaire : public Projectile{
private:

public:
    ProjectileLineaire(Point position, float vitesse, float degat, float rayon, std::string chemin_image, Direction direction);
    ~ProjectileLineaire(){};

    // Méthodes
    void deplacement(double deltaTime) override;
};