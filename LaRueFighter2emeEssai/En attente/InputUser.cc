#include "InputUser.hh"

Action InputUser::getActionJ2(){


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->action = Droite;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->action = Gauche;
    else
        this->action = Rien;
    return this->action;
}

Action InputUser::getActionJ1(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->action = Droite;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        this->action = Gauche;
    else
        this->action = Rien;
    return this->action;
}