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
        Personnage joueur1{{0,0}, 100, {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_AVANCER, CHEMIN_IMAGE_JOUEUR1_SAUT,CHEMIN_IMAGE_JOUEUR1_ATTAQUE1, CHEMIN_IMAGE_JOUEUR1_ATTAQUE2, CHEMIN_IMAGE_JOUEUR1_ATTAQUE1},  Direction::DROITE, TAILLE_JOUEUR1_SPRITE, CHEMIN_IMAGE_JOUEUR1_RIEN.first};
        Personnage joueur2{{0,0}, 100, {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_AVANCER, CHEMIN_IMAGE_JOUEUR1_SAUT,CHEMIN_IMAGE_JOUEUR1_ATTAQUE1, CHEMIN_IMAGE_JOUEUR1_ATTAQUE2, CHEMIN_IMAGE_JOUEUR1_ATTAQUE1}, Direction::GAUCHE,TAILLE_JOUEUR1_SPRITE, CHEMIN_IMAGE_JOUEUR1_RIEN.first};
        // Afficheur* afficheur;
    public:
        Jeu(/* args */);
        ~Jeu();
        int lancer(Afficheur* afficheur);

        /* Getter */
        Personnage getJoueur1(){return joueur1;}
        Personnage getJoueur2(){return joueur2;}
        // std::list<Projectile*> getListesProjectiles(){return listes_projectiles;}
        
        /* Méthode */
        void majJoueurs(InputUser inputUser)
        {
            // Implementation of the majJoueurs function
        }
    // void majProjectiles(double deltaTime);
    void empecherSortie();
};


#endif // JEU_HH

