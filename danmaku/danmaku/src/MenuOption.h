#pragma once
#include "Includes.h"

class MenuOption {
public:
	Font font;
	Text text;

	MenuOption(String, Font, float, float);
	virtual ~MenuOption();
};

