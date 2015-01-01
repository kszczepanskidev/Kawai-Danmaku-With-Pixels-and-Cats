#include "textureManager.h"

void TextureManager::loadTexture(const string &name, string filename) {
	Texture* tex = new Texture();

	/* loading texture from file */
	if (!tex->loadFromFile("resources/textures/" + filename)) {
		system("pause");
		exit(-1);
	}

	/* setting smoothing for texture and adding it to map of textures*/
	//tex->setSmooth(true);
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
	loadTexture("game_bg", "game_bg.png");
	loadTexture("game_scroll1", "scroll1.png");
	loadTexture("game_scroll2", "scroll2.png");
	loadTexture("game_scroll3", "scroll3.png");
	loadTexture("game_custom1", "sarima.png");
}

TextureManager::~TextureManager() {}