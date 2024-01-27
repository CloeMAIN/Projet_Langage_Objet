#ifndef INPUTUSER_HH
#define INPUTUSER_HH

#include <SFML/Graphics.hpp>
#include "Personnage.hh"


struct Commande {
    sf::Keyboard::Key Droite;
    sf::Keyboard::Key Gauche;
    // Ajoutez d'autres actions ici (ex: Attaquer droite, Attaquer gauche, Sauter, S'accroupir)
};

struct EtatJoueur {
    Action actionJ1;
    Action actionJ2;
};

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
};



#endif
