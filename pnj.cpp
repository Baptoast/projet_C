#include "pnj.h"

Pnj::Pnj(){}

//Constructeur perso 
Pnj::Pnj(int x, int y, Texture* texture, int id) {

    srand(1.0);

    Vector2i anim(1, Down);
    vitesse = 0;
    updateFPS = true;
    sprite_pnj.setTexture(*texture);
    sprite_pnj.setOrigin(24, 24);
    sprite_pnj.setPosition(x, y);
    sprite_pnj.setTextureRect(IntRect(0,0,48,48));
}

//Permet de telecharger la texture du perso dans le dossier res
void Pnj::loadTexturePnj()
{
    if (!texture_pnj.loadFromFile("res/img/pnj/monster1.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_pnj.setTexture(texture_pnj);
    }

}

//Fonction qui donne l'annimation du perso en fonction de sa direction
void Pnj::animationPnj(int y) {

    if (updateFPS) {
        if (timeAnimationPerso.getElapsedTime().asMilliseconds() >= 140) {
            anim.x++;
            if (anim.x * 48 >= sprite_pnj.getTexture()->getSize().x) {
                anim.x = 0;
            }
            timeAnimationPerso.restart();
        }
    }
    else {
        anim.x = 1;
    }

    sprite_pnj.setTextureRect(IntRect(anim.x * 48, anim.y * 48 + y, 48, 48));
}

void Pnj::deplacementPnj(RenderWindow& window,Joueur& leJoueur) {
    animationPnj(0);

    int posJoueurX = leJoueur.getPos().posX +24;
    int posJoueurY = leJoueur.getPos().posY +32;

    if (reflexion.getElapsedTime().asSeconds() >= 4 || enChasse && reflexion.getElapsedTime().asMilliseconds() >= 20) {
        //fonctionne !
        int dansRayonDAction = abs((sprite_pnj.getPosition().x - posJoueurX) * cos(anglePoints(sprite_pnj.getPosition().x, sprite_pnj.getPosition().y, posJoueurX, posJoueurY)) + (sprite_pnj.getPosition().y - posJoueurY) * sin(anglePoints(sprite_pnj.getPosition().x, sprite_pnj.getPosition().y, posJoueurX, posJoueurY)));
        if (dansRayonDAction <= 25) {
            leJoueur.changementApparence(1);
            estDead = true;
        }
        if (dansRayonDAction <= 250) {
            nouvelleDirectionX = posJoueurX;
            nouvelleDirectionY = posJoueurY;
            enChasse = true;
        }
        else {
            nouvelleDirectionX = sprite_pnj.getPosition().x + rand() % 1000 - 500.0;
            nouvelleDirectionY = sprite_pnj.getPosition().y + rand() % 1000 - 500.0;
            enChasse = false;
        }
        reflexion.restart();
    }
    sprite_pnj.setPosition(sprite_pnj.getPosition().x + 0.815*cos(anglePoints(sprite_pnj.getPosition().x, sprite_pnj.getPosition().y, nouvelleDirectionX, nouvelleDirectionY)), sprite_pnj.getPosition().y + 0.815 * sin(anglePoints(sprite_pnj.getPosition().x, sprite_pnj.getPosition().y, nouvelleDirectionX, nouvelleDirectionY)));

    window.draw(sprite_pnj);
}

//gives the angle from point one to point two
float Pnj::anglePoints(int x1, int y1, int x2, int y2)
{
    return atan2(y2 - y1, x2 - x1);
}