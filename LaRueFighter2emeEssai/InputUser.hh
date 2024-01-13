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
private:
    Commande CommandeJ1;
    Action actionJ1;
    Commande CommandeJ2;
    Action actionJ2;

public:
    InputUser();
    ~InputUser();

    /* Getters */

    Commande getCommandeJ1() const { return CommandeJ1; }
    Commande getCommandeJ2() const { return CommandeJ2; }
    Action getActionJ1(){return actionJ1;};
    Action getActionJ2(){return actionJ2;};


    /* Setter */

    void setActionJ1(Action action){actionJ1=action;};
    void setActionJ2(Action action){actionJ2=action;};

    /* Méthode */

    Action getOuputJ1(sf::Keyboard::Key key); 
    Action getOuputJ2(sf::Keyboard::Key key); 

    std::string str();


};



#endif
