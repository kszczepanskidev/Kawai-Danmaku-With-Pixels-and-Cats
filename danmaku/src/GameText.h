#pragma once
#include "Includes.h"

class GameText {
public:
	Font font;
	Text text;

	GameText(String, Font, float, float);
	virtual ~GameText();
};

