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
    Personnage joueur1{POSITION_DEPART_JOUEUR1, 100, {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_SAUT, CHEMIN_IMAGE_JOUEUR1_DROITE, CHEMIN_IMAGE_JOUEUR1_PIED_DROITE, CHEMIN_IMAGE_JOUEUR1_POING_DROITE, CHEMIN_IMAGE_ZIGZAG},  Direction::DROITE, {35,82}};
    Personnage joueur2{POSITION_DEPART_JOUEUR2, 100, {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_SAUT, CHEMIN_IMAGE_JOUEUR1_DROITE, CHEMIN_IMAGE_JOUEUR1_PIED_DROITE, CHEMIN_IMAGE_JOUEUR1_POING_DROITE, CHEMIN_IMAGE_ZIGZAG}, Direction::GAUCHE,{35,82}};
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
};


#endif // JEU_HH

