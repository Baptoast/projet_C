#include "sol.h"

//Constructeur perso 
Sol::Sol() {
    loadTextureSol();

}

//Fonctions
//Permet de telecharger la texture du perso dans le dossier res
void Sol::loadTextureSol()
{
    if (!texture_sol.loadFromFile("res/img/sol.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_sol.setTexture(texture_sol);
        sprite_sol.setOrigin(576,576);
    }

}

void Sol::afficheSol(RenderWindow& window, Joueur& leJoueur) {
    //Deplace le décors de façon à crée l'illusion de l'infini
    if (leJoueur.getPos().posX+32 >= niveauX + 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x + 96, sprite_sol.getPosition().y);
        niveauX = niveauX + 96;
    }
    if (leJoueur.getPos().posX + 32 <= niveauX - 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x - 96, sprite_sol.getPosition().y);
        niveauX = niveauX - 96;
    }
    if (leJoueur.getPos().posY + 32 >= niveauY + 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x , sprite_sol.getPosition().y + 96);
        niveauY = niveauY + 96;
    }
    if (leJoueur.getPos().posY + 32 <= niveauY - 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x , sprite_sol.getPosition().y - 96);
        niveauY = niveauY - 96;
    }
    window.draw(sprite_sol);
}