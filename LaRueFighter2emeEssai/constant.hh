#ifndef CONSTANT_HH
#define CONSTANT_HH

#pragma once
#include <array>
#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Header/ElementJeu.hh"
#include "Header/Question.hh"

// Taille fenêtre
const sf::Vector2f TAILLE_FENETRE = sf::Vector2f(static_cast<float>(sf::VideoMode::getDesktopMode().width), static_cast<float>(sf::VideoMode::getDesktopMode().height));

// Taille du sol
const int HAUTEUR_SOL = TAILLE_FENETRE.y/10;
const Point POSITION_SOL = {0, TAILLE_FENETRE.y - HAUTEUR_SOL};

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
const Taille TAILLE_JOUEUR_SPRITE = {float(TAILLE_FENETRE.x)/20, float(float(TAILLE_FENETRE.y)/6.5)};
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
const sf::Color COULEUR_BARRE_J1 = sf::Color(255, 165, 0); // Orange


// Chemin des ../images  ../images/Fighter/Idle_Rightb.png
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_RIEN ={"../images/Fighter/Idle_Rightb.png","../images/Fighter/Idle_Leftb.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_AVANCER = {"../images/Fighter/Walk_Right.png","../images/Fighter/Walk_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_SAUT = {"../images/Fighter/Saut_Right.png","../images/Fighter/Saut_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_ATTAQUE1= {"../images/Fighter/Fist_Right.png","../images/Fighter/Fist_Left.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR1_ATTAQUE2 = {"../images/Fighter/Foot_Right.png","../images/Fighter/Foot_Left.png"};

// Nombre d'../images par animation
const int NB_IMAGE_SPRITE_SAUT = 1;
const int NB_IMAGE_SPRITE_RIEN = 1;
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
const float TAILLE_INITIALE = float(float(TAILLE_FENETRE.x)/2.5);

const Point POSITION_BARRE_J2 = {float(TAILLE_FENETRE.x)-TAILLE_INITIALE -20 ,float(20)};
const sf::Color COULEUR_BARRE_J2 = sf::Color::Blue;


// Chemin des ../images
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_RIEN ={"../images/Fighter2/Idle_Right2.png","../images/Fighter2/Idle_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_AVANCER = {"../images/Fighter2/Walk_Right2.png","../images/Fighter2/Walk_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_SAUT = {"../images/Fighter2/Jump_Right2.png","../images/Fighter2/Jump_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_ATTAQUE1= {"../images/Fighter2/Fist_Right2.png","../images/Fighter2/Fist_Left2.png"};
const std::pair<std::string,std::string> CHEMIN_IMAGE_JOUEUR2_ATTAQUE2 = {"../images/Fighter2/Foot_Right2.png","../images/Fighter2/Foot_Left2.png"};

/*------------------------------------Attaques---------------------------------*/

//Attaques physiques (mêmes pour les deux joueurs)
const float DEGAT_ATTAQUE1 = 25;
const float DEGAT_ATTAQUE2 = 50;
const float DECALAGE_Y_PIED = 65;
const float DECALAGE_Y_POING = 55;
const Taille TAILLE_ATTAQUE1= {40, 20};
const Taille TAILLE_ATTAQUE2 = {50, 20};
const float RECUL_ATTAQUE1 = float(TAILLE_FENETRE.x)/10;
const float RECUL_ATTAQUE2 = float(TAILLE_FENETRE.x)/10;

//Temps de blocage des attaques (mêmes pour les deux joueurs)
const float TEMPS_BLOCAGE_ATTAQUE = 0.3;
const float TEMPS_BLOCAGE_PROJECTILE = 2;

//Projectiles: Direct
const int RAYON_DIRECT = 5;
const float VITESSE_DIRECT = 400;
const float DEGAT_DIRECT = 125;

//Projectiles: ZigZag
const float VITESSE_ZIGZAG = 200;
const float DEGAT_ZIGZAG = 100;
const float RAYON_ZIGZAG = 5;
const double AMPLITUDE_ZIGZAG = 300;
const double ANGLE_TIR_ZIGZAG = 90;
const double FREQUENCE_ZIGZAG = 3;

// Chemin des ../images
const std::string CHEMIN_IMAGE_ZIGZAG =  "../images/projectile.jpg";
const std::string CHEMIN_IMAGE_DIRECT =  "../images/projectile.jpg";

/*-----------------------------------MENU DU DEBUT-----------------------------------------*/
// Chemins des ../images:
const std::string CHEMIN_BACKGROUND_MENU("../images/BackgroundMenu.jpg");
const std::string CHEMIN_BOUTON_JOUER("../images/Jouer.jpg");
const std::string CHEMIN_BOUTON_QUITTER("../images/Quitter.jpg");
const std::string CHEMIN_BOUTON_COMMANDES("../images/Commandes.jpg");
const std::string CHEMIN_BACKGROUND_COMMANDES("../images/BackgroundCommandes.png");
const std::string CHEMIN_BOUTON_QUESTIONNAIRE("../images/Questionnaire.png");

//Position des boutons:
const Point POSITION_BOUTON_JOUER = {float(TAILLE_FENETRE.x)/2 - float(TAILLE_FENETRE.x)/6 , float(TAILLE_FENETRE.y)/2 + float(TAILLE_FENETRE.y)/6};
const Point POSITION_BOUTON_COMMANDES = { float(TAILLE_FENETRE.x) / 2 - float(TAILLE_FENETRE.x)/6  , float(TAILLE_FENETRE.y)/2 + float(TAILLE_FENETRE.y)/3};
const Point POSITION_BOUTON_QUITTER = {float(TAILLE_FENETRE.x)/2 +float(TAILLE_FENETRE.x)/6 - float(TAILLE_FENETRE.x)/10, float(TAILLE_FENETRE.y)/2+ float(TAILLE_FENETRE.y)/6};
const Point POSITION_BOUTON_QUESTIONNAIRE = {float(TAILLE_FENETRE.x)/2 + float(TAILLE_FENETRE.x)/6 - float(TAILLE_FENETRE.x)/10, float(TAILLE_FENETRE.y)/2 + float(TAILLE_FENETRE.y)/3};

//Taille des boutons:
const HitBox TAILLE_BOUTON_QUITTER = {POSITION_BOUTON_QUITTER.x, POSITION_BOUTON_QUITTER.y, POSITION_BOUTON_QUITTER.x+ float(TAILLE_FENETRE.x)/10, POSITION_BOUTON_QUITTER.y + float(TAILLE_FENETRE.y)/10};
const HitBox TAILLE_BOUTON_COMMANDES = { POSITION_BOUTON_COMMANDES.x, POSITION_BOUTON_COMMANDES.y , POSITION_BOUTON_COMMANDES.x+200 , POSITION_BOUTON_COMMANDES.y+ float(TAILLE_FENETRE.y)/10 };
const HitBox TAILLE_BOUTON_JOUER = { POSITION_BOUTON_JOUER.x, POSITION_BOUTON_JOUER.y , POSITION_BOUTON_JOUER.x+200 , POSITION_BOUTON_JOUER.y+ float(TAILLE_FENETRE.y)/10};
const HitBox TAILLE_BOUTON_QUESTIONNAIRE = { POSITION_BOUTON_QUESTIONNAIRE.x, POSITION_BOUTON_QUESTIONNAIRE.y , POSITION_BOUTON_QUESTIONNAIRE.x+200 , POSITION_BOUTON_QUESTIONNAIRE.y + float(TAILLE_FENETRE.y)/10};


/*------------------------------------JEU PRINCIPAL----------------------------------*/

//Plateformes
const int NB_PLATEFORMES = 2;
const Point POSITION_PLATEFORME1 = {float(TAILLE_FENETRE.x)/2  - 3*float(TAILLE_FENETRE.x)/8, float(TAILLE_FENETRE.y)/2 + 200};
const Point POSITION_PLATEFORME2 = {float(TAILLE_FENETRE.x)/2  + float(TAILLE_FENETRE.x)/8, float(TAILLE_FENETRE.y)/2 + 200};

const Taille TAILLE_PLATEFORME = {float(TAILLE_FENETRE.x)/4, 25};
const HitBox PLATEFORME = {POSITION_PLATEFORME1.x, POSITION_PLATEFORME1.y, POSITION_PLATEFORME1.x + TAILLE_PLATEFORME.largeur, POSITION_PLATEFORME1.y + TAILLE_PLATEFORME.hauteur};

const std::vector<std::string> CHEMIN_IMAGE_PARTIE = {"../images/LEVEL1.png", "../images/LEVEL2.png", "../images/LEVEL3.png", "../images/LEVEL4.png"};
const int NB_BACKGROUND = 4;

const std::string CHEMIN_PLATEFORME("../images/plateformes.png");
const std::string CHEMIN_SOL("../images/Sol.png");

/*-----------------------------------MENU DE VICTOIRE-----------------------------------------*/
// Chemins des ../images:
const std::string CHEMIN_BACKGROUND_VICTOIRE_J1("../images/Victoire_J1.png");
const std::string CHEMIN_BACKGROUND_VICTOIRE_J2("../images/Victoire_J2.png");
const std::string CHEMIN_BACKGROUND_VICTOIRE_QUIZZ("../images/Victoire_Quizz.png");
const std::string CHEMIN_BACKGROUND_DEFAITE_QUIZZ("../images/Defaite_Quizz.png");

const std::string CHEMIN_BOUTON_REJOUER("../images/Rejouer.png");

//Position des boutons:
const Point POSITION_BOUTON_REJOUER = {float(TAILLE_FENETRE.x)/2 - float(TAILLE_FENETRE.x)/6 , float(TAILLE_FENETRE.y)/2 + float(TAILLE_FENETRE.y)/6};
//Taille des boutons:
const HitBox TAILLE_BOUTON_REJOUER = { POSITION_BOUTON_JOUER.x, POSITION_BOUTON_JOUER.y , POSITION_BOUTON_JOUER.x+200 , POSITION_BOUTON_JOUER.y+ float(TAILLE_FENETRE.y)/10};

/*-----------------------------------QUESTIONS POUR FORMULAIRE-----------------------------------------*/

const std::string QUESTION1 = "Qui est le Judoka le plus médaillé aux JO et combien de médaille d\'or a-t-il remporté ?";
const std::string FORMAT1 = "Nom Prénom, nombre";
const std::string REPONSE1 = "Tadahiro Nomura,3";
const std::string BACKGROUND1 = "Louvres";
const std::string CHEMIN_QUESTION1 = "../images/Questions/Question1.png";

const std::string QUESTION2 = "En quelle année le Judo a été introduit en tant que sport olympique ? ";
const std::string FORMAT2 = "Année";
const std::string REPONSE2 = "1964";
const std::string BACKGROUND2 = "Tour Eiffel";
const std::string CHEMIN_QUESTION2 = "../images/Questions/Question2.png";


const std::string QUESTION3 = "Le Judo féminin est arrivé plus tard que le masculin, en quelle année était-ce ?";
const std::string FORMAT3 = "Année";
const std::string REPONSE3 = "1988";
const std::string BACKGROUND3 = "Arc de Triomphe";
const std::string CHEMIN_QUESTION3 = "../images/Questions/Question3.png";


const std::string QUESTION4 = "Sérénité, Gentillesse, Politesse, Contrôle de soi, Honneur, Amis, et Respect des autres sont les 7 maximes du Judo. L’une d’entre elles est apparut, laquelle ?";
const std::string FORMAT4 = "Maxime";
const std::string REPONSE4 = "Sérénité";
const std::string BACKGROUND4 = "Notre Dame";
const std::string CHEMIN_QUESTION4 = "../images/Questions/Question4.png";


const Question QUESTIONA = Question(QUESTION1, FORMAT1, REPONSE1, BACKGROUND1, CHEMIN_QUESTION1);
const Question QUESTIONB = Question(QUESTION2, FORMAT2, REPONSE2, BACKGROUND2, CHEMIN_QUESTION2);
const Question QUESTIONC = Question(QUESTION3, FORMAT3, REPONSE3, BACKGROUND3, CHEMIN_QUESTION3);
const Question QUESTIOND = Question(QUESTION4, FORMAT4, REPONSE4, BACKGROUND4, CHEMIN_QUESTION4);

const std::list<Question> QUESTIONS = {QUESTIONA, QUESTIONB, QUESTIONC, QUESTIOND};
const int NB_QUESTIONS = 4;

//Boutons pour les background :
const std::string NOTRE_DAME = "../images/Questions/Notre Dame.png";
const std::string LOUVRES = "../images/Questions/Louvres.png";
const std::string TOUR_EIFFEL = "../images/Questions/Tour Eiffel.png";
const std::string ARC_DE_TRIOMPHE = "../images/Questions/Arc de Triomphe.png";
const std::string VALIDE = "../images/Questions/Valide.png";
const std::string CHEMIN_PRESENTATION_FORMULAIRE = "../images/Questions/PrestentationFormulaire.png";

const Point POSITION_NOTRE_DAME = {150, float(TAILLE_FENETRE.y) - 450};
const Point POSITION_LOUVRES = {170 + float(TAILLE_FENETRE.x)/5, float(TAILLE_FENETRE.y) - 450};
const Point POSITION_TOUR_EIFFEL = {150, float(TAILLE_FENETRE.y) - 300};
const Point POSITION_ARC_DE_TRIOMPHE = {170+ float(TAILLE_FENETRE.x)/5, float(TAILLE_FENETRE.y) - 300};
const Point POSITION_VALIDE = {float(TAILLE_FENETRE.x)/2-float(TAILLE_FENETRE.x)/10,float(TAILLE_FENETRE.y)/2 + float(TAILLE_FENETRE.y)/3};
const Point POSITION_BOUTON_QUITTER_QUESTIONNAIRE = {float(TAILLE_FENETRE.x)/2 + float(TAILLE_FENETRE.x)/6 - float(TAILLE_FENETRE.x)/10, float(TAILLE_FENETRE.y)/2 + float(TAILLE_FENETRE.y)/3};

const HitBox TAILLE_NOTRE_DAME = {POSITION_NOTRE_DAME.x, POSITION_NOTRE_DAME.y, POSITION_NOTRE_DAME.x + float(TAILLE_FENETRE.x)/5, POSITION_NOTRE_DAME.y + 50};
const HitBox TAILLE_LOUVRES = {POSITION_LOUVRES.x, POSITION_LOUVRES.y, POSITION_LOUVRES.x + float(TAILLE_FENETRE.x)/5, POSITION_LOUVRES.y + 50};
const HitBox TAILLE_TOUR_EIFFEL = {POSITION_TOUR_EIFFEL.x, POSITION_TOUR_EIFFEL.y, POSITION_TOUR_EIFFEL.x + float(TAILLE_FENETRE.x)/5, POSITION_TOUR_EIFFEL.y + 50};
const HitBox TAILLE_ARC_DE_TRIOMPHE = {POSITION_ARC_DE_TRIOMPHE.x, POSITION_ARC_DE_TRIOMPHE.y, POSITION_ARC_DE_TRIOMPHE.x + float(TAILLE_FENETRE.x)/5, POSITION_ARC_DE_TRIOMPHE.y + 50};
const HitBox TAILLE_VALIDE = {POSITION_VALIDE.x, POSITION_VALIDE.y, POSITION_VALIDE.x +200 , POSITION_VALIDE.y + float(TAILLE_FENETRE.y)/10};
const HitBox TAILLE_BOUTON_QUITTER_QUESTIONNAIRE = { POSITION_BOUTON_QUESTIONNAIRE.x, POSITION_BOUTON_QUESTIONNAIRE.y , POSITION_BOUTON_QUESTIONNAIRE.x+200 , POSITION_BOUTON_QUESTIONNAIRE.y + float(TAILLE_FENETRE.y)/10};

#endif // CONSTANT_HH