#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#define PAUSE() {cout << "Press enter to continue ...";cin.get();}

enum states{ MAINMENU, GAME, CONNECT, SPLASH };

using namespace std;
using namespace sf;