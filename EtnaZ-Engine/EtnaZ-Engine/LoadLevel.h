#pragma once
#include <vector>
#include <iostream>
#include "Globals.h"
#include "GameObject.h" 
#include "Textures.h"
#include "Knife.h"
#include "Plate.h"
#include "Soy.h"
#include "Finish.h"


class LoadLevel {

public:
	std::vector<Knife*> knife;
	std::vector<Plate*> plate;
	std::vector<Soy*> soy;
	std::vector<Finish*> finish;




	LoadLevel();
	~LoadLevel();
	
	float spawnX = 560.f;
	float spawnY = 4800.f;

	bool loadLevel();

	void assignTextures();

};
