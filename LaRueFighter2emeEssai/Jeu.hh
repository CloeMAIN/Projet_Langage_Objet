#ifndef JEU_HH
#define JEU_HH

#pragma once
#include "Afficheur.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include "constant.hh"
#include "Projectile.hh"
#include <list>
#include <cstdlib>
#include <ctime>

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

        std::vector<ElementJeu> plateformes = {ElementJeu(POSITION_PLATEFORME1, Direction::GAUCHE, TAILLE_PLATEFORME),
                                                ElementJeu(POSITION_PLATEFORME2, Direction::GAUCHE, TAILLE_PLATEFORME), 
                                                ElementJeu(POSITION_PLATEFORME3, Direction::GAUCHE, TAILLE_PLATEFORME),
                                                ElementJeu(POSITION_PLATEFORME4, Direction::GAUCHE, TAILLE_PLATEFORME),};

        std::string chemin_image_fond; 
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        Jeu();
        ~Jeu(){};
        int lancer(Afficheur* afficheur);

        /* Getter */
        Personnage getJoueur1(){return joueur1;}
        Personnage getJoueur2(){return joueur2;}
        ElementJeu getPlateforme(int i){return plateformes[i];}
        std::string getCheminImageFond(){return chemin_image_fond;}
        sf::Sprite getSprite(){return sprite;}
        sf::Texture getTexture(){return texture;}
        
        /* Méthode */
        void majJoueurs();
        void empecherSortie();
        void reinitialiser();
        
};


#endif // JEU_HH

