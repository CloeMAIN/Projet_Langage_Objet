#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ElementJeu.hh"

// Taille fenêtre
const sf::Vector2f TAILLE_FENETRE = sf::Vector2f(static_cast<float>(sf::VideoMode::getDesktopMode().width), static_cast<float>(sf::VideoMode::getDesktopMode().height));

// Taille du sol
const int HAUTEUR_SOL = 150;

//Temps pour déplacer les projectiles en continu
const double DELTA_TIME = 0.05;

// Environnement
const float GRAVITE = 0.5f;



// Tests
const bool DEBUGGING_MODE = true;
const sf::Keyboard::Key TOUCHE_DEGAT_J1 = sf::Keyboard::A;
const sf::Keyboard::Key TOUCHE_DEGAT_J2 = sf::Keyboard::B;


// Constantes communes aux deux joueurs a modifier dans code
const float VITESSE_JOUEUR = 10;
const float VITESSE_JOUEUR_SAUT = -32.0f;
const Taille TAILLE_JOUEUR_SPRITE = {70, 164};
const float POINTS_DE_VIE_JOUEUR = 3500;


/*----------------------------------------JOUEUR 1-----------------------------------------------*/


//Commandes Joueur1
const sf::Keyboard::Key TOUCHE_SAUT_JOUEUR1 = sf::Keyboard::Z;
const sf::Keyboard::Key TOUCHE_GAUCHE_JOUEUR1 = sf::Keyboard::Q;
const sf::Keyboard::Key TOUCHE_DROITE_JOUEUR1 = sf::Keyboard::D;
const sf::Keyboard::Key TOUCHE_PROJECTILE_JOUEUR1 = sf::Keyboard::LShift;
const sf::Keyboard::Key TOUCHE_ATTAQUE1_JOUEUR1 = sf::Keyboard::G;
const sf::Keyboard::Key TOUCHE_ATTAQUE2_JOUEUR1 = sf::Keyboard::H;

// Personnages: Joueur 1
const float POINTS_DE_VIE_JOUEUR1 = 3500;
const Point POSITION_DEPART_JOUEUR1 = {float(TAILLE_FENETRE.x)/3, 0};


// Barre de vie
const Point POSITION_BARRE_J1 = {float(20),float(20)};
const sf::Color COULEUR_BARRE_J1 = sf::Color::Red;


// Chemin des images
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_RIEN ={"images/Fighter/Idle_Right.png","images/Fighter/Idle_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_AVANCER = {"images/Fighter/Walk_Right.png","images/Fighter/Walk_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_SAUT = {"images/Fighter/Saut_Right.png","images/Fighter/Saut_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_ATTAQUE1= {"images/Fighter/Fist_Right.png","images/Fighter/Fist_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_ATTAQUE2 = {"images/Fighter/Foot_Right.png","images/Fighter/Foot_Left.png"};

// Nombre d'images par animation
const int NB_IMAGE_SPRITE_SAUT = 1;
const int NB_IMAGE_SPRITE_RIEN = 6;
const int NB_IMAGE_SPRITE_AVANCER = 8;
const int NB_IMAGE_ATTAQUE1 = 1;
const int  NB_IMAGE_ATTAQUE2 = 1;

/*----------------------------------------JOUEUR 2-----------------------------------------------*/


//Commandes Joueur2
const sf::Keyboard::Key TOUCHE_SAUT_JOUEUR2 = sf::Keyboard::Up;
const sf::Keyboard::Key TOUCHE_GAUCHE_JOUEUR2 = sf::Keyboard::Left;
const sf::Keyboard::Key TOUCHE_DROITE_JOUEUR2 = sf::Keyboard::Right;
const sf::Keyboard::Key TOUCHE_PROJECTILE_JOUEUR2 = sf::Keyboard::RShift;
const sf::Keyboard::Key TOUCHE_ATTAQUE1_JOUEUR2 = sf::Keyboard::P;
const sf::Keyboard::Key TOUCHE_ATTAQUE2_JOUEUR2 = sf::Keyboard::M;


// Personnages: Joueur 2
const float POINTS_DE_VIE_JOUEUR2 = 3500;
const Point POSITION_DEPART_JOUEUR2 = {float(TAILLE_FENETRE.x)/3 * 2,0};

// Barre de vie
const Point POSITION_BARRE_J2 = {float(TAILLE_FENETRE.x)-1020,float(20)};
const sf::Color COULEUR_BARRE_J2 = sf::Color::Blue;


// Chemin des images
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_RIEN ={"images/Fighter/Idle_Right.png","images/Fighter/Idle_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_AVANCER = {"images/Fighter/Walk_Right.png","images/Fighter/Walk_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_SAUT = {"images/Fighter/Saut_Right.png","images/Fighter/Saut_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_ATTAQUE1= {"images/Fighter/Fist_Right.png","images/Fighter/Fist_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_ATTAQUE2 = {"images/Fighter/Foot_Right.png","images/Fighter/Foot_Left.png"};

// Nombre d'images par animation
// const int NB_IMAGE_SPRITE_SAUT = 1;
// const int NB_IMAGE_SPRITE_RIEN = 6;
// const int NB_IMAGE_SPRITE_AVANCER = 8;
// const int NB_IMAGE_ATTAQUE1 = 1;
// const int NB_IMAGE_ATTAQUE2 = 1;

/*------------------------------------Attaques---------------------------------*/

//Attaques physiques (mêmes pour les deux joueurs)
const float DEGAT_ATTAQUE1 = 50;
const float DEGAT_ATTAQUE2 = 100;
const float DECALAGE_Y_PIED = 65;
const float DECALAGE_Y_POING = 55;
const Taille TAILLE_ATTAQUE1= {40, 20};
const Taille TAILLE_ATTAQUE2 = {50, 20};

//Temps de blocage des attaques (mêmes pour les deux joueurs)
const float TEMPS_BLOCAGE_ATTAQUE = 10;
const float TEMPS_BLOCAGE_PROJECTILE = 2;

//Projectiles: Direct
const int RAYON_DIRECT = 5;
const float VITESSE_DIRECT = 400;
const float DEGAT_DIRECT = 5;

//Projectiles: ZigZag
const float VITESSE_ZIGZAG = 200;
const float DEGAT_ZIGZAG = 5;
const float RAYON_ZIGZAG = 5;
const double AMPLITUDE_ZIGZAG = 300;
const double ANGLE_TIR_ZIGZAG = 90;
const double FREQUENCE_ZIGZAG = 3;

// Chemin des images
const std::string CHEMIN_IMAGE_ZIGZAG =  "images/projectile.jpg";
const std::string CHEMIN_IMAGE_DIRECT =  "images/projectile.jpg";

/*-----------------------------------MENU DU DEBUT-----------------------------------------*/
// Chemins des images:
const std::string CHEMIN_BACKGROUND_MENU("images/BackgroundMenu.jpg");
const std::string CHEMIN_BOUTON_JOUER("images/Jouer.jpg");
const std::string CHEMIN_BOUTON_QUITTER("images/Quitter.jpg");
const std::string CHEMIN_BOUTON_COMMANDES("images/Commandes.jpg");
const std::string CHEMIN_BACKGROUND_COMMANDES("images/BackgroundCommandes.jpg");

//Position des boutons:
const Point POSITION_BOUTON_JOUER = {float(TAILLE_FENETRE.x)/2 -100 , float(TAILLE_FENETRE.y) - 325};
const Point POSITION_BOUTON_COMMANDES = { float(TAILLE_FENETRE.x) / 2 - 100 , float(TAILLE_FENETRE.y)- 225};
const Point POSITION_BOUTON_QUITTER = {float(TAILLE_FENETRE.x)/2 - 100, float(TAILLE_FENETRE.y) - 125};

//Taille des boutons:
const HitBox TAILLE_BOUTON_QUITTER = {POSITION_BOUTON_QUITTER.x, POSITION_BOUTON_QUITTER.y, POSITION_BOUTON_QUITTER.x+200 , POSITION_BOUTON_QUITTER.y+100 };
const HitBox TAILLE_BOUTON_COMMANDES = { POSITION_BOUTON_COMMANDES.x, POSITION_BOUTON_COMMANDES.y , POSITION_BOUTON_COMMANDES.x+200 , POSITION_BOUTON_COMMANDES.y+100 };
const HitBox TAILLE_BOUTON_JOUER = { POSITION_BOUTON_JOUER.x, POSITION_BOUTON_JOUER.y , POSITION_BOUTON_JOUER.x+200 , POSITION_BOUTON_JOUER.y+100};




/*------------------------------------JEU PRINCIPAL----------------------------------*/


const Point POSITION_BOUTON_RETOUR = {0, 0};
const Point POSITION_BOUTON_PAUSE = {float(TAILLE_FENETRE.x) - 300, 0};
const Point POSITION_SOL = {0, float(TAILLE_FENETRE.y) - HAUTEUR_SOL};


//Taille des boutons:
// const HitBox TAILLE_BOUTON_RETOUR = { 80 , 80 };
// const HitBox TAILLE_BOUTON_PAUSE = { 80 , 80 };
// const HitBox TAILLE_SOL = {TAILLE_FENETRE.x, 100};


const std::string CHEMIN_BOUTON_RETOUR("../images/Home.jpg");
const std::string CHEMIN_BOUTON_PAUSE("../images/Pause.jpg");
const std::string CHEMIN_BACKGROUND_ROUND1("../images/Round2.jpg");
const std::string CHEMIN_BACKGROUND_PAUSE("../images/Pause.jpg");


