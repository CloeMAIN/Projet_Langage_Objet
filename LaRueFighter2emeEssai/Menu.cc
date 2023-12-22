
#include "Menu.hh"
#include "Afficheur.hh"
#include <iostream>

int Menu::lancer(Afficheur* afficheur){

    bool lancerMenu = true;

    sf::RenderWindow* window = afficheur->getWindow();

    // Affichage de texte
    std::cout << "Lancement du menu menu.lancer()" << std::endl;

    while(window->isOpen() && lancerMenu){
        
        sf::Event event;        
        while(window->pollEvent(event)){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window->close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                lancerMenu = false;
            }
            // //si je clique avec ma souris
            // if(event.type == sf::Event::MouseButtonPressed){
            //     //si je clique sur le bouton jouer
            //     if(event.mouseButton.button == sf::Mouse::Left){
            //         //si le bouton jouer est cliqué, on return
            //         return;
            //     }
            //         //else si je clique sur le bouton commande
            //         //afficheur.afficherCommande();

            //         //else si je clique sur le bouton quitter
            //         window.close();
            // }

            //     afficheur.afficherMenu();



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
