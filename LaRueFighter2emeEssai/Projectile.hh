#pragma once
#include <string>
#include "ElementJeu.hh"

class Projectile : public ElementJeu {
protected:
    /* data */
    float rayon;
    float vitesse;
    float degat;
public:
    Projectile(Point position, float vitesse, float degat, float rayon, std::string chemin_image);
    Projectile() = default; 
    ~Projectile();
    virtual void deplacement() = 0 ;
    std::string toString(); 
};