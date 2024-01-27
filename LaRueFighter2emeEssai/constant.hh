#pragma once
#include <array>
#include <string>
#include <list>
#include "Formulaire.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ElementJeu.hh"

// Taille fenêtre
const sf::Vector2f TAILLE_FENETRE = sf::Vector2f(static_cast<float>(sf::VideoMode::getDesktopMode().width), static_cast<float>(sf::VideoMode::getDesktopMode().height));

// Taille du sol
const int HAUTEUR_SOL = 100;

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
const Point POSITION_DEPART_JOUEUR2 = {float(TAILLE_FENETRE.x)/3 * 2,0};

// Barre de vie
const Point POSITION_BARRE_J2 = {float(TAILLE_FENETRE.x)-1020,float(20)};
const sf::Color COULEUR_BARRE_J2 = sf::Color::Blue;


// Chemin des images
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_RIEN ={"images/Fighter2/Idle_Right2.png","images/Fighter2/Idle_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_AVANCER = {"images/Fighter2/Walk_Right2.png","images/Fighter2/Walk_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_SAUT = {"images/Fighter2/Jump_Right2.png","images/Fighter2/Jump_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_ATTAQUE1= {"images/Fighter2/Fist_Right2.png","images/Fighter2/Fist_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_ATTAQUE2 = {"images/Fighter2/Foot_Right2.png","images/Fighter2/Foot_Left2.png"};

// Nombre d'images par animation
// const int NB_IMAGE_SPRITE_SAUT = 1;
// const int NB_IMAGE_SPRITE_RIEN = 6;
// const int NB_IMAGE_SPRITE_AVANCER = 8;
// const int NB_IMAGE_ATTAQUE1 = 1;
// const int NB_IMAGE_ATTAQUE2 = 1;

/*------------------------------------Attaques---------------------------------*/

//Attaques physiques (mêmes pour les deux joueurs)
const float DEGAT_ATTAQUE1 = 100;
const float DEGAT_ATTAQUE2 = 150;
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
const float DEGAT_DIRECT = 300;

//Projectiles: ZigZag
const float VITESSE_ZIGZAG = 200;
const float DEGAT_ZIGZAG = 250;
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
const std::string CHEMIN_BOUTON_QUESTIONNAIRE("images/Questionnaire.png");

//Position des boutons:
const Point POSITION_BOUTON_JOUER = {float(TAILLE_FENETRE.x)/2 -100 , float(TAILLE_FENETRE.y) - 325};
const Point POSITION_BOUTON_COMMANDES = { float(TAILLE_FENETRE.x) / 2 - 100 , float(TAILLE_FENETRE.y)- 225};
const Point POSITION_BOUTON_QUITTER = {float(TAILLE_FENETRE.x)/2 - 100, float(TAILLE_FENETRE.y) - 125};
const Point POSITION_BOUTON_QUESTIONNAIRE = {float(TAILLE_FENETRE.x)/2 - 100, float(TAILLE_FENETRE.y) - 425};

//Taille des boutons:
const HitBox TAILLE_BOUTON_QUITTER = {POSITION_BOUTON_QUITTER.x, POSITION_BOUTON_QUITTER.y, POSITION_BOUTON_QUITTER.x+200 , POSITION_BOUTON_QUITTER.y+100 };
const HitBox TAILLE_BOUTON_COMMANDES = { POSITION_BOUTON_COMMANDES.x, POSITION_BOUTON_COMMANDES.y , POSITION_BOUTON_COMMANDES.x+200 , POSITION_BOUTON_COMMANDES.y+100 };
const HitBox TAILLE_BOUTON_JOUER = { POSITION_BOUTON_JOUER.x, POSITION_BOUTON_JOUER.y , POSITION_BOUTON_JOUER.x+200 , POSITION_BOUTON_JOUER.y+100};
const HitBox TAILLE_BOUTON_QUESTIONNAIRE = { POSITION_BOUTON_QUESTIONNAIRE.x, POSITION_BOUTON_QUESTIONNAIRE.y , POSITION_BOUTON_QUESTIONNAIRE.x+200 , POSITION_BOUTON_QUESTIONNAIRE.y+100};



/*------------------------------------JEU PRINCIPAL----------------------------------*/


const Point POSITION_BOUTON_RETOUR = {0, 0};
const Point POSITION_BOUTON_PAUSE = {float(TAILLE_FENETRE.x) - 300, 0};
const Point POSITION_SOL = {0, float(TAILLE_FENETRE.y) - HAUTEUR_SOL};

const int NB_PLATEFORMES = 4;
const Point POSITION_PLATEFORME1 = {float(TAILLE_FENETRE.x)/2 + 250, float(TAILLE_FENETRE.y) - 500};
const Point POSITION_PLATEFORME2 = {float(TAILLE_FENETRE.x)/2 - 200 , float(TAILLE_FENETRE.y) - 700};
const Point POSITION_PLATEFORME3 = {float(TAILLE_FENETRE.x)/2 - 500 , float(TAILLE_FENETRE.y) - 450};
const Point POSITION_PLATEFORME4 = {float(TAILLE_FENETRE.x) - 500 , float(TAILLE_FENETRE.y) - 200};

const Taille TAILLE_PLATEFORME = {float(TAILLE_FENETRE.x)/8, 25};
const HitBox PLATEFORME = {POSITION_PLATEFORME1.x, POSITION_PLATEFORME1.y, POSITION_PLATEFORME1.x + TAILLE_PLATEFORME.largeur, POSITION_PLATEFORME1.y + TAILLE_PLATEFORME.hauteur};
//Taille des boutons:
// const HitBox TAILLE_BOUTON_RETOUR = { 80 , 80 };
// const HitBox TAILLE_BOUTON_PAUSE = { 80 , 80 };
// const HitBox TAILLE_SOL = {TAILLE_FENETRE.x, 100};

const std::vector<std::string> CHEMIN_IMAGE_PARTIE = {"images/LEVEL1.png", "images/LEVEL2.png", "images/LEVEL3.png", "images/LEVEL4.png"};
const int NB_BACKGROUND = 4;

const std::string CHEMIN_BOUTON_RETOUR("../images/Home.jpg");
const std::string CHEMIN_BOUTON_PAUSE("../images/Pause.jpg");
const std::string CHEMIN_BACKGROUND_ROUND1("../images/Round2.jpg");
const std::string CHEMIN_BACKGROUND_PAUSE("../images/Pause.jpg");
const std::string CHEMIN_PLATEFORME("images/plateformes.png");

/* Background aléatoire*/
const std::vector<std::string> CHEMIN_BACKGROUNDS_RANDOM = {"images/background_jeu/louvre.png", "images/background_jeu/triomphe.png"};

/*-----------------------------------MENU DE VICTOIRE-----------------------------------------*/
// Chemins des images:
const std::string CHEMIN_BACKGROUND_VICTOIRE_J1("images/Victoire_J1.png");
const std::string CHEMIN_BACKGROUND_VICTOIRE_J2("images/Victoire_J1.png");

const std::string CHEMIN_BOUTON_REJOUER("images/Rejouer.png");

//Position des boutons:
const Point POSITION_BOUTON_REJOUER = {float(TAILLE_FENETRE.x)/2 -100 , float(TAILLE_FENETRE.y) - 325};

//Taille des boutons:
const HitBox TAILLE_BOUTON_REJOUER = { POSITION_BOUTON_JOUER.x, POSITION_BOUTON_JOUER.y , POSITION_BOUTON_JOUER.x+200 , POSITION_BOUTON_JOUER.y+100};

/*-----------------------------------QUESTIONS POUR FORMULAIRE-----------------------------------------*/

const std::string QUESTION1 = "Qui est le Judoka le plus médaillé aux JO et combien de médaille d\'or a-t-il remporté ?";
const std::string FORMAT1 = "Nom Prénom, nombre";
const std::string REPONSE1 = "Tadahiro Nomura,3";
const std::string BACKGROUND1 = "Louvres";

const std::string QUESTION2 = "En quelle année le Judo a été introduit en tant que sport olympique ? ";
const std::string FORMAT2 = "Année";
const std::string REPONSE2 = "1964";
const std::string BACKGROUND2 = "Tour Eiffel";

const std::string QUESTION3 = "Le Judo féminin est arrivé plus tard que le masculin, en quelle année était-ce ?";
const std::string FORMAT3 = "Année";
const std::string REPONSE3 = "1988";
const std::string BACKGROUND3 = "Arc de Triomphe";

const std::string QUESTION4 = "Sérénité, Gentillesse, Politesse, Contrôle de soi, Honneur, Amis, et Respect des autres sont les 7 maximes du Judo. L’une d’entre elles est apparut, laquelle ?";
const std::string FORMAT4 = "Maxime";
const std::string REPONSE4 = "Sérénité";
const std::string BACKGROUND4 = "Notre Dame";

const Question QUESTIONA = Question(QUESTION1, FORMAT1, REPONSE1, BACKGROUND1);
const Question QUESTIONB = Question(QUESTION2, FORMAT2, REPONSE2, BACKGROUND2);
const Question QUESTIONC = Question(QUESTION3, FORMAT3, REPONSE3, BACKGROUND3);
const Question QUESTIOND = Question(QUESTION4, FORMAT4, REPONSE4, BACKGROUND4);

const std::list<Question> QUESTIONS = {QUESTIONA, QUESTIONB, QUESTIONC, QUESTIOND};
const int NB_QUESTIONS = 4;
