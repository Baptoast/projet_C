#include "menu.h"

Menu::Menu() {

}

void Menu::loadImageMenu()
{
    if (!texture_menu.loadFromFile("res/img/sol2.png")) {
        cout << "erreur" << endl;
    }
    else {
        sprite_menu.setTexture(texture_menu);
        sprite_menu.setPosition(-500,-500);
    }
    if (!texture_Elem1.loadFromFile("res/img/caseCraft.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_Elem1.setPosition(-250, 0);

    }
    if (!texture_Elem2.loadFromFile("res/img/caseCraft.png")) {
        cout << "erreur" << endl;
    }
    else {

        sprite_Elem2.setPosition(0, 0);
    }
    if (!texture_Elem3.loadFromFile("res/img/caseCraft.png")) {
        cout << "erreur" << endl;
    }
    else {
        
        sprite_Elem3.setPosition(250 , 0);
    }
  
}

void Menu::creationMenu() {
    window.create(VideoMode(SCREEN_SIZE_WEIGHTS, SCREEN_SIZE_HEIGHTS), "Projet C");

    window.setPosition(Vector2i((ecran.getDesktopMode().width / 2) - (ecran.getDesktopMode().width / 5), ecran.getDesktopMode().height / 64));

    vue.setSize(Vector2f(SCREEN_SIZE_WEIGHTS, SCREEN_SIZE_HEIGHTS));
    vue.setCenter(32, 32);
    window.requestFocus();
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);    

}

void Menu::fermeFenetre() {
    fermeFenetr = true;
    window.close();
}

bool Menu::isOpen() {
    return window.isOpen();
}

void Menu::premiereConnexion(Socket::Status* status) {

    *status = socket.connect("192.168.1.27", 53000);
    while (*status != Socket::Done) {}
    char data[100];
    std::size_t received;

    //Envoie
    sprintf_s(data, "%02X", GetUserNameA);
    if (socket.send(data, 100) != Socket::Done) {}
    //Reçoit
    if (socket.receive(data, 100, received) != Socket::Done) {}

    //Premiere connexion
    if (data[0] != 't') {

        miseAJourChoixElements(data);

        while (!choix1) {

            int positionSourisX = laSouris.getPosition().x - window.getPosition().x - 450;
            int positionSourisY = laSouris.getPosition().y - window.getPosition().y - 475;

            if (sprite_Elem1.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem1);
                if (elem1 < 10) {
                    sprintf_s(data, "0%d", elem1);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix1 = true;
            }
            if (sprite_Elem2.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem2);
                if (elem2 < 10) {
                    sprintf_s(data, "0%d", elem2);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix1 = true;
            }
            if (sprite_Elem3.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem3);
                if (elem3 < 10) {
                    sprintf_s(data, "0%d", elem3);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix1 = true;
            }
        }

        if (socket.receive(data, 100, received) != Socket::Done) {}

        miseAJourChoixElements(data);

        while(laSouris.isButtonPressed(laSouris.Left)) {}

        while (!choix2) {

            int positionSourisX = laSouris.getPosition().x - window.getPosition().x - 450;
            int positionSourisY = laSouris.getPosition().y - window.getPosition().y - 475;

            if (sprite_Elem1.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem1);
                if (elem1 < 10) {
                    sprintf_s(data, "0%d", elem1);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix2 = true;
            }
            if (sprite_Elem2.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem2);
                if (elem2 < 10) {
                    sprintf_s(data, "0%d", elem2);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix2 = true;
            }
            if (sprite_Elem3.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem3);
                if (elem3 < 10) {
                    sprintf_s(data, "0%d", elem3);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix2 = true;
            }
        }

        if (socket.receive(data, 100, received) != Socket::Done) {}

        miseAJourChoixElements(data);

        while (laSouris.isButtonPressed(laSouris.Left)) {}

        while (!choix3) {

            int positionSourisX = laSouris.getPosition().x - window.getPosition().x - 450;
            int positionSourisY = laSouris.getPosition().y - window.getPosition().y - 475;

            if (sprite_Elem1.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem1);
                if (elem1 < 10) {
                    sprintf_s(data, "0%d", elem1);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix3 = true;
            }
            if (sprite_Elem2.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem2);
                if (elem2 < 10) {
                    sprintf_s(data, "0%d", elem2);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix3 = true;
            }
            if (sprite_Elem3.getGlobalBounds().contains(positionSourisX, positionSourisY) && laSouris.isButtonPressed(laSouris.Left)) {
                sprintf_s(data, "%d", elem3);
                if (elem3 < 10) {
                    sprintf_s(data, "0%d", elem3);
                }
                if (socket.send(data, 100) != Socket::Done) {}
                choix3 = true;
            }
        }

        if (socket.receive(data, 100, received) != Socket::Done) {}
        miseAJourChoixElements(data);

        //LETS GO !!
        accepteJeu = true;

    }
}

void Menu::bouclePrincipale() {

    if (window.pollEvent(event)) {
        input.InputHandler(event, window);
    }
    window.clear(Color::Black);

    //affiche sol
    window.draw(sprite_menu);

    //affiche elements
    window.draw(sprite_Elem1);
    window.draw(sprite_Elem2);
    window.draw(sprite_Elem3);


    window.setView(vue);
    window.display();
    
}

void Menu::miseAJourChoixElements(char* data) {
    int i = 2;
    if (data[i + 1] == ':') {
        elem1 = ((int)data[i] - 48);
        miseAJourCaseElements(elem1, 1);
    }
    else {
        elem1 = convertisseurDeuxCaractereChiffres(data[i], data[i + 1]);
        miseAJourCaseElements(elem1, 1);
        i++;
    }

    i += 2;

    if (data[i + 1] == ':') {
        elem2 = ((int)data[i] - 48);
        miseAJourCaseElements(elem2, 2);
    }
    else {
        elem2 = convertisseurDeuxCaractereChiffres(data[i], data[i + 1]);
        miseAJourCaseElements(elem2, 2);
        i++;
    }

    i += 2;

    if (data[i + 1] == ':') {
        elem3 = ((int)data[i] - 48);
        miseAJourCaseElements(elem3, 3);
    }
    else {
        elem3 = convertisseurDeuxCaractereChiffres(data[i], data[i + 1]);
        miseAJourCaseElements(elem3, 3);
        i++;
    }
}

void Menu::miseAJourCaseElements(int numElem, int cas) {
    Texture txt;
    switch (numElem)
    {
    case 1: {
        txt.loadFromFile("res/img/elements/Eau.png");
        break;
    }
    case 2: {
        txt.loadFromFile("res/img/elements/Feu.png");
        break;
    }
    case 3: {
        txt.loadFromFile("res/img/elements/Terre.png");
        break;
    }
    case 4: {
        txt.loadFromFile("res/img/elements/Metal.png");
        break;
    }
    case 5: {
        txt.loadFromFile("res/img/elements/Plante.png");
        break;
    }
    case 6: {
        txt.loadFromFile("res/img/elements/Electricite.png");
        break;
    }
    case 7: {
        txt.loadFromFile("res/img/elements/Air.png");
        break;
    }
    case 8: {
        txt.loadFromFile("res/img/elements/Tenebre.png");
        break;
    }
    case 9: {
        txt.loadFromFile("res/img/elements/Lumiere.png");
        break;
    }
    case 10: {
        txt.loadFromFile("res/img/elements/Espace.png");
        break;
    }
    case 11: {
        txt.loadFromFile("res/img/elements/Temps.png");
        break;
    }
    case 12: {
        txt.loadFromFile("res/img/elements/Poison.png");
        break;
    }   
    }
    switch (cas)
    {
    case 1: {
        texture_Elem1 = txt;
        sprite_Elem1.setTexture(texture_Elem1);
        break;

    case 2: {
        texture_Elem2 = txt;
        sprite_Elem2.setTexture(texture_Elem2);
        break;
    }
    case 3: {
        texture_Elem3 = txt;
        sprite_Elem3.setTexture(texture_Elem3);
        break;
    }

    }
    }
}

int Menu::convertisseurDeuxCaractereChiffres(char chiffre1, char chiffre2) {
    //cout << chiffre1 << (int)chiffre1 << endl;
    //cout << chiffre2 << (int)chiffre2 << endl;
    //cout << (((int)chiffre1 - 48) * 10) + ((int)chiffre2 - 48) << endl;
    return (((int)chiffre1 - 48) * 10) + ((int)chiffre2 - 48);
}