#pragma once
#include "Question.hh"
#include <list>
#include <string>

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
        int lancer();
        void debutLancer();
        void boucleLancer(int i);
        int finLancer();


};