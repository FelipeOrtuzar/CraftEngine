#include "model.h"




namespace gomaengine {

	
	
	//Model::Model(Vector _position, GraphicComponent _graphicComponent, int _orientation, SoundComponent _soundComponent, CR_MovableComponent* _movableComponent) {
	Model::Model(Vector _position, std::string _name, GraphicComponent _graphicComponent, SoundComponent _soundComponent) {
		std::cout << "Constructor Model\n";
		position = _position;
		target_position = _position;
		graphicComponent = _graphicComponent;
		orientation = 1;
		sound_component = _soundComponent;
		name = _name;

		//movable_component = _movableComponent;
		
	};

	Model::~Model() {
		std::cout << "Destructor of Model\n";
	}



	GraphicComponent Model::get_texture() { return graphicComponent; };
	Vector Model::get_position() { return Vector(position.x, position.y); };
	int Model::get_orientation() { return orientation; };

	void Model::set_graphicComponent(GraphicComponent _graphicComponent) { graphicComponent = _graphicComponent; };
	void Model::set_position(Vector _position) { 
		position = _position; 
		graphicComponent.set_sprite_position(_position);
	};
	void Model::set_orientation(int _orientation) { orientation = _orientation; };



	void Model::translate(Vector _delta_pos) {
		
		position = position.sum(_delta_pos);

		// this->graphicComponent().translate(this, position, orientation);

		if (std::abs(_delta_pos.y) < 0.0001) {
			orientation = _delta_pos.x > 0.0 ? 1.0 : -1.0;
			this->graphicComponent.set_sprite_scale(this->graphicComponent.get_scale().abs().multiply(Vector(orientation, 1.0)));
		}
		this->graphicComponent.translate(_delta_pos);
	}
	
	std::string Model::get_name() { return name; }

	SoundComponent Model::get_sound_component() { return sound_component; }

	//CR_MovableComponent Model::get_movableCompoment() { return *movable_component; }

	//void Model::insert_movableComponent_data(float _velocity) { movable_component.insert_data(this, _velocity); }

	Model* Model::get_me() { return this; }

	void Model::is_clicked() { sound_component.play_sound(); }

	void Model::set_velocity(float _velocity)
	{
		velocity = _velocity;
	}

	void Model::update() {
	


		Vector difference = target_position.subs(this->position);
		//std::cout << "\n dif: ";
		//difference.print();
		if (difference.magnitude() > velocity) {
			Vector norm_dif = difference.normalize();
			translate(norm_dif.multiply(velocity));
		}
		
	}

	void Model::set_target(Vector _target)
	{
		target_position = _target;
	}

	/*bool Model::has_soundComponent() {
		if (sound_component) {
			return true;
		}
		else {
			return false;
		}
	
	}*/
};
