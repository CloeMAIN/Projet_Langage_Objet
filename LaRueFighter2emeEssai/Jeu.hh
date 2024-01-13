#ifndef JEU_HH
#define JEU_HH

#include "Afficheur.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include "constant.hh"
#include "Projectile.hh"
#include <list>

class Jeu
{
private:
    Personnage joueur1{{200, TAILLE_FENETRE.y-HAUTEUR_SOL-TAILLE_JOUEUR1_SPRITE}, 100, CHEMIN_IMAGE_JOUEUR1_RIEN,{35,82},  Direction::DROITE};
    Personnage joueur2{{600, TAILLE_FENETRE.y-HAUTEUR_SOL-TAILLE_JOUEUR1_SPRITE}, 100, CHEMIN_IMAGE_JOUEUR1_RIEN,{35,82}, Direction::GAUCHE};
    std::list<Projectile*> listes_projectiles;
    // Afficheur* afficheur;
public:
    Jeu(/* args */);
    ~Jeu();
    int lancer(Afficheur* afficheur);

    /* Getter */
    Personnage getJoueur1(){return joueur1;}
    Personnage getJoueur2(){return joueur2;}
    std::list<Projectile*> getListesProjectiles(){return listes_projectiles;}
    
    /* Méthode */
    void majJoueurs(InputUser inputUser);
    void majProjectiles(double deltaTime);
};


#endif // JEU_HH

