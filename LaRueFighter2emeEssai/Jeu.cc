#include "Jeu.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include "ProjectileZigZag.hh"
#include "ProjectileLineaire.hh"

Jeu::Jeu(/* args */)
{
    // Créer les joueurs (1 et 2 pour l'instant)
    // si ca foire on met userinput en plus ici
   // int round = 1;

}

Jeu::~Jeu()
{
}

int Jeu::lancer(Afficheur* afficheur)
{
    bool lancerJeu = true;
    /* Initialisation des commandes avec le constructeur par défaut */
    InputUser inputUser;
    // sf::RenderWindow* window = afficheur->getWindow();
    // Affichage de texte
    std::cout << "Lancement de la partie jeu.lancer()" << std::endl;

    sf::Vector2f velocityJoueur1(0, 0);
    sf::Vector2f velocityJoueur2(0, 0);
    sf::RenderWindow* window = afficheur->getWindow();
    sf::Clock clock1; // Utilisé pour mesurer le temps écoulé
    sf::Time blockDuration1 = sf::seconds(TEMPS_BLOCAGE_PROJECTILE);
    bool blockjoueur1 = false;
    sf::Clock clock2; // Utilisé pour mesurer le temps écoulé
    sf::Time blockDuration2 = sf::seconds(TEMPS_BLOCAGE_PROJECTILE);
    bool blockjoueur2 = false;

    std::cout << joueur1.toString() << std::endl;
    std::cout << joueur2.toString() << std::endl;

    while (afficheur->getWindow()->isOpen() && lancerJeu)
    {
        inputUser.gererEvenements(afficheur->getWindow(), joueur1, joueur2);
        // sf::Event event;
        // while (afficheur->getWindow()->pollEvent(event)){
        //     /* Gestion des cliques */
        //     if (event.type == sf::Event::KeyPressed){
        //         sf::Keyboard::Key key = event.key.code;
        //         std::cout << "Touche enfoncée : " << key << std::endl;

        //         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Stop d'urgence avec escape
        //         {
        //             afficheur->getWindow()->close();
        //         }

        //         // Touches actions de joueurs
        //         if (sf::Keyboard::isKeyPressed(TOUCHE_PROJECTILE_JOUEUR1) && !blockjoueur1){
        //             // Création d'un projectile
        //             Projectile* projectile = new ProjectileZigZag({joueur1.getPosition().x+35, joueur1.getPosition().y + 41}, VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG, joueur2.getDirection());
        //             listes_projectiles.push_back(projectile);
        //             blockjoueur1 = true;
        //             clock1.restart();
        //         }
        //         if (sf::Keyboard::isKeyPressed(TOUCHE_PROJECTILE_JOUEUR2) && !blockjoueur2){
        //             Projectile* projectile = new ProjectileLineaire({joueur2.getPosition().x+35,joueur2.getPosition().y + 41 }, VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_ZIGZAG, joueur2.getDirection());
        //             listes_projectiles.push_back(projectile);
        //             blockjoueur2 = true;
        //             clock2.restart();
        //                 } 

        //         //Gestion des sauts pour les deux joueurs
                
        //         if (event.key.code == sf::Keyboard::Z && joueur1.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) { 
        //             // Si la touche Z est pressée et que le joueur1 est sur le sol
        //             velocityJoueur1.y = VITESSE_JOUEUR1_SAUT; // Définir la vélocité sur la vitesse de saut 
        //         }
        //         if (event.key.code == sf::Keyboard::Up && joueur2.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) { 
        //             // Si la touche haut est pressée et que le joueur2 est sur le sol
        //             velocityJoueur2.y = VITESSE_JOUEUR1_SAUT; // Définir la vélocité sur la vitesse de saut 
        //                 }

        //         if(DEBUGGING_MODE){
        //             if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J1)){
        //                 joueur1.setVie(joueur1.getVie()-5);
        //             }
        //             if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J2)){
        //                 joueur2.setVie(joueur2.getVie()-5);
        //             }
        //         }
        //     }
        // }

        // // Gestion des blocages de tirs
        // if (blockjoueur1 && clock1.getElapsedTime() > blockDuration1){
        //     blockjoueur1 = false;
        // }
        // if (blockjoueur2 && clock2.getElapsedTime() > blockDuration2){
        //     blockjoueur2 = false;
        // }

        // Appliquer la gravité pour les deux joueurs
        if (joueur1.getPosition().y + TAILLE_JOUEUR1_SPRITE.hauteur < POSITION_SOL.y) {
            // std::cout <<" GRAVITE APPLIED" << std::endl;
            joueur1.setVelocityY(joueur1.getVelocity().y + GRAVITE);
        }
        if (joueur2.getPosition().y + TAILLE_JOUEUR1_SPRITE.hauteur < POSITION_SOL.y) {
            joueur2.setVelocityY(joueur2.getVelocity().y + GRAVITE);
        }

        // Mettre à jour la position des joueurs
        empecherSortie();
        joueur1.mouvement();
        joueur2.mouvement();
        joueur1.GestionProjectileLineaire();
        joueur2.GestionProjectileZigZag();
        joueur1.majProjectiles(DELTA_TIME);
        joueur2.majProjectiles(DELTA_TIME);
        joueur1.update_attaque();
        joueur2.update_attaque();
        std::cout << "Vie joueur 1 : " << joueur1.getVie() << std::endl;
        joueur1.update_contact(joueur2);
        std::cout << "Vie joueur 2 : " << joueur2.getVie() << std::endl;
        joueur2.update_contact(joueur1);

        // Afficher les positions en console
        // std::cout << "Position Joueur1 - X: " << joueur1.getPosition().x << ", Y: " << joueur1.getPosition().y << std::endl;
        // std::cout << "Position Joueur2 - X: " << joueur2.getPosition().x << ", Y: " << joueur2.getPosition().y << std::endl;

        
        afficheur->afficher(*this); // Affiche le jeu
    }

    return 0;
}


void Jeu::empecherSortie(){

        // Empêcher les joueurs de sortir de l'écran
        if (joueur1.getPosition().x < 0) {
            joueur1.setPosition({0, joueur1.getPosition().y}); // Empêcher le joueur1 de sortir par la gauche
        } else if (joueur1.getPosition().x > TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE.hauteur) {
            joueur1.setPosition({TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE.hauteur, joueur1.getPosition().y}); // Empêcher le joueur1 de sortir par la droite
            joueur1.getSprite().setPosition({joueur1.getPosition().x,joueur1.getPosition().y}); // Placer le joueur1 sur le sol

        }

        if (joueur2.getPosition().x < 0) {
            joueur2.setPosition({0, joueur2.getPosition().y}); // Empêcher le joueur2 de sortir par la gauche
        } else if (joueur2.getPosition().x > TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE.hauteur) {
            joueur2.setPosition({TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE.hauteur, joueur2.getPosition().y}); // Empêcher le joueur2 de sortir par la droite
            joueur2.getSprite().setPosition({joueur2.getPosition().x,joueur2.getPosition().y}); // Placer le joueur1 sur le sol

        }

        // Empêcher les joueurs de passer à travers le sol
        if (joueur1.getPosition().y >= POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) {
            joueur1.setPosition({joueur1.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur}); // Placer le joueur1 sur le sol
            joueur1.setVelocityY(0); // Arrêter la chute pour joueur1
            joueur1.getSprite().setPosition({joueur1.getPosition().x,joueur1.getPosition().y}); // Placer le joueur1 sur le sol

        }

        if (joueur2.getPosition().y >= POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur) {
            joueur2.setPosition({joueur2.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE.hauteur}); // Placer le joueur2 sur le sol
            //placer le sprite pareil
            joueur2.getSprite().setPosition({joueur2.getPosition().x,joueur2.getPosition().y});
            joueur2.setVelocityY(0); // Arrêter la chute pour joueur2
        }

}
