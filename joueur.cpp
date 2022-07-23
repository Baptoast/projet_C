#include "joueur.h"

//Constructeur perso 
Joueur::Joueur(float x, float y, Inventaire* inventaireDuJoueur) {
    //attribut la position du joueur à sa génération
    setPosX(x);
    setPosY(y);

    Vector2i anim(1, Down);
    vitesse = 0;
    updateFPS = true;

    inventaire = inventaireDuJoueur;
}

//Getter
Joueur::Pos Joueur::getPos(void) const
{
    return posJoueur;
}

Sprite Joueur::getSprite() {
    return sprite_joueur;
}

//Setter
void Joueur::setInput(Input input) {
    inputPerso = input;
}

void Joueur::setPosX(float x)
{
    posJoueur.posX = x;
}
void Joueur::setPosY(float y)
{
    posJoueur.posY = y;
}




//Fonctions
//Permet de telecharger la texture du perso dans le dossier res
void Joueur::loadTexturePerso()
{
    if (!texture_joueur.loadFromFile("res/img/perso1.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_joueur.setTexture(texture_joueur);
    }
    if (!texture_boite.loadFromFile("res/img/chargement1.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_boite.setTexture(texture_boite);
    }
    if (!texture_chargement.loadFromFile("res/img/chargement2.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_chargement.setTexture(texture_chargement);
    }
    texture_joueur_slave.loadFromFile("res/img/perso1posses.png");
}

void Joueur::changementApparence(int num) {
    switch (num)
    {
    case 0: {
        sprite_joueur.setTexture(texture_joueur);
        compteurPossession = 0;
        estPossede = false;
        break;
    }
    case 1: {
        sprite_joueur.setTexture(texture_joueur_slave);
        estPossede = true;
        break;
    }
        
    }
}

//permet de determiner la vitesse de déplacement du perso
void Joueur::vitesseDeplacementPerso(int vitesse, vector<Materiaux *>& listeDesMateriaux) {
    if (timeDeplacementPerso.getElapsedTime().asMilliseconds() >= vitesse && !estPossede) {
        deplacementPerso(listeDesMateriaux);
        timeDeplacementPerso.restart();
    }
    else if (estPossede) {
        deplacementPersoPossede();
        timeDeplacementPerso.restart();
    }
}

//C'est pas toi qui décide en faite
void Joueur::deplacementPersoPossede() {
    setPosX(getPos().posX + 1.5 *cos(anglePoints(0, 0, getPos().posX, getPos().posY)));
    setPosY(getPos().posY + 1.5 * sin(anglePoints(0, 0, getPos().posX, getPos().posY)) + effet);

    if (!reverseEffet) {
        effet += 0.01;
    }
    else {
        effet -= 0.01;
    }
    if (effet >= 0.8 || effet <= -0.8) {
        reverseEffet = !reverseEffet;
    }
    
    sprite_joueur.setPosition(getPos().posX , getPos().posY);
    compteurPossession++;
    if (compteurPossession >= 1000) {
        changementApparence(0);
    }
}

//Dirige le personnage
void Joueur::deplacementPerso(vector<Materiaux *>& listeDesMateriaux) {
    int memoX = getPos().posX;
    int memoY = getPos().posY;

    updateFPS = false;
    vitesse = 4;
    
    if (inputPerso.GetButton().left == true) {
        if (inputPerso.GetButton().clicG != true) {
            anim.y = Left;
        }
        updateFPS = true;
        setPosX(getPos().posX - 1);
        if (inputPerso.GetButton().shift == true) {
            setPosX(getPos().posX - 1);
        }
        if (effetTotemSpeed) {
            setPosX(getPos().posX - 1);
        }
    }
    if (inputPerso.GetButton().right == true) {
        if (inputPerso.GetButton().clicG != true) {
            anim.y = Right;
        }
        updateFPS = true;
        setPosX(getPos().posX + 1);
        if (inputPerso.GetButton().shift == true) {
            setPosX(getPos().posX + 1);
        }
        if (effetTotemSpeed) {
            setPosX(getPos().posX + 1);
        }
    }
    if (inputPerso.GetButton().down == true) {
        if (inputPerso.GetButton().clicG != true) {
            anim.y = Down;
        }
        updateFPS = true;
        setPosY(getPos().posY + 1);
        if (inputPerso.GetButton().shift == true) {
            setPosY(getPos().posY + 1);
        }
        if (effetTotemSpeed) {
            setPosY(getPos().posY + 1);
        }
    }
    if (inputPerso.GetButton().up == true) {
        if (inputPerso.GetButton().clicG != true) {
            anim.y = Up;
        }
        updateFPS = true;
        setPosY(getPos().posY - 1);
        if (inputPerso.GetButton().shift == true) {
            setPosY(getPos().posY - 1);
        }
        if (effetTotemSpeed) {
            setPosY(getPos().posY - 1);
        }
    }
    
    for (int i = 0; i < listeDesMateriaux.size(); i++) {
        if (dansChampDeVision(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y)) {
            if (listeDesMateriaux.at(i)->getSprite().getGlobalBounds().contains(getPos().posX + 22, getPos().posY + 38)) {
                setPosX(memoX);
                setPosY(memoY);
            }
        }
    }

    sprite_joueur.setPosition(getPos().posX, getPos().posY);

    

}

//Fonction qui donne l'annimation du perso en fonction de sa direction
void Joueur::animationPerso(int y) {

    if (updateFPS) {
        if (timeAnimationPerso.getElapsedTime().asMilliseconds() >= 140) {
            anim.x++;
            if (anim.x * 48 >= texture_joueur.getSize().x) {
                anim.x = 0;
            }
            timeAnimationPerso.restart();
        }
    }
    else {
        anim.x = 1;
    }

    sprite_joueur.setTextureRect(IntRect(anim.x * 48, anim.y * 48 + y, 48, 48));
}

//Prolongation de la boucle principale.
//Dessine le perso dans la fenêtre
void Joueur::controlePerso(RenderWindow& window, vector<Materiaux*>& listeDesMateriaux, vector<Materiaux* >& listeDesMateriauxPoubelle) {
    
    if (!estPossede) {

        //Test pour chaque materiaux si le joueur est dans sa zone 
        for (int i = 0; i < listeDesMateriaux.size(); i++) {
            //Totem de speed
            if (listeDesMateriaux.at(i)->idMateriaux == 17) {
                int posJoueurX = getPos().posX + 24;
                int posJoueurY = getPos().posY + 32;
                int dansRayonDAction = abs((listeDesMateriaux.at(i)->getSprite().getPosition().x - posJoueurX) * cos(anglePoints(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y, posJoueurX, posJoueurY)) + (listeDesMateriaux.at(i)->getSprite().getPosition().y - posJoueurY) * sin(anglePoints(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y, posJoueurX, posJoueurY)));
                if (dansRayonDAction <= 250) {
                    effetTotemSpeed = true;
                }
                else {
                    effetTotemSpeed = false;
                }
            }
            else if (listeDesMateriaux.at(i)->idMateriaux == 18) {
                int posJoueurX = getPos().posX + 24;
                int posJoueurY = getPos().posY + 32;
                int dansRayonDAction = abs((listeDesMateriaux.at(i)->getSprite().getPosition().x - posJoueurX) * cos(anglePoints(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y, posJoueurX, posJoueurY)) + (listeDesMateriaux.at(i)->getSprite().getPosition().y - posJoueurY) * sin(anglePoints(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y, posJoueurX, posJoueurY)));
                if (dansRayonDAction <= 250) {
                    effetTotemRecupSpeed = true;
                }
                else {
                    effetTotemRecupSpeed = false;
                }
            }
        }

        if (inputPerso.GetButton().clicG) {
            ramasseMateriaux(window,listeDesMateriaux, listeDesMateriauxPoubelle);
        }
        else {
            ramassage = 0;
        }

        if (inputPerso.GetButton().clicD) {
            consultationMateriaux(window, listeDesMateriaux);
        }

        if (dansTableCraft) {
            bool fermeture = true;
            //On check pour tout les blocs
            for (int i = 0; i < listeDesMateriaux.size(); i++) {
                //Si ils sont à la portés
                if (listeDesMateriaux.at(i)->idMateriaux == 11) {
                    if (dansChampDeVision(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y)) {
                        if (listeDesMateriaux.at(i)->getSprite().getPosition().x <= getPos().posX + 80 && listeDesMateriaux.at(i)->getSprite().getPosition().x >= getPos().posX - 28 && listeDesMateriaux.at(i)->getSprite().getPosition().y <= getPos().posY + 75 && listeDesMateriaux.at(i)->getSprite().getPosition().y >= getPos().posY - 28) {
                            fermeture = false;
                        }
                    }
                }
            }
            if (fermeture == true) {
                //On rend les objets de la table de craft à l'inventaire
                dansTableCraft = false;
            }
        }
        animationPerso(0);
    }

    vitesseDeplacementPerso(vitesse, listeDesMateriaux);
    
    window.draw(sprite_joueur);
}

void Joueur::consultationMateriaux(RenderWindow& window, vector<Materiaux *>& listeDesMateriaux) {

    int positionSourisX = laSouris.getPosition().x + getPos().posX - window.getPosition().x - 450;
    int positionSourisY = laSouris.getPosition().y + getPos().posY - window.getPosition().y - 475;

    //On check pour tout les blocs
    for (int i = 0; i < listeDesMateriaux.size(); i++) {
        if (dansChampDeVision(listeDesMateriaux.at(i)->getSprite().getPosition().x, listeDesMateriaux.at(i)->getSprite().getPosition().y)) {
            //Si ils sont à la portés
            if (listeDesMateriaux.at(i)->getSprite().getPosition().x <= getPos().posX + 80 && listeDesMateriaux.at(i)->getSprite().getPosition().x >= getPos().posX - 28 && listeDesMateriaux.at(i)->getSprite().getPosition().y <= getPos().posY + 75 && listeDesMateriaux.at(i)->getSprite().getPosition().y >= getPos().posY - 28) {
                //Que la souris est dessus
                if (listeDesMateriaux.at(i)->getSprite().getGlobalBounds().contains(positionSourisX, positionSourisY)) {
                    if (listeDesMateriaux.at(i)->idMateriaux == 11) {
                        dansTableCraft = true;
                    }

                }
            }
        }
    }
}

void Joueur::ramasseMateriaux(RenderWindow& window, vector<Materiaux*>& listeDesMateriaux, vector<Materiaux* >& listeDesMateriauxPoubelle) {
    
    int positionSourisX = laSouris.getPosition().x + getPos().posX - window.getPosition().x-450;
    int positionSourisY = laSouris.getPosition().y + getPos().posY - window.getPosition().y - 475;

    //On check pour tout les blocs
    for (int i = 0; i < listeDesMateriaux.size(); i++) {
        //Si ils sont à la portés
        if (listeDesMateriaux.at(i)->getSprite().getPosition().x <= getPos().posX + 80 && listeDesMateriaux.at(i)->getSprite().getPosition().x >= getPos().posX-28 && listeDesMateriaux.at(i)->getSprite().getPosition().y <= getPos().posY + 75 && listeDesMateriaux.at(i)->getSprite().getPosition().y >= getPos().posY-28) {
            //Que la souris est dessus
            if (listeDesMateriaux.at(i)->getSprite().getGlobalBounds().contains(positionSourisX, positionSourisY)) {
           
                sprite_boite.setPosition(getPos().posX, getPos().posY - 32);
                window.draw(sprite_boite);

                sprite_chargement.setPosition(getPos().posX, getPos().posY - 32);
                sprite_chargement.setTextureRect(IntRect(0, 0, 48* ramassage / listeDesMateriaux.at(i)->solidite, 24));
                window.draw(sprite_chargement);

                ramassage+= 4;
                if (effetTotemRecupSpeed) {
                    ramassage += 4;
                }

                if (ramassage >= listeDesMateriaux.at(i)->solidite) {
                    bool dejaPresent = false;
                    for (int j = 0; j < inventaire->idMateriaux.size(); j++) {
                        if (inventaire->idMateriaux.at(j) == listeDesMateriaux.at(i)->idMateriaux) {
                            inventaire->quantite.at(j)++;
                            dejaPresent = true;
                        }
                    }
                    if (!dejaPresent) {
                        inventaire->idMateriaux.push_back(listeDesMateriaux.at(i)->idMateriaux);
                        inventaire->quantite.push_back(1);
                    }

                    listeDesMateriauxPoubelle.push_back(listeDesMateriaux.at(i));
                    listeDesMateriaux.erase(listeDesMateriaux.begin() + i);
                    ramassage = 0;
                }
                
            }
        }
    }
}

//gives the angle from point one to point two
float Joueur::anglePoints(int x1, int y1, int x2, int y2)
{
    return atan2(y2 - y1, x2 - x1);
}

//gives the true angle from point one to point two
float Joueur::anglePointsDegree(int x1, int y1, int x2, int y2)
{
    float prem = atan2(y2 - y1, x2 - x1);
    if (prem <= 0) {
        return abs(prem) * 60;
    }
    else {
        return 360 - (prem * 60);
    }

}

bool Joueur::dansChampDeVision(int xObj, int yObj) {
    if (xObj > getPos().posX - 540 && xObj <= getPos().posX + 540 && yObj > getPos().posY - 540 && yObj <= getPos().posY + 540) {
        return true;
    }
    return false;
}