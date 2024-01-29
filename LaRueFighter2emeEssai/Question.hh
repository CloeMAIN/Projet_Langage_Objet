#ifndef QUESTION_HH
#define QUESTION_HH

#pragma once
#include <iostream>
#include <string>

class Question{
    private:
        std::string question;
        std::string formatReponse;
        std::string reponse;
        std::string background;
    public:
        Question(std::string question,std::string format, std::string reponse, std::string background);
        ~Question() {};
        void setQuestion(std::string question){this->question = question;};
        void setReponse(std::string reponse){this->reponse = reponse;};
        void setFormatReponse(std::string formatReponse){this->formatReponse = formatReponse;};

        std::string getQuestion()const {return this->question;};
        std::string getReponse()const {return this->reponse;};
        std::string getBackground()const {return this->background;};
        std::string getFormatReponse()const {return this->formatReponse;};

        //Méthode
        friend std::ostream& operator<<(std::ostream& os, const Question& question);
        bool verifierReponse(std::string reponseUtilisateur);
        bool verifierBackground(std::string backgroundUtilisateur);

};

#endif // QUESTION_HH