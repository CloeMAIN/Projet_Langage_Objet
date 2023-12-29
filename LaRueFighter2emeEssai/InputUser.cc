#include "InputUser.hh"

InputUser::InputUser() {
    ActionJ1.Droite = sf::Keyboard::Right;
    ActionJ1.Gauche = sf::Keyboard::Left;

    ActionJ2.Droite = sf::Keyboard::Q;
    ActionJ2.Gauche = sf::Keyboard::D;
}

InputUser::~InputUser() {
    // Aucune allocation dynamique, pas besoin de libérer la mémoire ici
}