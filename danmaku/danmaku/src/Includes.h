#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#define PAUSE() {cout << "Press enter to continue ...";cin.get();}

enum states{ MAINMENU, GAME, CONNECT, QUIT };
enum texs{ SPLASH, MENU_BG, GAME_BG, SCROLL1, SCROLL2, SCROLL3, GAME_CUSTOM1};

using namespace std;
using namespace sf;