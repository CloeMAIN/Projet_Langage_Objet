#include "Jeu.hh"
#include "Personnage.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
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

    sf::RenderWindow* window = afficheur->getWindow();

    // Affichage de texte
    std::cout << "Lancement de la partie jeu.lancer()" << std::endl;

    while (afficheur->getWindow()->isOpen() && lancerJeu)
    {
        sf::Event event;        
        while(window->pollEvent(event)){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window->close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                lancerJeu = false;
            }
            
        }
        afficheur->afficher(*this); // Affiche le jeu 5PB d'affichage vient de là
        //afficheur->afficher(joueur1); // Affiche le joueur 1
        window->display();
       
    }

    return 0;
}