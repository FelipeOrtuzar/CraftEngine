#include "texture.h"
#include <SFML/Graphics.hpp>


namespace gomaengine {

    Texture::Texture(std::string _path_to_texture, Vector _position, Vector _scale) {

        sf::Texture _texture;
        if (!_texture.loadFromFile(_path_to_texture)) {
            printf("Error loading sprite. is the path correct?");
        }
        this->texture = _texture;
        sf::Sprite _sprite;
        _sprite.setTexture(_texture);
        _sprite.setPosition(sf::Vector2f(_position.x, _position.y));
        _sprite.setScale(sf::Vector2f(_scale.x, _scale.y));
        this->sprite = _sprite;

    }

    //GET
    sf::Texture Texture::get_texture() { return this->texture; };
    sf::Sprite Texture::get_sprite() { return this->sprite; };
    std::string Texture::get_path_to_texture() { return this->path_to_texture; };
    Vector Texture::get_position() { return Vector(this->position.x, this->position.y); };
    Vector Texture::get_scale() { return Vector(this->scale.x, this->scale.y); };
    //SET
    void Texture::set_texture(sf::Texture _texture) { this->texture = _texture; };
    void Texture::set_sprite(sf::Sprite _sprite) { this->sprite = _sprite; };
    void Texture::set_path_to_texture(std::string _path_to_texture) { this->path_to_texture = _path_to_texture; };
    void Texture::set_sprite_position(Vector _position) { this->position = sf::Vector2f(_position.x, _position.y); };
    void Texture::set_sprite_scale(Vector _scale) { this->scale = sf::Vector2f(_scale.x, _scale.y); };




}