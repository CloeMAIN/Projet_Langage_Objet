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
                // Si la touche Z est pressée et que le joueur1 est sur le sol
                joueur1.setVelocityY(VITESSE_JOUEUR1_SAUT); // Définir la vélocité sur la vitesse de saut
                
            }
            if (event.key.code == sf::Keyboard::Up && joueur2.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) { 
                // Si la touche haut est pressée et que le joueur2 est sur le sol
                joueur2.setVelocityY(VITESSE_JOUEUR1_SAUT); // Définir la vélocité sur la vitesse de saut
                    }

           
            if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J1)){
                joueur1.setVie(joueur1.getVie()-5);
            }
            if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J2)){
                joueur2.setVie(joueur2.getVie()-5);
            }
            
        }
    }

    // Appliquer la gravité pour les deux joueurs
        if (joueur1.getPosition().y + TAILLE_JOUEUR1_SPRITE.hauteur < POSITION_SOL.y) {
            joueur1.setVelocityY(joueur1.getVelocity().y + GRAVITE);
        }
        if (joueur2.getPosition().y + TAILLE_JOUEUR1_SPRITE.hauteur < POSITION_SOL.y) {
            joueur2.setVelocityY(joueur2.getVelocity().y + GRAVITE);
        }

        //Joueur 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            joueur1.setVelocityX(-5.0f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            joueur1.setVelocityX(5.0f);
        } else {
            joueur1.setVelocityX(0.0f);
        }

        // Joueur 2 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            joueur2.setVelocityX(-5.0f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            joueur2.setVelocityX(5.0f);
        } else {
            joueur2.setVelocityX(0.0f);  
            }

}