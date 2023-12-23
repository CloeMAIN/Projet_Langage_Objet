#ifndef AFFICHEUR_HH
#define AFFICHEUR_HH

#include <SFML/Graphics.hpp>
#include "Personnage.hh"
#include "constant.hh"

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

};

#endif // AFFICHEUR_HH

