#ifndef MENU_HH
#define MENU_HH
#pragma once
#include "Afficheur.hh"
#include "ElementJeu.hh"
#include <vector>
#include <string>
#include <iostream>

class Afficheur;

class Menu
{
private:
    std::vector<std::string> cheminBackgroundMenu; //Le 1er element est le chemin du fond principal, le 2ème est le chemin du fond si on clique sur le 2eme bouton
    std::vector<std::pair<std::string, std::pair<HitBox, Point>>> listeBoutons; //LE 1er bouton sert à jouer, le 2ème à afficher les commandes, le 3ème à quitter
public:
    Menu(std::vector<std::string> cheminBackgroundMenu, std::vector<std::pair<std::string, std::pair< HitBox, Point>>> listeBoutons);
    ~Menu();

    //Getter
    std::vector<std::string> getCheminBackgroundMenu() const {return cheminBackgroundMenu;}
    std::vector<std::pair<std::string, std::pair<HitBox, Point>>> getListeBoutons() const {return listeBoutons;}
    int lancer(Afficheur* afficheur);
};

#endif // MENU_HH
