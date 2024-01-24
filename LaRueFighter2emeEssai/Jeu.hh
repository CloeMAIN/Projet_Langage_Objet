#ifndef JEU_HH
#define JEU_HH

#pragma once
#include "Afficheur.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include "constant.hh"
#include "Projectile.hh"
#include <list>

class Jeu
{
private:
    Personnage joueur1{POSITION_DEPART_JOUEUR1, 100, CHEMIN_IMAGE_JOUEUR1_RIEN_DROITE,  Direction::DROITE, {35,82}};
    Personnage joueur2{POSITION_DEPART_JOUEUR2, 100, CHEMIN_IMAGE_JOUEUR1_RIEN_GAUCHE, Direction::GAUCHE,{35,82}};
    std::list<Projectile*> listes_projectiles;
    // Afficheur* afficheur;
public:
    Jeu(/* args */);
    ~Jeu();
    int lancer(Afficheur* afficheur);

    /* Getter */
    Personnage getJoueur1(){return joueur1;}
    Personnage getJoueur2(){return joueur2;}
    std::list<Projectile*> getListesProjectiles(){return listes_projectiles;}
    
    /* Méthode */
    void majJoueurs(InputUser inputUser);
    void majProjectiles(double deltaTime);
    void empecherSortie();
};


#endif // JEU_HH

