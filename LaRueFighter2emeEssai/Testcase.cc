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
    ProjectileLineaire pl(p, 2, 0, 0, "", Direction::DROITE);
    while(pl.getTempsDeVie() < 10){
        pl.deplacement(0.5);
        std::cout << pl.toString() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    ProjectileZigZag pz(p, 2, 0, 0, "", 3, 45, 10, Direction::GAUCHE);
    while(pz.getTempsDeVie() < 10){
        pz.deplacement(0.5);
        std::cout << pz.toString() << std::endl;
    }


    /*---------------------------------- TEST PERSONNAGE DEPLACEMENT--------------------------------------*/

    // Création des personnages
    Personnage joueur1({200.0, TAILLE_FENETRE.y - HAUTEUR_SOL - 128.0f * 5}, 100, CHEMIN_IMAGE_JOUEUR1_RIEN_DROITE, Direction::GAUCHE, {50.0,50.0});
    Personnage joueur2({600.0, TAILLE_FENETRE.y - HAUTEUR_SOL - 128.0f * 5}, 100, CHEMIN_IMAGE_JOUEUR1_RIEN_DROITE, Direction::DROITE, {50.0,50.0});

    // std::cout << "------------ TEST DISTANCE  -------------" << std::endl;
    // std::cout << "Distance joueur1 et joueur2 :" << "\n" << joueur1.distance(joueur2) << std::endl;

    //Déplacement des personnages
    std::cout << "------------ TEST DE DEPLACEMENT  -------------" << std::endl;
        
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

    std::cout << "------------ TEST DE CONTACT  -------------" << std::endl;
    joueur1.setPosition({200.0, 200.0});
    joueur2.setPosition({300.0, 200.0});
    joueur1.setTaille({50.0,50.0});
    joueur2.setTaille({50.0,50.0});
    std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    std::cout << "Contact J1 :" << joueur1.contact(joueur2) << std::endl;
    std::cout << "Contact J2:" << joueur2.contact(joueur1) << "\n" << std::endl;

    joueur1.setPosition({200.0, 200.0});
    joueur2.setPosition({250.0, 200.0});
    joueur1.setTaille({50.0,50.0});
    joueur2.setTaille({50.0,50.0});
    std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    std::cout << "Contact J1:" << joueur1.contact(joueur2) << std::endl;
    std::cout << "Contact J2:" << joueur2.contact(joueur1) << "\n"<< std::endl;

    joueur1.setPosition({200.0, 200.0});
    joueur2.setPosition({250.0, 100.0});
    joueur1.setTaille({50.0,50.0});
    joueur2.setTaille({50.0,50.0});
    std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    std::cout << "Contact J1 :" << joueur1.contact(joueur2) << std::endl;
    std::cout << "Contact J2 :" << joueur2.contact(joueur1) << "\n"<< std::endl;

    joueur1.setPosition({200.0, 200.0});
    joueur2.setPosition({250.0, 100.0});
    joueur1.setTaille({50.0,25.0});
    joueur2.setTaille({50.0,50.0});
    std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    std::cout << "Contact J1 :" << joueur1.contact(joueur2)  << std::endl;
    std::cout << "Contact J2 :" << joueur2.contact(joueur1) << "\n"<< std::endl;

    joueur1.setPosition({100.0, 100.0});
    joueur2.setPosition({150.0, 150.0});
    joueur1.setTaille({50.0,100.0});
    joueur2.setTaille({25.0,25.0});
    std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    std::cout << "Contact J1 :" << joueur1.contact(joueur2)  << std::endl;
    std::cout << "Contact J2 :" << joueur2.contact(joueur1) << "\n"<< std::endl;

    return 0;
}