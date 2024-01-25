#include "ElementJeu.hh"
#include <iostream>

ElementJeu::ElementJeu()
{
    position.x = 0;
    position.y = 0;
    taille.largeur = 0;
    taille.hauteur = 0;
    direction = Direction::DROITE;
}

ElementJeu::ElementJeu(Point position, Direction direction, Taille taille)
{
    this->position = position;
    this->direction = direction;
    this->taille = taille;
}

ElementJeu::~ElementJeu()
{
}

ElementJeu& ElementJeu::operator=(std::nullptr_t){
    if (this != nullptr) {
    position.x = -100;
    position.y = -100;
    taille.largeur = 0;
    taille.hauteur = 0;
    direction = Direction::DROITE;
    }
    return *this;
}

ElementJeu& ElementJeu::operator=(const ElementJeu& b){
    position.x = b.getPosition().x;
    position.y = b.getPosition().y;
    taille.largeur = b.getTaille().largeur;
    taille.hauteur = b.getTaille().hauteur;
    direction = b.getDirection();
    return *this;
}

bool ElementJeu::operator!=(std::nullptr_t){
    if(position.x != -100 or position.y != -100 or taille.largeur != 0 or taille.hauteur != 0 or direction != Direction::DROITE){
        return true;
    }
    return false;
}

float ElementJeu::distance(const ElementJeu& b)const
{

    // On détermine les centre des 2 objets : 
    float centrexA;
    float centrexB;
    centrexA = position.x + taille.largeur/2;
    centrexB = b.getPosition().x + b.getTaille().largeur/2;
    // std::cout << "Centre x A : " << centrexA << std::endl;
    // std::cout << "Centre x B : " << centrexB << std::endl;

    //On calcul la distance entre les 2 centres
    float distance = abs(centrexA - centrexB);
    return distance;
}

bool ElementJeu::contact(const ElementJeu& b) const{
    // ON détermine l'élément le + petit : 
    ElementJeu petit = b;
    ElementJeu grand = *this;
    if(taille.hauteur < b.getTaille().hauteur){
        petit = *this;
        grand = b;
    }
    float centre_petit = petit.getPosition().y + petit.getTaille().hauteur/2;

    float distance = grand.distance(petit);
    // std::cout << "centre petit : " << centre_petit << std::endl;
    if(distance <= (taille.largeur + b.getTaille().largeur)/2 and centre_petit <= grand.getPosition().y + grand.getTaille().hauteur and centre_petit >= grand.getPosition().y){
        return true;
    }
    return false;
}