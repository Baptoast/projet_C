#include "materiaux.h"

//Constructeur perso 
Materiaux::Materiaux(int x, int y,Texture* texture, int id, float rotation) {
    //attribut la position du joueur à sa génération
    posX = x;
    posY = y;
    idMateriaux = id;
    sprite_materiaux.setTexture(*texture);
    sprite_materiaux.setOrigin(24, 24);
    sprite_materiaux.setPosition(posX, posY);
    sprite_materiaux.setRotation(rotation);

    switch (idMateriaux)
    {
    case 1: {
        solidite = 2000;
        break;
        }
    case 2: {
        solidite = 1000;
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
        solidite = 4000;
        break;
    }
    case 6: {
        solidite = 8000;
        break;
    }
    case 7: {
        solidite = 15000;
        break;
    }
    case 8: {
        solidite = 16000;
        break;
    }
    case 9: {
        solidite = 1500;
        break;
    }
    case 10: {
        solidite = 100000;
        break;
    }
    case 11: {
        solidite = 7000;
        break;
    }
    case 12: {
        solidite = 2000;
        resistant = 10000;
        resistantmax = 10000;
        break;
    }
    case 13: {
        solidite = 4000;
        resistant = 100000;
        resistantmax = 100000;
        break;
    }
    case 14: {
        solidite = 8000;
        resistant = 1000000;
        resistantmax = 1000000;
        break;
    }
    case 15: {
        solidite = 1;
        break;
    }
    case 16: {
        solidite = 6000;
        break;
    }
    case 17: {
        solidite = 3000;
        break;
    }
    case 18: {
        solidite = 3000;
        break;
    }
    case 19: {
        solidite = 3000;
        break;
    }
    case 20: {
        solidite = 1;
        break;
    }
    case 21: {
        solidite = 200;
        break;
    }
    }

}
/*
Liste ID materiaux :
1 - Bois
2 - Fleur1
3 - Fleur2
4 - Fleur3
5 - Pierre1
6 - Pierre2
7 - BoisMort
8 - Pierre3
9 - PlanteBougeante
10 - Fleur4
11 - Table de Craft
12 - Mur en bois
13 - Mur en pierre
14 - Mur en pierre des âmes
15 - Pioche
16 - Baril
17 - Totem de speed
18 - Totem de recup speed
19 - Totem repousse brume
20 - Pelle
21 - Note
*/

void Materiaux::afficheMateriaux(RenderWindow& window) {
    if (idMateriaux == 17) {
        CircleShape cercleSelection;
        cercleSelection.setRadius(250.0);
        cercleSelection.setPosition(sprite_materiaux.getPosition().x, sprite_materiaux.getPosition().y);
        cercleSelection.setOrigin(250.0, 250.0);
        cercleSelection.setFillColor(Color(255, 128, 0, 25));
        window.draw(cercleSelection);
    }
    if (idMateriaux == 18) {
        CircleShape cercleSelection;
        cercleSelection.setRadius(250.0);
        cercleSelection.setPosition(sprite_materiaux.getPosition().x, sprite_materiaux.getPosition().y);
        cercleSelection.setOrigin(250.0, 250.0);
        cercleSelection.setFillColor(Color(255, 192, 203, 25));
        window.draw(cercleSelection);
    }

    if (resistantmax != -1) {
        if (resistant < resistantmax / 2) {
            sprite_materiaux.setColor(Color(200, 200, 200, 200));
        }
        if (resistant < resistantmax / 4) {
            sprite_materiaux.setColor(Color(100, 100, 100, 100));
        }
    }
    

    window.draw(sprite_materiaux);
}


Sprite Materiaux::getSprite() {
    return sprite_materiaux;
}