#ifndef INPUTUSER_HH
#define INPUTUSER_HH

#include <SFML/Graphics.hpp>
#include "Personnage.hh"


class InputUser {
public:
    // ... (autres membres et méthodes)
    
    InputUser();
    ~InputUser();

    void gererEvenements(sf::RenderWindow* window, Personnage& joueur1, Personnage& joueur2, std::vector<ElementJeu> Plateformes);
    void checkRien(Personnage& joueur);
    void checkDegat(Personnage& joueur);
    void checkGauche(Personnage& joueur);
    void checkDroite(Personnage& joueur);
    void checkSaut(Personnage& joueur);
    void checkAttaque1(Personnage& joueur);
    void checkAttaque2(Personnage& joueur);
    void checkProjectile(Personnage& joueur);
    void DemandeAttaque(Personnage& joueur1, Personnage& joueur2);
    
    //Methode pour formulaire
    void gererPremiereEtape(sf::RenderWindow* window, std::string* pseudo, sf::Text* text, int* etape);
    int gererFormulaire(sf::RenderWindow* window, std::string* Reponse, std::string* Background, sf::Text* text1, int* questionCourante);
    void gererFinformulaire(sf::RenderWindow* window);
    };



#endif