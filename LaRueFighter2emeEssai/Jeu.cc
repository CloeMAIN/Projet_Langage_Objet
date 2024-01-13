#include "Jeu.hh"
#include "Personnage.hh"
#include "InputUser.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include <cmath>
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


// void Jeu::lancer(){

//     bool PartieLancee = true;
//     compteur_round = 1;
//     while(PartieLancee == true && !(JoueurMort) && ){

//         On prend les inputs (touches claviers, mouse, clic....)
//         if ( une toute est touchée){
//         InputUser input;
//         SI on touche une touche du clavier
//         actionJ1 = input.getActionJ1();
//         actionJ2 = input.getActionJ2();
//         }

//         On met à jour le jeu en fonction des inputs
//         On met à jour les joueurs
//         updateStateJoueurs(_joueur1, _joueur2, actionJ1, actionJ2);
        
//         On met à jour l'affichage
//         afficheur.afficher(_joueur1);
//         afficheur.afficher(_joueur2);
//         afficheur.afficher(_background);
//         afficheur.afficher(_sol);
//         afficheur.afficher(_barreDeVieJ1);
//         afficheur.afficher(_barreDeVieJ2);

//         On vérifie si la fenêtre de jeu (attribut de afficheur) est toujours ouverte
//         PartieLancee = afficheur.getwindow().isOpen();
//     }

//     round++;

// }


int Jeu::lancer(Afficheur* afficheur)
{
    bool lancerJeu = true;
    
    /* Initialisation des commandes avec le constructeur par defaut*/
    InputUser inputUser;

    // sf::RenderWindow* window = afficheur->getWindow();

    // Affichage de texte
    std::cout << "Lancement de la partie jeu.lancer()" << std::endl;

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
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
                    //Création d'un projectile
                    Projectile* projectile = new ProjectileZigZag({joueur2.getPosition().x+35, joueur1.getPosition().y + 41}, VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG, joueur2.getDirection());
                    listes_projectiles.push_back(projectile);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    Projectile* projectile = new ProjectileLineaire({joueur2.getPosition().x+35,joueur1.getPosition().y + 41 }, VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_ZIGZAG, joueur2.getDirection());
                    listes_projectiles.push_back(projectile);
                }
                else
                {

                    EtatJoueur etatJoueur;
                    etatJoueur.actionJ1 = inputUser.getOuputJ1(key);
                    etatJoueur.actionJ2 = inputUser.getOuputJ2(key);
                    // afficher etat joueur en console
                    std::cout << "Changement d'état : \n" << inputUser.str() << std::endl;

                }
            }else{

                /* si on ne clique pas on réinitialise les états des joueurs*/
                inputUser.setActionJ1(Action::Rien);
                inputUser.setActionJ2(Action::Rien);

            }
            
            
//         On prend les inputs (touches claviers, mouse, clic....)
//         if ( une toute est touchée){
//         InputUser input;
//         SI on touche une touche du clavier
//         actionJ1 = input.getActionJ1();
//         actionJ2 = input.getActionJ2();
//         }



           
            


//         On met à jour le jeu en fonction des inputs
//         On met à jour les joueurs
//         updateStateJoueurs(_joueur1, _joueur2, actionJ1, actionJ2);
        
//         On met à jour l'affichage
//         afficheur.afficher(_joueur1);
//         afficheur.afficher(_joueur2);
//         afficheur.afficher(_background);
//         afficheur.afficher(_sol);
//         afficheur.afficher(_barreDeVieJ1);
//         afficheur.afficher(_barreDeVieJ2);
            
        }

         /* MAJ des attributs des joueurs*/

            majJoueurs(inputUser);
            majProjectiles(DELTA_TIME);
        afficheur->afficher(*this); // Affiche le jeu 5PB d'affichage vient de là
        //afficheur->afficher(joueur1); // Affiche le joueur 1
       
    }

    return 0;
}

void Jeu::majJoueurs(InputUser inputUser){
    joueur1.maj(inputUser.getActionJ1());
    joueur2.maj(inputUser.getActionJ2());
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