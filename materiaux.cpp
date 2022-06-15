#include "materiaux.h"

//Constructeur perso 
Materiaux::Materiaux(int x, int y,Texture* texture, int id) {
    //attribut la position du joueur à sa génération
    posX = x;
    posY = y;
    idMateriaux = id;
    sprite_materiaux.setTexture(*texture);
    sprite_materiaux.setOrigin(24, 24);
    sprite_materiaux.setPosition(posX, posY);

    switch (idMateriaux)
    {
    case 1: {
        solidite = 2000;
        break;
        }
    case 2: {
        solidite = 4000;
        break;
    }
    case 3: {
        solidite = 1000;
        break;
    }
    case 4: {
        solidite = 1000;
        break;
    }
    case 5: {
        solidite = 1000;
        break;
    }
    }

}
/*
Liste ID materiaux :
1 - Bois
2 - Pierre
3 - Fleur1
4 - Fleur2
5 - Fleur3
*/

void Materiaux::afficheMateriaux(RenderWindow& window) {
    window.draw(sprite_materiaux);
}


Sprite Materiaux::getSprite() {
    return sprite_materiaux;
}