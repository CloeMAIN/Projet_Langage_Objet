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

    //Getter
    double getAmplitude() const {return amplitude;}
    double getAngleTir() const {return angle_tir;}
    double getFrequence() const {return frequence;}

    //Setter
    void setAmplitude(double amplitude){this->amplitude = amplitude;}
    void setAngleTir(double angle_tir){this->angle_tir = angle_tir;}
    void setFrequence(double frequence){this->frequence = frequence;}

    // Méthodes
    void deplacement(double deltaTime) override;
    std::string toString() override;
};