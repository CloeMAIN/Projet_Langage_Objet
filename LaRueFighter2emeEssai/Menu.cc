
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

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                lancerMenu = false;
            
            //si je clique avec ma souris
            if(event.type == sf::Event::MouseButtonPressed){
                //si je clique sur le bouton jouer
                if(event.mouseButton.button == sf::Mouse::Left){
                    //si le bouton jouer est cliqué, on return
                    if (event.mouseButton.x >= TAILLE_BOUTON_JOUER.GaucheHaut.x && event.mouseButton.x <= TAILLE_BOUTON_JOUER.DroiteBas.x && event.mouseButton.y >= TAILLE_BOUTON_JOUER.GaucheHaut.y && event.mouseButton.y <= TAILLE_BOUTON_JOUER.DroiteBas.y){
                        std::cout << "Jouer" << std::endl;
                        return 0;}

                    //else si je clique sur le bouton commandes
                    else if (event.mouseButton.x >= TAILLE_BOUTON_COMMANDES.GaucheHaut.x && event.mouseButton.x <= TAILLE_BOUTON_COMMANDES.DroiteBas.x && event.mouseButton.y >= TAILLE_BOUTON_COMMANDES.GaucheHaut.y && event.mouseButton.y <= TAILLE_BOUTON_COMMANDES.DroiteBas.y){
                        std::cout << "Commandes" << std::endl;
                        afficheur->afficher(CHEMIN_BACKGROUND_COMMANDES);
                        window->display();
                        //On attend que l'utilisateur appuie sur la touche B pour revenir au menu
                        while(!sf::Keyboard::isKeyPressed(sf::Keyboard::B)){}
                        }

                    //else si je clique sur le bouton quitter
                    else if (event.mouseButton.x >= TAILLE_BOUTON_QUITTER.GaucheHaut.x && event.mouseButton.x <= TAILLE_BOUTON_QUITTER.DroiteBas.x && event.mouseButton.y >= TAILLE_BOUTON_QUITTER.GaucheHaut.y && event.mouseButton.y <= TAILLE_BOUTON_QUITTER.DroiteBas.y){
                        std::cout << "Quitter" << std::endl;
                        window->close();
                        return 2;}

                }
            }
        }

        afficheur->afficherMenu();
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
