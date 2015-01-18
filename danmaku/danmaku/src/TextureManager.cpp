#include "TextureManager.h"

void TextureManager::loadTexture(const string &name, string filename) {
	Texture* tex = new Texture();

	/* loading texture from file */
	if (!tex->loadFromFile("resources/textures/" + filename)) {
		system("pause");
		exit(-1);
	}

	/* setting smoothing for texture and adding it to map of textures*/
	tex->setSmooth(true);
	this->textures[name] = *tex;

	return;
}

Texture& TextureManager::getTexture(const string &texture) {
	return this->textures.at(texture);
}

/* loading all textures on texture manager creating*/
TextureManager::TextureManager() {
	loadTexture("splashin", "krysztal_splash.png");
	loadTexture("menu_bg", "menu_bg.png");
	loadTexture("connect_bg", "connect_bg.png");
	loadTexture("credits_bg", "credits_bg.png");
	loadTexture("game_bg", "game_bg.png");
	//loadTexture("game_scroll1", "scroll1.png");
	//loadTexture("game_scroll2", "scroll2.png");
	//loadTexture("game_scroll3", "scroll3.png");
	loadTexture("cloud0", "cloud0.png");
	loadTexture("cloud1", "cloud1.png");
	loadTexture("cloud2", "cloud2.png");
	loadTexture("cloud3", "cloud3.png");
	loadTexture("cloud4", "cloud4.png");
	loadTexture("cloud5", "cloud5.png");
	loadTexture("cloud6", "cloud6.png");
	loadTexture("cloud7", "cloud7.png");
	loadTexture("cloud8", "cloud8.png");
	loadTexture("cloud9", "cloud9.png");
	loadTexture("game_custom1", "sarima.png");
	loadTexture("player", "player.png");
	loadTexture("bullet", "bullet.png");
	loadTexture("enemy1", "enemy1.png");
	loadTexture("krysztal_av", "krysztal_av.png");
	loadTexture("scofield_av", "scofield_av.png");
	loadTexture("shihoin_av", "shihoin_av.png");
	loadTexture("archer_av", "archer_av.png");
}

TextureManager::~TextureManager() {}