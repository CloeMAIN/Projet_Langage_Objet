
#include "Menu.hh"
#include "Afficheur.hh"

int Menu::lancer(Afficheur* afficheur){


    bool lancerMenu = true;

    while(afficheur->getWindow()->isOpen() && lancerMenu){
        
        // sf::Event event;        
        // while(window.pollEvent(event)){
        //     //si je clique avec ma souris
        //     if(event.type == sf::Event::MouseButtonPressed){
        //         //si je clique sur le bouton jouer
        //         if(event.mouseButton.button == sf::Mouse::Left){
        //             //si le bouton jouer est cliqué, on return
        //             return;
        //         }
        //             //else si je clique sur le bouton commande
        //             //afficheur.afficherCommande();

        //             //else si je clique sur le bouton quitter
        //             window.close();
        //     }
        // }
        // afficheur.afficherMenu();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            afficheur->getWindow()->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            lancerMenu = false;
        }
    }
    return 0;
}


Menu::Menu(/* args */)
{
    // Constructeur
}

Menu::~Menu()
{
    // Destructeur
}
