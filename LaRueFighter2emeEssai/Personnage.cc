#include "Personnage.hh"

Personnage::Personnage(/* args */)
{
}

Personnage::Personnage(Point position, int vie, std::string cheminImage)
{
    this->position = position;
    this->vie = vie;
    this->cheminImage = cheminImage;
}

Personnage::~Personnage()
{
}
