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
}

void Inventaire::initialiseListeMateriaux(vector<Materiaux>* laListe) {
    listeDeMateriaux = laListe;
}

void Inventaire::afficheInventaire(RenderWindow& window, int x, int y) {
    int positionSourisX = souris.getPosition().x + x - window.getPosition().x - 450;
    int positionSourisY = souris.getPosition().y + y - window.getPosition().y - 475;

    sprite_inventaire.setPosition(-390 + x, -420 + y);
    sprite_flecheG.setPosition(-440 + x, -395 + y);
    sprite_flecheD.setPosition(-295 + x, -395 + y);

    window.draw(sprite_inventaire);
    window.draw(sprite_flecheG);
    window.draw(sprite_flecheD);

    if (idMateriaux.size() > 0) {
       
        if (souris.isButtonPressed(souris.Left) && sprite_flecheG.getGlobalBounds().contains(positionSourisX, positionSourisY) && !enAppuie) {
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
        else if (souris.isButtonPressed(souris.Left) && sprite_materiaux.getGlobalBounds().contains(positionSourisX, positionSourisY) && !enAppuie) {
            
            enSelection = true;
            enAppuie = true;
        }
        else if (enAppuie && !souris.isButtonPressed(souris.Left)) enAppuie = false;

        if (enSelection) {

            cercleSelection.setPosition(x, y);
            sprite_materiaux.setPosition(positionSourisX - 28, positionSourisY - 28);

            if (!souris.isButtonPressed(souris.Left)) {
                bool ok = false;
                for (int i = 0; i < cercleSelection.getPointCount(); i++) {
                    if (sprite_materiaux.getGlobalBounds().contains((cercleSelection.getTransform().transformPoint(cercleSelection.getPoint(i)).x+x)/2, (cercleSelection.getTransform().transformPoint(cercleSelection.getPoint(i)).y+y)/2  )) {
                        ok = true;
                    }
                }
                if (ok) {
                    listeDeMateriaux->push_back(Materiaux(positionSourisX, positionSourisY, imgStock.getImageByID(idMateriaux.at(curseur)), idMateriaux.at(curseur)));
                    
                    quantite.at(curseur)--;
                    if (quantite.at(curseur) == 0) {
                        quantite.erase(quantite.begin() + curseur);
                        idMateriaux.erase(idMateriaux.begin() + curseur);
                        curseur--;
                        if (curseur == -1) {
                            curseur = 0;
                        }
                    }
                    sprite_materiaux.setPosition(-390 + x + 26, -420 + y + 24);
                    
                }
                enSelection = false;
            }
            
            window.draw(cercleSelection);
        }
        else {
            sprite_materiaux.setPosition(-390 + x + 26, -420 + y + 24);
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
