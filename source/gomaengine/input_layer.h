#pragma once
#include <SFML/Window.hpp>
#include <map>

#include <iostream>

namespace gomaengine {

	/// <summary>
	/// Estructura que define una traduccion de inputs del gameengine junto a los de la libreria SFML::Keyboard
	/// </summary>
	struct Keyboard {
		/// <summary>
		/// String con el tipo de boton
		/// </summary>
		std::string key;
		/// <summary>
		/// Boton de la libreria SFML
		/// </summary>
		sf::Keyboard::Key keyboard_key;		
	};

	const static Keyboard A = { "A", sf::Keyboard::A };
	const static Keyboard S = { "S", sf::Keyboard::S };
	const static Keyboard D = { "D", sf::Keyboard::D };
	const static Keyboard W = { "W", sf::Keyboard::W };
	const static Keyboard Left = { "Left", sf::Keyboard::Left };
	const static Keyboard Right = { "Right", sf::Keyboard::Right };
	const static Keyboard Up = { "Up", sf::Keyboard::Up };
	const static Keyboard Down = { "Down", sf::Keyboard::Down };
	const static Keyboard Q = { "Q", sf::Keyboard::Q };
	const static Keyboard Space = { "Space", sf::Keyboard::Space };
	const static Keyboard O = { "O", sf::Keyboard::O };
	const static Keyboard P = { "P", sf::Keyboard::P };


	/// <summary>
	/// Clase para definir y operar elementos de la funcion Input (en construccion)
	/// </summary>
	class Input {
	private:
		

	public:


	};





}