#ifndef INPUTUSER_HH
#define INPUTUSER_HH

#include <SFML/Graphics.hpp>
#include "Personnage.hh"

enum Action {
    Droite,Gauche,Rien
};
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

    /* Setter */

    Action setActionJ1(Action action){actionJ1=action;};
    Action setActionJ2(Action action){actionJ2=action;};

    /* Méthode */

    EtatJoueur getOuput(sf::Keyboard::Key key); 
    std::string str();


};



#endif
