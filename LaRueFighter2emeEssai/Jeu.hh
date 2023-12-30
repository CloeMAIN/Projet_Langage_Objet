#ifndef JEU_HH
#define JEU_HH

#include "Afficheur.hh"
#include "Personnage.hh"
#include "InputUser.hh"

class Jeu
{
private:
    Personnage joueur1{sf::Vector2f(200, TAILLE_FENETRE.y-HAUTEUR_SOL-128*5), 100, CHEMIN_IMAGE_JOUEUR1_RIEN};
    Personnage joueur2{sf::Vector2f(600, TAILLE_FENETRE.y-HAUTEUR_SOL-128*5), 100, CHEMIN_IMAGE_JOUEUR1_RIEN};
    // Afficheur* afficheur;
public:
    Jeu(/* args */);
    ~Jeu();
    int lancer(Afficheur* afficheur);

    /* Getter */
    Personnage getJoueur1(){return joueur1;}
    Personnage getJoueur2(){return joueur2;}
    
    /* Méthode */
    void majJoueurs(InputUser inputUser);
};

#endif // JEU_HH

