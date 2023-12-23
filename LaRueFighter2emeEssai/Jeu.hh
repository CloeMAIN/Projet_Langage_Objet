#ifndef JEU_HH
#define JEU_HH

#include "Afficheur.hh"
#include "Personnage.hh"

class Jeu
{
private:
    Personnage joueur1{sf::Vector2f(200, 100), 100, "luffy.png"};
    Personnage joueur2{sf::Vector2f(600, 100), 100, "luffy.png"};
    Afficheur afficheur;
public:
    Jeu(/* args */);
    ~Jeu();
    int lancer(Afficheur* afficheur);

    /* Getter */
    Personnage getJoueur1(){return joueur1;}
    Personnage getJoueur2(){return joueur2;}
    
};

#endif // JEU_HH

