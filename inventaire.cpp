#include "inventaire.h"

//Constructeur perso 
Inventaire::Inventaire() {
    loadTextureInventaire();
}

//RENDU ICI, FAUT FAIRE UNE FONCTION QUI INITIALISE LA GALERIE D'IMAGE POUR POUVOIR RECUP LES TEXTURES DES MATERIAUX POUR LES OBJ D'INVENTAIRE
void Inventaire::accesImages(Img& images) {
    
}

//Fonctions
//Permet de telecharger la texture du perso dans le dossier res
void Inventaire::loadTextureInventaire()
{
    if (!texture_inventaire.loadFromFile("res/img/inventaire.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_inventaire.setTexture(texture_inventaire);
        sprite_inventaire.setPosition(-390, -420);
    }
    if (!texture_flecheG.loadFromFile("res/img/flecheG.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_flecheG.setTexture(texture_flecheG);
        sprite_flecheG.setPosition(-440, -395);
    }
    if (!texture_flecheD.loadFromFile("res/img/flecheD.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_flecheD.setTexture(texture_flecheD);
        sprite_flecheD.setPosition(-295, -395);
    }

}

void Inventaire::afficheInventaire(RenderWindow& window, int x, int y) {
    
    if (idMateriaux.size() > 0) {
        
        window.draw(sprite_materiaux);
    }

    sprite_inventaire.setPosition(-390 + x, -420 + y);
    sprite_flecheG.setPosition(-440 + x, -395 + y);
    sprite_flecheD.setPosition(-295 + x, -395 + y);

    window.draw(sprite_inventaire);
    window.draw(sprite_flecheG);
    window.draw(sprite_flecheD);

}
