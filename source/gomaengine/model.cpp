#include "model.h"
#include <iostream>

namespace gomaengine {


	
	Model::Model(Vector _position, Texture _texture, int _orientation) {
		
		position = sf::Vector2f(_position.x, _position.y);
		texture = _texture;
		orientation = _orientation;
	};



	Texture Model::get_texture() { return texture; };
	Vector Model::get_position() { return Vector(position.x, position.y); };
	int Model::get_orientation() { return orientation; };

	void Model::set_texture(Texture _texture) { texture = _texture; };
	void Model::set_position(Vector _position) { 
		position = sf::Vector2f(_position.x, _position.y); 
		texture.set_sprite_position(_position);
	};
	void Model::set_orientation(int _orientation) { orientation = _orientation; };

	void Model::translate(Vector _delta_pos) {
		position = sf::Vector2f(position.x + _delta_pos.x, position.y + _delta_pos.y);
		if (std::abs(_delta_pos.y) < 0.0001) {
			orientation = _delta_pos.x > 0.0 ? 1.0 : -1.0;
			this->texture.set_sprite_scale(this->texture.get_scale().abs().multiply(Vector(orientation, 1.0)));
		}
		this->texture.translate(_delta_pos);
	}
	
};