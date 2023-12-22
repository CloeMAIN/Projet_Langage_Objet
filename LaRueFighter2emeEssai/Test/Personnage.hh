#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH

#include <string>
#include "ElementJeu.hh"

class Personnage : public ElementJeu{
private:
    //Hitbox hitbox;
    int vie;
public:
    //constructeur
    Personnage();
    Personnage(Point position, int vie, std::string cheminImage);
    ~Personnage();

    //Hitbox getHitbox();
    Point getPosition(){return position;}
    int getVie(){return vie;}

    //setter
    //void setHitbox(Hitbox hitbox);
    void setPosition(Point position){this->position = position;}
    void setVie(int vie){this->vie = vie;}   

};

#endif // PERSONNAGE_HH