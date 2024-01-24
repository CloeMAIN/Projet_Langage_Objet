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
        joueur.setEtat("Sauter", true);
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
    joueur.setVelocityX(0.0f);
    joueur.setEtat("Avancer", false);
    joueur.setEtat("Rien", true);
}