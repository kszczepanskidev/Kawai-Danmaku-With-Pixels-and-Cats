#include "GameText.h"

GameText::GameText(String t, Font f, float pos_x, float pos_y) {
	font = f;

	this->text.setFont(font);
	this->text.setCharacterSize(32);
	this->text.setColor(Color::White);
	this->text.setStyle(Text::Bold);
	
	this->text.setString(t);
	this->text.setPosition(pos_x, pos_y);
}


GameText::~GameText() {}
