#pragma once
#include "Includes.h"
#include "FlyingObject.h"

class Bonus : public FlyingObject {
private:
public:
	int update();
	void draw(RenderWindow*);

	Bonus(TextureManager*, float, float);
	virtual ~Bonus();
};

