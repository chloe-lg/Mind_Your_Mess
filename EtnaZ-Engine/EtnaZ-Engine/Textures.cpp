#include "Textures.h"

Textures* Textures::TextureManager = nullptr;

Textures::Textures() {
    loadAllTexture();
}

Textures* Textures::getTexturesManager() {
    if (TextureManager == nullptr) {
        TextureManager = new Textures();
    }
    return TextureManager;
}

void Textures::loadTexture(texturesIndices _index, const char* fileName) {
    sf::Texture texture = sf::Texture();
    auto toto = texture.loadFromFile(fileName);

    auto index = (int)_index;
    if (index >= tabTextures.size())
    {
        tabTextures.resize(index + 1);
    }

    tabTextures[index] = texture;
}

void Textures::loadFont(fontsIndices _index, const char* fileName) {
    sf::Font font(fileName);

    auto index = (int)_index;
    if (index >= tabFonts.size())
    {
        tabFonts.resize(index + 1);
    }

    tabFonts[index] = font;
}

sf::Texture& Textures::getTexture(texturesIndices index) {
    return tabTextures[(int)index];
}

sf::Font& Textures::getFont(fontsIndices index) {
    return tabFonts[(int)index];
}

void Textures::loadAllTexture()
{
    loadTexture(Textures::texturesIndices::sushi_s, "assets/sushi_s.png");
    loadTexture(Textures::texturesIndices::sushi_t, "assets/sushi_t.png");
    loadTexture(Textures::texturesIndices::plate_w, "assets/plate_w.png");
    loadTexture(Textures::texturesIndices::plate_b, "assets/plate_b.png");
    loadTexture(Textures::texturesIndices::plate_r, "assets/plate_r.png");
    loadTexture(Textures::texturesIndices::knife, "assets/knife.png");
    loadTexture(Textures::texturesIndices::soy_sauce_1, "assets/soy_sauce_1.png");
    loadTexture(Textures::texturesIndices::soy_sauce_2, "assets/soy_sauce_2.png");
    loadTexture(Textures::texturesIndices::bg_menu, "assets/bg_menu.png");
    loadTexture(Textures::texturesIndices::bg_game, "assets/bg_game.png");

    loadTexture(Textures::texturesIndices::title, "assets/title.png");
    loadTexture(Textures::texturesIndices::btn_start, "assets/btn_start.png");
    loadTexture(Textures::texturesIndices::btn_resume, "assets/btn_resume.png");
    loadTexture(Textures::texturesIndices::btn_quit, "assets/btn_quit.png");
    loadTexture(Textures::texturesIndices::btn_restart, "assets/btn_restart.png");
    loadTexture(Textures::texturesIndices::img_gameover, "assets/gameover.png");
    loadTexture(Textures::texturesIndices::img_win, "assets/win.png");
}
