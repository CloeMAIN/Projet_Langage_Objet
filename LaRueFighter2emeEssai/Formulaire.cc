#include "Formulaire.hh"

Formulaire::Formulaire(std::list<Question> questions, int nbQuestions){
    this->questions = questions;
    this->nbQuestions = nbQuestions;
    this->score = 0;
    this->nom = "";
    this->prenom = "";
}

int Formulaire::lancer(Afficheur* afficheur){

    // system("x-terminal-emulator");

    debutLancer();

    for(int i = 0; i < this->nbQuestions; i++){
        boucleLancer(i);
    }
    return finLancer(afficheur);

   // Fermer un terminal
    // Note : cela fermera le terminal où le programme est exécuté
    // system("kill -9 $$"); 
}


void Formulaire::debutLancer(){
    std::cout << "Bienvenue dans le formulaire de Quizz" << std::endl;
    std::cout << "Veuillez saisir votre nom : " << std::endl;
    std::cin >> this->nom;
    std::cout << "Veuillez saisir votre prenom : " << std::endl;
    std::cin >> this->prenom;
    std::cin.ignore();
    std::cout << "Bonjour " << this->prenom << " " << this->nom << std::endl;
    std::cout << "Vous allez répondre à " << this->nbQuestions << " questions" << std::endl;
    std::cout << "Bonne chance !" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void Formulaire::boucleLancer(int i){
    std::cout << "Question " << i+1 << " : " << std::endl;
        std::cout << this->questions.front().getQuestion() << std::endl;
        std::string reponseUtilisateur;
        std::cout << "Veuillez saisir votre réponse : " << std::endl;
        std::getline(std::cin, reponseUtilisateur);
        std::cout << "Veuillez saisir le background de votre réponse : " << std::endl;
        std::string backgroundUtilisateur;
        std::getline(std::cin, backgroundUtilisateur);
        if(this->questions.front().verifierReponse(reponseUtilisateur) && this->questions.front().verifierBackground(backgroundUtilisateur)){
            std::cout << "Bonne réponse !" << std::endl;
            this->score++;
        }
        else{
            std::cout << "Mauvaise réponse !" << std::endl;
        }
        this->questions.pop_front();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
}

int Formulaire::finLancer(Afficheur* afficheur){
    std::cout << "Fin du formulaire" << std::endl;
    std::cout << "Votre score est de " << this->score << "/" << this->nbQuestions << std::endl;
    std::cout << "Merci d'avoir participé !" << std::endl;
    
    if (this->score == this->nbQuestions){
        std::cout << "Vous avez eu un sans faute !\n Si vous voulez rejouer, taper 1.\n Si vous voulez quitter taper 2" << std::endl;
    }
    else{
        std::cout << "Retentez une autre fois !\n Si vous voulez rejouer, taper 1.\n Si vous voulez quitter taper 2" << std::endl;
        }

    std::string reponse;
    std::cin >> reponse;
    if (reponse == "1"){
        afficheur->getWindow()->setVisible(true);
        return -1;
    }
    else if (reponse == "2"){
        afficheur->getWindow()->close();
        return 3;
    }
    return 0;
}