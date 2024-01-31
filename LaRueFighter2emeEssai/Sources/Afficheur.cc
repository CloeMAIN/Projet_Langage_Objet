#include "../Header/Afficheur.hh"


Afficheur::Afficheur() : window(sf::VideoMode::getDesktopMode(), "Jeu", sf::Style::Fullscreen)
{
    // créer une fenêtre SFLM
    window.setFramerateLimit(60); // Limiter le taux de rafraîchissement à 60 images par seconde
    fondTexture.loadFromFile(CHEMIN_SOL);

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
    int diviseur = 850;
    sprite.setScale(TAILLE_FENETRE.x / diviseur, TAILLE_FENETRE.x / diviseur);
    // Calcul de la position X de la texture à afficher
    int largeurImage = texture.getSize().x / joueur.getNbImageSprite(); //8
    int xTexture = static_cast<int>(joueur.getPosition().x) / largeurImage % joueur.getNbImageSprite();
    xTexture = xTexture * largeurImage;

    sprite.setTextureRect(sf::IntRect(xTexture, 0, largeurImage, texture.getSize().y)); //82

    // Met le personnage à sa position dans la window
    sprite.setPosition({joueur.getPosition().x, joueur.getPosition().y});
    // Affiche le personnage
    window.draw(sprite);
    //afficher le sprite pendant 10 ms
    

    
}

void Afficheur::afficher(const ElementJeu& element) {
    // sf::RectangleShape test(sf::Vector2f(element.getTaille().largeur, element.getTaille().hauteur)); // Utilisation de Vector2f pour la taille
    // test.setPosition(element.getPosition().x, element.getPosition().y); // Positionné au bas au milieu
    // test.setFillColor(sf::Color::Black);
    // window.draw(test);
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
    window.clear(); // enlever le menu
    window.draw(jeu.getSprite());
    //On affiche un écran noir transparent
    sf::RectangleShape rectangle(sf::Vector2f(TAILLE_FENETRE.x, TAILLE_FENETRE.y));
    rectangle.setFillColor(sf::Color(0, 0, 0, 150));
    window.draw(rectangle);
    afficherSol();
    afficherBarreVieJ1(jeu.getJoueur1().getVie());
    afficherBarreVieJ2(jeu.getJoueur2().getVie());
    
    for (int i = 0; i < NB_PLATEFORMES; i++) {
        afficher(CHEMIN_PLATEFORME, PLATEFORME, jeu.getPlateforme(i).getPosition());
    }
    afficher(jeu.getJoueur1()); // Affiche le joueur 1
    afficher(jeu.getJoueur2()); // Affiche le joueur 2
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
    // couleur
    sol.setFillColor(sf::Color(128, 128, 128));
    //sol.setScale(static_cast<float>(TAILLE_FENETRE.x) / static_cast<float>(sol.getLocalBounds().width), static_cast<float>(TAILLE_FENETRE.y) / static_cast<float>(sol.getLocalBounds().height));
    sol.setPosition(0, TAILLE_FENETRE.y-HAUTEUR_SOL); // Positionné au bas au milieu
    window.draw(sol);
}

//Je laisse pour quand on affichera le nom des joueurs
// Afficheur:: afficher(Texte){

// }


void Afficheur::afficher(Menu menu){
    /* Affichage du background */
    afficher(menu.getCheminBackgroundMenu()[0]);
    
    /*Affichage des différents boutons*/
    for(int i = 0; i <menu.getListeBoutons().size()  ; i++)
        afficher(menu.getListeBoutons()[i].first, menu.getListeBoutons()[i].second.first, menu.getListeBoutons()[i].second.second);
    // std::string test1;
    // std::string test2; 
    // afficher(CHEMIN_QUESTION1, &test1, &test2);
    window.display();

}


void Afficheur::afficherBarreVieJ1(float vie) {
    const float vieMaximale = POINTS_DE_VIE_JOUEUR;
    
    // Calcul de la largeur de la barre de vie en fonction de la valeur de "vie"
    float largeurBarre = (vie > 0) ? (vie / vieMaximale) * TAILLE_INITIALE : TAILLE_INITIALE;

    // Barre de vie
    sf::RectangleShape barreVie(sf::Vector2f(largeurBarre, 50));
    barreVie.setPosition(POSITION_BARRE_J1.x, POSITION_BARRE_J1.y);
    barreVie.setFillColor(COULEUR_BARRE_J1);

    // Fond de la barre de vie
    sf::RectangleShape barreVieFond(sf::Vector2f(TAILLE_INITIALE, 50));
    barreVieFond.setPosition(POSITION_BARRE_J1.x, POSITION_BARRE_J1.y);
    barreVieFond.setFillColor(sf::Color::Black);

    // Affichage en fonction de la vie
    if (vie <= 0) {
        window.draw(barreVieFond);
    } else {
        window.draw(barreVieFond);
        window.draw(barreVie);
    }
}
void Afficheur::afficherBarreVieJ2(float vie) {
    const float vieMaximale = POINTS_DE_VIE_JOUEUR;

    // Calcul de la largeur de la barre de vie en fonction de la valeur de "vie"
    float largeurBarre = (vie > 0) ? (vie / vieMaximale) * TAILLE_INITIALE : TAILLE_INITIALE;

    // Barre de vie
    sf::RectangleShape barreVie(sf::Vector2f(largeurBarre, 50));
    barreVie.setPosition(POSITION_BARRE_J2.x + (TAILLE_INITIALE - largeurBarre), POSITION_BARRE_J2.y);
    barreVie.setFillColor(COULEUR_BARRE_J2);

    // Fond de la barre de vie
    sf::RectangleShape barreVieFond(sf::Vector2f(TAILLE_INITIALE, 50));
    barreVieFond.setPosition(POSITION_BARRE_J2.x , POSITION_BARRE_J2.y);
    barreVieFond.setFillColor(sf::Color::Black);

    // Affichage en fonction de la vie
    if (vie <= 0) {
        window.draw(barreVieFond);
    } else {
        window.draw(barreVieFond);
        window.draw(barreVie);
    }
}

void Afficheur::afficher(std::string cheminImageQuestion, sf::Text ReponseUtilisateur){
    sf::Texture texture;
    texture.loadFromFile(cheminImageQuestion);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(static_cast<float>(TAILLE_FENETRE.x) / static_cast<float>(sprite.getLocalBounds().width), static_cast<float>(TAILLE_FENETRE.y) / static_cast<float>(sprite.getLocalBounds().height));
    window.draw(sprite);
    sf::RectangleShape inputRect(sf::Vector2f(float(TAILLE_FENETRE.x)/3, 60.f)); // Rectangle pour le prénom
    inputRect.setFillColor(sf::Color::White);
    inputRect.setPosition(float(TAILLE_FENETRE.x)/8,float(TAILLE_FENETRE.y)/2);
    afficher(TOUR_EIFFEL, TAILLE_TOUR_EIFFEL,POSITION_TOUR_EIFFEL);
    afficher(LOUVRES, TAILLE_LOUVRES,POSITION_LOUVRES);
    afficher(NOTRE_DAME, TAILLE_NOTRE_DAME,POSITION_NOTRE_DAME);
    afficher(ARC_DE_TRIOMPHE, TAILLE_ARC_DE_TRIOMPHE,POSITION_ARC_DE_TRIOMPHE); 
    afficher(VALIDE, TAILLE_VALIDE,POSITION_VALIDE); 
    window.draw(ReponseUtilisateur) ;
    window.draw(inputRect);

}


void Afficheur::afficher(Formulaire form, sf::Text text1){
    window.clear(); 
    std::string test1;
    std::string test2; 
    //On se décale jusquà la question courante

    afficher(form.getQuestions().front().getCheminImageQuestion(), text1);
    window.draw(text1);
}

void Afficheur::afficherquizz(std::string cheminbackground, sf::Text text){
    window.clear();
    afficher(cheminbackground);
    afficher(CHEMIN_BOUTON_JOUER, TAILLE_BOUTON_QUITTER_QUESTIONNAIRE, POSITION_BOUTON_QUITTER_QUESTIONNAIRE);
    afficher(VALIDE, TAILLE_VALIDE, POSITION_VALIDE);
    sf::RectangleShape inputRect(sf::Vector2f(float(TAILLE_FENETRE.x)/3, 60.f)); // Rectangle pour le prénom
    inputRect.setFillColor(sf::Color::White);
    inputRect.setPosition(float(TAILLE_FENETRE.x)/8,2*float(TAILLE_FENETRE.y)/3);
    window.draw(inputRect);
    window.draw(text);
    std::cout << "On affiche le quizz" << std::endl;



}