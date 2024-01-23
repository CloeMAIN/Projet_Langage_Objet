#include "ElementJeu.hh"
#include <iostream>

ElementJeu::ElementJeu(/* args */)
{
}

ElementJeu::~ElementJeu()
{
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