#ifndef JEU_HH
#define JEU_HH

#pragma once
#include "Afficheur.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include "../constant.hh"
#include "Projectile.hh"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>

class Afficheur;

class Jeu
{
    private:
        Personnage joueur1; // Personnage joueur1
        Personnage joueur2; // Personnage joueur2

        std::vector<ElementJeu> plateformes; // Plateformes du jeu

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
        void majJoueurs(sf::Clock & clock);
        void empecherSortie();
        
};


#endif // JEU_HH

