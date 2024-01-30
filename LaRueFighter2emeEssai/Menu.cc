
#include "Menu.hh"

int Menu::lancer(Afficheur* afficheur){

    bool lancerMenu = true;
    sf::Music music; 

  
    if(!music.openFromFile("Son/Kamado Tanjiro.wav"))
        std::cout << "Erreur lors du chargement de la musique" << std::endl;
    else
        std::cout << "Musique chargée" << std::endl;

    music.setLoop(true); 
    music.play();
    // sf::RenderWindow* window = afficheur->getWindow();

    // Affichage de texte
    std::cout << "Lancement du menu menu.lancer()" << std::endl;

    while(afficheur->getWindow()->isOpen() && lancerMenu){
        
        sf::Event event;        
        while(afficheur->getWindow()->pollEvent(event)){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                afficheur->getWindow()->close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                lancerMenu = false;
            
            //si je clique avec ma souris
            if(event.type == sf::Event::MouseButtonPressed){
                //si je clique sur le bouton jouer
                if(event.mouseButton.button == sf::Mouse::Left){
                    //si le bouton jouer est cliqué, on return
                    if (event.mouseButton.x >= listeBoutons[0].second.first.GaucheHaut.x && event.mouseButton.x <= listeBoutons[0].second.first.DroiteBas.x && event.mouseButton.y >= listeBoutons[0].second.first.GaucheHaut.y && event.mouseButton.y <= listeBoutons[0].second.first.DroiteBas.y){
                        // std::cout << "Jouer" << std::endl;
                        return 0;}

                    //else si je clique sur le bouton commandes
                    else if (event.mouseButton.x >= listeBoutons[1].second.first.GaucheHaut.x && event.mouseButton.x <= listeBoutons[1].second.first.DroiteBas.x && event.mouseButton.y >= listeBoutons[1].second.first.GaucheHaut.y && event.mouseButton.y <= listeBoutons[1].second.first.DroiteBas.y){
                        // std::cout << "Commandes" << std::endl;
                        afficheur->afficher(cheminBackgroundMenu[1]);
                        afficheur->getWindow()->display();
                        //On attend que l'utilisateur appuie sur la touche B pour revenir au menu
                        while(!sf::Keyboard::isKeyPressed(sf::Keyboard::B)){}
                        }

                    //else si je clique sur le bouton quitter
                    else if (event.mouseButton.x >= listeBoutons[2].second.first.GaucheHaut.x && event.mouseButton.x <= listeBoutons[2].second.first.DroiteBas.x && event.mouseButton.y >= listeBoutons[2].second.first.GaucheHaut.y && event.mouseButton.y <= listeBoutons[2].second.first.DroiteBas.y){
                        // std::cout << "Quitter" << std::endl;
                        afficheur->getWindow()->close();
                        return 3;}
                    
                    //else si je clique sur le bouton questionnaire
                    else if (event.mouseButton.x >= listeBoutons[3].second.first.GaucheHaut.x && event.mouseButton.x <= listeBoutons[3].second.first.DroiteBas.x && event.mouseButton.y >= listeBoutons[3].second.first.GaucheHaut.y && event.mouseButton.y <= listeBoutons[3].second.first.DroiteBas.y){
                        // std::cout << "Questionnaire" << std::endl;
                        // afficheur->getWindow()->setVisible(false);
                        return 4;}

                }
            }
        }

        afficheur->afficher(*this);
    }
    return 0;
}


Menu::Menu(std::vector<std::string> cheminBackgroundMenu, std::vector<std::pair<std::string, std::pair<HitBox, Point>>> listeBoutons)
{
    // Constructeur
    this->cheminBackgroundMenu = cheminBackgroundMenu;
    this->listeBoutons = listeBoutons;
    
    }

Menu::~Menu()
{
    // Destructeur
}
