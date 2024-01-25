#include "Jeu.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include "ProjectileZigZag.hh"
#include "ProjectileLineaire.hh"

int Jeu::lancer(Afficheur* afficheur)
{
    bool lancerJeu = true;
    InputUser inputUser;
    sf::RenderWindow* window = afficheur->getWindow();

    while (afficheur->getWindow()->isOpen() && lancerJeu)
    {
        // Gestion des événements
        inputUser.gererEvenements(afficheur->getWindow(), joueur1, joueur2);

        //Mise à jour des joueurs
        majJoueurs();
        
        //Gérer tous les affichages
        afficheur->afficher(*this); 

        if(joueur1.getVie() <= 0 ){
            lancerJeu = false;
            return 1;
        }

        if(joueur1.getVie() <= 0 ){
            lancerJeu = false;
            return 2;
        }
    }

    return 0;
}


void Jeu::empecherSortie(){

        // Empêcher les joueurs de sortir de l'écran
        if (joueur1.getPosition().x < 0) {
            joueur1.setPosition({0, joueur1.getPosition().y}); // Empêcher le joueur1 de sortir par la gauche
        } else if (joueur1.getPosition().x > TAILLE_FENETRE.x - TAILLE_JOUEUR_SPRITE.hauteur) {
            joueur1.setPosition({TAILLE_FENETRE.x - TAILLE_JOUEUR_SPRITE.hauteur, joueur1.getPosition().y}); // Empêcher le joueur1 de sortir par la droite
            joueur1.getSprite().setPosition({joueur1.getPosition().x,joueur1.getPosition().y}); // Placer le joueur1 sur le sol

        }

        if (joueur2.getPosition().x < 0) {
            joueur2.setPosition({0, joueur2.getPosition().y}); // Empêcher le joueur2 de sortir par la gauche
        } else if (joueur2.getPosition().x > TAILLE_FENETRE.x - TAILLE_JOUEUR_SPRITE.hauteur) {
            joueur2.setPosition({TAILLE_FENETRE.x - TAILLE_JOUEUR_SPRITE.hauteur, joueur2.getPosition().y}); // Empêcher le joueur2 de sortir par la droite
            joueur2.getSprite().setPosition({joueur2.getPosition().x,joueur2.getPosition().y}); // Placer le joueur1 sur le sol

        }

        // Empêcher les joueurs de passer à travers le sol
        if (joueur1.getPosition().y >= POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.hauteur) {
            joueur1.setPosition({joueur1.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.hauteur}); // Placer le joueur1 sur le sol
            joueur1.setVelocityY(0); // Arrêter la chute pour joueur1
            joueur1.getSprite().setPosition({joueur1.getPosition().x,joueur1.getPosition().y}); // Placer le joueur1 sur le sol

        }

        if (joueur2.getPosition().y >= POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.hauteur) {
            joueur2.setPosition({joueur2.getPosition().x, POSITION_SOL.y - TAILLE_JOUEUR_SPRITE.hauteur}); // Placer le joueur2 sur le sol
            //placer le sprite pareil
            joueur2.getSprite().setPosition({joueur2.getPosition().x,joueur2.getPosition().y});
            joueur2.setVelocityY(0); // Arrêter la chute pour joueur2
        }

}


void Jeu::majJoueurs(){
    // Appliquer la gravité pour les deux joueurs
        if (joueur1.getPosition().y + TAILLE_JOUEUR_SPRITE.hauteur < POSITION_SOL.y) {
            // std::cout <<" GRAVITE APPLIED" << std::endl;
            joueur1.setVelocityY(joueur1.getVelocity().y + GRAVITE);
        }
        if (joueur2.getPosition().y + TAILLE_JOUEUR_SPRITE.hauteur < POSITION_SOL.y) {
            joueur2.setVelocityY(joueur2.getVelocity().y + GRAVITE);
        }

        // Mettre à jour la position des joueurs
        empecherSortie();
        joueur1.mouvement();
        joueur2.mouvement();

        //Gerer les projectiles des joueurs
        joueur1.GestionProjectileLineaire();
        joueur2.GestionProjectileZigZag();
        joueur1.majProjectiles(DELTA_TIME);
        joueur2.majProjectiles(DELTA_TIME);

        //Gerer les actions des joueurs
        joueur1.update_attaque();
        joueur2.update_attaque();

        //Gérer les contacts des joueurs
        joueur1.update_contact(joueur2);
        joueur2.update_contact(joueur1);

}