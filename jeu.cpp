#include "jeu.h"

Jeu::Jeu() {
    inventaire.accesImages(imageStock);
    /*
Liste ID materiaux :
1 - Bois
2 - Pierre
3 - Fleur1
4 - Fleur2
5 - Fleur3
*/
    listeDeMateriaux.push_back(Materiaux(100, 100, &imageStock.pierre,2));
    listeDeMateriaux.push_back(Materiaux(200, 150, &imageStock.fleur2,4));
    listeDeMateriaux.push_back(Materiaux(-50, -150, &imageStock.fleur3, 5));

    Joueur leJoueurPrincipal = Joueur(0,0, inventaire);
    listeDeJoueur.push_back(leJoueurPrincipal);
    listeDeJoueur.at(0).loadTexturePerso();


}

void Jeu::creationJeu() {
    window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "La Brume");

    window.setPosition(Vector2i((ecran.getDesktopMode().width / 2) - (ecran.getDesktopMode().width / 5), ecran.getDesktopMode().height / 64));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
    vue.setCenter(32, 32);
    window.requestFocus();

   
}

bool Jeu::isOpen() {
    return window.isOpen();
}

void Jeu::bouclePrincipale() {

    //fonction qui capte si un bouton est appuyé (avant il y avait un while).

    if (window.pollEvent(event)) {
        input.InputHandler(event, window);
        listeDeJoueur.at(0).setInput(input);
    }
    window.clear(Color::Black);

    //affiche sol
    leSol.afficheSol(window, listeDeJoueur.at(0));
    //Les materiaux
    for (int i = 0; i < listeDeMateriaux.size(); i++) {
        listeDeMateriaux.at(i).afficheMateriaux(window);
    }
    //Affiche inventaire
    inventaire.afficheInventaire(window, listeDeJoueur.at(0).getPos().posX, listeDeJoueur.at(0).getPos().posY);
    //Joueur et vue
    listeDeJoueur.at(0).controlePerso(window,listeDeMateriaux);
    vue.setCenter(listeDeJoueur.at(0).getPos().posX+32, listeDeJoueur.at(0).getPos().posY + 32);
    
    

    window.setView(vue);
    window.display();



}

