#ifndef FORMULAIRE_HH
#define FORMULAIRE_HH

#pragma once
#include "Question.hh"
#include "Afficheur.hh"
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
        std::string nom;
        std::string prenom;
    
    public:
        Formulaire(std::list<Question> questions, int nbQuestions);
        ~Formulaire(){};

        //Getter
        int getScore();
        int getNbQuestions();
        std::string getNom();
        std::string getPrenom();
        std::list<Question> getQuestions();

        //Setter
        void setScore(int score);
        void setNbQuestions(int nbQuestions);
        void setNom(std::string nom);
        void setPrenom(std::string prenom);
        void setQuestions(std::list<Question> questions);

        //Méthode
        int lancer(Afficheur* afficheur);
        void debutLancer();
        void boucleLancer(int i);
        int finLancer(Afficheur* afficheur);


};

#endif // FORMULAIRE_HH