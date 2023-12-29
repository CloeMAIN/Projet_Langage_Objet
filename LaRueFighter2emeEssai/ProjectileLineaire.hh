#pragma once
#include "Projectile.hh"
#include "constant.hh"

class ProjectileLineaire : public Projectile{
private:
    /* data */
public:
    ProjectileLineaire(Point position, float vitesse, float degat, float rayon, std::string chemin_image);
    ~ProjectileLineaire();
    void deplacement() override;
    bool contact();
};