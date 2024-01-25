#include "InputUser.hh"
#include <iostream>
#include <sstream>


InputUser::InputUser(){

}

InputUser::~InputUser() {
    // Aucune allocation dynamique, pas besoin de libérer la mémoire ici
}

// Dans la classe InputUser (implémentation dans le .cpp)
void InputUser::gererEvenements(sf::RenderWindow* window, Personnage& joueur1, Personnage& joueur2) {
    sf::Event event;
    while (window->pollEvent(event)) {
        /* Gestion des cliques */
        if (event.type == sf::Event::KeyPressed) {
            sf::Keyboard::Key key = event.key.code;
            std::cout << "Touche enfoncée : " << key << std::endl;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Stop d'urgence avec escape
            {
                window->close();
            }
        
            //Gestion des sauts pour les deux joueurs
            
            if (event.key.code == sf::Keyboard::Z && joueur1.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) { 
                checkSaut(joueur1);

                
            }
            if (event.key.code == sf::Keyboard::Up && joueur2.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) { 
                checkSaut(joueur2);
            }

            if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J1)){
                checkDegat(joueur1);
            }
            if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J2)){
                checkDegat(joueur2);

            }
            
        }
    }

     //Gestion des projectiles pour les deux joueurs

            if (sf::Keyboard::isKeyPressed(TOUCHE_PROJECTILE_JOUEUR1) && !joueur1.getBlock()){
                checkProjectile(joueur1);
                joueur2.setBlock(true);
                joueur1.setClockProj(joueur1.getClockProj().restart());
            }

            if (sf::Keyboard::isKeyPressed(TOUCHE_PROJECTILE_JOUEUR2) && !joueur2.getBlock()){
                checkProjectile(joueur2);
                joueur2.setBlock(true);
                joueur2.setClockProj(joueur2.getClockProj().restart());
            }

            //Gestion des attaques pour les deux joueurs
            if (sf::Keyboard::isKeyPressed(TOUCHE_ATTAQUE1_JOUEUR1)){
                checkAttaque1(joueur1);
                joueur1.setClockAtt(joueur1.getClockAtt().restart());
            }
            if (sf::Keyboard::isKeyPressed(TOUCHE_ATTAQUE2_JOUEUR1)){
                checkAttaque2(joueur1);
                joueur1.setClockAtt(joueur1.getClockAtt().restart());

            }
            if (sf::Keyboard::isKeyPressed(TOUCHE_ATTAQUE1_JOUEUR2)){
                checkAttaque1(joueur2);
                joueur2.setClockAtt(joueur2.getClockAtt().restart());
            }
            if (sf::Keyboard::isKeyPressed(TOUCHE_ATTAQUE2_JOUEUR2)){
                checkAttaque2(joueur2);
                joueur2.setClockAtt(joueur2.getClockAtt().restart());
            }
        //Joueur 1 Avancer
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {//Gauche
            checkGauche(joueur1);
            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//Droite
            checkDroite(joueur1);
        } else {
            checkRien(joueur1);
        }

        // Joueur 2 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {//Gauche
            checkGauche(joueur2);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { //Droite
            checkDroite(joueur2);
        } else {
            checkRien(joueur2);
            }

}

void InputUser::checkSaut(Personnage& joueur){
        joueur.setVelocityY(VITESSE_JOUEUR1_SAUT); // Définir la vélocité sur la vitesse de saut
        std::cout << "Check Saut" << std::endl;
        joueur.setEtat("Saut", true);
        joueur.setEtat("Rien", false);
}

void InputUser::checkDegat(Personnage& joueur){
    joueur.setVie(joueur.getVie()-5);
}

void InputUser::checkGauche(Personnage& joueur){
    joueur.setVelocityX(-5.0f);
    joueur.setEtat("Avancer", true);
    joueur.setEtat("Rien", false);
    joueur.setDirection(Direction::GAUCHE);
}

void InputUser::checkDroite(Personnage& joueur){
    joueur.setVelocityX(5.0f);
    joueur.setEtat("Avancer", true);
    joueur.setEtat("Rien", false);
    joueur.setDirection(Direction::DROITE);
}

void InputUser::checkRien(Personnage& joueur){
    if(!joueur.getEtat().at("Saut").first){
        joueur.setVelocityX(0.0f);
        joueur.setEtat("Avancer", false);
        joueur.setEtat("Saut", false);
        joueur.setEtat("Rien", true);
    }
}

void InputUser::checkAttaque1(Personnage& joueur){
    joueur.setVelocityX(0.0f);
    joueur.setEtat("Avancer", false);
    joueur.setEtat("Rien", false);
    joueur.setEtat("Attaque1", true);
}

void InputUser::checkAttaque2(Personnage& joueur){
    joueur.setVelocityX(0.0f);
    joueur.setEtat("Avancer", false);
    joueur.setEtat("Rien", false);
    joueur.setEtat("Attaque2", true);
}

void InputUser::checkProjectile(Personnage& joueur){
    if(not(joueur.getBlock())){
        joueur.setVelocityX(0.0f);
        joueur.setEtat("Rien", false);
        joueur.setEtat("Projectile", true);
        joueur.setBlock(true);
    }
}