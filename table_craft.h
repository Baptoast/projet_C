#ifndef TABLECRAFT_H
#define TABLECRAFT_H

//include
#include <SFML/Graphics.hpp>
#include "img.h"
#include <iostream>
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class TableCraft {

	Texture texture_case; 
	Texture texture_jauge;
	Texture texture_conteneurDeJauge;
	Texture texture_fond;
	Texture texture_plus;
	Texture texture_moins;
	Font font;

	
	Text nombreDeItem1;
	Text nombreDeItem2;
	
	Sprite sprite_conteneurDeJauge;
	Sprite sprite_fond;
	


public:

	int fiche = -1;

	Sprite sprite_case1;
	Sprite sprite_case2;
	Sprite sprite_caseResult;
	Sprite sprite_materiaux1;
	Sprite sprite_materiaux2;
	Sprite sprite_materiaux3;
	Sprite sprite_jauge;
	Sprite sprite_plus1;
	Sprite sprite_plus2;
	Sprite sprite_moins1;
	Sprite sprite_moins2;
	bool objet1EnPlace = false;
	bool objet2EnPlace = false;
	int idObj1 = 0;
	int idObj2 = 0;
	int nbrItem1 = 0;
	int nbrItem2 = 0;

	int ui = 0;
	int ui2 = 0;
	bool verr = false;
	bool afficheResultat = false;
	bool open = false;
	int idObjResult = 0;
	int idObjResultNombre = 0;

	//Proto du contructeur
	TableCraft();

	//fontion
	void loadTextureTableCraft();
	void afficheRenduTableCraft(RenderWindow& window, int xJ, int yJ);
	void ajoutMateriaux(Img* imageStock, int idMateriaux, int numCase);
	void productionResultat(Img* imageStock);

private:

};
#endif