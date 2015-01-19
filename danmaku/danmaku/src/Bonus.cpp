#include "Bonus.h"

#define _USE_MATH_DEFINES
#include <math.h>

int Bonus::update() {
	if (pos_y > 720.f)
		return 1;

	pos_y += speed_y;
	return 0;
}

void Bonus::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);
}

Bonus::Bonus(TextureManager* texManager, float x, float y) {
	id = -1;
	live = true;

	sprite.setTexture(texManager->getTexture("bonus"));
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setColor(Color::Magenta);

	pos_x = x;
	pos_y = y;

	speed_y = 3.5f;

	hitbox_r = 12.5f;
	hitbox.setOrigin(hitbox_r, hitbox_r);
	hitbox_pos_x = sprite.getOrigin().x;
	hitbox_pos_y = sprite.getOrigin().y;
}


Bonus::~Bonus() {}
