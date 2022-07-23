#include "jeu.h"

Jeu::Jeu() {

    srand(1.0);

    //Centre
    generationAleatoireMateriaux(220);
    tabCarte[220] = 5;

    generationAleatoireMateriaux(219);
    generationAleatoireMateriaux(221);

    generationAleatoireMateriaux(200);
    generationAleatoireMateriaux(199);
    generationAleatoireMateriaux(198);

    generationAleatoireMateriaux(240);
    generationAleatoireMateriaux(241);
    generationAleatoireMateriaux(242);
    

    inventaire.initialiseListeMateriaux(&listeDeMateriaux, &listeDeMateriauxJoueur,&listeDeMateriauxPoubelle, &tableCraft);
    laBrume.initialiseListeMateriaux(&listeDeMateriaux);

    Joueur leJoueurPrincipal = Joueur(0,64, &inventaire);
    listeDeJoueur.push_back(leJoueurPrincipal);
    listeDeJoueur.at(0).loadTexturePerso();


}

void Jeu::creationJeu() {
    window.create(VideoMode(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT), "La Brume");

    window.setPosition(Vector2i((ecran.getDesktopMode().width / 2) - (ecran.getDesktopMode().width / 5), ecran.getDesktopMode().height / 64));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHT, SCREEN_SIZE_HEIGHT));
    vue.setCenter(32, 32);
    window.requestFocus();
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);
   
}

bool Jeu::isOpen() {
    return window.isOpen();
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
*/
void Jeu::generationAleatoireMateriaux(int numcase) {
    int zone = tabCarte[numcase];
    int nbr = numcase;
    switch (zone)
    {
    case 1: {
        listeDeMateriaux.push_back(Materiaux(0, 0, &imageStock.table_craft, 11, 0));
        //Rangee gauche
        
        listeDeMateriaux.push_back(Materiaux(-192, 0, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, 32, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, 64, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, 96, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, 128, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, -32, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, -64, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, -96, &imageStock.mur_bois, 12, 270));
        listeDeMateriaux.push_back(Materiaux(-192, -128, &imageStock.mur_bois, 12, 270));
        
        //Rangee haut
        listeDeMateriaux.push_back(Materiaux(-128, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(-96, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(-64, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(-32, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(0, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(32, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(64, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(96, -192, &imageStock.mur_bois, 12, 0));
        listeDeMateriaux.push_back(Materiaux(128, -192, &imageStock.mur_bois, 12, 0));
        //Rangee bas
        listeDeMateriaux.push_back(Materiaux(-128, 192, &imageStock.mur_bois, 12, 180));
        listeDeMateriaux.push_back(Materiaux(-96, 192, &imageStock.mur_bois, 12, 180));
        listeDeMateriaux.push_back(Materiaux(-64, 192, &imageStock.mur_bois, 12, 180));
        listeDeMateriaux.push_back(Materiaux(64, 192, &imageStock.mur_bois, 12, 180));
        listeDeMateriaux.push_back(Materiaux(96, 192, &imageStock.mur_bois, 12, 180));
        listeDeMateriaux.push_back(Materiaux(128, 192, &imageStock.mur_bois, 12, 180));
        //Rangee droite
        listeDeMateriaux.push_back(Materiaux(192, 0, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, 32, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, 64, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, 96, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, -64, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, -32, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, -96, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, 128, &imageStock.mur_bois, 12, 90));
        listeDeMateriaux.push_back(Materiaux(192, -128, &imageStock.mur_bois, 12, 90));
        //Coins
        listeDeMateriaux.push_back(Materiaux(172, -172, &imageStock.mur_bois, 12, 45));
        listeDeMateriaux.push_back(Materiaux(172, 172, &imageStock.mur_bois, 12, 135));
        listeDeMateriaux.push_back(Materiaux(-172, 172, &imageStock.mur_bois, 12, 225));
        listeDeMateriaux.push_back(Materiaux(-172, -172, &imageStock.mur_bois, 12, 315));
        //note de base
        listeDeMateriaux.push_back(Materiaux(96, -96, &imageStock.note, 21, 45));
        break;
    }
    case 2: {
        for (int i = 0; i < 15; i++) {
            float alea = rand() % 100 + 1.0;
            if (alea >= 1.0 && alea <= 30.0) {
                alea = 1.0;
            }
            else if (alea >= 31.0 && alea <= 60.0) {
                alea = 2.0;
            }
            else if (alea >= 61.0 && alea <= 98.0) {
                alea = 3.0;
            }
            else if (alea == 99.0 ) {
                alea = 5.0;
            }
            else if (alea == 100.0) {
                alea = 4.0;
            }
            switch ((int)alea)
            {
            case 1: {
                
                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0)+ (nbr% 21)*1000 - 10000, (rand() % 1000 - 500.0)+(nbr/ 21)*1000 - 10000, &imageStock.bois, (int)alea, 0));
                break;
            }
            case 2: {
                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.fleur1, (int)alea, 0));
                break;
            }
            case 3: {
                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.fleur2, (int)alea, 0));
                break;
            }
            case 4: {
                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.fleur3, (int)alea, 0));
                break;
            }
            case 5: {
                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.note, 21, 0));
                break;
            }

            }
        }
        
        float aleaMonstre = rand() % 20 + 1.0;
        if ((int)aleaMonstre == 20) {
            listeDePnj.push_back(Pnj((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.espritVengeur, 0));
        }

        break;
    }
    case 3: {
        for (int i = 0; i < 15; i++) {
            float alea = rand() % 15 + 1.0;
            if (alea >= 1.0 && alea <= 7.0) {
                alea = 1.0;
            }
            else if (alea >= 8.0 && alea <= 14.0) {
                alea = 2.0;
            }
            else if (alea == 15.0) {
                alea = 3.0;
            }
            switch ((int)alea)
            {
            case 1: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.bois, 1, 0));
                break;
            }
            case 2: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.pierre1, 5, 0));
                break;
            }
            case 3: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.pierre2, 6, 0));
                break;
            }

            }
        }

        float aleaMonstre = rand() % 10 + 1.0;
        if ((int)aleaMonstre == 10) {
            listeDePnj.push_back(Pnj((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.espritVengeur, 0));
        }

        break;
    }
    case 0: {
        for (int i = 0; i < 15; i++) {
            float alea = rand() % 100 + 1.0;
            if (alea >= 1.0 && alea <= 30.0) {
                alea = 1.0;
            }
            else if (alea >= 31.0 && alea <= 60.0) {
                alea = 2.0;
            }
            else if (alea >= 61.0 && alea <= 90.0) {
                alea = 3.0;
            }
            else if (alea >= 91.0 && alea <= 99.0) {
                alea = 4.0;
            }
            else if (alea == 100.0) {
                alea = 5.0;
            }

            switch ((int)alea)
            {
            case 1: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.pierre1, 5, 0));
                break;
            }
            case 2: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.boisMort, 7, 0));
                break;
            }
            case 3: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.pierre3, 8, 0));
                break;
            }
            case 4: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.planteBougeante, 9, 0));
                break;
            }
            case 5: {

                listeDeMateriaux.push_back(Materiaux((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.fleur4, 10, 0));
                break;
            }
            }
        }

        listeDePnj.push_back(Pnj((rand() % 1000 - 500.0) + (nbr % 21) * 1000 - 10000, (rand() % 1000 - 500.0) + (nbr / 21) * 1000 - 10000, &imageStock.espritVengeur, 0));
        break;
    }
    }
    tabCarte[numcase] = 4;
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

    

    //En met en liste que les éléments qui doivent apparaitre à l'écran
    
    if (tempsRafraichissementMateriaux.getElapsedTime().asMilliseconds() > 200) {

        //Generation des materiaux en fonction du tableau correspondant à la map
        //On regarde si le joueur ce situe sur une case qui est egal à 4, si oui alors on génère autour des 4 et il devient 5
        for (int d = 0; d < 441; d++) {
            if (tabCarte[d] == 4) {
                if (listeDeJoueur.at(0).getPos().posX > (d % 21) * 1000 - 10500 && listeDeJoueur.at(0).getPos().posX < (d % 21) * 1000 - 9500) {
                    if (listeDeJoueur.at(0).getPos().posY > (d / 21) * 1000 - 10500 && listeDeJoueur.at(0).getPos().posY < (d / 21) * 1000 - 9500) {

                        if (tabCarte[d - 1] != 4 && tabCarte[d - 1] != 5) {
                            generationAleatoireMateriaux(d - 1);
                            tabCarte[d - 1] = 4;
                        }
                        if (tabCarte[d + 1] != 4 && tabCarte[d + 1] != 5) {
                            generationAleatoireMateriaux(d + 1);
                            tabCarte[d + 1] = 4;
                        }
                        if (tabCarte[d + 21] != 4 && tabCarte[d + 21] != 5) {
                            generationAleatoireMateriaux(d + 21);
                            tabCarte[d + 21] = 4;
                        }
                        if (tabCarte[d - 21] != 4 && tabCarte[d - 21] != 5) {
                            generationAleatoireMateriaux(d - 21);
                            tabCarte[d - 21] = 4;
                        }
                        if (tabCarte[d + 20] != 4 && tabCarte[d + 20] != 5) {
                            generationAleatoireMateriaux(d + 20);
                            tabCarte[d + 20] = 4;
                        }
                        if (tabCarte[d - 20] != 4 && tabCarte[d - 20] != 5) {
                            generationAleatoireMateriaux(d - 20);
                            tabCarte[d - 20] = 4;
                        }
                        if (tabCarte[d + 22] != 4 && tabCarte[d + 22] != 5) {
                            generationAleatoireMateriaux(d + 22);
                            tabCarte[d + 22] = 4;
                        }
                        if (tabCarte[d - 22] != 4 && tabCarte[d - 22] != 5) {
                            generationAleatoireMateriaux(d - 22);
                            tabCarte[d - 22] = 4;
                        }
                        tabCarte[d] = 5;
                    }
                }
            }
        }
        
        listeDeMateriauxJoueur.clear();

        vector<int> listeObjetADetruire;
        for (int j = 0; j < listeDeMateriauxPoubelle.size(); j++) {
            for (int k = 0; k < listeDeMateriaux.size(); k++) {
                if (listeDeMateriauxPoubelle.at(j)->idMateriaux == listeDeMateriaux.at(k).idMateriaux) {
                    if (listeDeMateriauxPoubelle.at(j)->posX == listeDeMateriaux.at(k).posX && listeDeMateriauxPoubelle.at(j)->posY == listeDeMateriaux.at(k).posY) {
                        listeObjetADetruire.push_back(k);
                    }
                    
                }
            }
        }
        
        listeDeMateriauxPoubelle.clear();
        
        for (int l = 0; l < listeObjetADetruire.size(); l++) {
            
            listeDeMateriaux.erase(listeDeMateriaux.begin() + listeObjetADetruire.at(l) - l);
        }
        
        for (int i = 0; i < listeDeMateriaux.size(); i++) {
            if (listeDeJoueur.at(0).dansChampDeVision(listeDeMateriaux.at(i).getSprite().getPosition().x, listeDeMateriaux.at(i).getSprite().getPosition().y)) {
                listeDeMateriauxJoueur.push_back(&listeDeMateriaux.at(i));
            }

        }

        

        tempsRafraichissementMateriaux.restart();
    }

    //Les materiaux
    for (int i = 0; i < listeDeMateriauxJoueur.size(); i++) {
            listeDeMateriauxJoueur.at(i)->afficheMateriaux(window);
    }

    //Les monstres
    
    vector<int> compteDead;
    for (int i = 0; i < listeDePnj.size(); i++) {
        listeDePnj.at(i).deplacementPnj(window, listeDeJoueur.at(0));
        if (listeDePnj.at(i).estDead) {
            compteDead.push_back(i);
        }
    }
    for (int i = 0; i < compteDead.size(); i++) {
        listeDePnj.erase(listeDePnj.begin() + compteDead.at(i) - i);
    }
    
       
    //Affiche table de craft
    if (listeDeJoueur.at(0).dansTableCraft) {
        tableCraft.afficheRenduTableCraft(window, listeDeJoueur.at(0).getPos().posX, listeDeJoueur.at(0).getPos().posY);
        tableCraft.open = true;
    }
    else {
        tableCraft.open = false;
    }

    //Affiche inventaire
    inventaire.afficheInventaire(window, listeDeJoueur.at(0).getPos().posX, listeDeJoueur.at(0).getPos().posY,input.GetButton().molletteB, input.GetButton().moletteH);

    //Joueur et vue
    listeDeJoueur.at(0).controlePerso(window, listeDeMateriauxJoueur, listeDeMateriauxPoubelle);
    vue.setCenter(listeDeJoueur.at(0).getPos().posX+32, listeDeJoueur.at(0).getPos().posY + 32);

    //La brume
    laBrume.afficheBrume(window, listeDeJoueur.at(0).getPos().posX, listeDeJoueur.at(0).getPos().posY);
    
    

    window.setView(vue);
    window.display();
    



}

