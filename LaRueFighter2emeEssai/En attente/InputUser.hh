class enum Action{
    Droite; 
    Gauche;
    //Attaquer droite 
    //Attaquer gauche
    //Sauter
    //S'accroupir
}

class InputUser{
    private:

    public:
        InputUser();
        ~InputUser();
        Action getActionJ1();
        Action getActionJ2();
};