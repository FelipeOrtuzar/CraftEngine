#include "model.h"
#include <iostream>

namespace gomaengine {

	Model::Model(Vector _position, Texture _texture) {
		position = sf::Vector2f(_position.x, _position.y);
		texture = _texture;
	};


	Texture Model::get_texture() { return texture; };
	Vector Model::get_position() { return Vector(position.x, position.y); };

	void Model::set_texture(Texture _texture) { texture = _texture; };
	void Model::set_position(Vector _position) { position = sf::Vector2f(_position.x, _position.y); };


	
};