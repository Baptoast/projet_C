#include "main.h"

void lancementPremierThread() {
    menu.premiereConnexion(&status);
    elementJoueur.push_back(menu.elem1);
    elementJoueur.push_back(menu.elem2);
    elementJoueur.push_back(menu.elem3);
    menu.fermeFenetr = true;
}

void lancementSecondThread() {
    jeu.communicationServeur(&status);
}

void lancementTroisiemeThread() {
    jeu.communicationServeurReception(&status);
}

int main()
{

    menu.loadImageMenu();
    menu.creationMenu();

    Thread thread(lancementPremierThread);
    thread.launch();

    while (!menu.fermeFenetr) {
        menu.bouclePrincipale();
    }
    menu.fermeFenetre();

    //Si on ne quitte pas le menu comme un bourrin
    if (menu.accepteJeu) {
        //Jeu
        jeu.creationJeu(&elementJoueur);

        Thread thread(lancementSecondThread);
        thread.launch();

        Thread thread2(lancementTroisiemeThread);
        thread2.launch();
    
        while (jeu.isOpen()) {
            jeu.bouclePrincipale();
        }
    }

    return 0;
}