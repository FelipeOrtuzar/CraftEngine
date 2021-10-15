#include "model.h"
#include <iostream>

namespace gomaengine {
	//Model::Model(Vector _position, int _orientation) {
	Model::Model(Vector _position, Texture _texture, int _orientation) {
		position = sf::Vector2f(_position.x, _position.y);
		texture = _texture;
		orientation = _orientation;
	};

	//Model::Model() {
	////Model::Model(Vector _position, Texture _texture, int _orientation) {
	//	position = sf::Vector2f(0.0, 0.0);
	//	texture = Texture::Texture("", Vector(0.0, 0.0), Vector(0.0, 0.0));
	//	orientation = 1;
	//};

	Texture Model::get_texture() { return texture; };
	Vector Model::get_position() { return Vector(position.x, position.y); };
	int Model::get_orientation() { return orientation; };

	void Model::set_texture(Texture _texture) { texture = _texture; };
	void Model::set_position(Vector _position) { position = sf::Vector2f(_position.x, _position.y); };
	void Model::set_orientation(int _orientation) { orientation = _orientation; };


	
};