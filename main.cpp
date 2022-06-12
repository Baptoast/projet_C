#include "main.h"

int main()
{
    //Jeu
    jeu.creationJeu();

    while (jeu.isOpen()) {
        jeu.bouclePrincipale();
    }
    return 0;
}