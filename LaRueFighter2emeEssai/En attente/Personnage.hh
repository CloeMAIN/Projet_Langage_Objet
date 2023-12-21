#ifndef PERSONNAGE_HH
#define PERSONNAGE_HH

#include <string>

class Personnage : public ElementJeu
{
private:
    Hitbox hitbox;
    //Point position;
    int vie;
    std::string cheminImage;
public:
    //constructeur
    Personnage();
    ~Personnage();

    //getter
    Hitbox getHitbox();
    //Position getPosition();
    int getVie();

    //setter
    void setHitbox(Hitbox hitbox);
    void setPosition(Position position);
    void setVie(int vie);
    
};



#endif // PERSONNAGE_HH