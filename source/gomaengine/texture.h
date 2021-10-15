#pragma once
#include <SFML/Graphics.hpp>

namespace gomaengine {

    struct Vector {
        float x = 0.0;
        float y = 0.0;
        sf::Vector2f to_sfVector() { return sf::Vector2f(x, y); };
    };

    class Texture {
    private:
        sf::Texture* texture;
        sf::Sprite* sprite;
        std::string path_to_texture = "";
        sf::Vector2f position;
        sf::Vector2f scale;

    public:
        Texture(std::string _path_to_texture, Vector _position, Vector _scale);

        sf::Texture* get_texture();
        sf::Sprite* get_sprite();
        std::string get_path_to_texture();
        Vector get_position();
        Vector get_scale();

        void set_texture(sf::Texture* _texture);
        void set_sprite(sf::Sprite* _sprite);
        void set_path_to_texture(std::string _path_to_texture);
        void set_sprite_position(Vector _position);
        void set_sprite_scale(Vector _scale);

        void load_resources();

	};



}