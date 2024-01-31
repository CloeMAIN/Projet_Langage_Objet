#include "InputUser.hh"
#include <iostream>
#include <sstream>


InputUser::InputUser(){

}

InputUser::~InputUser() {
    // Aucune allocation dynamique, pas besoin de libérer la mémoire ici
}

// Dans la classe InputUser (implémentation dans le .cpp)
void InputUser::gererEvenements(sf::RenderWindow* window, Personnage& joueur1, Personnage& joueur2, std::vector<ElementJeu> Plateformes) {
    sf::Event event;
    while (window->pollEvent(event)) {
        /* Gestion des cliques */
        if (event.type == sf::Event::KeyPressed) {
            sf::Keyboard::Key key = event.key.code;
            // std::cout << "Touche enfoncée : " << key << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Stop d'urgence avec escape
                window->close();
        
            //Gestion des sauts pour les deux joueurs 
            
            if (event.key.code == sf::Keyboard::Z && (joueur1.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.hauteur || joueur1.getSurPlateforme())) { 
                checkSaut(joueur1);}
            if (event.key.code == sf::Keyboard::Up && (joueur2.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.hauteur || joueur2.getSurPlateforme())) { 
                checkSaut(joueur2);}
            if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J1)){
                checkDegat(joueur1);}
            if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J2)){
                checkDegat(joueur2);}
        }
    }
    DemandeAttaque(joueur1,joueur2);

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


void InputUser::DemandeAttaque( Personnage& joueur1, Personnage& joueur2){
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
}

void InputUser::checkSaut(Personnage& joueur){
        joueur.setVelocityY(VITESSE_JOUEUR_SAUT); // Définir la vélocité sur la vitesse de saut
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
    joueur.setEtat("Attaque1", false);
    joueur.setEtat("Attaque2", false);
}

void InputUser::checkDroite(Personnage& joueur){
    joueur.setVelocityX(5.0f);
    joueur.setEtat("Avancer", true);
    joueur.setEtat("Rien", false);
    joueur.setDirection(Direction::DROITE);
    joueur.setEtat("Attaque1", false);
    joueur.setEtat("Attaque2", false);
}

void InputUser::checkRien(Personnage& joueur){
    if(!joueur.getEtat().at("Saut").first && !joueur.getEtat().at("Attaque1").first && !joueur.getEtat().at("Attaque2").first){
        joueur.setVelocityX(0.0f);
        joueur.setEtat("Avancer", false);
        joueur.setEtat("Saut", false);
        joueur.setEtat("Rien", true);
    }
}

void InputUser::checkAttaque1(Personnage& joueur){
    if(not(joueur.getBlockAtt())){
        joueur.setVelocityX(0.0f);
        joueur.setEtat("Avancer", false);
        joueur.setEtat("Rien", false);
        joueur.setEtat("Attaque1", true);
    }
}

void InputUser::checkAttaque2(Personnage& joueur){
    if(not(joueur.getBlockAtt())){
        joueur.setVelocityX(0.0f);
        joueur.setEtat("Avancer", false);
        joueur.setEtat("Rien", false);
        joueur.setEtat("Attaque2", true);
    }
}

void InputUser::checkProjectile(Personnage& joueur){
    if(not(joueur.getBlock())){
        joueur.setVelocityX(0.0f);
        joueur.setEtat("Rien", false);
        joueur.setEtat("Projectile", true);
        joueur.setBlock(true);
    }
}


int InputUser::gererFormulaire(sf::RenderWindow* window, std::string* Reponse, std::string* Background, sf::Text* text1, int* questionCourante){
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128) // Assurez-vous que le caractère est ASCII
            {
                if (event.text.unicode == 8) // Vérifie si la touche Backspace est pressée
                {
                    if (!(*Reponse).empty())
                        (*Reponse).pop_back();
                }
                else
                {
                    *Reponse += static_cast<char>(event.text.unicode);
                }

                text1->setString(*Reponse);
            }
        }

        else if(event.type == sf::Event::MouseButtonPressed){
            //si je clique sur le bouton jouer
            if(event.mouseButton.button == sf::Mouse::Left){
                if (event.mouseButton.x >= TAILLE_NOTRE_DAME.GaucheHaut.x && event.mouseButton.x <= TAILLE_NOTRE_DAME.DroiteBas.x && event.mouseButton.y >= TAILLE_NOTRE_DAME.GaucheHaut.y && event.mouseButton.y <= TAILLE_NOTRE_DAME.DroiteBas.y){
                    *Background = "Notre Dame";
                    }
                else if (event.mouseButton.x >= TAILLE_LOUVRES.GaucheHaut.x && event.mouseButton.x <= TAILLE_LOUVRES.DroiteBas.x && event.mouseButton.y >= TAILLE_LOUVRES.GaucheHaut.y && event.mouseButton.y <= TAILLE_LOUVRES.DroiteBas.y){
                    *Background = "Louvres";
                }
                else if (event.mouseButton.x >= TAILLE_TOUR_EIFFEL.GaucheHaut.x && event.mouseButton.x <= TAILLE_TOUR_EIFFEL.DroiteBas.x && event.mouseButton.y >= TAILLE_TOUR_EIFFEL.GaucheHaut.y && event.mouseButton.y <= TAILLE_TOUR_EIFFEL.DroiteBas.y ){
                    *Background = "Tour Eiffel";
                }
                else if (event.mouseButton.x >= TAILLE_ARC_DE_TRIOMPHE.GaucheHaut.x && event.mouseButton.x <= TAILLE_ARC_DE_TRIOMPHE.DroiteBas.x && event.mouseButton.y >= TAILLE_ARC_DE_TRIOMPHE.GaucheHaut.y && event.mouseButton.y <= TAILLE_ARC_DE_TRIOMPHE.DroiteBas.y){
                    *Background = "Arc de Triomphe";
                }
                else if (event.mouseButton.x >= TAILLE_VALIDE.GaucheHaut.x && event.mouseButton.x <= TAILLE_VALIDE.DroiteBas.x && event.mouseButton.y >= TAILLE_VALIDE.GaucheHaut.y && event.mouseButton.y <= TAILLE_VALIDE.DroiteBas.y){
                    *questionCourante +=1;
                    return 1; 
                }
            }
        }

    }
    return 0; 
}

void InputUser::gererPremiereEtape(sf::RenderWindow* window, std::string* pseudo, sf::Text* text, int* etape){
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128) // Assurez-vous que le caractère est ASCII
            {
                if (event.text.unicode == 8) // Vérifie si la touche Backspace est pressée
                {
                    if (!(*pseudo).empty())
                        (*pseudo).pop_back();
                }
                else
                {
                    *pseudo += static_cast<char>(event.text.unicode);
                }

                text->setString(*pseudo);
            }
        }
        else if(event.type == sf::Event::MouseButtonPressed){
            //si je clique sur le bouton jouer
            if(event.mouseButton.button == sf::Mouse::Left){
                if (event.mouseButton.x >= TAILLE_VALIDE.GaucheHaut.x && event.mouseButton.x <= TAILLE_VALIDE.DroiteBas.x && event.mouseButton.y >= TAILLE_VALIDE.GaucheHaut.y && event.mouseButton.y <= TAILLE_VALIDE.DroiteBas.y){
                    *etape = 2;
                    return;
                }
            }
        }

    }
}