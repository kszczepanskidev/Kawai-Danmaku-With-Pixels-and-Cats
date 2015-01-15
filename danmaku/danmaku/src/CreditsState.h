#pragma once
#include "State.h"
#include "FlyingObject.h"
#include "Player.h"
#include "Enemy.h"

class CreditsState : public State {
private:
	vector<GameText*> gameTexts;

	TextureManager* texManager;

	vector<FlyingObject*> objects;
	vector<Bullet*> bullets;

	void initTexts();
	void initSprites(TextureManager*);

public:
	void handleEvent(Event*, StateManager*);
	void update(StateManager*);
	void draw(RenderWindow*);

	CreditsState(Font, TextureManager*);
	virtual ~CreditsState();
};

