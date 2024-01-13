#include <iostream>
#include "ProjectileLineaire.hh"
#include "ElementJeu.hh"
#include "Projectile.hh"
#include "ProjectileZigZag.hh"
#include "constant.hh"
#include "Afficheur.hh"
#include "Personnage.hh"

int main(){

    /*---------------------------------- TEST PROJECTILES --------------------------------------*/
    Point p;
    p.x = 0;
    p.y = 0;
    HitBox hb;
    hb.GaucheHaut = p;
    hb.DroiteBas = p;
    // ElementJeu e;
    // e.setPosition(p);
    // e.getCheminImage();
    std::cout << "------------ TEST PROJECTILE -------------" << std::endl;
    ProjectileLineaire pl(p, 2, 0, 0, "");
    while(pl.getTempsDeVie() < 10){
        pl.deplacement(0.5);
        std::cout << pl.toString() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    ProjectileZigZag pz(p, 2, 0, 0, "", 3, 45, 10);
    while(pz.getTempsDeVie() < 10){
        pz.deplacement(0.5);
        std::cout << pz.toString() << std::endl;
    }


    /*---------------------------------- TEST PERSONNAGE DEPLACEMENT--------------------------------------*/

    // Création des personnages
    Personnage joueur1({200.0, TAILLE_FENETRE.y - HAUTEUR_SOL - 128.0f * 5}, 100, CHEMIN_IMAGE_JOUEUR1_RIEN);
    Personnage joueur2({600.0, TAILLE_FENETRE.y - HAUTEUR_SOL - 128.0f * 5}, 100, CHEMIN_IMAGE_JOUEUR1_RIEN);

    //Déplacement des personnages
    std::cout << "------------ TEST E DEPLACEMENT  -------------" << std::endl;
        
    std::cout << "\n" << std::endl;
    std::cout << "Vitesse joueur2 :" << "\n" << VITESSE_JOUEUR1 << std::endl;
    std::cout << "Initial:" << "\n" << joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;
    joueur2.maj(Action::Droite); // test à droite
    std::cout << "Apres deplacement Droite:" << "\n" ;
    std::cout <<  joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;
    joueur2.maj(Action::Gauche); // test à gauche
    std::cout << "Apres deplacement Gauche:" << "\n";
    std::cout <<  joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;
    joueur2.maj(Action::Rien); // test rien
    std::cout << "Apres deplacement Rien:" << "\n";
    std::cout <<  joueur2.toString() << std::endl;

    std::cout << "\n" << std::endl;
    std::cout << "Vitesse joueur1 :" << "\n" << VITESSE_JOUEUR1 << std::endl;
    std::cout << "Initial:" << "\n" << joueur1.toString() << std::endl;
    std::cout << "\n" << std::endl;
    joueur1.maj(Action::Droite); // test à droite
    std::cout << "Apres deplacement Droite:" << "\n" ;
    std::cout <<  joueur1.toString() << std::endl;
    std::cout << "\n" << std::endl;
    joueur1.maj(Action::Gauche); // test à gauche
    std::cout << "Apres deplacement Gauche:" << "\n";
    std::cout <<  joueur1.toString() << std::endl;
    std::cout << "\n" << std::endl;
    joueur1.maj(Action::Rien); // test rien
    std::cout << "Apres deplacement Rien:" << "\n";
    std::cout <<  joueur1.toString() << std::endl;

    return 0;
}