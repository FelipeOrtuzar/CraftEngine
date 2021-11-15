#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include "GraphicComponent.h"
#include "SoundComponent.h"
//#include "CR_MovableComponent.h"
#include <SFML/Audio.hpp>

//class CR_MovableComponent;

namespace gomaengine {





	/** 
	* Clase que define los modelos del engine.
	*
	* Model define las caracteristicas intrisecas de una unidad en el game engine.
	*
	*/
	class Model {
		private:
			/// <summary>
			/// Vector que identifica la posicion abstracta del modelo en el juego.
			/// </summary>
			Vector position = Vector(0.0f, 0.0f);
			/// <summary>
			/// Int que define si mira hacia la derecha o la izquierda
			/// </summary>
			int orientation = 1;
			/// <summary>
			/// Textura que define la visualizacion del modelo
			/// </summary>
			GraphicComponent graphicComponent = GraphicComponent("", Vector(0.0, 0.0), Vector(0.0, 0.0));

			SoundComponent sound_component;

			Vector target_position = Vector(0.0f, 0.0f);

			float velocity = 1.0f;
			//CR_MovableComponent* movable_component;

			std::string name = "";
			

		public:
			/// <summary>
			/// Funcion que retorna la posicion del modelo
			/// </summary>
			/// <returns> Un vector de la posicion del modelo</returns>
			Vector get_position();
			/// <summary>
			/// Funcion que retorna la textura usada por el modelo.
			/// </summary>
			/// <returns>Una textura.</returns>
			GraphicComponent get_texture();

			/// <summary>
			/// Funcion que retorna la orientacion de hacia donde mira el modelo.
			/// </summary>
			/// <returns>Un 1 o -1 dependiendo</returns>
			int get_orientation();
			
			/// <summary>
			/// Funcion que define la posicion en el modelo
			/// </summary>
			/// <param name="_position">Posicion a settear </param>
			void set_position(Vector _position);

			/// <summary>
			/// Funcion que define la textura en el modelo
			/// </summary>
			/// <param name="_texture">Textura a settear </param>
			void set_graphicComponent(GraphicComponent _graphicComponent);

			/// <summary>
			/// Funcion que define la orientacion en el modelo
			/// </summary>
			/// <param name="_orientation"> Int a settear referente a la orientacion del modelo</param>
			void set_orientation(int _orientation); 

			/// <summary>
			/// Constructor de Model.
			/// </summary>
			/// <param name="_position">Posicion abstracta del modelo</param>
			/// <param name="_texture"> Textura del modelo</param>
			/// <param name="_orientation">Orientacion del modelo</param>
			/// <param name="_soundComponent">Componente de sonido</param>
			//Model(Vector _position, GraphicComponent _graphicComponent, int _orientation, SoundComponent _soundComponent, CR_MovableComponent* _movableComponent);
			Model(Vector _position, std::string _name, GraphicComponent _graphicComponent, SoundComponent _soundComponent);
			~Model();

			/// <summary>
			/// Funcion que traslada la posicion abstracta del modelo
			/// </summary>
			/// <param name="_delta_pos">Vector con cambio en la posicion</param>
			void translate(Vector _delta_pos);

			/// <summary>
			/// Funcion que te da el nombre del modelo
			/// </summary>
			/// <returns>Un std string del modelo</returns>
			std::string get_name();

			SoundComponent get_sound_component();


			void set_velocity(float _velocity);
			//CR_MovableComponent get_movableCompoment();

			//void insert_movableComponent_data(float _velocity);

			void is_clicked();

			//bool has_soundComponent();

			Model* get_me();

			void update();

			void set_target(Vector _target);
	};
	


};