#pragma once
#include "Includes.h"

#include <map>

class TextureManager {
private:
	map<string, Texture> textures;
public:
	void loadTexture(const string&, string);
	Texture& getTexture(const string&);

	TextureManager();
	virtual ~TextureManager();
};

