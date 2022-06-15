#ifndef IMG_H
#define IMG_H

//include
#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Img {
	

public:
	
	Texture bois;
	Texture pierre;
	Texture fleur1;
	Texture fleur2;
	Texture fleur3;
	//Proto du contructeur
	Img();
	void loadTextures();
	



	//attribut private
private:

};
#endif

