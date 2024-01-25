#ifndef AFFICHEUR_HH
#define AFFICHEUR_HH
#pragma once
#include <SFML/Graphics.hpp>
#include "Personnage.hh"
#include "constant.hh"
#include "Projectile.hh"

// Déclaration anticipée de la classe Jeu pour éviter la dépendance cyclique
class Jeu;

class Afficheur
{
    private:
        sf::RenderWindow window;
    public:
        Afficheur(/* args */);
        ~Afficheur();

        /* Getter */
        sf::RenderWindow* getWindow(){return &window;}


        /* Méthode */
        void afficher(const Personnage &joueur);
        void afficher(Jeu &jeu);
        void afficherMenu();
        void afficher(std::string cheminbouton, Point position, HitBox taille);
        void afficher(std::string cheminBackground);
        void afficherSol();
        void afficher(const Projectile &projectile);
        void afficherBarreVieJ1(int vie);
        void afficherBarreVieJ2(int vie);
        void afficher(const ElementJeu& element);

};

#endif // AFFICHEUR_HH

