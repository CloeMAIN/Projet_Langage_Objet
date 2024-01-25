#ifndef JEU_HH
#define JEU_HH

#pragma once
#include "Afficheur.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include "constant.hh"
#include "Projectile.hh"
#include <list>

class Afficheur;

class Jeu
{
    private:
        Personnage joueur1{POSITION_DEPART_JOUEUR1,
                            POINTS_DE_VIE_JOUEUR, 
                            {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_AVANCER, CHEMIN_IMAGE_JOUEUR1_SAUT,CHEMIN_IMAGE_JOUEUR1_ATTAQUE1, CHEMIN_IMAGE_JOUEUR1_ATTAQUE2, CHEMIN_IMAGE_JOUEUR1_ATTAQUE1}, 
                            Direction::DROITE, 
                            TAILLE_JOUEUR_SPRITE,
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first};

        Personnage joueur2{POSITION_DEPART_JOUEUR2,
                            POINTS_DE_VIE_JOUEUR,
                            {CHEMIN_IMAGE_JOUEUR2_RIEN, CHEMIN_IMAGE_JOUEUR2_AVANCER,
                             CHEMIN_IMAGE_JOUEUR2_SAUT,CHEMIN_IMAGE_JOUEUR2_ATTAQUE1,
                             CHEMIN_IMAGE_JOUEUR2_ATTAQUE2, CHEMIN_IMAGE_JOUEUR2_ATTAQUE1}, 
                            Direction::GAUCHE,
                            TAILLE_JOUEUR_SPRITE, 
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first};

    public:
        Jeu(){};
        ~Jeu(){};
        int lancer(Afficheur* afficheur);

        /* Getter */
        Personnage getJoueur1(){return joueur1;}
        Personnage getJoueur2(){return joueur2;}
        // std::list<Projectile*> getListesProjectiles(){return listes_projectiles;}
        
        /* Méthode */
        void majJoueurs();
        void empecherSortie();
};


#endif // JEU_HH

