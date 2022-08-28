#ifndef SORT_H
#define SORT_H

//include
#include <SFML/Graphics.hpp>
#include "joueur.h"
#include "pnj.h"
#include <iostream>
#include <vector>


//namespaces
using namespace sf;
using namespace std;

class Sort {

	Mouse souris;
	Joueur* lejoueur;

	Texture* textureElem1;
	Texture* textureElem2;

	int elem1;
	int elem2;

	int degatsZone1;
	int degatsZone2;

	bool realisation = false;
	bool selection = true;
	bool zone1Fini = false;
	bool zone2Fini = false;

	bool degatAppliqueZ1 = false;
	bool degatAppliqueZ2 = false;
	bool faitZ1 = false;
	bool faitZ2 = false;

	bool apparitionZone2 = false;
	float scaleZ2 = 0.0;
	vector<CircleShape> memoCircle;
	vector<Pnj>* listeMobs;

	bool premiere = false;

	Clock timeAnimation;
	Clock timeAnimation2;


public:
	//Proto du contructeur
	Sort(int elem1, int elem2, Joueur *leJoueur,Texture* texture1, Texture* texture2, int degats1, int degats2, vector<Pnj>* listeMonstres);

	void afficheSort(RenderWindow& window);

	float anglePoints(int x1, int y1, int x2, int y2);


	//attribut private
private:

};
#endif


