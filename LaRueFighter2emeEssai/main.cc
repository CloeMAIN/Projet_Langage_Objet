#include "constant.hh"
#include "Menu.hh"
#include "Jeu.hh"
#include "Afficheur.hh"
#include "ElementJeu.hh"
#include "Personnage.hh"
#include "Projectile.hh"
#include "ProjectileZigZag.hh"
#include "InputUser.hh"
#include "Formulaire.hh"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Afficheur afficheur;
    Menu menu ({CHEMIN_BACKGROUND_MENU, CHEMIN_BACKGROUND_COMMANDES}, {{CHEMIN_BOUTON_JOUER,{TAILLE_BOUTON_JOUER, POSITION_BOUTON_JOUER}},
                                                                    {CHEMIN_BOUTON_COMMANDES,{TAILLE_BOUTON_COMMANDES, POSITION_BOUTON_COMMANDES}}, 
                                                                    {CHEMIN_BOUTON_QUITTER, {TAILLE_BOUTON_QUITTER, POSITION_BOUTON_QUITTER}}, 
                                                                    {CHEMIN_BOUTON_QUESTIONNAIRE, {TAILLE_BOUTON_QUESTIONNAIRE, POSITION_BOUTON_QUESTIONNAIRE}}}); // Remove the parentheses here
    int test = -1;
    
    int Partie = 0;
    
    while(Partie == 0){

        if (test == -1){
            test = menu.lancer(&afficheur);
        }
        
        if (test == 0){
            Jeu jeu;
            //Le jeu lance la partie
            test = jeu.lancer(&afficheur);
            }
            //On affiche le menu dans le cas où le joueur 1 a perdu
        if (test == 1){
            Menu menu ({CHEMIN_BACKGROUND_VICTOIRE_J2,  ""}, {{CHEMIN_BOUTON_REJOUER,{TAILLE_BOUTON_REJOUER, POSITION_BOUTON_REJOUER}},
                                                                {CHEMIN_BOUTON_COMMANDES,{TAILLE_BOUTON_COMMANDES, {-200, -200}}}, 
                                                                {CHEMIN_BOUTON_QUITTER, {TAILLE_BOUTON_QUITTER, POSITION_BOUTON_QUITTER}}, 
                                                                {CHEMIN_BOUTON_QUESTIONNAIRE, {TAILLE_BOUTON_QUESTIONNAIRE, POSITION_BOUTON_QUESTIONNAIRE}}});
            test = menu.lancer(&afficheur);
        }
        //On affiche le menu dans le cas où le joueur 2 a perdu
        if (test == 2){
            Menu menu({CHEMIN_BACKGROUND_VICTOIRE_J1,  ""}, {{CHEMIN_BOUTON_REJOUER,{TAILLE_BOUTON_REJOUER, POSITION_BOUTON_REJOUER}},
                                                                            {CHEMIN_BOUTON_COMMANDES,{TAILLE_BOUTON_COMMANDES, {-200, -200}}}, 
                                                                            {CHEMIN_BOUTON_QUITTER, {TAILLE_BOUTON_QUITTER, POSITION_BOUTON_QUITTER}},
                                                                            {CHEMIN_BOUTON_QUESTIONNAIRE, {TAILLE_BOUTON_QUESTIONNAIRE, POSITION_BOUTON_QUESTIONNAIRE}}});
            test = menu.lancer(&afficheur);
        }
        //Si il n'y a plus de fenêtre ouverte, on quitte le jeu
        if (test == 3){
            Partie = 1;
        }

        if (test == 4){
            // Crée une instance de la classe Formulaire en utilisant les variables QUESTIONS et NB_QUESTIONS
            Formulaire formulaire(QUESTIONS, NB_QUESTIONS);

            // Lance la fonction membre lancer() de la classe Formulaire
            test = formulaire.lancer(&afficheur); 
        }

        if (test == 5){
            //On affichera le menu de victoire du questionnaire
            std::cout << "Victoire du questionnaire" << std::endl;
            Menu menu({CHEMIN_BACKGROUND_VICTOIRE_QUIZZ,  ""}, {{CHEMIN_BOUTON_REJOUER,{TAILLE_BOUTON_REJOUER, POSITION_BOUTON_REJOUER}},
                                                            {CHEMIN_BOUTON_COMMANDES,{TAILLE_BOUTON_COMMANDES, {-200, -200}}}, 
                                                            {CHEMIN_BOUTON_QUITTER, {TAILLE_BOUTON_QUITTER, POSITION_BOUTON_QUITTER}}});
            test = menu.lancer(&afficheur);
        }
        if (test == 6){
            //On affichera le menu de victoire du questionnaire
            std::cout << "Défaite au questionnaire" << std::endl;
            Menu menu({CHEMIN_BACKGROUND_DEFAITE_QUIZZ,  ""}, {{CHEMIN_BOUTON_REJOUER,{TAILLE_BOUTON_REJOUER, POSITION_BOUTON_REJOUER}},
                                                            {CHEMIN_BOUTON_COMMANDES,{TAILLE_BOUTON_COMMANDES, {-200, -200}}}, 
                                                            {CHEMIN_BOUTON_QUITTER, {TAILLE_BOUTON_QUITTER, POSITION_BOUTON_QUITTER}}});
            test = menu.lancer(&afficheur);
        }

        if (afficheur.getWindow()->isOpen() == false){
            Partie = 1;
        }

    }

    return 0;
}