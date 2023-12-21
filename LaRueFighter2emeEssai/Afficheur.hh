#ifndef AFFICHEUR_HH
#define AFFICHEUR_HH
#include <SFML/Graphics.hpp>
class Afficheur
{
private:
    sf::RenderWindow window;
public:
    Afficheur(/* args */);
    ~Afficheur();

    /* Getter */
    sf::RenderWindow* getWindow(){return &window;}
};

#endif // AFFICHEUR_HH

