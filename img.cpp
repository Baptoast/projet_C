#include "img.h"

//Constructeur perso 
Img::Img() {
    loadTextures();

}

/*
Liste ID materiaux :
1 - Bois
2 - Pierre
3 - Fleur1
4 - Fleur2
5 - Fleur3
*/
void Img::loadTextures() {
    if (!bois.loadFromFile("res/img/materiaux/bois.png")) {}
    if (!pierre.loadFromFile("res/img/materiaux/pierre.png")) {}
    if (!fleur1.loadFromFile("res/img/materiaux/fleur1.png")) {}
    if (!fleur2.loadFromFile("res/img/materiaux/fleur2.png")) {}
    if (!fleur3.loadFromFile("res/img/materiaux/fleur3.png")) {}
    
}

Texture* Img::getImageByID(int id) {
    switch (id)
    {
    case 1: return &bois;
    case 2: return &pierre;
    case 3: return &fleur1;
    case 4: return &fleur2;
    case 5: return &fleur3;
    }
    return &bois;
}