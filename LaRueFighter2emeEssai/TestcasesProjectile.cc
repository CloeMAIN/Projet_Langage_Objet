#include <iostream>
#include "ProjectileLineaire.hh"
#include "ElementJeu.hh"
#include "Projectile.hh"

int main(){
    Point p;
    p.x = 0;
    p.y = 0;
    HitBox hb;
    hb.GaucheHaut = p;
    hb.DroiteBas = p;
    // ElementJeu e;
    // e.setPosition(p);
    // e.getCheminImage();
    ProjectileLineaire pl(p, 0, 0, 0, "");
    // pl.deplacement();
    std::cout << pl.toString() << std::endl;


    return 0;
}