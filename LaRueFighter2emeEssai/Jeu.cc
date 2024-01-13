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
    
    /* Initialisation des commandes avec le constructeur par defaut*/
    InputUser inputUser;

    // sf::RenderWindow* window = afficheur->getWindow();

    // Affichage de texte
    std::cout << "Lancement de la partie jeu.lancer()" << std::endl;

    sf::Sprite spriteJ1 = joueur1.getSprite();
    // vrai sprite de j2 avec un pointeur
    sf::Sprite spriteJ2 = joueur2.getSprite();
    sf::Vector2f velocity(0, 0);
    sf::RenderWindow* window = afficheur->getWindow();

    while (afficheur->getWindow()->isOpen() && lancerJeu)
    {
        sf::Event event;        
        while(afficheur->getWindow()->pollEvent(event)){

            /* Gestion des cliques*/
            if (event.type == sf::Event::KeyPressed)
            {
                sf::Keyboard::Key key = event.key.code;
                std::cout << "Touche enfoncée : " << key << std::endl;

                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Stop d'urgence avec escape
                {
                    afficheur->getWindow()->close();

                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
                    //Création d'un projectile
                    Projectile* projectile = new ProjectileZigZag(joueur1.getPosition(), VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG);
                    listes_projectiles.push_back(projectile);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    Projectile* projectile = new ProjectileLineaire(joueur1.getPosition(), VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_ZIGZAG);
                    listes_projectiles.push_back(projectile);
                }
            


                    if (event.key.code == sf::Keyboard::Up) { 
                            // Si la touchehaut est pressée et que le joueur2 est sur le sol
                                velocity.y = VITESSE_JOUEUR1_SAUT; // Définir la vélocité sur la vitesse de saut
                            
                        }

                   
                
            }
            
            
        }

         // Appliquer la gravité
        if (spriteJ2.getPosition().y + TAILLE_JOUEUR1_SPRITE < POSITION_SOL.y) {
            velocity.y += GRAVITE;
        }


        // Gérer le déplacement horizontal
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x = -5.0f; // Vélocité de déplacement vers la gauche
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x = 5.0f; // Vélocité de déplacement vers la droite
        } else {
            velocity.x = 0.0f; // Arrêter le déplacement horizontal
        }

        // Mettre à jour la position du joueur2
        joueur2.update(velocity);

        // Empêcher le spriteJ2 de sortir de l'écran
        if (spriteJ2.getPosition().x < 0) {
            spriteJ2.setPosition(0, spriteJ2.getPosition().y); // Empêcher le spriteJ2 de sortir par la gauche
        } else if (spriteJ2.getPosition().x > window->getSize().x - TAILLE_JOUEUR1_SPRITE) {
            spriteJ2.setPosition(window->getSize().x - TAILLE_JOUEUR1_SPRITE, spriteJ2.getPosition().y); // Empêcher le spriteJ2 de sortir par la droite
        }

        // Empêcher le rectangle de passer à travers le sol // NOT WORKING
        if (spriteJ2.getPosition().y  == POSITION_SOL.y + TAILLE_JOUEUR1_SPRITE) {
            spriteJ2.setPosition(spriteJ2.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR1_SPRITE); // Placer le rectangle sur le sol
            velocity.y = 0; // Arrêter la chute
        }

        // Afficher les positions en console
        std::cout << "Position X: " << spriteJ2.getPosition().x << ", Position Y: " << spriteJ2.getPosition().y << std::endl;

        
        for (Projectile* projectile : listes_projectiles) {
            projectile->deplacement(0.05);
            if(projectile->getADetruire() == true){
                listes_projectiles.remove(projectile);
            }
        }


        majProjectiles(DELTA_TIME);
        afficheur->afficher(*this); // Affiche le jeu 5PB d'affichage vient de là
        //afficheur->afficher(joueur1); // Affiche le joueur 1
       
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
