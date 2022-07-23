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
    
    if (!texture_sol2.loadFromFile("res/img/sol2.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_sol2.setTexture(texture_sol2);
        sprite_sol2.setOrigin(576, 576);
    }
    if (!texture_sol3.loadFromFile("res/img/sol3.png")) {
        cout << "erreur" << endl;
    }

}

void Sol::afficheSol(RenderWindow& window, Joueur& leJoueur) {
    //Deplace le décors de façon à crée l'illusion de l'infini

    if (leJoueur.getPos().posX+32 >= niveauX + 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x + 96, sprite_sol.getPosition().y);
        sprite_sol2.setPosition(sprite_sol2.getPosition().x + 96, sprite_sol2.getPosition().y);
        niveauX = niveauX + 96;
    }
    if (leJoueur.getPos().posX + 32 <= niveauX - 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x - 96, sprite_sol.getPosition().y);
        sprite_sol2.setPosition(sprite_sol2.getPosition().x - 96, sprite_sol2.getPosition().y);
        niveauX = niveauX - 96;
    }
    if (leJoueur.getPos().posY + 32 >= niveauY + 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x , sprite_sol.getPosition().y + 96);
        sprite_sol2.setPosition(sprite_sol2.getPosition().x, sprite_sol2.getPosition().y + 96);
        niveauY = niveauY + 96;
    }
    if (leJoueur.getPos().posY + 32 <= niveauY - 96) {
        sprite_sol.setPosition(sprite_sol.getPosition().x , sprite_sol.getPosition().y - 96);
        sprite_sol2.setPosition(sprite_sol2.getPosition().x, sprite_sol2.getPosition().y - 96);
        niveauY = niveauY - 96;
    }

    //(Autre)
    //GetPlayerX+50*cos(angleT),GetPlayerY+50*sin(angleT)
    //ObjMove_GetX(bossObj)+xxx*cos(angleT),ObjMove_GetY(bossObj)+xxx*sin(angleT)
    //angleToPlayer(ObjMove_GetX(bossObj), ObjMove_GetY(bossObj));
    
    //CALCUL MAGIQUE DU CERCLE DE L'INFINIIIIIIII
    //float calcul = (abs(leJoueur.getPos().posX+(255.0 / 6720.0)*abs(leJoueur.getPos().posX)*cos(leJoueur.anglePoints(0,0, leJoueur.getPos().posX, leJoueur.getPos().posY))) + abs(leJoueur.getPos().posY + (255.0 / 6720.0) * abs(leJoueur.getPos().posY) * sin(leJoueur.anglePoints(0, 0, leJoueur.getPos().posX, leJoueur.getPos().posY))))/ (6720.0 / 255.0);
    float calcul = (abs((255.0 / 6720.0) * abs(leJoueur.getPos().posX) * cos(leJoueur.anglePoints(0, 0, leJoueur.getPos().posX, leJoueur.getPos().posY))) + abs((255.0 / 6720.0) * abs(leJoueur.getPos().posY) * sin(leJoueur.anglePoints(0, 0, leJoueur.getPos().posX, leJoueur.getPos().posY))));

    if (calcul < 255.0) {
        sprite_sol.setTexture(texture_sol);
        sprite_sol2.setTexture(texture_sol2);
        sprite_sol.setColor(Color(255, 255, 255, 255 - calcul));
    }
    else {
        sprite_sol.setTexture(texture_sol2);
        sprite_sol2.setTexture(texture_sol3);
        sprite_sol.setColor(Color(255, 255, 255, 510 - calcul ));
    }

    window.draw(sprite_sol2);
    window.draw(sprite_sol);
}
