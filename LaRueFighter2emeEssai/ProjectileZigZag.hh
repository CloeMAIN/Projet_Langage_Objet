#pragma once
#include "Projectile.hh"
#include "constant.hh"

class ProjectileZigZag : public Projectile{
private:
    /* data */
    double amplitude; 
    double angle_tir;
    double frequence;
public:
    ProjectileZigZag(Point position, float vitesse, float degat, float rayon, std::string chemin_image, double amplitude, double angle_tir, double frequence, Direction direction);
    ~ProjectileZigZag(){};
    void deplacement(double deltaTime) override;
    bool contact();
};