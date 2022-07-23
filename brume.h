#ifndef BRUME_H
#define BRUME_H

//include
#include <SFML/Graphics.hpp>
#include "materiaux.h"
#include <iostream>
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Brume {

	struct particule
	{
		int x;
		int y;
		float rotate = 0.0;
		Sprite laParticule;
	};

	struct brumaille
	{
		float x;
		float y;
		float augmentation = 0.0;
		Sprite laParticule;
		Sprite laParticuleDerriere;
		bool bloquee = false;
		float ralentissement = 0.0;
		Clock avancementBrume;
	};

	float seed;

	Texture texture_brume;
	Texture texture_grande_brume;

	Sprite sprite_brume;
	Sprite sprite_grande_brume;

	CircleShape laBrume;
	vector<brumaille> listeBrume;
	vector<VertexArray> listeVertex;

	vector<particule> listeEffetBrume;

	vector<Materiaux>* listeDeMateriaux;
	
	float tourne = 0.0;

	Clock tempsAvantDisparitionObj;
	


public:
	//Proto du contructeur
	Brume();

	//fontion
	void loadTextureBrume();
	void afficheBrume(RenderWindow& window, int xJ, int yJ);
	void initialiseListeMateriaux(vector<Materiaux>* laListe);
	float anglePoints(int x1, int y1, int x2, int y2);




	//attribut private
private:

};
#endif


