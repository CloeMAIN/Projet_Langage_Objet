#pragma once
#include <string>
#include "ElementJeu.hh"

class Projectile : public ElementJeu {
protected:
    /* data */
    float rayon;
    float vitesse;
    float degat;
    double temps_de_vie;
    bool a_detruire = false;
public:
    Projectile(Point position, float vitesse, float degat, float rayon, std::string chemin_image);
    Projectile() = default; 
    ~Projectile();
    float getRayon() const { return rayon;};
    float getVitesse() const { return vitesse;};
    float getDegat() const{ return degat;};
    double getTempsDeVie() const {return temps_de_vie;};
    void setRayon(float rayon){this->rayon = rayon;};
    void setVitesse(float vitesse){this->vitesse = vitesse;};
    void setDegat(float degat){this->degat = degat;};
    void setTempsDeVie(double temps_de_vie) {this->temps_de_vie = temps_de_vie;};
    bool getADetruire() const {return a_detruire;};
    void setADetruire(bool a_detruire) {this->a_detruire = a_detruire;};
    virtual void deplacement(double deltaTime) = 0 ;
    std::string toString(); 
};