#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ElementJeu.hh"
// Window


// Personnages: Joueur 1
const unsigned int POINTS_DE_VIE_JOUEUR1 = 3500;
const unsigned int DEGAT_ATTAQUE_POING1 = 5;
const unsigned int DEGAT_ATTAQUE_PIED1 = 5;

// Personnages: Joueur 2
const unsigned int POINTS_DE_VIE_JOUEUR2 = 3500;
const unsigned int DEGAT_ATTAQUE_POING2 = 5;
const unsigned int DEGAT_ATTAQUE_PIED2 = 5;

//Projectiles: Direct
const float VITESSE_DIRECT = 2;
const unsigned int DEGAT_DIRECT = 5;

//Projectiles: ZigZag
const float VITESSE_ZIGZAG = 2;
const unsigned int DEGAT_ZIGZAG = 5;

// Taille fenêtre
const sf::Vector2u TAILLE_FENETRE = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);

// Taille du sol

const int HAUTEUR_SOL = 150;
//Position des boutons:
const Point POSITION_BOUTON_JOUER = {int(TAILLE_FENETRE.x)/2 -100 , int(TAILLE_FENETRE.y) - 325};
const Point POSITION_BOUTON_COMMANDES = { int(TAILLE_FENETRE.x) / 2 - 100 , int(TAILLE_FENETRE.y)- 225};
const Point POSITION_BOUTON_QUITTER = {int(TAILLE_FENETRE.x)/2 - 100, int(TAILLE_FENETRE.y) - 125};



const Point POSITION_DEPART_JOUEUR1 = {0, 0};
const Point POSITION_DEPART_JOUEUR2 = {0, 0};
const Point POSITION_BOUTON_RETOUR = {0, 0};
const Point POSITION_BOUTON_PAUSE = {int(TAILLE_FENETRE.x) - 300, 0};
const Point POSITION_SOL = {0, int(TAILLE_FENETRE.y) - HAUTEUR_SOL};



//Taille des boutons:
const HitBox TAILLE_BOUTON_QUITTER = {POSITION_BOUTON_QUITTER.x, POSITION_BOUTON_QUITTER.y, POSITION_BOUTON_QUITTER.x+200 , POSITION_BOUTON_QUITTER.y+100 };
// const HitBox TAILLE_BOUTON_RETOUR = { 80 , 80 };
const HitBox TAILLE_BOUTON_COMMANDES = { POSITION_BOUTON_COMMANDES.x, POSITION_BOUTON_COMMANDES.y , POSITION_BOUTON_COMMANDES.x+200 , POSITION_BOUTON_COMMANDES.y+100 };
const HitBox TAILLE_BOUTON_JOUER = { POSITION_BOUTON_JOUER.x, POSITION_BOUTON_JOUER.y , POSITION_BOUTON_JOUER.x+200 , POSITION_BOUTON_JOUER.y+100};
// const HitBox TAILLE_BOUTON_PAUSE = { 80 , 80 };
// const HitBox TAILLE_SOL = {TAILLE_FENETRE.x, 100};


// Chemins des images:
const std::string CHEMIN_BACKGROUND_MENU("images/BackgroundMenu.jpg");
const std::string CHEMIN_BOUTON_JOUER("images/Jouer.jpg");
const std::string CHEMIN_BOUTON_QUITTER("images/Quitter.jpg");
const std::string CHEMIN_BOUTON_COMMANDES("images/Commandes.jpg");
const std::string CHEMIN_BACKGROUND_COMMANDES("images/BackgroundCommandes.jpg");


const std::string CHEMIN_IMAGE_JOUEUR1_RIEN("images/Fighter/Idle.png");
const std::string CHEMIN_IMAGE_JOUEUR1_DROITE("images/Fighter/Walk_Right.png");
const std::string CHEMIN_IMAGE_JOUEUR1_GAUCHE("images/Fighter/Walk_Left.png");
const std::string CHEMIN_IMAGE_JOUEUR2("../images/Joueur2.jpg");
const std::string CHEMIN_BOUTON_RETOUR("../images/Home.jpg");
const std::string CHEMIN_BOUTON_PAUSE("../images/Pause.jpg");
const std::string CHEMIN_BACKGROUND_ROUND1("../images/Round2.jpg");
const std::string CHEMIN_BACKGROUND_PAUSE("../images/Pause.jpg");


//Vitesse :
const int VITESSE_JOUEUR1 = 25;