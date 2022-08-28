#include "sort.h"

/* Liste elements :
	1 - Eau
	2 - Feu
	3 - Terre
	4 - Metal
	5 - Plante
	6 - Electricité
	7 - Air
	8 - Ténèbre
	9 - Lumière
	10 - Espace
	11 - Temps
	12 - Poison
	*/
Sort::Sort(int element1,int element2, Joueur* leJoueur, Texture* texture1, Texture* texture2, int degats1, int degats2, vector<Pnj>* listeMonstres) {
	elem1 = element1;
	elem2 = element2;
	lejoueur = leJoueur;
	textureElem1 = texture1;
	textureElem2 = texture2;
	degatsZone1 = degats1;
	degatsZone2 = degats2;
	listeMobs = listeMonstres;
}


void Sort::afficheSort(RenderWindow& window) {

	int positionSourisX = souris.getPosition().x + lejoueur->getPos().posX - window.getPosition().x - 450;
	int positionSourisY = souris.getPosition().y + lejoueur->getPos().posY - window.getPosition().y - 475;

	int nbrPoint = 20;

	if (souris.isButtonPressed(souris.Left) && !realisation) {
		realisation = true;
	}

	if (!realisation || selection) {
		switch (elem1)
		{
			//Eau
		case 1: {
			CircleShape zone1;
			CircleShape zone2;
			CircleShape zone3;
			CircleShape zone4;

			zone1.setPointCount(nbrPoint);
			zone2.setPointCount(nbrPoint);
			zone3.setPointCount(nbrPoint);
			zone4.setPointCount(nbrPoint);

			zone1.setRadius(36.0);
			zone1.setOrigin(42, 44);


			zone2.setRadius(36.0);
			zone2.setOrigin(42, 44);

			zone3.setRadius(36.0);
			zone3.setOrigin(42, 44);

			zone4.setRadius(36.0);
			zone4.setOrigin(42, 44);



			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);
			zone2.setPosition(positionSourisX + 90 * cos(angleT), positionSourisY + 90 * sin(angleT));
			zone3.setPosition(positionSourisX + 180 * cos(angleT), positionSourisY + 180 * sin(angleT));
			zone4.setPosition(positionSourisX + 270 * cos(angleT), positionSourisY + 270 * sin(angleT));

			zone1.setFillColor(Color(0, 0, 255, 75));
			zone2.setFillColor(Color(0, 0, 255, 55));
			zone3.setFillColor(Color(0, 0, 255, 35));
			zone4.setFillColor(Color(0, 0, 255, 15));
			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));
				zone2.setFillColor(Color(255, 0, 0, 55));
				zone3.setFillColor(Color(255, 0, 0, 35));
				zone4.setFillColor(Color(255, 0, 0, 15));
			}

			window.draw(zone1);
			window.draw(zone2);
			window.draw(zone3);
			window.draw(zone4);

			if (realisation) {
				memoCircle.push_back(zone1);
				memoCircle.push_back(zone2);
				memoCircle.push_back(zone3);
				memoCircle.push_back(zone4);
			}

			break;
		}
			  //Feu
		case 2: {
			CircleShape zone1;

			zone1.setPointCount(nbrPoint);

			zone1.setRadius(96.0);
			zone1.setOrigin(100, 100);


			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);

			zone1.setFillColor(Color(0, 0, 255, 75));
			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));

			}

			window.draw(zone1);
			if (realisation) {
				memoCircle.push_back(zone1);
			}

			break;
		}
			  //Terre
		case 3: {
			CircleShape zone1;
			CircleShape zone2;
			CircleShape zone3;

			zone1.setPointCount(nbrPoint);
			zone2.setPointCount(nbrPoint);
			zone3.setPointCount(nbrPoint);

			zone1.setRadius(75.0);
			zone1.setOrigin(80, 80);


			zone2.setRadius(75.0);
			zone2.setOrigin(80, 80);

			zone3.setRadius(75.0);
			zone3.setOrigin(80, 80);

			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);
			zone2.setPosition(positionSourisX + 75 * cos(angleT), positionSourisY + 75 * sin(angleT));
			zone3.setPosition(positionSourisX + 150 * cos(angleT), positionSourisY + 150 * sin(angleT));

			zone1.setFillColor(Color(0, 0, 255, 75));
			zone2.setFillColor(Color(0, 0, 255, 55));
			zone3.setFillColor(Color(0, 0, 255, 35));
			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));
				zone2.setFillColor(Color(255, 0, 0, 55));
				zone3.setFillColor(Color(255, 0, 0, 35));
			}

			window.draw(zone1);
			window.draw(zone2);
			window.draw(zone3);
			if (realisation) {
				memoCircle.push_back(zone1);
				memoCircle.push_back(zone2);
				memoCircle.push_back(zone3);
			}


			break;
		}
			  //Metal
		case 4: {
			CircleShape zone1;

			zone1.setPointCount(nbrPoint);

			zone1.setRadius(32.0);
			zone1.setOrigin(38, 38);

			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);

			zone1.setFillColor(Color(0, 0, 255, 75));
			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 100) {
				zone1.setFillColor(Color(255, 0, 0, 75));
			}

			window.draw(zone1);
			if (realisation) {
				memoCircle.push_back(zone1);
			}

			break;
		}
			  //Plante
		case 5: {
			CircleShape zone1;
			CircleShape zone2;
			CircleShape zone3;
			CircleShape zone4;
			CircleShape zone5;

			zone1.setPointCount(nbrPoint);
			zone2.setPointCount(nbrPoint);
			zone3.setPointCount(nbrPoint);
			zone4.setPointCount(nbrPoint);
			zone5.setPointCount(nbrPoint);

			zone1.setRadius(36.0);
			zone1.setOrigin(42, 44);

			zone2.setRadius(36.0);
			zone2.setOrigin(42, 44);

			zone3.setRadius(36.0);
			zone3.setOrigin(42, 44);

			zone4.setRadius(36.0);
			zone4.setOrigin(42, 44);

			zone5.setRadius(36.0);
			zone5.setOrigin(42, 44);



			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);

			zone2.setPosition(positionSourisX + 65 * cos(angleT), positionSourisY + 65 * sin(angleT));
			zone3.setPosition(positionSourisX - 65 * cos(angleT), positionSourisY + 65 * sin(angleT));
			zone4.setPosition(positionSourisX + 65 * cos(angleT), positionSourisY - 65 * sin(angleT));
			zone5.setPosition(positionSourisX - 65 * cos(angleT), positionSourisY - 65 * sin(angleT));

			zone1.setFillColor(Color(0, 0, 255, 75));
			zone2.setFillColor(Color(0, 0, 255, 55));
			zone3.setFillColor(Color(0, 0, 255, 55));
			zone4.setFillColor(Color(0, 0, 255, 55));
			zone5.setFillColor(Color(0, 0, 255, 55));

			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));
				zone2.setFillColor(Color(255, 0, 0, 55));
				zone3.setFillColor(Color(255, 0, 0, 55));
				zone4.setFillColor(Color(255, 0, 0, 55));
				zone5.setFillColor(Color(255, 0, 0, 55));

			}

			window.draw(zone1);
			window.draw(zone2);
			window.draw(zone3);
			window.draw(zone4);
			window.draw(zone5);
			if (realisation) {
				memoCircle.push_back(zone1);
				memoCircle.push_back(zone2);
				memoCircle.push_back(zone3);
				memoCircle.push_back(zone4);
				memoCircle.push_back(zone5);
			}


			break;
		}
			  //Electricite
		case 6: {
			CircleShape zone1;
			CircleShape zone2;
			CircleShape zone3;
			CircleShape zone4;
			CircleShape zone5;
			CircleShape zone6;
			CircleShape zone7;
			CircleShape zone8;

			zone1.setPointCount(nbrPoint);
			zone2.setPointCount(nbrPoint);
			zone3.setPointCount(nbrPoint);
			zone4.setPointCount(nbrPoint);
			zone5.setPointCount(nbrPoint);
			zone6.setPointCount(nbrPoint);
			zone7.setPointCount(nbrPoint);
			zone8.setPointCount(nbrPoint);

			zone1.setRadius(24.0);
			zone1.setOrigin(30, 30);

			zone2.setRadius(24.0);
			zone2.setOrigin(30, 30);

			zone3.setRadius(24.0);
			zone3.setOrigin(30, 30);

			zone4.setRadius(24.0);
			zone4.setOrigin(30, 30);

			zone5.setRadius(24.0);
			zone5.setOrigin(30, 30);

			zone6.setRadius(24.0);
			zone6.setOrigin(30, 30);

			zone7.setRadius(24.0);
			zone7.setOrigin(30, 30);

			zone8.setRadius(24.0);
			zone8.setOrigin(30, 30);

			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);

			zone2.setPosition(positionSourisX + 30 * cos(angleT), positionSourisY + 30 * sin(angleT));
			zone3.setPosition(positionSourisX + 60 * cos(angleT), positionSourisY + 60 * sin(angleT));
			zone4.setPosition(positionSourisX + 90 * cos(angleT), positionSourisY + 90 * sin(angleT));
			zone5.setPosition(positionSourisX + 120 * cos(angleT), positionSourisY + 120 * sin(angleT));
			zone6.setPosition(positionSourisX + 150 * cos(angleT), positionSourisY + 150 * sin(angleT));
			zone7.setPosition(positionSourisX + 180 * cos(angleT), positionSourisY + 180 * sin(angleT));
			zone8.setPosition(positionSourisX + 210 * cos(angleT), positionSourisY + 210 * sin(angleT));

			zone1.setFillColor(Color(0, 0, 255, 75));
			zone2.setFillColor(Color(0, 0, 255, 65));
			zone3.setFillColor(Color(0, 0, 255, 55));
			zone4.setFillColor(Color(0, 0, 255, 45));
			zone5.setFillColor(Color(0, 0, 255, 40));
			zone6.setFillColor(Color(0, 0, 255, 35));
			zone7.setFillColor(Color(0, 0, 255, 25));
			zone8.setFillColor(Color(0, 0, 255, 15));

			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));
				zone2.setFillColor(Color(255, 0, 0, 65));
				zone3.setFillColor(Color(255, 0, 0, 55));
				zone4.setFillColor(Color(255, 0, 0, 45));
				zone5.setFillColor(Color(255, 0, 0, 40));
				zone6.setFillColor(Color(255, 0, 0, 35));
				zone7.setFillColor(Color(255, 0, 0, 25));
				zone8.setFillColor(Color(255, 0, 0, 15));

			}

			window.draw(zone1);
			window.draw(zone2);
			window.draw(zone3);
			window.draw(zone4);
			window.draw(zone5);
			window.draw(zone6);
			window.draw(zone7);
			window.draw(zone8);

			if (realisation) {
				memoCircle.push_back(zone1);
				memoCircle.push_back(zone2);
				memoCircle.push_back(zone3);
				memoCircle.push_back(zone4);
				memoCircle.push_back(zone5);
				memoCircle.push_back(zone6);
				memoCircle.push_back(zone7);
				memoCircle.push_back(zone8);
			}


			break;
		}
			  //Air
		case 7: {
			CircleShape zone1;

			zone1.setPointCount(nbrPoint);

			zone1.setRadius(1000.0);
			zone1.setOrigin(1005.0, 1005.0);

			zone1.setPosition(lejoueur->getPos().posX, lejoueur->getPos().posY);
			zone1.setFillColor(Color(0, 0, 255, 75));

			window.draw(zone1);
			if (realisation) {
				memoCircle.push_back(zone1);
			}

			break;
		}
			  //Tenebre
		case 8: {
			CircleShape zone1;

			zone1.setPointCount(nbrPoint + 20);

			zone1.setRadius(250.0);
			zone1.setOrigin(255, 255);


			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);

			zone1.setFillColor(Color(0, 0, 255, 75));
			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));

			}

			window.draw(zone1);
			if (realisation) {
				memoCircle.push_back(zone1);

			}

			break;
		}
			  //Lumiere
		case 9: {
			CircleShape zone1;

			zone1.setPointCount(nbrPoint + 20);

			zone1.setRadius(250.0);
			zone1.setOrigin(250 - 16, 250 - 16);

			zone1.setPosition(lejoueur->getPos().posX, lejoueur->getPos().posY);
			zone1.setFillColor(Color(0, 0, 255, 75));

			window.draw(zone1);
			if (realisation) {
				memoCircle.push_back(zone1);
			}

			break;
		}
			  //Espace
		case 10: {
			CircleShape zone1;
			CircleShape zone2;
			CircleShape zone3;
			CircleShape zone4;
			CircleShape zone5;

			zone1.setPointCount(nbrPoint + 20);
			zone2.setPointCount(nbrPoint + 10);
			zone3.setPointCount(nbrPoint);
			zone4.setPointCount(nbrPoint);
			zone5.setPointCount(nbrPoint);

			zone1.setRadius(125.0);
			zone1.setOrigin(128, 128);

			zone2.setRadius(96.0);
			zone2.setOrigin(100, 100);

			zone3.setRadius(75.0);
			zone3.setOrigin(80, 80);

			zone4.setRadius(45.0);
			zone4.setOrigin(50, 50);

			zone5.setRadius(32.0);
			zone5.setOrigin(35, 35);


			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);
			zone2.setPosition(positionSourisX, positionSourisY);
			zone3.setPosition(positionSourisX, positionSourisY);
			zone4.setPosition(positionSourisX, positionSourisY);
			zone5.setPosition(positionSourisX, positionSourisY);

			zone1.setFillColor(Color(0, 0, 255, 75));
			zone2.setFillColor(Color(0, 0, 255, 55));
			zone3.setFillColor(Color(0, 0, 255, 35));
			zone4.setFillColor(Color(0, 0, 255, 15));
			zone5.setFillColor(Color(0, 0, 255, 5));

			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));
				zone2.setFillColor(Color(255, 0, 0, 55));
				zone3.setFillColor(Color(255, 0, 0, 35));
				zone4.setFillColor(Color(255, 0, 0, 15));
				zone5.setFillColor(Color(255, 0, 0, 5));

			}

			window.draw(zone1);
			window.draw(zone2);
			window.draw(zone3);
			window.draw(zone4);
			window.draw(zone5);
			if (realisation) {
				memoCircle.push_back(zone1);
				memoCircle.push_back(zone2);
				memoCircle.push_back(zone3);
				memoCircle.push_back(zone4);
				memoCircle.push_back(zone5);
			}

			break;
		}
			   //Temps
		case 11: {
			CircleShape zone1;

			zone1.setPointCount(nbrPoint + 20);

			zone1.setRadius(120.0);
			zone1.setOrigin(125, 125);


			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);

			zone1.setFillColor(Color(0, 0, 255, 75));
			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));

			}

			window.draw(zone1);
			if (realisation) {
				memoCircle.push_back(zone1);
			}

			break;
		}
			   //Poison
		case 12: {
			CircleShape zone1;
			CircleShape zone2;

			zone1.setPointCount(nbrPoint + 20);
			zone2.setPointCount(nbrPoint + 10);

			zone1.setRadius(96.0);
			zone1.setOrigin(100, 100);

			zone2.setRadius(45.0);
			zone2.setOrigin(50, 50);


			float angleT = anglePoints(lejoueur->getPos().posX + 32, lejoueur->getPos().posY + 32, positionSourisX, positionSourisY);

			zone1.setPosition(positionSourisX, positionSourisY);
			zone2.setPosition(positionSourisX, positionSourisY);

			zone1.setFillColor(Color(0, 0, 255, 75));
			zone2.setFillColor(Color(0, 0, 255, 55));

			int dansRayonDAction = (positionSourisX - lejoueur->getPos().posX - 32) * cos(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY)) + (positionSourisY - lejoueur->getPos().posY - 32) * sin(anglePoints(lejoueur->getPos().posX, lejoueur->getPos().posY, positionSourisX, positionSourisY));
			if (dansRayonDAction >= 450) {
				zone1.setFillColor(Color(255, 0, 0, 75));
				zone2.setFillColor(Color(255, 0, 0, 55));

			}

			window.draw(zone1);
			window.draw(zone2);
			if (realisation) {
				memoCircle.push_back(zone1);
				memoCircle.push_back(zone2);
			}

			break;
		}
		}

		if (realisation) {
			selection = false;
			timeAnimation.restart();
		}
	}
	else {
	if (!zone1Fini) {

		switch (elem1)
		{
			//Eau
		case 1: {
			
			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite animEau;
				animEau.setTexture(*textureElem1);
				animEau.setScale(0.5,0.5);
				scaleZ2 = 0.5;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 240 + i*60) {
					animEau.setTextureRect(IntRect(0,0,192,192));
					animEau.setPosition(memoCircle.at(i).getPosition().x-50 , memoCircle.at(i).getPosition().y - 50 - (240 + i * 60) + timeAnimation.getElapsedTime().asMilliseconds());
				}else if (timeAnimation.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					animEau.setTextureRect(IntRect(192, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 580 + i * 60) {
					animEau.setTextureRect(IntRect(384, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if(timeAnimation.getElapsedTime().asMilliseconds() < 680 + i * 60) {
					animEau.setTextureRect(IntRect(576, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 780 + i * 60) {
					animEau.setTextureRect(IntRect(768, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 880 + i * 60) {
					animEau.setTextureRect(IntRect(0, 192, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					apparitionZone2 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 980 + i * 60) {
					animEau.setTextureRect(IntRect(192, 192, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else {
					zone1Fini = true;
					//faitZ1 = false;
					ok = false;
				}
				if (ok) {
					window.draw(animEau);
				}
				
			}

			break;
		}
			//Feu
		case 2: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(1.5, 1.5);
				scaleZ2 = 1.5;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200 - (240 + i * 60) + timeAnimation.getElapsedTime().asMilliseconds());
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
					apparitionZone2 = true;
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 580 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 680 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 780 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 880 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else {
					zone1Fini = true;
					//faitZ1 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Terre
		case 3: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(1.5, 1.5);
				scaleZ2 = 1.5;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 120 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200 );
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 300 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 420 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 150, memoCircle.at(i).getPosition().y - 200);
					apparitionZone2 = true;
				}
				else {
					zone1Fini = true;
					ok = false;
					//faitZ1 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Metal
		case 4: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(0.5, 0.5);
				scaleZ2 = 0.5;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 70 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 140 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 210 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 280 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 350 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 420 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					apparitionZone2 = true;
				}
				else {
					zone1Fini = true;
					ok = false;
					//faitZ1 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Plante
		case 5: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(0.5, 0.5);
				scaleZ2 = 0.5;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < 120) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 240 ) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 300 ) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 ) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 420 ) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 480 ) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					apparitionZone2 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 800) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else {
					zone1Fini = true;
					ok = false;
					//faitZ1 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Electricite
		case 6: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(0.5, 0.5);
				scaleZ2 = 0.5;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 120 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 300 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 420 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
					apparitionZone2 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 600 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 660 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 780 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 50, memoCircle.at(i).getPosition().y - 50);
				}
				else {
					if (i == memoCircle.size() - 1) {
						zone1Fini = true;
						//faitZ1 = false;
						
					}
					
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Air
		case 7: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(12.0, 12.0);
				scaleZ2 = 12.0;
				int placement = 1200;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 90 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					apparitionZone2 = true;
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 180 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 270 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 450 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 630 + i * 60) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 810 + i * 60) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 900 + i * 60) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 990 + i * 60) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1080 + i * 60) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1170 + i * 60) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1260 + i * 60) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1350 + i * 60) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1440 + i * 60) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1530 + i * 60) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1620 + i * 60) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1710 + i * 60) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1800 + i * 60) {
					anim.setTextureRect(IntRect(768, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1890 + i * 60) {
					anim.setTextureRect(IntRect(0, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1980 + i * 60) {
					anim.setTextureRect(IntRect(192, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else {
					zone1Fini = true;
					//faitZ1 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
		//Tenebre
		case 8: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(4.0, 4.0);
				scaleZ2 = 4.0;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 90 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 180 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 270 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 450 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 630 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
					apparitionZone2 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 810 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 900 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 990 + i * 60) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1080 + i * 60) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1170 + i * 60) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - 400, memoCircle.at(i).getPosition().y - 400);
				}
				else {
					zone1Fini = true;
					ok = false;
					//faitZ1 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Lumiere
		case 9: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(3.5, 3.5);
				scaleZ2 = 3.5;
				int placement = 315;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 90 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 180 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 270 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 450 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				//
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 630 + i * 60) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 810 + i * 60) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 900 + i * 60) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 990 + i * 60) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1080 + i * 60) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1170 + i * 60) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1260 + i * 60) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1350 + i * 60) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1440 + i * 60) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1530 + i * 60) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1620 + i * 60) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1710 + i * 60) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1800 + i * 60) {
					anim.setTextureRect(IntRect(768, 576, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1890 + i * 60) {
					anim.setTextureRect(IntRect(0, 768, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1980 + i * 60) {
					anim.setTextureRect(IntRect(192, 768, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2070 + i * 60) {
					anim.setTextureRect(IntRect(384, 768, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2160 + i * 60) {
					anim.setTextureRect(IntRect(576, 768, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2250 + i * 60) {
					anim.setTextureRect(IntRect(768, 768, 192, 192));
					anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2340 + i * 60) {
				anim.setTextureRect(IntRect(0, 960, 192, 192));
				anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2430 + i * 60) {
				anim.setTextureRect(IntRect(192, 960, 192, 192));
				anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2520 + i * 60) {
				anim.setTextureRect(IntRect(384, 960, 192, 192));
				anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2610 + i * 60) {
				anim.setTextureRect(IntRect(576, 960, 192, 192));
				anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2700 + i * 60) {
				anim.setTextureRect(IntRect(768, 960, 192, 192));
				anim.setPosition(lejoueur->getPos().posX - placement, lejoueur->getPos().posY - placement);
				apparitionZone2 = true;
				}
				else {
					zone1Fini = true;
					ok = false;
					//faitZ1 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
		//Espace
		case 10: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(3.0 - (i*0.5), 3.0 - (i * 0.5));
				scaleZ2 = 3.0 - (i * 0.5);
				int placement = 300 - (i * 50);
				int delai = 2000;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * delai) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 180 + i * delai) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 270 + i * delai) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * delai) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 450 + i * delai) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * delai) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 630 + i * delai) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * delai) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 810 + i * delai) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 900 + i * delai) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 990 + i * delai) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1080 + i * delai) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1170 + i * delai) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1260 + i * delai) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1350 + i * delai) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1440 + i * delai) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1530 + i * delai) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1620 + i * delai) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1710 + i * delai) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					apparitionZone2 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1800 + i * delai) {
					anim.setTextureRect(IntRect(768, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1890 + i * delai) {
					anim.setTextureRect(IntRect(0, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1980 + i * delai) {
					anim.setTextureRect(IntRect(192, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2070 + i * delai) {
					anim.setTextureRect(IntRect(384, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2160 + i * delai) {
					anim.setTextureRect(IntRect(576, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 2250 + i * delai) {
					anim.setTextureRect(IntRect(768, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else {
					if (i == memoCircle.size() - 1) {
						zone1Fini = true;
						
					}
					//faitZ1 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
		//Temps
		case 11: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(2.5, 2.5);
				scaleZ2 = 2.5;
				int placement = 250;
				int delai = 2250;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * delai) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 180 + i * delai) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 270 + i * delai) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * delai) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 450 + i * delai) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * delai) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 630 + i * delai) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * delai) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 810 + i * delai) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 900 + i * delai) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 990 + i * delai) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1080 + i * delai) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1170 + i * delai) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					apparitionZone2 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1260 + i * delai) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1350 + i * delai) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1440 + i * delai) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1530 + i * delai) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1620 + i * delai) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				
				else {
					if (i == memoCircle.size() - 1) {
						zone1Fini = true;
					}
					//faitZ1 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			   //Poison
		case 12: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem1);
				anim.setScale(1.0 - (i * 0.5), 1.0 - (i * 0.5));
				scaleZ2 = 1.0 - (i * 0.5);
				int placement = 100 - (i * 50);
				int delai = 630;
				bool ok = true;
				if (timeAnimation.getElapsedTime().asMilliseconds() < i * delai) {
					ok = false;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 90 + i * delai) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 180 + i * delai) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ1 = true;
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 270 + i * delai) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 360 + i * delai) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 450 + i * delai) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 540 + i * delai) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 630 + i * delai) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 720 + i * delai) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 810 + i * delai) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 900 + i * delai) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 990 + i * delai) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1080 + i * delai) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1170 + i * delai) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation.getElapsedTime().asMilliseconds() < 1260 + i * delai) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					apparitionZone2 = true;
				}
				
				else {
					if (i == memoCircle.size() - 1) {
						zone1Fini = true;
					}
					//faitZ1 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
		}

	}
	if (!zone2Fini && apparitionZone2) {

		if (!premiere) {
			timeAnimation2.restart();
			premiere = true;
		}

		switch (elem2)
		{
			//Eau
		case 1: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite animEau;
				animEau.setTexture(*textureElem2);
				animEau.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					animEau.setTextureRect(IntRect(0, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart - (240 + i * 60) + timeAnimation2.getElapsedTime().asMilliseconds());
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					animEau.setTextureRect(IntRect(192, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 580 + i * 60) {
					animEau.setTextureRect(IntRect(384, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 680 + i * 60) {
					animEau.setTextureRect(IntRect(576, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 780 + i * 60) {
					animEau.setTextureRect(IntRect(768, 0, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 880 + i * 60) {
					animEau.setTextureRect(IntRect(0, 192, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 980 + i * 60) {
					animEau.setTextureRect(IntRect(192, 192, 192, 192));
					animEau.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(animEau);
				}

			}

			break;
		}
			  //Feu
		case 2: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart - (240 + i * 60) + timeAnimation2.getElapsedTime().asMilliseconds());
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 580 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 680 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 780 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 880 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Terre
		case 3: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 120 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 300 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 420 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Metal
		case 4: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 70 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 140 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 210 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 280 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 350 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 420 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Plante
		case 5: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < 120) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 240) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 300) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 420) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 480) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 800) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Electricite
		case 6: {
			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 120 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 240 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 300 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 420 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 480 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 600 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 660 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 780 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					if (i == memoCircle.size() - 1) {
						zone2Fini = true;
					}
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Air
		case 7: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int placement = scaleZ2*100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 90 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 180 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 270 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 450 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 630 + i * 60) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 810 + i * 60) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 900 + i * 60) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 990 + i * 60) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1080 + i * 60) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1170 + i * 60) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1260 + i * 60) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1350 + i * 60) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1440 + i * 60) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1530 + i * 60) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1620 + i * 60) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1710 + i * 60) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1800 + i * 60) {
					anim.setTextureRect(IntRect(768, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1890 + i * 60) {
					anim.setTextureRect(IntRect(0, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1980 + i * 60) {
					anim.setTextureRect(IntRect(192, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Tenebre
		case 8: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int ecart = scaleZ2 * 100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 90 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 180 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 270 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 450 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 630 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 810 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 900 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 990 + i * 60) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1080 + i * 60) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1170 + i * 60) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - ecart, memoCircle.at(i).getPosition().y - ecart);
				}
				else {
					zone2Fini = true;
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Lumiere
		case 9: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int placement = scaleZ2*100;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * 60) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 90 + i * 60) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 180 + i * 60) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 270 + i * 60) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * 60) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 450 + i * 60) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * 60) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 630 + i * 60) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * 60) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 810 + i * 60) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 900 + i * 60) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 990 + i * 60) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1080 + i * 60) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1170 + i * 60) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1260 + i * 60) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1350 + i * 60) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1440 + i * 60) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1530 + i * 60) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1620 + i * 60) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1710 + i * 60) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1800 + i * 60) {
					anim.setTextureRect(IntRect(768, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1890 + i * 60) {
					anim.setTextureRect(IntRect(0, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1980 + i * 60) {
					anim.setTextureRect(IntRect(192, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2070 + i * 60) {
					anim.setTextureRect(IntRect(384, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2160 + i * 60) {
					anim.setTextureRect(IntRect(576, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2250 + i * 60) {
					anim.setTextureRect(IntRect(768, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2340 + i * 60) {
					anim.setTextureRect(IntRect(0, 960, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2430 + i * 60) {
					anim.setTextureRect(IntRect(192, 960, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2520 + i * 60) {
					anim.setTextureRect(IntRect(384, 960, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2610 + i * 60) {
					anim.setTextureRect(IntRect(576, 960, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2700 + i * 60) {
					anim.setTextureRect(IntRect(768, 960, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else {
				zone2Fini = true;
				//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			  //Espace
		case 10: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int placement = scaleZ2*100 - (i * 50);
				int delai = 2000;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * delai) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 180 + i * delai) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 270 + i * delai) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * delai) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 450 + i * delai) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * delai) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 630 + i * delai) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * delai) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 810 + i * delai) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 900 + i * delai) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 990 + i * delai) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1080 + i * delai) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1170 + i * delai) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1260 + i * delai) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1350 + i * delai) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1440 + i * delai) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1530 + i * delai) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1620 + i * delai) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1710 + i * delai) {
					anim.setTextureRect(IntRect(576, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1800 + i * delai) {
					anim.setTextureRect(IntRect(768, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1890 + i * delai) {
					anim.setTextureRect(IntRect(0, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1980 + i * delai) {
					anim.setTextureRect(IntRect(192, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2070 + i * delai) {
					anim.setTextureRect(IntRect(384, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2160 + i * delai) {
					anim.setTextureRect(IntRect(576, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 2250 + i * delai) {
					anim.setTextureRect(IntRect(768, 768, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else {
					if (i == memoCircle.size() - 1) {
						zone2Fini = true;
					}
					//faitZ2 = false;
					ok = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			   //Temps
		case 11: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int placement = scaleZ2*100;
				int delai = 2250;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * delai) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 180 + i * delai) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 270 + i * delai) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * delai) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 450 + i * delai) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * delai) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 630 + i * delai) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * delai) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 810 + i * delai) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 900 + i * delai) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 990 + i * delai) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1080 + i * delai) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1170 + i * delai) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1260 + i * delai) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1350 + i * delai) {
					anim.setTextureRect(IntRect(768, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1440 + i * delai) {
					anim.setTextureRect(IntRect(0, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1530 + i * delai) {
					anim.setTextureRect(IntRect(192, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1620 + i * delai) {
					anim.setTextureRect(IntRect(384, 576, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}

				else {
					if (i == memoCircle.size() - 1) {
						zone2Fini = true;
					}
					ok = false;
					//faitZ2 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
			   //Poison
		case 12: {

			for (int i = 0; i < memoCircle.size(); i++)
			{
				Sprite anim;
				anim.setTexture(*textureElem2);
				anim.setScale(scaleZ2, scaleZ2);
				int placement = scaleZ2*100 - (i * 50);
				int delai = 630;
				bool ok = true;
				if (timeAnimation2.getElapsedTime().asMilliseconds() < i * delai) {
					ok = false;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 90 + i * delai) {
					anim.setTextureRect(IntRect(0, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 180 + i * delai) {
					anim.setTextureRect(IntRect(192, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
					degatAppliqueZ2 = true;
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 270 + i * delai) {
					anim.setTextureRect(IntRect(384, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 360 + i * delai) {
					anim.setTextureRect(IntRect(576, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 450 + i * delai) {
					anim.setTextureRect(IntRect(768, 0, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 540 + i * delai) {
					anim.setTextureRect(IntRect(0, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				//
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 630 + i * delai) {
					anim.setTextureRect(IntRect(192, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 720 + i * delai) {
					anim.setTextureRect(IntRect(384, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 810 + i * delai) {
					anim.setTextureRect(IntRect(576, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 900 + i * delai) {
					anim.setTextureRect(IntRect(768, 192, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 990 + i * delai) {
					anim.setTextureRect(IntRect(0, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1080 + i * delai) {
					anim.setTextureRect(IntRect(192, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1170 + i * delai) {
					anim.setTextureRect(IntRect(384, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}
				else if (timeAnimation2.getElapsedTime().asMilliseconds() < 1260 + i * delai) {
					anim.setTextureRect(IntRect(576, 384, 192, 192));
					anim.setPosition(memoCircle.at(i).getPosition().x - placement, memoCircle.at(i).getPosition().y - placement);
				}

				else {
					if (i == memoCircle.size() - 1) {
						zone2Fini = true;
					}
					ok = false;
					//faitZ2 = false;
				}
				if (ok) {
					window.draw(anim);
				}

			}

			break;
		}
		}

	}
	
	if (degatAppliqueZ1 && !faitZ1) {
		degatAppliqueZ1 = false;
		faitZ1 = true;
		int taille = listeMobs->size();
		for (int i = 0; i < taille; i++) {
			for (int j = 0; j < memoCircle.size(); j++){
				if (memoCircle.at(j).getGlobalBounds().contains(listeMobs->at(i).sprite_pnj.getPosition().x, listeMobs->at(i).sprite_pnj.getPosition().y)) {
					listeMobs->at(i).pv = listeMobs->at(i).pv + degatsZone1;
					if (listeMobs->at(i).pv <= 0) {
						listeMobs->at(i).estDead = true;
					}
				}
			}
		}
	}
	
	if (degatAppliqueZ2 && !faitZ2) {
		degatAppliqueZ2 = false;
		faitZ2 = true;
		int taille = listeMobs->size();
		for (int i = 0; i < taille; i++) {
			for (int j = 0; j < memoCircle.size(); j++) {
				if (memoCircle.at(j).getGlobalBounds().contains(listeMobs->at(i).sprite_pnj.getPosition().x, listeMobs->at(i).sprite_pnj.getPosition().y)) {
					listeMobs->at(i).pv = listeMobs->at(i).pv + degatsZone2;
					if (listeMobs->at(i).pv <= 0) {
						listeMobs->at(i).estDead = true;
					}
				}
			}
		}
	}
	}
}

//gives the angle from point one to point two
float Sort::anglePoints(int x1, int y1, int x2, int y2)
{
	return atan2(y2 - y1, x2 - x1);
}