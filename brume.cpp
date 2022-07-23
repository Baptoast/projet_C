#include "brume.h"

//Constructeur perso 
Brume::Brume() {
    loadTextureBrume();
    seed = 1456.0;
    srand(seed);
}

//Fonctions
//Permet de telecharger la texture du perso dans le dossier res
void Brume::loadTextureBrume()
{
    if (!texture_brume.loadFromFile("res/img/brume.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_brume.setTexture(texture_brume);
        sprite_brume.setOrigin(192, 192);
    }
    
    laBrume.setRadius(13450.0);
    laBrume.setOrigin(13450.0, 13450.0);
    laBrume.setPointCount(12);
    
    /*
    for (int i = 0; i < 5; i++) {
        particule nouvelParticule;
        nouvelParticule.rotate = i;
        float x = rand() % 960;
        float y = rand() % 960;
        nouvelParticule.x = x;
        nouvelParticule.y = y;
        nouvelParticule.laParticule.setPosition(x, y);
        nouvelParticule.laParticule.setTexture(texture_brume);
        nouvelParticule.laParticule.setOrigin(24, 24);
        listeEffetBrume.push_back(nouvelParticule);
    }*/

    for (int i = 0; i < 12; i++) {
        Sprite point;
        point.setTexture(texture_brume);
        point.setOrigin(192, 192);
        point.setColor(Color(255,255,255,200));
        point.scale(15,15);
        point.setPosition(laBrume.getTransform().transformPoint(laBrume.getPoint(i)).x, laBrume.getTransform().transformPoint(laBrume.getPoint(i)).y);
        brumaille brum;
        brum.x = laBrume.getTransform().transformPoint(laBrume.getPoint(i)).x;
        brum.y = laBrume.getTransform().transformPoint(laBrume.getPoint(i)).y;
        brum.laParticuleDerriere = point;
        listeBrume.push_back(brum);
    }
    /*
    for (int i = 0; i < 19; i++) {
        // création d'un tableau de 3 vertex définissant un triangle
        VertexArray triangle(Quads, 4);
        

        triangle[0].texCoords = Vector2f(95, 37);
        triangle[1].texCoords = Vector2f(95+22, 37);
        triangle[2].texCoords = Vector2f(95, 37+22);
        triangle[3].texCoords = Vector2f(95 + 22, 37 + 22);

        triangle[0].color = Color(255,255,255,195);
        triangle[1].color = Color(255, 255, 255, 185);
        triangle[2].color = Color(255, 255, 255, 195);
        triangle[3].color = Color(255, 255, 255, 185);

        listeVertex.push_back(triangle);
    }*/
}

void Brume::initialiseListeMateriaux(vector<Materiaux>* laListe) {
    listeDeMateriaux = laListe;

}

void Brume::afficheBrume(RenderWindow& window,int xJ, int yJ) {
    
    

    //int dansRayonDAction = (positionSourisX - 32) * cos(anglePoints(x, y, positionSourisX, positionSourisY)) + (positionSourisY - y - 32) * sin(anglePoints(x, y, positionSourisX, positionSourisY));
    for (int i = 0; i < listeBrume.size(); i++) {
        
        
        bool avance = true;

        int taille = listeDeMateriaux->size();

        

        //Valeur à changer pour moins ramer dans le cas où sa rame
        if (listeBrume.at(i).avancementBrume.getElapsedTime().asMicroseconds() > 200) {
            
            for (int j = 0; j < taille; j++) {
                if (listeDeMateriaux->at(j).resistant >= 0) {
                    if (listeBrume.at(i).laParticuleDerriere.getGlobalBounds().contains(listeDeMateriaux->at(j).posX, listeDeMateriaux->at(j).posY)) {
                        int dansRayonDAction = abs((listeDeMateriaux->at(j).getSprite().getPosition().x - listeBrume.at(i).laParticuleDerriere.getPosition().x) * cos(anglePoints(listeDeMateriaux->at(j).getSprite().getPosition().x, listeDeMateriaux->at(j).getSprite().getPosition().y, listeBrume.at(i).laParticuleDerriere.getPosition().x, listeBrume.at(i).laParticuleDerriere.getPosition().y)) + (listeDeMateriaux->at(j).getSprite().getPosition().y - listeBrume.at(i).laParticuleDerriere.getPosition().y) * sin(anglePoints(listeDeMateriaux->at(j).getSprite().getPosition().x, listeDeMateriaux->at(j).getSprite().getPosition().y, listeBrume.at(i).laParticuleDerriere.getPosition().x, listeBrume.at(i).laParticuleDerriere.getPosition().y)));
                        if (dansRayonDAction <= 2850) {
                            listeBrume.at(i).ralentissement += 1.0;
                            listeDeMateriaux->at(j).resistant = listeDeMateriaux->at(j).resistant - 1;
                        }
                    }
                }
            }

            float alea = 10 / (7 - listeBrume.at(i).ralentissement) + 0.001;
            if (listeBrume.at(i).ralentissement > 7.0) {
                alea = 10 / 0.001;
            }
            

            float nouveauX = (listeBrume.at(i).x + cos(anglePoints(listeBrume.at(i).x, listeBrume.at(i).y, 0, 0)) / alea );
            float nouveauY = (listeBrume.at(i).y + sin(anglePoints(listeBrume.at(i).x, listeBrume.at(i).y, 0, 0)) / alea );

            listeBrume.at(i).ralentissement = 0.0;

            listeBrume.at(i).x = nouveauX;
            listeBrume.at(i).y = nouveauY;

           listeBrume.at(i).avancementBrume.restart();
        }
        
        listeBrume.at(i).laParticuleDerriere.setPosition(listeBrume.at(i).x, listeBrume.at(i).y);
        //ROTATION A REMETTRE
        listeBrume.at(i).laParticuleDerriere.setRotation(tourne);

        if (listeBrume.at(i).laParticule.getPosition().x > xJ - 10520 && listeBrume.at(i).laParticule.getPosition().x <= xJ + 10520 && listeBrume.at(i).laParticule.getPosition().y > yJ - 10520 && listeBrume.at(i).laParticule.getPosition().y <= yJ + 10520) {
            //Rajouter des textures brumeuses dans les vertex 
            /*
            if (i != listeBrume.size()-1) {
                 listeBrume.at(i).laParticuleDerriere.setPosition(listeBrume.at(i).x * cos(anglePoints(listeBrume.at(i).x, listeBrume.at(i).y, 0, 0)), listeBrume.at(i).y * sin(anglePoints(listeBrume.at(i).x, listeBrume.at(i).y, 0, 0)));
            }*/
            /*if (!listeBrume.at(i).bloquee) {
                listeBrume.at(i).laParticuleDerriere.setScale(listeBrume.at(i).laParticuleDerriere.getScale().x - alea / 50000, listeBrume.at(i).laParticuleDerriere.getScale().y - alea / 50000);
            }*/
            window.draw(listeBrume.at(i).laParticuleDerriere);

            
        }
    }
    tourne += 0.02;
    if (tourne == 360.0) {
        tourne = 0.0;
    }

    
    /*
    for (int i = 0; i < listeVertex.size(); i++) {
        if (listeBrume.at(i).laParticule.getPosition().x > xJ - 2020 && listeBrume.at(i).laParticule.getPosition().x <= xJ + 2020 && listeBrume.at(i).laParticule.getPosition().y > yJ - 2020 && listeBrume.at(i).laParticule.getPosition().y <= yJ + 2020) {
            if (listeBrume.at(i).laParticule.getPosition().x <= 0 && listeBrume.at(i).laParticule.getPosition().y <= 0) {
                listeVertex.at(i)[0].position = Vector2f(xJ - 520, yJ - 520);
            }
            else if (listeBrume.at(i).laParticule.getPosition().x > 0 && listeBrume.at(i).laParticule.getPosition().y <= 0) {
                listeVertex.at(i)[0].position = Vector2f(xJ + 520, yJ - 520);
            }
            else if (listeBrume.at(i).laParticule.getPosition().x <= 0 && listeBrume.at(i).laParticule.getPosition().y > 0) {
                listeVertex.at(i)[0].position = Vector2f(xJ - 520, yJ + 520);
            }
            else {
                listeVertex.at(i)[0].position = Vector2f(xJ + 520, yJ + 520);
            }

            if (listeBrume.at(i + 1).laParticule.getPosition().x <= 0 && listeBrume.at(i + 1).laParticule.getPosition().y <= 0) {
                listeVertex.at(i)[3].position = Vector2f(xJ - 520, yJ - 520);
            }
            else if (listeBrume.at(i + 1).laParticule.getPosition().x > 0 && listeBrume.at(i + 1).laParticule.getPosition().y <= 0) {
                listeVertex.at(i)[3].position = Vector2f(xJ + 520, yJ - 520);
            }
            else if (listeBrume.at(i + 1).laParticule.getPosition().x <= 0 && listeBrume.at(i + 1).laParticule.getPosition().y > 0) {
                listeVertex.at(i)[3].position = Vector2f(xJ - 520, yJ + 520);
            }
            else {
                listeVertex.at(i)[3].position = Vector2f(xJ + 520, yJ + 520);
            }

            listeVertex.at(i)[1].position = Vector2f(listeBrume.at(i).laParticule.getPosition().x, listeBrume.at(i).laParticule.getPosition().y);
            listeVertex.at(i)[2].position = Vector2f(listeBrume.at(i + 1).laParticule.getPosition().x, listeBrume.at(i + 1).laParticule.getPosition().y);
            
            //window.draw(listeVertex.at(i), &texture_brume);
        }
        
    }
    
    if (tempsAvantDisparitionObj.getElapsedTime().asSeconds() > 4) {
        vector<int> listeDeIntPourErase;
        int taille = listeDeMateriaux->size();
        for (int j = 0; j < taille; j++) {
            if (listeDeMateriaux->at(j).resistant == -1) {
                if (listeDeMateriaux->at(j).getSprite().getPosition().x > xJ - 500 && listeDeMateriaux->at(j).getSprite().getPosition().x <= xJ + 500 && listeDeMateriaux->at(j).getSprite().getPosition().y > yJ - 500 && listeDeMateriaux->at(j).getSprite().getPosition().y <= yJ + 500) {
                    int i = 0;
                    bool pasTrouver = true;
                    while (i < listeVertex.size() && pasTrouver) {
                        if (listeBrume.at(i).laParticule.getPosition().x > xJ - 500 && listeBrume.at(i).laParticule.getPosition().x <= xJ + 500 && listeBrume.at(i).laParticule.getPosition().y > yJ - 500 && listeBrume.at(i).laParticule.getPosition().y <= yJ + 500) {
                            int dansRayonDAction = listeBrume.at(i).laParticule.getPosition().x * cos(anglePoints(listeDeMateriaux->at(j).getSprite().getPosition().x, listeDeMateriaux->at(j).getSprite().getPosition().y, listeBrume.at(i).laParticule.getPosition().x, listeBrume.at(i).laParticule.getPosition().y)) + listeBrume.at(i).laParticule.getPosition().y * sin(anglePoints(listeDeMateriaux->at(j).getSprite().getPosition().x, listeDeMateriaux->at(j).getSprite().getPosition().y, listeBrume.at(i).laParticule.getPosition().x, listeBrume.at(i).laParticule.getPosition().y));
                            if (dansRayonDAction <= 128) {
                                if (listeVertex.at(i).getBounds().contains(listeDeMateriaux->at(j).getSprite().getPosition().x, listeDeMateriaux->at(j).getSprite().getPosition().y)) {
                                    listeDeIntPourErase.push_back(j);
                                    pasTrouver = false;
                                }
                            }
                        }
                        i++;
                    }
                }
            }
            
        }
        for (int i = 0; i < listeDeIntPourErase.size(); i++) {
            listeDeMateriaux->erase(listeDeMateriaux->begin() + listeDeIntPourErase.at(i) - i);

        }
        tempsAvantDisparitionObj.restart();
    }*/
    

    /*
    for (int i = 0; i < listeEffetBrume.size(); i++) {

        listeEffetBrume.at(i).rotate++;
        listeEffetBrume.at(i).laParticule.setRotation(listeEffetBrume.at(i).rotate);

        if (listeEffetBrume.at(i).rotate == 360) {
            float x = rand() % 960 - 480.0;
            float y = rand() % 960 - 480.0;
            listeEffetBrume.at(i).x = x;
            listeEffetBrume.at(i).y = y;
            listeEffetBrume.at(i).rotate = 0;
        }

        listeEffetBrume.at(i).laParticule.setPosition(xJ + listeEffetBrume.at(i).x, yJ + listeEffetBrume.at(i).y);
        for (int j = 0; j < listeVertex.size(); j++) {
            if (listeVertex.at(j).getBounds().contains(xJ + listeEffetBrume.at(i).x, yJ + listeEffetBrume.at(i).y)) {
                window.draw(listeEffetBrume.at(i).laParticule);
            }
            
        }

    }*/

}

//gives the angle from point one to point two
float Brume::anglePoints(int x1, int y1, int x2, int y2)
{
    return atan2(y2 - y1, x2 - x1);
}