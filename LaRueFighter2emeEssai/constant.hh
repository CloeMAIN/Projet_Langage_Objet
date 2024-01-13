#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ElementJeu.hh"

// Taille fenêtre
const sf::Vector2f TAILLE_FENETRE = sf::Vector2f(static_cast<float>(sf::VideoMode::getDesktopMode().width), static_cast<float>(sf::VideoMode::getDesktopMode().height));

// Taille du sol
const int HAUTEUR_SOL = 150;

const double DELTA_TIME = 0.05;

// Environnement
const float GRAVITE = 0.5f;

// Personnages: Joueur 1
const float POINTS_DE_VIE_JOUEUR1 = 3500;
const float DEGAT_ATTAQUE_POING1 = 5;
const float DEGAT_ATTAQUE_PIED1 = 5;
const Point POSITION_DEPART_JOUEUR1 = {float(TAILLE_FENETRE.x)/3, float(TAILLE_FENETRE.y)-HAUTEUR_SOL-150};

const float VITESSE_JOUEUR1 = 25;
const float VITESSE_JOUEUR1_SAUT = -12.0f;
//taille sprite
const float TAILLE_JOUEUR1_SPRITE = 82*2;



// Personnages: Joueur 2
const float POINTS_DE_VIE_JOUEUR2 = 3500;
const float DEGAT_ATTAQUE_POING2 = 5;
const float DEGAT_ATTAQUE_PIED2 = 5;
const Point POSITION_DEPART_JOUEUR2 = {2*float(TAILLE_FENETRE.x)/3,float(TAILLE_FENETRE.y)-HAUTEUR_SOL-150};


//Projectiles: Direct
const int RAYON_DIRECT = 5;
const float VITESSE_DIRECT = 45;
const float DEGAT_DIRECT = 5;
const Point POSITION_DEPART_DIRECT = {POSITION_DEPART_JOUEUR1.x + 20, POSITION_DEPART_JOUEUR1.y + 75};//20 et 75 c'st en supposant que les personnage font 40*150

//Projectiles: ZigZag
// const Point POSITION_DEPART_ZIGZAG = {POSITION_DEPART_JOUEUR1.x, POSITION_DEPART_JOUEUR1.y};//20 et 75 c'st en supposant que les personnage font 40*150
const float VITESSE_ZIGZAG = 30;
const float DEGAT_ZIGZAG = 5;
const float RAYON_ZIGZAG = 5;
const std::string CHEMIN_IMAGE_ZIGZAG = "images/projectile.jpg";
const double AMPLITUDE_ZIGZAG = 100;
const double ANGLE_TIR_ZIGZAG = 1;
const double FREQUENCE_ZIGZAG = 3;




//Position des boutons:
const Point POSITION_BOUTON_JOUER = {float(TAILLE_FENETRE.x)/2 -100 , float(TAILLE_FENETRE.y) - 325};
const Point POSITION_BOUTON_COMMANDES = { float(TAILLE_FENETRE.x) / 2 - 100 , float(TAILLE_FENETRE.y)- 225};
const Point POSITION_BOUTON_QUITTER = {float(TAILLE_FENETRE.x)/2 - 100, float(TAILLE_FENETRE.y) - 125};



const Point POSITION_BOUTON_RETOUR = {0, 0};
const Point POSITION_BOUTON_PAUSE = {float(TAILLE_FENETRE.x) - 300, 0};
const Point POSITION_SOL = {0, float(TAILLE_FENETRE.y) - HAUTEUR_SOL};


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


const std::string CHEMIN_IMAGE_JOUEUR1_RIEN_GAUCHE("images/Fighter/Idle_Left.png");
const std::string CHEMIN_IMAGE_JOUEUR1_RIEN_DROITE("images/Fighter/Idle_Right.png");
const std::string CHEMIN_IMAGE_JOUEUR1_DROITE("images/Fighter/Walk_Right.png");
const std::string CHEMIN_IMAGE_JOUEUR1_GAUCHE("images/Fighter/Walk_Left.png");
const std::string CHEMIN_IMAGE_JOUEUR2("../images/Joueur2.jpg");
const std::string CHEMIN_BOUTON_RETOUR("../images/Home.jpg");
const std::string CHEMIN_BOUTON_PAUSE("../images/Pause.jpg");
const std::string CHEMIN_BACKGROUND_ROUND1("../images/Round2.jpg");
const std::string CHEMIN_BACKGROUND_PAUSE("../images/Pause.jpg");


