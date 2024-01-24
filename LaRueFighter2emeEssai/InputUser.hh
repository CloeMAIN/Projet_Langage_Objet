#ifndef INPUTUSER_HH
#define INPUTUSER_HH

#include <SFML/Graphics.hpp>
#include "Personnage.hh"


struct Commande {
    sf::Keyboard::Key Droite;
    sf::Keyboard::Key Gauche;
    // Ajoutez d'autres actions ici (ex: Attaquer droite, Attaquer gauche, Sauter, S'accroupir)
};

struct EtatJoueur {
    Action actionJ1;
    Action actionJ2;
};

class InputUser {
public:
    // ... (autres membres et méthodes)
    
    InputUser();
    ~InputUser();

    void gererEvenements(sf::RenderWindow* window, Personnage& joueur1, Personnage& joueur2);

};



#endif
