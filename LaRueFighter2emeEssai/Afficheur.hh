#ifndef AFFICHEUR_HH
#define AFFICHEUR_HH

#include <SFML/Graphics.hpp>
#include "Personnage.hh"

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

        /* Méthodes */
        void afficher(const Personnage& joueur);
        void afficher(Jeu& jeu);

};

#endif // AFFICHEUR_HH

