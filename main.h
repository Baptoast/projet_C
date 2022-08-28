//Include
#include "menu.h"
#include "jeu.h"
#include <windows.h>
#include <vector>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

Menu menu;
Jeu jeu;

Socket::Status status;

vector<int> elementJoueur;