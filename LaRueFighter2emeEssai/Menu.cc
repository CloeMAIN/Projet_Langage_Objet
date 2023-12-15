#include "Menu.hh"

Menu::lancer(){
    while(window.isOpen()){
        
        sf::Event event;        
        while(window.pollEvent(event)){
            //si je clique avec ma souris
            if(event.type == sf::Event::MouseButtonPressed){
                //si je clique sur le bouton jouer
                if(event.mouseButton.button == sf::Mouse::Left){
                    //si le bouton jouer est cliqué, on return
                    return;
                }
                    //else si je clique sur le bouton commande
                    //afficheur.afficherCommande();

                    //else si je clique sur le bouton quitter
                    window.close();
            }
        }
        afficheur.afficherMenu();
    }
}
