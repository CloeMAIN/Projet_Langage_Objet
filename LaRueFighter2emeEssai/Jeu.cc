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

    while (afficheur->getWindow()->isOpen() && lancerJeu)
    {
        sf::Event event;
        while (afficheur->getWindow()->pollEvent(event)){
            /* Gestion des cliques */
            if (event.type == sf::Event::KeyPressed){
                sf::Keyboard::Key key = event.key.code;
                std::cout << "Touche enfoncée : " << key << std::endl;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Stop d'urgence avec escape
                {
                    afficheur->getWindow()->close();
                }
                else if (sf::Keyboard::isKeyPressed(TOUCHE_PROJECTILE_JOUEUR1) && !blockjoueur1){
                    // Création d'un projectile
                    Projectile* projectile = new ProjectileZigZag({joueur1.getPosition().x+35, joueur1.getPosition().y + 41}, VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG, joueur2.getDirection());
                    listes_projectiles.push_back(projectile);
                    blockjoueur1 = true;
                    clock1.restart();
                }
                else if (sf::Keyboard::isKeyPressed(TOUCHE_PROJECTILE_JOUEUR2) && !blockjoueur2){
                    Projectile* projectile = new ProjectileLineaire({joueur2.getPosition().x+35,joueur2.getPosition().y + 41 }, VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_ZIGZAG, joueur2.getDirection());
                    listes_projectiles.push_back(projectile);
                    blockjoueur2 = true;
                    clock2.restart();
                }
                else if (event.key.code == sf::Keyboard::Up && joueur2.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE) { 
                    // Si la touche haut est pressée et que le joueur2 est sur le sol
                    velocityJoueur2.y = VITESSE_JOUEUR1_SAUT; // Définir la vélocité sur la vitesse de saut 
                }
                else if (event.key.code == sf::Keyboard::Z && joueur1.getPosition().y  == POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE) { 
                    // Si la touche Z est pressée et que le joueur1 est sur le sol
                    velocityJoueur1.y = VITESSE_JOUEUR1_SAUT; // Définir la vélocité sur la vitesse de saut 
                }

                if(DEBUGGING_MODE){
                    if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J1)){
                        joueur1.setVie(joueur1.getVie()-5);
                    }
                    if (sf::Keyboard::isKeyPressed(TOUCHE_DEGAT_J2)){
                        joueur2.setVie(joueur2.getVie()-5);
                    }
                }
            }
        }

        // Gestion des blocages de tirs
        if (blockjoueur1 && clock1.getElapsedTime() > blockDuration1){
            blockjoueur1 = false;
        }
        if (blockjoueur2 && clock2.getElapsedTime() > blockDuration2){
            blockjoueur2 = false;
        }

        // Appliquer la gravité pour les deux joueurs
        if (joueur1.getPosition().y + TAILLE_JOUEUR1_SPRITE < POSITION_SOL.y) {
            velocityJoueur1.y += GRAVITE;
        }
        if (joueur2.getPosition().y + TAILLE_JOUEUR1_SPRITE < POSITION_SOL.y) {
            velocityJoueur2.y += GRAVITE;
        }

        // Gérer le déplacement horizontal pour les deux joueurs

        //Joueur 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            velocityJoueur1.x = -5.0f; // Vélocité de déplacement vers la gauche pour joueur1
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocityJoueur1.x = 5.0f; // Vélocité de déplacement vers la droite pour joueur1
        } else {
            velocityJoueur1.x = 0.0f; // Arrêter le déplacement horizontal pour joueur1
        }

        // Joueur 2 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocityJoueur2.x = -5.0f; // Vélocité de déplacement vers la gauche pour joueur2
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocityJoueur2.x = 5.0f; // Vélocité de déplacement vers la droite pour joueur2
        } else {
            velocityJoueur2.x = 0.0f; // Arrêter le déplacement horizontal pour joueur2
        }

        // Mettre à jour la position des joueurs
        joueur1.update(velocityJoueur1);
        joueur2.update(velocityJoueur2);

        // Empêcher les joueurs de sortir de l'écran
        if (joueur1.getPosition().x < 0) {
            joueur1.setPosition({0, joueur1.getPosition().y}); // Empêcher le joueur1 de sortir par la gauche
        } else if (joueur1.getPosition().x > TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE) {
            joueur1.setPosition({TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE, joueur1.getPosition().y}); // Empêcher le joueur1 de sortir par la droite
        }

        if (joueur2.getPosition().x < 0) {
            joueur2.setPosition({0, joueur2.getPosition().y}); // Empêcher le joueur2 de sortir par la gauche
        } else if (joueur2.getPosition().x > TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE) {
            joueur2.setPosition({TAILLE_FENETRE.x - TAILLE_JOUEUR1_SPRITE, joueur2.getPosition().y}); // Empêcher le joueur2 de sortir par la droite
        }

        // Empêcher les joueurs de passer à travers le sol
        if (joueur1.getPosition().y >= POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE) {
            joueur1.setPosition({joueur1.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE}); // Placer le joueur1 sur le sol
            velocityJoueur1.y = 0; // Arrêter la chute pour joueur1
        }

        if (joueur2.getPosition().y >= POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE) {
            joueur2.setPosition({joueur2.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE}); // Placer le joueur2 sur le sol
            velocityJoueur2.y = 0; // Arrêter la chute pour joueur2
        }

        // Afficher les positions en console
        std::cout << "Position Joueur1 - X: " << joueur1.getPosition().x << ", Y: " << joueur1.getPosition().y << std::endl;
        std::cout << "Position Joueur2 - X: " << joueur2.getPosition().x << ", Y: " << joueur2.getPosition().y << std::endl;

        majProjectiles(DELTA_TIME);
        afficheur->afficher(*this); // Affiche le jeu
    }

    return 0;
}


void Jeu::majProjectiles(double deltaTime){
    // Utilisez un itérateur pour parcourir la liste
    for (auto it = listes_projectiles.begin(); it != listes_projectiles.end(); ) {
        Projectile* projectile = *it;
        projectile->deplacement(deltaTime);

        // Si le projectile doit être détruit, supprimez-le de la liste et libérez la mémoire
        if (projectile->getADetruire()) {
            it = listes_projectiles.erase(it);  // La fonction erase() retourne le prochain itérateur valide
            delete projectile;
        } else {
            ++it;
        }
    }
}
