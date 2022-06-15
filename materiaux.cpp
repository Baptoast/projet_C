#include "materiaux.h"

//Constructeur perso 
Materiaux::Materiaux(int x, int y,Texture* texture) {
    //attribut la position du joueur à sa génération
    posX = x;
    posY = y;

    sprite_materiaux.setTexture(*texture);
    sprite_materiaux.setOrigin(24, 24);
    sprite_materiaux.setPosition(posX, posY);
    

}

void Materiaux::afficheMateriaux(RenderWindow& window) {
    window.draw(sprite_materiaux);
}


Sprite Materiaux::getSprite() {
    return sprite_materiaux;
}