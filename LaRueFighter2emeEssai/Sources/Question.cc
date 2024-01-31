#include "../Header/Question.hh"

Question::Question(std::string question, std::string format , std::string reponse, std::string background, std::string cheminImageQuestion){
    this->question = question;
    this->reponse = reponse;
    this->background = background;
    this->formatReponse = format;
    this->cheminImageQuestion = cheminImageQuestion;
}

bool Question::verifierReponse(std::string reponseUtilisateur){
    if(reponseUtilisateur == this->reponse ){
        return true;
    }
    else{
        return false;
    }
}

bool Question::verifierBackground(std::string backgroundUtilisateur){
    if(backgroundUtilisateur == this->background ){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Question& question){
    os << question.getQuestion() << std::endl;
    os << question.getFormatReponse() << std::endl;
    os << question.getBackground() << std::endl;
    os << question.getReponse() << std::endl;
    return os;
}