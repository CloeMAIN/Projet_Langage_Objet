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
    Personnage joueur1{POSITION_DEPART_JOUEUR1, 100, {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_SAUT, CHEMIN_IMAGE_JOUEUR1_DROITE, CHEMIN_IMAGE_JOUEUR1_PIED_DROITE, CHEMIN_IMAGE_JOUEUR1_POING_DROITE, CHEMIN_IMAGE_ZIGZAG},  Direction::DROITE, {35,82}};
    std::cout << "------------ TEST DEPLACEMENT PERSONNAGE -------------" << std::endl;
    Personnage joueur2{POSITION_DEPART_JOUEUR2, 100, {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_SAUT, CHEMIN_IMAGE_JOUEUR1_DROITE, CHEMIN_IMAGE_JOUEUR1_PIED_DROITE, CHEMIN_IMAGE_JOUEUR1_POING_DROITE, CHEMIN_IMAGE_ZIGZAG}, Direction::GAUCHE,{35,82}};
    
    // std::cout << "------------ TEST DISTANCE  -------------" << std::endl;
    // std::cout << "Distance joueur1 et joueur2 :" << "\n" << joueur1.distance(joueur2) << std::endl;

    // Déplacement des personnages
    std::cout << "------------ TEST DE DEPLACEMENT  -------------" << std::endl;
        
    std::cout << "\n" << std::endl;
    std::cout << "Vitesse joueur2 :" << "\n" << VITESSE_JOUEUR1 << std::endl;
    std::cout << "Initial:" << "\n" << joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;

    joueur2.setEtat("Avancer", true);
    joueur2.mouvement({0,0}); // test à droite
    std::cout << "Apres deplacement Droite:" << "\n" ;
    std::cout <<  joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;

    joueur2.setDirection(Direction::GAUCHE);
    joueur2.mouvement({0,0}); // test à gauche
    std::cout << "Apres deplacement Gauche:" << "\n";
    std::cout <<  joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;

    joueur2.setEtat("Rien", true);
    joueur2.setEtat("Avancer", false);
    joueur2.mouvement({0,0}); // test rien
    std::cout << "Apres deplacement Rien:" << "\n";
    std::cout <<  joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;

    joueur2.setEtat("Saut", true);
    joueur2.setEtat("Rien", false);
    joueur2.mouvement({2,2}); // test saut
    std::cout << "Apres deplacement Gauche:" << "\n";
    std::cout <<  joueur2.toString() << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "------------ TEST ATTAQUE  -------------" << std::endl;


    // std::cout << "------------ TEST DE CONTACT  -------------" << std::endl;
    // joueur1.setPosition({200.0, 200.0});
    // joueur2.setPosition({300.0, 200.0});
    // joueur1.setTaille({50.0,50.0});
    // joueur2.setTaille({50.0,50.0});
    // std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    // std::cout << "Contact J1 :" << joueur1.contact(joueur2) << std::endl;
    // std::cout << "Contact J2:" << joueur2.contact(joueur1) << "\n" << std::endl;

    // joueur1.setPosition({200.0, 200.0});
    // joueur2.setPosition({250.0, 200.0});
    // joueur1.setTaille({50.0,50.0});
    // joueur2.setTaille({50.0,50.0});
    // std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    // std::cout << "Contact J1:" << joueur1.contact(joueur2) << std::endl;
    // std::cout << "Contact J2:" << joueur2.contact(joueur1) << "\n"<< std::endl;

    // joueur1.setPosition({200.0, 200.0});
    // joueur2.setPosition({250.0, 100.0});
    // joueur1.setTaille({50.0,50.0});
    // joueur2.setTaille({50.0,50.0});
    // std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    // std::cout << "Contact J1 :" << joueur1.contact(joueur2) << std::endl;
    // std::cout << "Contact J2 :" << joueur2.contact(joueur1) << "\n"<< std::endl;

    // joueur1.setPosition({200.0, 200.0});
    // joueur2.setPosition({250.0, 100.0});
    // joueur1.setTaille({50.0,25.0});
    // joueur2.setTaille({50.0,50.0});
    // std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    // std::cout << "Contact J1 :" << joueur1.contact(joueur2)  << std::endl;
    // std::cout << "Contact J2 :" << joueur2.contact(joueur1) << "\n"<< std::endl;

    // joueur1.setPosition({100.0, 100.0});
    // joueur2.setPosition({150.0, 150.0});
    // joueur1.setTaille({50.0,100.0});
    // joueur2.setTaille({25.0,25.0});
    // std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Joueur2 :" << "\n" << joueur2.toString() << std::endl;
    // std::cout << "Contact J1 :" << joueur1.contact(joueur2)  << std::endl;
    // std::cout << "Contact J2 :" << joueur2.contact(joueur1) << "\n"<< std::endl;


    // std::cout << "------------ TEST D'ATTAQUE -------------" << std::endl;
    // joueur1.setPosition({200.0, 200.0});
    // joueur1.setEtat("Attaque1", true);
    // std::cout << "Joueur1 :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Element :" << "\nTaille :" << joueur1.getAttaque().getTaille().hauteur << " " << joueur1.getAttaque().getTaille().largeur << "\nPosition :" << joueur1.getAttaque().getPosition().x << " " << joueur1.getAttaque().getPosition().y << "\nCheminImage :" << joueur1.getAttaque().getCheminImage() << "\nDirection :" << joueur1.getAttaque().getDirection() << "\n" << std::endl;

    // joueur1.update_attaque();
    // std::cout << "Joueur1 Après :" << "\n" << joueur1.toString() << std::endl;
    // std::cout << "Element Après  :" << "\nTaille :" << joueur1.getAttaque().getTaille().hauteur << " " << joueur1.getAttaque().getTaille().largeur << "\nPosition :" << joueur1.getAttaque().getPosition().x << " " << joueur1.getAttaque().getPosition().y << "\nCheminImage :" << joueur1.getAttaque().getCheminImage() << "\nDirection :" << joueur1.getAttaque().getDirection() << "\n" << std::endl;

}