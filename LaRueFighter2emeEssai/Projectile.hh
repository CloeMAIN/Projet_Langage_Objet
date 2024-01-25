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
    std::string chemin_image;

public:
    Projectile(Point position, float vitesse, float degat, float rayon, std::string chemin_image, Direction direction);
    Projectile() = default; 
    ~Projectile();

    //Getter
    float getRayon() const { return rayon;};
    float getVitesse() const { return vitesse;};
    float getDegat() const{ return degat;};
    double getTempsDeVie() const {return temps_de_vie;};
    bool getADetruire() const {return a_detruire;};
    std::string getCheminImage() const {return chemin_image;}


    //Setter
    void setRayon(float rayon){this->rayon = rayon;};
    void setVitesse(float vitesse){this->vitesse = vitesse;};
    void setDegat(float degat){this->degat = degat;};
    void setTempsDeVie(double temps_de_vie) {this->temps_de_vie = temps_de_vie;};
    void setADetruire(bool a_detruire) {this->a_detruire = a_detruire;};
    void setCheminImage(std::string chemin){chemin_image = chemin;}

    // Méthodes
    std::string toString(); 
    virtual void deplacement(double deltaTime) = 0 ;
    
};