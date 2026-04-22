#include "LoadLevel.h"
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Knife.h"
#include "Plate.h"
#include "Soy.h"
#include "Finish.h"


LoadLevel::LoadLevel()
{
}

LoadLevel::~LoadLevel()
{
	for (auto& knife : knife) {
		delete knife;
		knife = nullptr;
	}
	knife.clear();

	for (auto& plate : plate) {
		delete plate;
		plate = nullptr;
	}
	plate.clear();

	for (auto& soy : soy) {
		delete soy;
		soy = nullptr;
	}
	soy.clear();

	for (auto& finish : finish) {
		delete finish;
		finish = nullptr;
	}
	finish.clear();
}

bool LoadLevel::loadLevel() {
	std::ifstream file("Level.txt");

	std::string line;
	std::string section;
	float maxHeight = PLAYABLE_HEIGHT;

	while (getline(file, line)) {

		if (line.empty()) {
			continue;
		}
		if (line == "SPAWN") {
			section = "SPAWN";
			continue;
		}
		if (line == "KNIFE") {
			section = "KNIFE";
			continue;
		}
		if (line == "PLATE") {
			section = "PLATE";
			continue;
		}
		if (line == "SOY") {
			section = "SOY";
			continue;
		}
		if (line == "FINISH") {
			section = "FINISH";
			continue;
		}

		std::istringstream iss(line);

		if (section == "SPAWN") {
			iss >> spawnX >> spawnY;
			maxHeight = std::max(maxHeight, spawnY + PLAYABLE_HEIGHT);
		}
		else if (section == "KNIFE") {
			float x, y, w, h;
			int direction = -1;
			iss >> x >> y >> w >> h;
			iss >> direction;
			Knife* myKnife = new Knife(x, y, w, h);
			if (direction != -1) {
				myKnife->setFacingRight(direction == 1);
			}
			knife.push_back(myKnife);
			maxHeight = std::max(maxHeight, y + h);
		}
		else if (section == "PLATE") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Plate* myPlate = new Plate(x, y, w, h);
			plate.push_back(myPlate);
			maxHeight = std::max(maxHeight, y + h);
		}
		else if (section == "SOY") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Soy* mySoy = new Soy(x, y, w, h);
			soy.push_back(mySoy);
			maxHeight = std::max(maxHeight, y + h);
		}
		else if (section == "FINISH") {
			float x, y, w, h;
			iss >> x >> y >> w >> h;
			Finish* myFinish = new Finish(x, y, w, h);
			finish.push_back(myFinish);
			maxHeight = std::max(maxHeight, y + h);
		}
	}

	LEVEL_HEIGHT = maxHeight;
	return true;
}

void LoadLevel::assignTextures() {

	for (auto& k : knife) {
		k->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::knife));
	}

	for (auto& p : plate) {
		//random if plate is plate_w or plate_b or plate_r
		int color = rand() % 3;
		if (color == 0) {
			p->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::plate_w));
		} else if (color == 1) {
			p->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::plate_b));
		} else {
			p->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::plate_r));
		}
	}

	for (auto& s : soy) {
		int type = rand() % 2;
		if (type == 0) {
			s->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::soy_sauce_1));
		} else {
			s->setTexture(&Textures::getTexturesManager()->getTexture(Textures::texturesIndices::soy_sauce_2));
		}
	}
}
