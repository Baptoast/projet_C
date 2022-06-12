#include "jeu.h"

Jeu::Jeu() {

}

void Jeu::creationJeu() {
    window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "nom_du_jeu");

    window.setPosition(Vector2i((ecran.getDesktopMode().width / 2) - (ecran.getDesktopMode().width / 5), ecran.getDesktopMode().height / 64));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
    vue.setCenter(SCREEN_SIZE_WEIGHT / 2, SCREEN_SIZE_HEIGHT / 2);
    window.requestFocus();
}

bool Jeu::isOpen() {
    return window.isOpen();
}

void Jeu::bouclePrincipale() {

    //fonction qui capte si un bouton est appuyé (avant il y avait un while).

    if (window.pollEvent(event)) {

    }
    window.clear(Color::Black);

    //affiche
    //sol.afficheSol(window);

    window.setView(vue);
    window.display();



}

