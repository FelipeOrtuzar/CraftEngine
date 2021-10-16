#include "texture.h"
#include <SFML/Graphics.hpp>


namespace gomaengine {

    Texture::Texture(std::string _path_to_texture, Vector _position, Vector _scale) {
        texture = new sf::Texture();
        sprite = new sf::Sprite();
        path_to_texture = _path_to_texture;
        position = sf::Vector2f(_position.x, _position.y);
        scale = sf::Vector2f(_scale.x, _scale.y);
        

    }

    //GET
    sf::Texture* Texture::get_texture() { return this->texture; };
    sf::Sprite* Texture::get_sprite() { return this->sprite; };
    std::string Texture::get_path_to_texture() { return this->path_to_texture; };
    Vector Texture::get_position() { return Vector(this->position.x, this->position.y); };
    Vector Texture::get_scale() { return Vector(this->scale.x, this->scale.y); };
    //SET
    void Texture::set_texture(sf::Texture* _texture) { this->texture = _texture; };
    void Texture::set_sprite(sf::Sprite* _sprite) { this->sprite = _sprite; };
    void Texture::set_path_to_texture(std::string _path_to_texture) { this->path_to_texture = _path_to_texture; };
    void Texture::set_sprite_position(Vector _position) {
        this->position = sf::Vector2f(_position.x, _position.y); sprite->setPosition(position);
    };
    void Texture::set_sprite_scale(Vector _scale) { this->scale = sf::Vector2f(_scale.x, _scale.y); sprite->setScale(scale); };
    //funct
    void Texture::load_resources() {
        if (!texture->loadFromFile(path_to_texture)) {
            printf("Error loading sprite. is the path correct?");
        }
        else {
            printf("Texture loaded succesfully\n");
            printf(get_path_to_texture().c_str());
        }
        sprite->setTexture(*texture);
        sprite->setPosition(position);
        sprite->setOrigin(10.0, 10.0);
        sprite->setScale(scale);
        printf("\nsprite setted");
        
    }
    void Texture::translate(Vector _vector) {
        this->set_sprite_position(this->get_position().sum(_vector));
    }



}