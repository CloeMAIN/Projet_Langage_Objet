#include "Afficheur.hh"


Afficheur::Afficheur(/* args */) : window(sf::VideoMode::getDesktopMode(), "Jeu", sf::Style::Fullscreen)
{
    // créer une fenêtre SFLM
    window.setFramerateLimit(60); // Limiter le taux de rafraîchissement à 60 images par seconde


}

Afficheur::~Afficheur() 
{
}

void Afficheur::afficher(const Personnage& joueur) {
    for (Projectile* projectile : joueur.getListeProjectiles()) {
        afficher(*projectile);
    }
    if(joueur.getEtat()["Attaque1"].first){
        afficher(joueur.getAttaque());
    }
    else if(joueur.getEtat()["Attaque2"].first){
        afficher(joueur.getAttaque());
    }

    sf::Texture texture;

    // Charge l'image correspondante
    if (!texture.loadFromFile(joueur.getCheminImageActuelle())) 
        throw std::runtime_error("Erreur de chargement de l'image : " + joueur.getCheminImageActuelle());

    sf::Sprite sprite = joueur.getSprite();
    sprite.setTexture(texture);
    sprite.setScale(2.f, 2.f); // Ajuste l'échelle en fonction de la direction

    // Calcul de la position X de la texture à afficher
    int largeurImage = texture.getSize().x / joueur.getNbImageSprite(); //8
    int xTexture = static_cast<int>(joueur.getPosition().x) / largeurImage % joueur.getNbImageSprite();
    xTexture = xTexture * largeurImage;

    sprite.setTextureRect(sf::IntRect(xTexture, 0, largeurImage, texture.getSize().y)); //82

    // Met le personnage à sa position dans la window
    sprite.setPosition({joueur.getPosition().x, joueur.getPosition().y});
    // Affiche le personnage
    window.draw(sprite);

    
}

void Afficheur::afficher(const ElementJeu& element) {
    sf::RectangleShape test(sf::Vector2f(element.getTaille().largeur, element.getTaille().hauteur)); // Utilisation de Vector2f pour la taille
    test.setPosition(element.getPosition().x, element.getPosition().y); // Positionné au bas au milieu
    test.setFillColor(sf::Color::Black);
    window.draw(test);
}

void Afficheur::afficher(const Projectile& projectile) {
    //Créer un sprite pour le projectile
    sf::Sprite spriteProjectile;
    sf::Texture textureProjectile;
    textureProjectile.loadFromFile(projectile.getCheminImage());
    spriteProjectile.setTexture(textureProjectile);
    // Met le projectile à sa position dans la window
    spriteProjectile.setPosition({projectile.getPosition().x, projectile.getPosition().y});
    spriteProjectile.setScale(0.1f, 0.1f); 
    // Affiche le projectile
    window.draw(spriteProjectile);
}


void Afficheur::afficher(Jeu& jeu) {
    // inclut le nom du personnage au-dessus et une pdp du perso
    // la barre de vie
    window.clear(sf::Color::Green); // enlever le menu
    afficherSol();
    afficherBarreVieJ1(jeu.getJoueur1().getVie());
    afficherBarreVieJ2(jeu.getJoueur2().getVie());
    afficher(jeu.getJoueur1()); // Affiche le joueur 1
    afficher(jeu.getJoueur2()); // Affiche le joueur 2
    for (int i = 0; i < NB_PLATEFORMES; i++) {
        afficher(CHEMIN_PLATEFORME, PLATEFORME, jeu.getPlateforme(i).getPosition());
    }
    // Ajoutez d'autres éléments à afficher en fonction de l'objet Jeu
    window.display();
}


void Afficheur:: afficher(std::string cheminbouton, HitBox taille, Point position){
sf::Texture texture;
    texture.loadFromFile(cheminbouton);
    sf::Sprite bouton;
    bouton.setTexture(texture);
    bouton.setPosition(position.x, position.y);
    bouton.setScale((taille.DroiteBas.x - taille.GaucheHaut.x) / bouton.getLocalBounds().width, (taille.DroiteBas.y - taille.GaucheHaut.y) / bouton.getLocalBounds().height);
    window.draw(bouton);
}

void Afficheur:: afficher(std::string cheminBackground){
    sf::Texture texture;
    texture.loadFromFile(cheminBackground);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(static_cast<float>(TAILLE_FENETRE.x) / static_cast<float>(sprite.getLocalBounds().width), static_cast<float>(TAILLE_FENETRE.y) / static_cast<float>(sprite.getLocalBounds().height));
    window.draw(sprite);
}

void Afficheur::afficherSol() {
    sf::RectangleShape sol(sf::Vector2f(TAILLE_FENETRE.x, HAUTEUR_SOL)); // Utilisation de Vector2f pour la taille
    sol.setPosition(0, TAILLE_FENETRE.y-HAUTEUR_SOL); // Positionné au bas au milieu
    sol.setFillColor(sf::Color::Blue);
    window.draw(sol);
}

//Je laisse pour quand on affichera le nom des joueurs
// Afficheur:: afficher(Texte){

// }


void Afficheur::afficher(Menu menu){
    /* Affichage du background */
    afficher(menu.getCheminBackgroundMenu()[0]);
    
    /*Affichage des différents boutons*/
    afficher(menu.getListeBoutons()[0].first, menu.getListeBoutons()[0].second.first, menu.getListeBoutons()[0].second.second);
    afficher(menu.getListeBoutons()[1].first, menu.getListeBoutons()[1].second.first, menu.getListeBoutons()[1].second.second);
    afficher(menu.getListeBoutons()[2].first, menu.getListeBoutons()[2].second.first, menu.getListeBoutons()[2].second.second);
    window.display();
}


void Afficheur::afficherBarreVieJ1(float vie){
    sf::RectangleShape barreVie(sf::Vector2f(vie*10, 50));
    barreVie.setPosition(POSITION_BARRE_J1.x, POSITION_BARRE_J1.y);
    barreVie.setFillColor(COULEUR_BARRE_J1);
    sf::RectangleShape barreVieFond(sf::Vector2f(1000, 50));
    barreVieFond.setPosition(POSITION_BARRE_J1.x, POSITION_BARRE_J1.y);
    barreVieFond.setFillColor(sf::Color::Black);
    if(vie<=0){
        window.draw(barreVieFond); 
    }else{
            window.draw(barreVieFond);
        window.draw(barreVie);
    }

};

void Afficheur::afficherBarreVieJ2(float vie) {
    sf::RectangleShape barreVie(sf::Vector2f(vie * 10, 50));
    barreVie.setPosition(POSITION_BARRE_J2.x + (1000 - vie * 10), POSITION_BARRE_J2.y);
    barreVie.setFillColor(COULEUR_BARRE_J2);
    sf::RectangleShape barreVieFond(sf::Vector2f(1000, 50));
    barreVieFond.setPosition(POSITION_BARRE_J2.x, POSITION_BARRE_J2.y);
    barreVieFond.setFillColor(sf::Color::Black);

    if (vie <= 0) {
        window.draw(barreVieFond);
    } else {
        window.draw(barreVieFond);
        window.draw(barreVie);
    }
}
