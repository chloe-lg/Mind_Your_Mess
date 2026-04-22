#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

// Need to modifie

class Textures {
public:
    enum class texturesIndices {
        sushi_s,
        sushi_t,
        plate_w,
        plate_b,
        plate_r,
        knife,
        soy_sauce_1,
        soy_sauce_2,
        bg_menu,
        bg_game,

        title,
        btn_start,
        btn_resume,
        btn_quit,
        btn_restart,
        img_gameover,
        img_win,
    };

    enum class fontsIndices {
    };

private:
    Textures();

public:
    ~Textures() = default;

    sf::Texture& getTexture(texturesIndices index);
    sf::Font& getFont(fontsIndices index);

    void loadAllTexture();

    void loadTexture(texturesIndices _index, const char* filename);
    void loadFont(fontsIndices _index, const char* filename);

    static Textures* getTexturesManager();

private:
    static Textures* TextureManager;

    std::vector<sf::Texture> tabTextures;
    std::vector<sf::Font> tabFonts;
};
