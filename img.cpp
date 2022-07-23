#include "img.h"

//Constructeur perso 
Img::Img() {
    loadTextures();

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
void Img::loadTextures() {
    if (!bois.loadFromFile("res/img/materiaux/bois.png")) {}
    if (!pierre1.loadFromFile("res/img/materiaux/pierre.png")) {}
    if (!pierre2.loadFromFile("res/img/materiaux/pierre2.png")) {}
    if (!pierre3.loadFromFile("res/img/materiaux/pierre3.png")) {}
    if (!fleur1.loadFromFile("res/img/materiaux/fleur1.png")) {}
    if (!fleur2.loadFromFile("res/img/materiaux/fleur2.png")) {}
    if (!fleur3.loadFromFile("res/img/materiaux/fleur3.png")) {}
    if (!fleur4.loadFromFile("res/img/materiaux/fleur3.png")) {} //temporaire
    if (!table_craft.loadFromFile("res/img/materiaux/table_craft.png")) {}
    if (!mur_bois.loadFromFile("res/img/materiaux/mur_bois.png")) {}
    if (!mur_pierre.loadFromFile("res/img/materiaux/mur_pierre.png")) {}
    if (!mur_pierre_ame.loadFromFile("res/img/materiaux/mur_pierre2.png")) {}
    if (!pioche.loadFromFile("res/img/materiaux/pioche.png")) {}
    if (!pelle.loadFromFile("res/img/materiaux/pelle.png")) {}
    if (!totem1.loadFromFile("res/img/materiaux/totem1.png")) {}
    if (!totem2.loadFromFile("res/img/materiaux/totem2.png")) {}
    if (!totem3.loadFromFile("res/img/materiaux/totem3.png")) {}
    if (!boisMort.loadFromFile("res/img/materiaux/bois_mort.png")) {}
    if (!planteBougeante.loadFromFile("res/img/materiaux/plante_bougeante.png")) {}
    if (!baril.loadFromFile("res/img/materiaux/baril.png")) {}
    if (!note.loadFromFile("res/img/materiaux/feuilles.png")) {}
    //A partir de l'id 500 c'est les mobs
    if (!espritVengeur.loadFromFile("res/img/pnj/monster1.png")) {}
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
21 - Note
*/
Texture* Img::getImageByID(int id) {
    switch (id)
    {
    case 1: return &bois;
    case 2: return &fleur1;
    case 3: return &fleur2;
    case 4: return &fleur3;
    case 5: return &pierre1;
    case 6: return &pierre2;
    case 7: return &boisMort;
    case 8: return &pierre3;
    case 9: return &planteBougeante;
    case 10: return &fleur4;
    case 11: return &table_craft;
    case 12: return &mur_bois;
    case 13: return &mur_pierre;
    case 14: return &mur_pierre_ame;
    case 15: return &pioche;
    case 16: return &baril;
    case 17: return &totem1;
    case 18: return &totem2;
    case 19: return &totem3;
    case 20: return &pelle;
    case 21: return &note;
    }
    return &bois;
}