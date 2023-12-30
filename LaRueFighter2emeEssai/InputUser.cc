#include "InputUser.hh"
#include <iostream>
#include <sstream>


InputUser::InputUser() {
    CommandeJ1.Droite = sf::Keyboard::D;
    CommandeJ1.Gauche = sf::Keyboard::Q;

    CommandeJ2.Droite = sf::Keyboard::Right;
    CommandeJ2.Gauche = sf::Keyboard::Left;
    
}

InputUser::~InputUser() {
    // Aucune allocation dynamique, pas besoin de libérer la mémoire ici
}


EtatJoueur InputUser::getOuput(sf::Keyboard::Key key) {
    EtatJoueur etat;
      // Vous pouvez ajuster cela en fonction de votre logique

    // Logique pour déterminer l'action en fonction de la touche (key)
    if (key == CommandeJ1.Droite) {
        actionJ1 = Action::Droite;
    } else if (key == CommandeJ1.Gauche) {
        actionJ1 = Action::Gauche;
    } else if (key == CommandeJ2.Droite) {
        actionJ2 = Action::Droite;
    } else if (key == CommandeJ2.Gauche) {
        actionJ2 = Action::Gauche;
    }

    etat.actionJ1 = actionJ1;
    etat.actionJ2 = actionJ2;

    return etat;
}

std::string InputUser::str() {
    std::ostringstream output;

    // Écrire l'état du joueur J1 dans l'objet std::ostringstream
    output << "Action J1: ";
    switch (actionJ1) {
        case Droite:
            output << "Droite";
            break;
        case Gauche:
            output << "Gauche";
            break;
        // Ajoutez d'autres cas pour d'autres actions si nécessaire
    }

    output << std::endl;

    // Écrire l'état du joueur J2 dans l'objet std::ostringstream
    output << "Action J2: ";
    switch (actionJ2) {
        case Droite:
            output << "Droite";
            break;
        case Gauche:
            output << "Gauche";
            break;
        // Ajoutez d'autres cas pour d'autres actions si nécessaire
    }

    output << std::endl;

    // Renvoyer la chaîne de caractères construite
    return output.str();
}

