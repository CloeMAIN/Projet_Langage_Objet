#include "Jeu.hh"
#include "Personnage.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
Jeu::Jeu(/* args */)
{
    //Créer les joueurs  (1 et 2 pour l'instants)
    Personnage joueur1;
    Personnage joueur2;
    //On créée l'afficheur:
    Afficheur afficheur;
    // si ca foire on met userinput en plus ici
    int round = 1;
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

    // Affichage de texte
    std::cout << "Lancement de la partie jeu.lancer()" << std::endl;


    while (afficheur->getWindow()->isOpen() && lancerJeu)
    {

        afficheur->afficher(this); // Affiche le jeu
    
        // Conditions pour quitter le jeu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            afficheur->getWindow()->close();
            lancerJeu = false;
        }
    }

    return 0;
}