// Let DocTest provide main():
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../Header/Personnage.hh"
#include "../constant.hh"
#include "../Header/InputUser.hh"
#include "../Header/Projectile.hh"
#include "../Header/Question.hh"



  TEST_CASE("Création de personnage"){
    // Affichage console création des personnages et affichage
    std::cout << "" << std::endl;
    std::cout << "--------------------------- Création des personnages --------------------------" << std::endl;
    std::cout << "" << std::endl;
    Personnage joueur1;
    Personnage joueur2;
    joueur1 = Personnage(POSITION_DEPART_JOUEUR1,
                            POINTS_DE_VIE_JOUEUR, 
                            {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_AVANCER, CHEMIN_IMAGE_JOUEUR1_SAUT,CHEMIN_IMAGE_JOUEUR1_ATTAQUE1, CHEMIN_IMAGE_JOUEUR1_ATTAQUE2, CHEMIN_IMAGE_JOUEUR1_ATTAQUE1}, 
                            Direction::DROITE, 
                            TAILLE_JOUEUR_SPRITE,
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first);
    joueur2 = Personnage(POSITION_DEPART_JOUEUR2,
                            POINTS_DE_VIE_JOUEUR,
                            {CHEMIN_IMAGE_JOUEUR2_RIEN, CHEMIN_IMAGE_JOUEUR2_AVANCER,
                             CHEMIN_IMAGE_JOUEUR2_SAUT,CHEMIN_IMAGE_JOUEUR2_ATTAQUE1,
                             CHEMIN_IMAGE_JOUEUR2_ATTAQUE2, CHEMIN_IMAGE_JOUEUR2_ATTAQUE1}, 
                            Direction::GAUCHE,
                            TAILLE_JOUEUR_SPRITE, 
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first);

    std::cout << "Personnage 1 : \n " << joueur1.toString() << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Personnage 2 : \n " << joueur2.toString() << std::endl;
    // utilisation to string


    CHECK(joueur1.getVie() == POINTS_DE_VIE_JOUEUR);
    CHECK(joueur1.getDirection() == Direction::DROITE);
    CHECK(joueur1.getEtat()["Rien"].first == true);

    CHECK(joueur2.getVie() == POINTS_DE_VIE_JOUEUR);
    CHECK(joueur2.getDirection() == Direction::GAUCHE);
    CHECK(joueur2.getEtat()["Rien"].first == true);

  // Additional checks for default values
    CHECK(joueur1.getPosition().x == POSITION_DEPART_JOUEUR1.x);
    CHECK(joueur1.getPosition().y == POSITION_DEPART_JOUEUR1.y);
    CHECK(joueur1.getVelocity() == sf::Vector2f(0.0f, 0.0f));

    CHECK(joueur2.getPosition().x == POSITION_DEPART_JOUEUR2.x);
    CHECK(joueur2.getPosition().y == POSITION_DEPART_JOUEUR2.y);
    CHECK(joueur2.getVelocity() == sf::Vector2f(0.0f, 0.0f));
  }

TEST_CASE("Entrées utilisateur et état joueur"){
    Personnage joueur;
    InputUser input;
    joueur = Personnage(POSITION_DEPART_JOUEUR1,
                            POINTS_DE_VIE_JOUEUR, 
                            {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_AVANCER, CHEMIN_IMAGE_JOUEUR1_SAUT,CHEMIN_IMAGE_JOUEUR1_ATTAQUE1, CHEMIN_IMAGE_JOUEUR1_ATTAQUE2, CHEMIN_IMAGE_JOUEUR1_ATTAQUE1}, 
                            Direction::DROITE, 
                            TAILLE_JOUEUR_SPRITE,
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first);

 
  input.checkSaut(joueur);
  CHECK(joueur.getEtat()["Saut"].first == true);
  CHECK(joueur.getEtat()["Rien"].first == false);
  CHECK(joueur.getVelocity().y == VITESSE_JOUEUR_SAUT);

  input.checkAttaque1(joueur);
  CHECK(joueur.getEtat()["Attaque1"].first == true);
  CHECK(joueur.getEtat()["Rien"].first == false);

  input.checkAttaque2(joueur);
  CHECK(joueur.getEtat()["Attaque2"].first == true);
  CHECK(joueur.getEtat()["Rien"].first == false);


  input.checkGauche(joueur);
  CHECK(joueur.getDirection() == Direction::GAUCHE);

  input.checkDroite(joueur);
  CHECK(joueur.getDirection() == Direction::DROITE);

}
TEST_CASE("Projectiles"){

  std::cout << "" << std::endl;
  std::cout << "--------------------------- Création des projectiles --------------------------" << std::endl;
  std::cout << "" << std::endl;

  //créer un projectile
  ProjectileLineaire projectileLineaire = ProjectileLineaire({0,0}, VITESSE_DIRECT, DEGAT_DIRECT, RAYON_DIRECT, CHEMIN_IMAGE_DIRECT, Direction::DROITE);

  // Affichage toString du projectile
  std::cout << "Projectile : \n " << projectileLineaire.toString() << std::endl;

  ProjectileZigZag ProjectileZigZagg = ProjectileZigZag({0,0}, VITESSE_ZIGZAG, DEGAT_ZIGZAG, RAYON_ZIGZAG, CHEMIN_IMAGE_ZIGZAG, AMPLITUDE_ZIGZAG, ANGLE_TIR_ZIGZAG, FREQUENCE_ZIGZAG , Direction::DROITE);

  // Affichage toString du projectile
  std::cout << "Projectile : \n " << projectileLineaire.toString() << std::endl;


  Personnage joueur1;
  joueur1 = Personnage(POSITION_DEPART_JOUEUR1,
                            POINTS_DE_VIE_JOUEUR, 
                            {CHEMIN_IMAGE_JOUEUR1_RIEN, CHEMIN_IMAGE_JOUEUR1_AVANCER, CHEMIN_IMAGE_JOUEUR1_SAUT,CHEMIN_IMAGE_JOUEUR1_ATTAQUE1, CHEMIN_IMAGE_JOUEUR1_ATTAQUE2, CHEMIN_IMAGE_JOUEUR1_ATTAQUE1}, 
                            Direction::DROITE, 
                            TAILLE_JOUEUR_SPRITE,
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first);

  CHECK(joueur1.getListeProjectiles().size() == 0);
  joueur1.setEtat("Projectile",true);
  joueur1.GestionProjectileLineaire();
  CHECK(joueur1.getListeProjectiles().size() == 1);

  Personnage joueur2;
  joueur2 = Personnage(POSITION_DEPART_JOUEUR2,
                            POINTS_DE_VIE_JOUEUR,
                            {CHEMIN_IMAGE_JOUEUR2_RIEN, CHEMIN_IMAGE_JOUEUR2_AVANCER,
                             CHEMIN_IMAGE_JOUEUR2_SAUT,CHEMIN_IMAGE_JOUEUR2_ATTAQUE1,
                             CHEMIN_IMAGE_JOUEUR2_ATTAQUE2, CHEMIN_IMAGE_JOUEUR2_ATTAQUE1}, 
                            Direction::GAUCHE,
                            TAILLE_JOUEUR_SPRITE, 
                            CHEMIN_IMAGE_JOUEUR1_RIEN.first);

  CHECK(joueur2.getListeProjectiles().size() == 0);
  joueur2.setEtat("Projectile",true);
  joueur2.GestionProjectileZigZag();
    CHECK(joueur1.getListeProjectiles().size() == 1);



}

TEST_CASE("Question"){
  // Création d'une instance de la classe Question
  Question question = Question(QUESTION1, FORMAT1, REPONSE1, BACKGROUND1, CHEMIN_QUESTION1);

  // Vérification des getters
    CHECK(question.getQuestion() == QUESTION1);
    CHECK(question.getFormatReponse() == FORMAT1);
    CHECK(question.getReponse() == REPONSE1);
    CHECK(question.getBackground() == BACKGROUND1);
    CHECK(question.getCheminImageQuestion() == CHEMIN_QUESTION1);

}