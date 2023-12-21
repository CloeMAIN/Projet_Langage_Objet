#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH

#include <string>
#include "ElementJeu.hh"

class Personnage : public ElementJeu{
private:
    //Hitbox hitbox;
    Point position;
    int vie;
    std::string cheminImage;
public:
    //constructeur
    Personnage();
    ~Personnage();

    //getter
    //Hitbox getHitbox();
    Point getPosition(){return position;};
        int getVie();

        //setter
        //void setHitbox(Hitbox hitbox);
        void setPosition(Point position);
        void setVie(int vie);   

};

#endif // PERSONNAGE_HH