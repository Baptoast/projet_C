#ifndef MATERIAUX_H
#define MATERIAUX_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Materiaux {

	Sprite sprite_materiaux;

	//Fonction public
public:
	int posX;
	int posY;
	int solidite;
	int idMateriaux;

	//Proto du contructeur
	Materiaux(int x, int y, Texture* texture, int id);
	void afficheMateriaux(RenderWindow& window);

	Sprite getSprite();


	//attribut private
private:

};
#endif

