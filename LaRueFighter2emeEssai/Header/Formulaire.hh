#ifndef FORMULAIRE_HH
#define FORMULAIRE_HH

#pragma once
#include "Question.hh"
#include "Afficheur.hh"
#include "InputUser.hh"
#include <list>
#include <string>

class Afficheur;

class Question;

class Formulaire 
{
    private : 
        std::list<Question> questions;
        int score;
        int nbQuestions;
        std::string pseudo;
        int questionCourante;
    
    public:
        Formulaire(std::list<Question> questions, int nbQuestions);
        ~Formulaire(){};

        //Getter
        int getScore(){return score;};
        int getNbQuestions(){return nbQuestions;};
        std::string getPseudo(){return pseudo;};
        std::list<Question> getQuestions(){return questions;};
        int getQuestionCourante(){return questionCourante;};

        //Setter
        void setScore(int score);
        void setNbQuestions(int nbQuestions);
        void setPseudo(std::string pseudo);
        void setQuestions(std::list<Question> questions);
        void setQuestionCourante(int questionCourante);

        //Méthode
        int lancer(Afficheur* afficheur);
        void debutLancer();
        void majFormulaire(std::string* reponseUtilisateur, std::string* backgroundUtilisateur, int* etape, bool* finquestion, sf::Text* rep);
        int finLancer(Afficheur* afficheur);
        void genererText(sf::Text* text);
        int bouclelancer(int* etape, sf::Text* text, sf::Text* rep, bool* finquestion, std::string* Reponse, std::string* Background, Afficheur* afficheur, InputUser* inputUser);


};

#endif // FORMULAIRE_HH