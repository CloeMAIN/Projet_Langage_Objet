#ifndef JEU_HH
#define JEU_HH

#include "Afficheur.hh"
#include "Personnage.hh"

class Jeu
{
private:
    Personnage joueur1;
    Personnage joueur2;
    Afficheur afficheur;
public:
    Jeu(/* args */);
    ~Jeu();
    int lancer(Afficheur* afficheur);
    
    
};

#endif // JEU_HH

