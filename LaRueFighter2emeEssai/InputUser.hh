#ifndef INPUTUSER_HH
#define INPUTUSER_HH

#include <SFML/Graphics.hpp>

struct Action {
    sf::Keyboard::Key Droite;
    sf::Keyboard::Key Gauche;
    // Ajoutez d'autres actions ici (ex: Attaquer droite, Attaquer gauche, Sauter, S'accroupir)
};

class InputUser {
private:
    Action ActionJ1;
    Action ActionJ2;

public:
    InputUser();
    ~InputUser();

    /* Getters */

    Action getActionJ1() const { return ActionJ1; }
    Action getActionJ2() const { return ActionJ2; }

    /* Méthode */

    // std::string Ouput(sf::Keyboard touche){
    //     if ( touche est droite pour J2){
    //         return " J2, Droite "
    //     }
    // }

};



#endif
