#include "inventaire.h"

//Constructeur perso 
Inventaire::Inventaire() {
    loadTextureInventaire();
}

//RENDU ICI, FAUT FAIRE UNE FONCTION QUI INITIALISE LA GALERIE D'IMAGE POUR POUVOIR RECUP LES TEXTURES DES MATERIAUX POUR LES OBJ D'INVENTAIRE

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
    
    if (!font.loadFromFile("res/img/font/mytype.ttf")) {
        cout << "erreur de chargement de l'ecriture" << endl;
    }
    else {
        nombreDeItem.setFont(font);
        //nombreDeItem.setFillColor(Color(125,125,125,255));
    }

    cercleSelection.setRadius(128.0);
    cercleSelection.setOrigin(105, 100);
    cercleSelection.setFillColor(Color(100, 250, 50, 75));

    sprite_materiaux.setOrigin(24, 24);
}

void Inventaire::initialiseListeMateriaux(vector<Materiaux>* laListe, vector<Materiaux*>* laListeJoueur, vector<Materiaux*>* laListeJoueurPoubelle, TableCraft* laTableDeCraft) {
    listeDeMateriaux = laListe;
    listeDeMateriauxJoueur = laListeJoueur;
    listeDeMateriauxPoubelle = laListeJoueurPoubelle;
    tableCraft = laTableDeCraft;

}

void Inventaire::afficheInventaire(RenderWindow& window, int x, int y, bool mouseWheelB, bool mouseWheelH) {
    int positionSourisX = souris.getPosition().x + x - window.getPosition().x - 450;
    int positionSourisY = souris.getPosition().y + y - window.getPosition().y - 475;

    sprite_inventaire.setPosition(-390 + x, -420 + y);
    sprite_flecheG.setPosition(-440 + x, -395 + y);
    sprite_flecheD.setPosition(-295 + x, -395 + y);

    window.draw(sprite_inventaire);
    window.draw(sprite_flecheG);
    window.draw(sprite_flecheD);

    if (tempsAttenteAjoutRetrait.getElapsedTime().asMilliseconds() > 100) {
        //Si table de craft ouverte et la premiere case contient un objet
        if (tableCraft->open && tableCraft->objet1EnPlace) {

            //Si on clique sur le plus
            if (tableCraft->sprite_plus1.getGlobalBounds().contains(positionSourisX, positionSourisY) && souris.isButtonPressed(souris.Left)) {
                //Si c'est possible de mettre plus
                int nbrEfface = -1;
                for (int l = 0; l < idMateriaux.size(); l++) {
                    if (idMateriaux.at(l) == tableCraft->idObj1) {
                        tableCraft->nbrItem1++;
                        quantite.at(l)--;
                        if (quantite.at(l) == 0) {
                            nbrEfface = l;
                        }
                    }
                }
                if (nbrEfface != -1) {
                    idMateriaux.erase(idMateriaux.begin() + nbrEfface);
                    quantite.erase(quantite.begin() + nbrEfface);
                    curseur--;
                    if (curseur == -1) {
                        curseur = idMateriaux.size() - 1;
                    }
                }
                tableCraft->productionResultat(&imgStock);
            }

            //Si on clique sur le moin
            if (tableCraft->sprite_moins1.getGlobalBounds().contains(positionSourisX, positionSourisY) && souris.isButtonPressed(souris.Left)) {

                bool existe = false;
                for (int l = 0; l < idMateriaux.size(); l++) {
                    if (idMateriaux.at(l) == tableCraft->idObj1) {
                        if (tableCraft->nbrItem1 > 1) {
                            tableCraft->nbrItem1--;
                            quantite.at(l)++;
                        }

                        existe = true;
                    }
                }

                if (!existe && tableCraft->nbrItem1 > 1) {
                    idMateriaux.push_back(tableCraft->idObj1);
                    quantite.push_back(1);
                    tableCraft->nbrItem1--;
                    curseur = idMateriaux.size() - 1;
                }
                tableCraft->productionResultat(&imgStock);
            }
        }
        //Si table de craft ouverte et la deuxième case contient un objet
        if (tableCraft->open && tableCraft->objet2EnPlace) {

            //Si on clique sur le plus
            if (tableCraft->sprite_plus2.getGlobalBounds().contains(positionSourisX, positionSourisY) && souris.isButtonPressed(souris.Left)) {
                //Si c'est possible de mettre plus
                int nbrEfface = -1;
                for (int l = 0; l < idMateriaux.size(); l++) {
                    if (idMateriaux.at(l) == tableCraft->idObj2) {
                        tableCraft->nbrItem2++;
                        quantite.at(l)--;
                        if (quantite.at(l) == 0) {
                            nbrEfface = l;
                        }
                    }
                }
                if (nbrEfface != -1) {
                    idMateriaux.erase(idMateriaux.begin() + nbrEfface);
                    quantite.erase(quantite.begin() + nbrEfface);
                    curseur--;
                    if (curseur == -1) {
                        curseur = idMateriaux.size() - 1;
                    }
                }
                tableCraft->productionResultat(&imgStock);
            }

            //Si on clique sur le moin
            if (tableCraft->sprite_moins2.getGlobalBounds().contains(positionSourisX, positionSourisY) && souris.isButtonPressed(souris.Left)) {

                bool existe = false;
                for (int l = 0; l < idMateriaux.size(); l++) {
                    if (idMateriaux.at(l) == tableCraft->idObj2) {
                        if (tableCraft->nbrItem2 > 1) {
                            tableCraft->nbrItem2--;
                            quantite.at(l)++;
                        }

                        existe = true;
                    }
                }

                if (!existe && tableCraft->nbrItem2 > 1) {
                    idMateriaux.push_back(tableCraft->idObj2);
                    quantite.push_back(1);
                    tableCraft->nbrItem2--;
                    curseur = idMateriaux.size() - 1;
                }
                tableCraft->productionResultat(&imgStock);
            }
        }
        tempsAttenteAjoutRetrait.restart();
    }
    
    //Si la table de craft ferme on rend les obj
    if (tableCraft->open) {
        tableCraftOuverte = true;
    }
    else if (!tableCraft->open && tableCraftOuverte) {
        tableCraftOuverte = false;

        //On rend les objets restant au joueur
        if (tableCraft->objet1EnPlace) {
            bool existe = false;
            for (int l = 0; l < idMateriaux.size(); l++) {
                if (idMateriaux.at(l) == tableCraft->idObj1) {
                    
                    quantite.at(l) += tableCraft->nbrItem1;
                    tableCraft->nbrItem1 = 0;

                    existe = true;
                }
            }

            if (!existe) {
                idMateriaux.push_back(tableCraft->idObj1);
                quantite.push_back(tableCraft->nbrItem1);
                tableCraft->nbrItem1 = 0;
                curseur = idMateriaux.size() - 1;
            }
        }
        if (tableCraft->objet2EnPlace) {
            bool existe = false;
            for (int l = 0; l < idMateriaux.size(); l++) {
                if (idMateriaux.at(l) == tableCraft->idObj2) {
                    
                    quantite.at(l) += tableCraft->nbrItem2;
                    tableCraft->nbrItem2 = 0;

                    existe = true;
                }
            }

            if (!existe) {
                idMateriaux.push_back(tableCraft->idObj2);
                quantite.push_back(tableCraft->nbrItem2);
                tableCraft->nbrItem2 = 0;
                curseur = idMateriaux.size() - 1;
            }
        }

        //Reinitialisation des variables de la table de craft
        tableCraft->idObj1 = 0;
        tableCraft->idObj2 = 0;
        tableCraft->idObjResult = 0;
        tableCraft->idObjResultNombre = 0;
        tableCraft->objet1EnPlace = false;
        tableCraft->objet2EnPlace = false;
        tableCraft->nbrItem1 = 0;
        tableCraft->nbrItem2 = 0;

        tableCraft->ui = 0;
        tableCraft->ui2 = 0;
        tableCraft->verr = false;
        tableCraft->afficheResultat = false;
        tableCraft->sprite_jauge.setTextureRect(IntRect(128, 130, 23, 23));
        tableCraft->sprite_materiaux1 = Sprite();
        tableCraft->sprite_materiaux2 = Sprite();
        tableCraft->sprite_materiaux3 = Sprite();

    }

    //On ramasse le resultat du craft
    if (tableCraft->open && tableCraft->objet1EnPlace && tableCraft->objet2EnPlace) {
        if (souris.isButtonPressed(souris.Left) && tableCraft->sprite_caseResult.getGlobalBounds().contains(positionSourisX, positionSourisY)) {

            if (tableCraft->fiche == 1) {
                fichetmp.loadFromFile("res/img/informations/info_bois.png");
                fichetmp_sprite.setTexture(fichetmp);
                afficheFiche = true;
                tableCraft->fiche = -1;
            }
            else if (tableCraft->fiche == 2) {
                fichetmp.loadFromFile("res/img/informations/info_pierre.png");
                fichetmp_sprite.setTexture(fichetmp);
                afficheFiche = true;
                tableCraft->fiche = -1;
            }
            else {
                bool dejaPresent = false;
                for (int j = 0; j < idMateriaux.size(); j++) {
                    if (idMateriaux.at(j) == tableCraft->idObjResult) {
                        quantite.at(j) += tableCraft->idObjResultNombre;
                        dejaPresent = true;
                    }
                }
                if (!dejaPresent) {
                    idMateriaux.push_back(tableCraft->idObjResult);
                    quantite.push_back(tableCraft->idObjResultNombre);
                }
            }

            //Reinitialisation des variables de la table de craft
            tableCraft->idObj1 = 0;
            tableCraft->idObj2 = 0;
            tableCraft->idObjResult = 0;
            tableCraft->idObjResultNombre = 0;
            tableCraft->objet1EnPlace = false;
            tableCraft->objet2EnPlace = false;
            tableCraft->nbrItem1 = 0;
            tableCraft->nbrItem2 = 0;

            tableCraft->ui = 0;
            tableCraft->ui2 = 0;
            tableCraft->verr = false;
            tableCraft->afficheResultat = false;
            tableCraft->sprite_jauge.setTextureRect(IntRect(128, 130, 23, 23));
            tableCraft->sprite_materiaux1 = Sprite();
            tableCraft->sprite_materiaux2 = Sprite();
            tableCraft->sprite_materiaux3 = Sprite();
        }
    }
    if (afficheFiche) {
        fichetmp_sprite.setPosition(x+225,y-350);
        if (souris.isButtonPressed(souris.Left) && fichetmp_sprite.getGlobalBounds().contains(positionSourisX, positionSourisY)) {
            afficheFiche = false;
        }
        window.draw(fichetmp_sprite);
    }

    if (idMateriaux.size() > 0) {
       
        if (souris.isButtonPressed(souris.Left)&& sprite_flecheG.getGlobalBounds().contains(positionSourisX, positionSourisY)  && !enAppuie) {
            curseur--;
            if (curseur == -1) {
                curseur = idMateriaux.size()-1;
            }
            enAppuie = true;
        }
        else if (souris.isButtonPressed(souris.Left) && sprite_flecheD.getGlobalBounds().contains(positionSourisX, positionSourisY) && !enAppuie) {
            curseur++;
            if (curseur == idMateriaux.size()) {
                curseur = 0;
            }
            enAppuie = true;
        }
        else if (((souris.isButtonPressed(souris.Left) && sprite_materiaux.getGlobalBounds().contains(positionSourisX, positionSourisY)) || souris.isButtonPressed(souris.Middle)) && !enAppuie) {
            if (souris.isButtonPressed(souris.Middle)) {
                enAppuieMiddle = true;
                first = true;
            }
            enSelection = true;
            enAppuie = true;
        }
        else if (enAppuie && !souris.isButtonPressed(souris.Left)) enAppuie = false;


        if (enAppuieMiddle && (souris.isButtonPressed(souris.Middle) || souris.isButtonPressed(souris.Left)) && !first) {
            enAppuieMiddle = false;
        }
        if (first && !souris.isButtonPressed(souris.Middle)) {
            first = false;
        }
        
        
        if (enSelection) {
            cercleSelection.setPosition(x, y);
            
            sprite_materiaux.setPosition(positionSourisX, positionSourisY);

            if (mouseWheelB) {
                rotationM += 10;
                sprite_materiaux.setRotation(rotationM);
            }
            else if (mouseWheelH) {
                rotationM -= 10;
                sprite_materiaux.setRotation(rotationM);
            }

            if (!souris.isButtonPressed(souris.Left) && !enAppuieMiddle) {
                bool ok = false;
                int dansRayonDAction = (positionSourisX - x - 32) * cos(anglePoints(x, y, positionSourisX, positionSourisY)) + (positionSourisY - y - 32) * sin(anglePoints(x, y, positionSourisX, positionSourisY));
                
                //Pose un materiaux dans la table de craft
                if (tableCraft->open) {
                    if (tableCraft->sprite_case1.getGlobalBounds().intersects(sprite_materiaux.getGlobalBounds())) {
                        
                        //On rend l'objet initiale et sa quantité avant remplacement
                        if (tableCraft->idObj1 != 0) {
                            bool existe = false;
                            for (int l = 0; l < idMateriaux.size(); l++) {
                                if (idMateriaux.at(l) == tableCraft->idObj1) {

                                    quantite.at(l) += tableCraft->nbrItem1;
                                    tableCraft->nbrItem1 = 0;

                                    existe = true;
                                }
                            }

                            if (!existe) {
                                idMateriaux.push_back(tableCraft->idObj1);
                                quantite.push_back(tableCraft->nbrItem1);
                                tableCraft->nbrItem1 = 0;
                            }
                        }

                        tableCraft->ajoutMateriaux(&imgStock, idMateriaux.at(curseur), 1);
                        tableCraft->productionResultat(&imgStock);

                        quantite.at(curseur)--;
                        if (quantite.at(curseur) == 0) {
                            quantite.erase(quantite.begin() + curseur);
                            idMateriaux.erase(idMateriaux.begin() + curseur);
                            curseur--;
                            if (curseur == -1) {
                                curseur = 0;
                            }
                        }
                    }
                    if (tableCraft->sprite_case2.getGlobalBounds().intersects(sprite_materiaux.getGlobalBounds())) {

                        if (tableCraft->idObj2 != 0) {
                            bool existe = false;
                            for (int l = 0; l < idMateriaux.size(); l++) {
                                if (idMateriaux.at(l) == tableCraft->idObj2) {

                                    quantite.at(l) += tableCraft->nbrItem2;
                                    tableCraft->nbrItem2 = 0;

                                    existe = true;
                                }
                            }

                            if (!existe) {
                                idMateriaux.push_back(tableCraft->idObj2);
                                quantite.push_back(tableCraft->nbrItem2);
                                tableCraft->nbrItem2 = 0;
                            }
                        }

                        tableCraft->ajoutMateriaux(&imgStock, idMateriaux.at(curseur), 2);
                        tableCraft->productionResultat(&imgStock);

                        quantite.at(curseur)--;
                        if (quantite.at(curseur) == 0) {
                            quantite.erase(quantite.begin() + curseur);
                            idMateriaux.erase(idMateriaux.begin() + curseur);
                            curseur--;
                            if (curseur == -1) {
                                curseur = 0;
                            }
                        }
                    }

                }

                //Depose un materiaux au sol
                else if ( dansRayonDAction <= 128 ) {
                    ok = true;
                }
                if (ok) {
                    //Si le materiaux en question est une pioche, on verifie si il y a un autre materiaux en dessous
                    if (idMateriaux.at(curseur) == 15) {
                        bool piocheSurMateriaux = false;
                        for (int y = 0; y < listeDeMateriauxJoueur->size(); y++) {
                            if (listeDeMateriauxJoueur->at(y)->getSprite().getGlobalBounds().contains(positionSourisX, positionSourisY)) {

                                bool dejaPresent = false;
                                for (int j = 0; j < idMateriaux.size(); j++) {
                                    if (idMateriaux.at(j) == listeDeMateriauxJoueur->at(y)->idMateriaux) {
                                        quantite.at(j)++;
                                        dejaPresent = true;
                                    }
                                }
                                if (!dejaPresent) {
                                    idMateriaux.push_back(listeDeMateriauxJoueur->at(y)->idMateriaux);
                                    quantite.push_back(1);
                                }

                                listeDeMateriauxPoubelle->push_back(listeDeMateriauxJoueur->at(y));
                                listeDeMateriauxJoueur->erase(listeDeMateriauxJoueur->begin() + y);

                                quantite.at(curseur)--;
                                if (quantite.at(curseur) == 0) {
                                    quantite.erase(quantite.begin() + curseur);
                                    idMateriaux.erase(idMateriaux.begin() + curseur);
                                    curseur--;
                                    if (curseur == -1) {
                                        curseur = 0;
                                    }
                                }
                                sprite_materiaux.setPosition(-390 + x + 50, -420 + y + 50);
                                rotationM = 0.0;
                                sprite_materiaux.setRotation(rotationM);
                                piocheSurMateriaux = true;
                                break;
                            }
                        }
                        if (!piocheSurMateriaux) {
                            Materiaux poseAuSol = Materiaux(positionSourisX, positionSourisY, imgStock.getImageByID(idMateriaux.at(curseur)), idMateriaux.at(curseur), rotationM);
                            listeDeMateriaux->push_back(poseAuSol);
                            listeDeMateriauxJoueur->push_back(&listeDeMateriaux->at(listeDeMateriaux->size() - 1));

                            quantite.at(curseur)--;
                            if (quantite.at(curseur) == 0) {
                                quantite.erase(quantite.begin() + curseur);
                                idMateriaux.erase(idMateriaux.begin() + curseur);
                                curseur--;
                                if (curseur == -1) {
                                    curseur = 0;
                                }
                            }
                            sprite_materiaux.setPosition(-390 + x + 50, -420 + y + 50);
                            rotationM = 0.0;
                            sprite_materiaux.setRotation(rotationM);
                        }
                    }

                    //Depose materiaux au sol (de façon ordianire)
                    else {
                        Materiaux poseAuSol = Materiaux(positionSourisX, positionSourisY, imgStock.getImageByID(idMateriaux.at(curseur)), idMateriaux.at(curseur), rotationM);
                        listeDeMateriaux->push_back(poseAuSol);
                        listeDeMateriauxJoueur->push_back(&listeDeMateriaux->at(listeDeMateriaux->size() - 1));

                        quantite.at(curseur)--;
                        if (quantite.at(curseur) == 0) {
                            quantite.erase(quantite.begin() + curseur);
                            idMateriaux.erase(idMateriaux.begin() + curseur);
                            curseur--;
                            if (curseur == -1) {
                                curseur = 0;
                            }
                        }
                        sprite_materiaux.setPosition(-390 + x + 50, -420 + y + 50);
                        rotationM = 0.0;
                        sprite_materiaux.setRotation(rotationM);
                    }
                    
                    
                }

                enSelection = false;
            }
            else if (souris.isButtonPressed(souris.Right)) {
                sprite_materiaux.setPosition(-390 + x + 50, -420 + y + 50);
                rotationM = 0.0;
                sprite_materiaux.setRotation(rotationM);
                enSelection = false;
            }
            
            window.draw(cercleSelection);
        }
        else {
            sprite_materiaux.setPosition(-390 + x + 50, -420 + y + 50);
            rotationM = 0.0;
            sprite_materiaux.setRotation(rotationM);

            if (mouseWheelB) {
                curseur--;
                if (curseur == -1) {
                    curseur = idMateriaux.size() - 1;
                }
            }
            else if (mouseWheelH) {
                curseur++;
                if (curseur == idMateriaux.size()) {
                    curseur = 0;
                }
            }
        }


        if (idMateriaux.size() > 0) {
            sprite_materiaux.setTexture(*imgStock.getImageByID(idMateriaux.at(curseur)));
            window.draw(sprite_materiaux);
        

            char leNombre[3];
            sprintf_s(leNombre, "%d", quantite.at(curseur));
            nombreDeItem.setString(leNombre);
            nombreDeItem.setPosition(-390 + x + 60, -420 + y + 45);
            window.draw(nombreDeItem);
        }
    }
    
}

//gives the angle from point one to point two
float Inventaire::anglePoints(int x1, int y1, int x2, int y2)
{
    return atan2(y2 - y1, x2 - x1);
}

//gives the true angle from point one to point two
float Inventaire::anglePointsDegree(int x1, int y1, int x2, int y2)
{
    float prem = atan2(y2 - y1, x2 - x1);
    if (prem <= 0) {
        return abs(prem) * 60;
    }
    else {
        return 360 - (prem * 60);
    }

}