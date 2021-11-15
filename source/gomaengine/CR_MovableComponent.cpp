#include "CR_MovableComponent.h"


namespace gomaengine {



	CR_MovableComponent::CR_MovableComponent()
	{
		velocity = 0.0f;
		target_position = Vector(0.0f, 0.0f);

	}

	CR_MovableComponent::~CR_MovableComponent()
	{
	}

	void CR_MovableComponent::insert_data(float _velocity) {

		velocity = _velocity;
	}

	void CR_MovableComponent::update(Model* _model) {

		Vector difference = target_position.substract(_model->get_position());
		Vector norm_dif = difference.normalize();
		_model->translate(norm_dif.multiply(velocity));

	}
	//void CR_MovableComponent::update() {}

	void CR_MovableComponent::set_target_position(Vector _new_target) { this->target_position = _new_target; };
	void CR_MovableComponent::set_velocity(float _new_velocity) { this->velocity = _new_velocity; };





};

