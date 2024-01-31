#ifndef AFFICHEUR_HH
#define AFFICHEUR_HH
#pragma once
#include <SFML/Graphics.hpp>
#include "Personnage.hh"
#include "../constant.hh"
#include "ElementJeu.hh"
#include "Formulaire.hh"
#include "Menu.hh"
#include "Jeu.hh"
#include <iostream>
#include "Projectile.hh"
#include <string>

class Formulaire; 

class Menu;
// Déclaration anticipée de la classe Jeu pour éviter la dépendance cyclique
class Jeu;

class Afficheur
{
    private:
        sf::RenderWindow window;
        sf::Texture fondTexture;
    public:
        Afficheur();
        ~Afficheur();

        /* Getter */
        sf::RenderWindow* getWindow(){return &window;}


        /* Méthode */
        void afficher(const Personnage &joueur);
        void afficher(Jeu &jeu);
        void afficher(Menu menu);
        void afficher(std::string cheminbouton,HitBox taille, Point position);
        void afficher(std::string cheminBackground);
        void afficherSol();
        void afficher(const Projectile &projectile);
        void afficherBarreVieJ1(float vie);
        void afficherBarreVieJ2(float vie);
        void afficher(const ElementJeu& element);
        void afficher(std::vector<std::string> cheminBackground);
        // Initialise dès le départ un fond pour la partie
        void loadFondJeu();
        // Fonction pour afficher le fond lors des parties qui load pas
        void afficherFondJeu();
        void afficher(std::string cheminImageQuestion, sf::Text ReponseUtilisateur);
        void afficher(Formulaire form, sf::Text text1);
        void afficherquizz(std::string cheminImageQuestion, sf::Text text);


};

#endif // AFFICHEUR_HH

