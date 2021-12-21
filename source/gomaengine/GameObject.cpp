#include "GameObject.h"




namespace gomaengine {

	
	
	//Model::Model(Vector _position, GraphicComponent _graphicComponent, int _orientation, SoundComponent _soundComponent, CR_MovableComponent* _movableComponent) {
	GameObject::GameObject(Vector _position, std::string _name, GraphicComponent _graphicComponent, SoundComponent _soundComponent) {
		std::cout << "Constructor Model\n";
		position = _position;
		target_position = _position;
		graphicComponent = _graphicComponent;
		orientation = 1;
		sound_component = _soundComponent;
		animation_component = AnimationComponent();
		name = _name;
		has_graphic_component = 1;

		//movable_component = _movableComponent;
		
	};

	GameObject::GameObject(Vector _position, std::string _name, AnimationComponent _animationComponent, SoundComponent _soundComponent) {
		std::cout << "Constructor Model\n";
		position = _position;
		target_position = _position;
		animation_component = _animationComponent;
		orientation = 1;
		sound_component = _soundComponent;
		name = _name;
		has_animation_component = 1;
	
	}


	GameObject::~GameObject() {
		std::cout << "Destructor of Model\n";
	}



	GraphicComponent GameObject::get_texture() { return graphicComponent; };
	Vector GameObject::get_position() { return Vector(position.x, position.y); };
	int GameObject::get_orientation() { return orientation; };

	void GameObject::set_graphicComponent(GraphicComponent _graphicComponent) { graphicComponent = _graphicComponent; };
	void GameObject::set_position(Vector _position) {
		position = _position; 
		graphicComponent.set_sprite_position(_position);
	};
	void GameObject::set_orientation(int _orientation) { orientation = _orientation; };



	void GameObject::translate(Vector _delta_pos) {
		
		position = position.sum(_delta_pos);

		// this->graphicComponent().translate(this, position, orientation);

		if (std::abs(_delta_pos.y) < 0.0001) {
			orientation = _delta_pos.x > 0.0 ? 1.0 : -1.0;
			this->graphicComponent.set_sprite_scale(this->graphicComponent.get_scale().abs().multiply(Vector(orientation, 1.0)));
		}
		this->graphicComponent.translate(_delta_pos);
	}
	
	std::string GameObject::get_name() { return name; }

	SoundComponent GameObject::get_sound_component() { return sound_component; }

	//CR_MovableComponent Model::get_movableCompoment() { return *movable_component; }

	//void Model::insert_movableComponent_data(float _velocity) { movable_component.insert_data(this, _velocity); }

	GameObject* GameObject::get_me() { return this; }

	void GameObject::is_clicked() { sound_component.play_sound(); };

	void GameObject::set_velocity(float _velocity) { velocity = _velocity; };

	void GameObject::update(float _delta_time, sf::RenderWindow& _window) {
	


		

		move_to_target(_delta_time);

		if (has_graphic_component) this->graphicComponent.update(_window);
		float new_angle = get_angle();
		//std::cout << "new_angle: " << new_angle << "\n";
		if (has_animation_component) this->animation_component.update_animation(_window, new_angle, position);

		this->sound_component.update();
		
	}

	
	void GameObject::move_to_target(float _delta_time)
	{
		Vector difference = target_position.subs(this->position);
		if (difference.magnitude() > velocity) {
			Vector norm_dif = difference.normalize();
			std::cout << _delta_time;
			translate(norm_dif.multiply(velocity));
		}
	}

	void GameObject::set_target(Vector _target)
	{
		target_position = _target;
	}

	float GameObject::get_angle() {
		Vector difference = target_position.subs(this->position);
		float angle = difference.get_deg_angle();
		//std::cout <<"Angle: "<< angle << "Difx: " << difference.x << "Dify: " << difference.y << "\n";
		return angle;
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
