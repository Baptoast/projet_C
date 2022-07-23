#include "table_craft.h"

//Constructeur perso 
TableCraft::TableCraft() {
    loadTextureTableCraft();

}

//Fonctions
//Permet de telecharger la texture du perso dans le dossier res
void TableCraft::loadTextureTableCraft()
{
    if (!texture_case.loadFromFile("res/img/caseCraft.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_case1.setTexture(texture_case);
        sprite_case2.setTexture(texture_case);
        sprite_caseResult.setTexture(texture_case);

        
    }
    if (!texture_conteneurDeJauge.loadFromFile("res/img/tubeCraft.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_conteneurDeJauge.setTexture(texture_conteneurDeJauge); 
    }
    if (!texture_jauge.loadFromFile("res/img/jaugeCraft.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_jauge.setTexture(texture_jauge);
        sprite_jauge.setTextureRect(IntRect(128,130,23,23));
        
    }
    if (!texture_fond.loadFromFile("res/img/fondCraft.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_fond.setTexture(texture_fond);
    }
    if (!texture_plus.loadFromFile("res/img/plus.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_plus1.setTexture(texture_plus);
        sprite_plus2.setTexture(texture_plus);
    }
    if (!texture_moins.loadFromFile("res/img/moins.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_moins1.setTexture(texture_moins);
        sprite_moins2.setTexture(texture_moins);
    }
    if (!font.loadFromFile("res/img/font/mytype.ttf")) {
        cout << "erreur de chargement de l'ecriture" << endl;
    }
    else {
        nombreDeItem1.setFont(font);
        nombreDeItem1.setString("0");
        nombreDeItem2.setFont(font);
        nombreDeItem2.setString("0");
    }

}

void TableCraft::ajoutMateriaux(Img* imageStock,int idMateriaux, int numCase) {
    if (numCase == 1) {
        sprite_materiaux1.setTexture(*imageStock->getImageByID(idMateriaux));
        objet1EnPlace = true;
        idObj1 = idMateriaux;
        nbrItem1 = 1;
        
    }
    if (numCase == 2) {
        sprite_materiaux2.setTexture(*imageStock->getImageByID(idMateriaux));
        objet2EnPlace = true;
        idObj2 = idMateriaux;
        nbrItem2 = 1;
        
    }
    
}

void TableCraft::productionResultat(Img* imageStock) {
    if (objet1EnPlace && objet2EnPlace) {

        if (idObj1 == 1 && nbrItem1 == 1 && idObj2 == 1 && nbrItem2 == 1) {
            idObjResult = 12;
            idObjResultNombre = 4;
        }
        else if (idObj1 == 5 && nbrItem1 == 1 && idObj2 == 5 && nbrItem2 == 1) {
            idObjResult = 13;
            idObjResultNombre = 4;
        }
        else if (idObj1 == 8 && nbrItem1 == 1 && idObj2 == 8 && nbrItem2 == 1) {
            idObjResult = 14;
            idObjResultNombre = 4;
        }
        else if (idObj1 == 1 && nbrItem1 == 1 && idObj2 == 5 && nbrItem2 == 1 || idObj1 == 5 && nbrItem1 == 1 && idObj2 == 1 && nbrItem2 == 1) {
            idObjResult = 15;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 1 && nbrItem1 == 5 && idObj2 == 6 && nbrItem2 == 2 || idObj1 == 6 && nbrItem1 == 2 && idObj2 == 1 && nbrItem2 == 5) {
            idObjResult = 16;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 1 && nbrItem1 == 2 && idObj2 == 2 && nbrItem2 == 10 || idObj1 == 2 && nbrItem1 == 10 && idObj2 == 1 && nbrItem2 == 2) {
            idObjResult = 17;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 1 && nbrItem1 == 2 && idObj2 == 3 && nbrItem2 == 10 || idObj1 == 3 && nbrItem1 == 10 && idObj2 == 1 && nbrItem2 == 2) {
            idObjResult = 18;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 1 && nbrItem1 == 2 && idObj2 == 4 && nbrItem2 == 10 || idObj1 == 4 && nbrItem1 == 10 && idObj2 == 1 && nbrItem2 == 2) {
            idObjResult = 19;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 7 && nbrItem1 == 1 && idObj2 == 5 && nbrItem2 == 1 || idObj1 == 5 && nbrItem1 == 1 && idObj2 == 7 && nbrItem2 == 1) {
            idObjResult = 20;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 6 && nbrItem1 == 4 && idObj2 == 5 && nbrItem2 == 10 || idObj1 == 5 && nbrItem1 == 10 && idObj2 == 6 && nbrItem2 == 4) {
            idObjResult = 11;
            idObjResultNombre = 1;
        }
        else if (idObj1 == 21 && nbrItem1 == 1 && idObj2 == 1 && nbrItem2 == 1 || idObj1 == 1 && nbrItem1 == 1 && idObj2 == 21 && nbrItem2 == 1) {
            idObjResult = 21;
            idObjResultNombre = 1;
            fiche = 1;
        }
        else if (idObj1 == 21 && nbrItem1 == 1 && idObj2 == 5 && nbrItem2 == 1 || idObj1 == 5 && nbrItem1 == 1 && idObj2 == 21 && nbrItem2 == 1) {
            idObjResult = 21;
            idObjResultNombre = 1;
            fiche = 2;
        }

        sprite_materiaux3.setTexture(*imageStock->getImageByID(idObjResult));

    }
}

void TableCraft::afficheRenduTableCraft(RenderWindow& window, int xJ, int yJ) {
    int x = xJ - 205;
    int y = yJ - 350;

    sprite_fond.setPosition(x, y);
    window.draw(sprite_fond);

    if (objet1EnPlace && sprite_jauge.getTextureRect().left > 0) {
        ui++;
        sprite_jauge.setTextureRect(IntRect(sprite_jauge.getTextureRect().left - 1, sprite_jauge.getTextureRect().top, sprite_jauge.getTextureRect().width + 1, sprite_jauge.getTextureRect().height));
    }
    if (objet1EnPlace && objet2EnPlace && sprite_jauge.getTextureRect().width < 281 && !verr) {
        sprite_jauge.setTextureRect(IntRect(sprite_jauge.getTextureRect().left, sprite_jauge.getTextureRect().top, sprite_jauge.getTextureRect().width + 1, sprite_jauge.getTextureRect().height));
    }
    if ((!objet1EnPlace && objet2EnPlace && sprite_jauge.getTextureRect().width < 153)) {
        sprite_jauge.setTextureRect(IntRect(sprite_jauge.getTextureRect().left, sprite_jauge.getTextureRect().top, sprite_jauge.getTextureRect().width + 1, sprite_jauge.getTextureRect().height));
        verr = true;
    }
    //DerniereJauge
    if (objet1EnPlace && objet2EnPlace && sprite_jauge.getTextureRect().width == 281 && sprite_jauge.getTextureRect().left == 0 && !afficheResultat) {
        if (sprite_jauge.getTextureRect().top > 0) {
            ui2++;
            sprite_jauge.setTextureRect(IntRect(sprite_jauge.getTextureRect().left, sprite_jauge.getTextureRect().top - 1, sprite_jauge.getTextureRect().width, sprite_jauge.getTextureRect().height + 1));
        }
        else {
            afficheResultat = true;
        }
    }

    sprite_case1.setPosition(x + 25, y + 206);
    sprite_materiaux1.setPosition(x + 25+8, y + 206+8);
    sprite_case2.setPosition(x + 368, y + 206);
    sprite_materiaux2.setPosition(x + 368+8, y + 206+8);
    sprite_caseResult.setPosition(x + 198, y + 26);
    sprite_materiaux3.setPosition(x + 198+8, y + 26+8);
    sprite_jauge.setPosition(x + 217-ui, y + 220- ui2);
    sprite_conteneurDeJauge.setPosition(x + 89, y + 90);

    sprite_plus1.setPosition(x + 20, y + 276);
    sprite_moins1.setPosition(x + 60, y + 276);

    sprite_plus2.setPosition(x + 20 + 343, y + 276);
    sprite_moins2.setPosition(x + 60 + 343, y + 276);

    nombreDeItem1.setPosition(x + 68, y + 230);
    nombreDeItem2.setPosition(x + 68 + 368 - 25, y + 230 );
    
    window.draw(sprite_jauge);
    window.draw(sprite_conteneurDeJauge);
    window.draw(sprite_case1);
    window.draw(sprite_case2);
    window.draw(sprite_caseResult);
    window.draw(sprite_materiaux1);
    window.draw(sprite_materiaux2);
    window.draw(sprite_plus1);
    window.draw(sprite_moins1);
    window.draw(sprite_plus2);
    window.draw(sprite_moins2);
    if (afficheResultat) {
        window.draw(sprite_materiaux3);
    }
    if (objet1EnPlace) {
        char leNombre[3];
        sprintf_s(leNombre, "%d", nbrItem1);
        nombreDeItem1.setString(leNombre);
        window.draw(nombreDeItem1);
    }
    if (objet2EnPlace) {
        char leNombre[3];
        sprintf_s(leNombre, "%d", nbrItem2);
        nombreDeItem2.setString(leNombre);
        window.draw(nombreDeItem2);
    }
    
}