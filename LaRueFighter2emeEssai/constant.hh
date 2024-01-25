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

// Tests
const bool DEBUGGING_MODE = true;
const sf::Keyboard::Key TOUCHE_DEGAT_J1 = sf::Keyboard::A;
const sf::Keyboard::Key TOUCHE_DEGAT_J2 = sf::Keyboard::B;


// Barre de vie
const Point POSITION_BARRE_J1 = {float(20),float(20)};
const Point POSITION_BARRE_J2 = {float(TAILLE_FENETRE.x)-1020,float(20)};
const sf::Color COULEUR_BARRE_J1 = sf::Color::Red;
const sf::Color COULEUR_BARRE_J2 = sf::Color::Blue;

// Personnages: Joueur 1
const float POINTS_DE_VIE_JOUEUR1 = 3500;
const float DEGAT_ATTAQUE_POING1 = 5;
const float DEGAT_ATTAQUE_PIED1 = 5;
const Taille TAILLE_JOUEUR1_SPRITE = {70, 164};
const Point POSITION_DEPART_JOUEUR1 = {float(TAILLE_FENETRE.x)/3, float(TAILLE_FENETRE.y)-HAUTEUR_SOL- TAILLE_JOUEUR1_SPRITE.hauteur};
const float VITESSE_JOUEUR1 = 5;
const float VITESSE_JOUEUR1_SAUT = -32.0f;
const float DECALAGE_Y_PIED = 20;
const float DECALAGE_Y_POING = 30;
const Taille TAILLE_COUP_POING = {50, 20};
const Taille TAILLE_COUP_PIED = {70, 30};


//Commandes Joueur1
const sf::Keyboard::Key TOUCHE_SAUT_JOUEUR1 = sf::Keyboard::Z;
const sf::Keyboard::Key TOUCHE_GAUCHE_JOUEUR1 = sf::Keyboard::Q;
const sf::Keyboard::Key TOUCHE_DROITE_JOUEUR1 = sf::Keyboard::D;
const sf::Keyboard::Key TOUCHE_PROJECTILE_JOUEUR1 = sf::Keyboard::LShift;
const sf::Keyboard::Key TOUCHE_ATTAQUE1_JOUEUR1 = sf::Keyboard::G;
const sf::Keyboard::Key TOUCHE_ATTAQUE2_JOUEUR1 = sf::Keyboard::H;

//Commandes Joueur2
const sf::Keyboard::Key TOUCHE_SAUT_JOUEUR2 = sf::Keyboard::Up;
const sf::Keyboard::Key TOUCHE_GAUCHE_JOUEUR2 = sf::Keyboard::Left;
const sf::Keyboard::Key TOUCHE_DROITE_JOUEUR2 = sf::Keyboard::Right;
const sf::Keyboard::Key TOUCHE_PROJECTILE_JOUEUR2 = sf::Keyboard::RShift;
const sf::Keyboard::Key TOUCHE_ATTAQUE1_JOUEUR2 = sf::Keyboard::P;
const sf::Keyboard::Key TOUCHE_ATTAQUE2_JOUEUR2 = sf::Keyboard::M;




// Personnages: Joueur 2
const float POINTS_DE_VIE_JOUEUR2 = 3500;
const float DEGAT_ATTAQUE_POING2 = 5;
const float DEGAT_ATTAQUE_PIED2 = 5;
// Taille TAILLE_JOUEUR2_SPRITE = {35, 82};
const Point POSITION_DEPART_JOUEUR2 = {float(TAILLE_FENETRE.x)/3 * 2,float(TAILLE_FENETRE.y)-HAUTEUR_SOL-TAILLE_JOUEUR1_SPRITE.hauteur};


const float TEMPS_BLOCAGE_PROJECTILE = 2;
const float TEMPS_BLOCAGE_ATTAQUE = 1;

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
const std::string CHEMIN_IMAGE_ZIGZAG =  "images/projectile.jpg";
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


const std::string CHEMIN_IMAGE_JOUEUR1_RIEN ="images/Fighter/Idle_Left.png";
const std::string CHEMIN_IMAGE_JOUEUR1_DROITE = "images/Fighter/Walk_Right.png";
const std::string CHEMIN_IMAGE_JOUEUR1_SAUT = "images/Fighter/Saut.png";
const std::string CHEMIN_IMAGE_JOUEUR1_POING_DROITE = "images/Fighter/Fist.png";
const std::string CHEMIN_IMAGE_JOUEUR1_PIED_DROITE = "images/Fighter/Foot.png";

const std::string CHEMIN_BOUTON_RETOUR("../images/Home.jpg");
const std::string CHEMIN_BOUTON_PAUSE("../images/Pause.jpg");
const std::string CHEMIN_BACKGROUND_ROUND1("../images/Round2.jpg");
const std::string CHEMIN_BACKGROUND_PAUSE("../images/Pause.jpg");


