#include "../Header/Formulaire.hh"

Formulaire::Formulaire(std::list<Question> questions, int nbQuestions){
    this->questions = questions;
    this->nbQuestions = nbQuestions;
    this->score = 0;
    this->pseudo = "";
    this->questionCourante = 0; 
}

int Formulaire::lancer(Afficheur* afficheur){
    int etape = 1; 
    bool finquestion = 0;
    InputUser inputUser;

    sf::Music music; 
    if(!music.openFromFile("../Son/Clock.wav"))
        std::cout << "Erreur lors du chargement de la musique" << std::endl;
    else
        std::cout << "Musique chargée" << std::endl;
    music.setLoop(true); 
    music.play();

    sf::RenderWindow* window = afficheur->getWindow();
    sf::Text text; sf::Text rep; 
    sf::Font font;
    font.loadFromFile("Font/DEJAVUSANS.TTF");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(float(TAILLE_FENETRE.x)/8,2*float(TAILLE_FENETRE.y)/3);
    text.setString(L"Réponse :");

    rep.setFont(font);
    rep.setCharacterSize(50);
    rep.setFillColor(sf::Color::Black);
    rep.setPosition(float(TAILLE_FENETRE.x)/8,float(TAILLE_FENETRE.y)/2);
    rep.setString(L"Réponse :");
    std::string Reponse; 
    std::string Background; 

    std::cout << "Lancement Formulaire" << std::endl;

    int result = bouclelancer(&etape, &text, &rep,&finquestion, &Reponse, &Background, afficheur, &inputUser);
    return result;
}


void Formulaire::majFormulaire(std::string* reponseUtilisateur, std::string* backgroundUtilisateur, int* etape, bool* finquestion, sf::Text* rep){
    if(this->questions.front().verifierReponse(*reponseUtilisateur) && this->questions.front().verifierBackground(*backgroundUtilisateur)){
        this->score++;
        printf("Bonne réponse\n");
    }
    else{
        printf("Mauvaise réponse\n");
    }
    rep->setString(L"Réponse :");
    *reponseUtilisateur = "";
    *backgroundUtilisateur = "";
    *finquestion = 0;
    Question temp = this->questions.front();
    this->questions.pop_front();//
    this->questions.push_back(temp);
    if(questionCourante == nbQuestions){
        *etape = 3; 
    }

}

int Formulaire::finLancer(Afficheur* afficheur){
    if (this->score == this->nbQuestions){
        return 5;
        }
    else{
        return 6;
        }

}

int Formulaire::bouclelancer(int* etape, sf::Text* text, sf::Text* rep, bool* finquestion, std::string* Reponse, std::string* Background, Afficheur* afficheur, InputUser* inputUser){
    while (afficheur->getWindow()->isOpen() && *etape!=4){
        if(*etape == 1){
            inputUser->gererPremiereEtape(afficheur->getWindow(), &pseudo, text, etape);
            afficheur->afficherquizz(CHEMIN_PRESENTATION_FORMULAIRE, *text);
        }

        if (*etape== 2){
            *finquestion = inputUser->gererFormulaire(afficheur->getWindow(), Reponse, Background, rep, &questionCourante); 
            if (*finquestion == 1){
                majFormulaire(Reponse, Background, etape, finquestion, rep);
            }
            afficheur->afficher(*this, *rep);
        }

        if (*etape == 3){
            *etape=4; 
            return finLancer(afficheur);
        }
    afficheur->getWindow()->display();
     }
        
}