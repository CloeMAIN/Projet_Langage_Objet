#include <iostream>
#include "ProjectileLineaire.hh"
#include "ElementJeu.hh"
#include "Projectile.hh"
#include "ProjectileZigZag.hh"

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
    std::cout << "-------------------------" << std::endl;
    ProjectileLineaire pl(p, 2, 0, 0, "");
    while(pl.getTempsDeVie() < 10){
        pl.deplacement(0.5);
        std::cout << pl.toString() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    ProjectileZigZag pz(p, 2, 0, 0, "", 3, 45, 10);
    while(pz.getTempsDeVie() < 10){
        pz.deplacement(0.5);
        std::cout << pz.toString() << std::endl;
    }


    return 0;
}