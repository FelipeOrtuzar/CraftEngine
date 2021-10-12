#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include "texture.h"

namespace gomaengine {



	//struct Input {
	//	sf::Keyboard down;
	//	sf::Keyboard up;
	//	sf::Keyboard left;
	//	sf::Keyboard right;
	//};

	class Model {
		private:
			sf::Vector2f position = sf::Vector2f(0.0, 0.0);
			Texture texture = Texture("", Vector(0.0, 0.0), Vector(0.0, 0.0));
		public:
			Vector get_position();
			Texture get_texture();

			void set_position(Vector _position);
			void set_texture(Texture _texture);

			Model(Vector _position, Texture _texture);

	};
	


}