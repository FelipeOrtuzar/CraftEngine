#include "MovableComponent.h"


namespace gomaengine {






	MovableComponent::MovableComponent(Model* _model)
	{
		model = _model;
	}

	MovableComponent::~MovableComponent()
	{
	}

	MovableComponent::set_target_position(Vector _new_target) { this->target_position = _new_target; }
	MovableComponent::set_velocity(Vector _new_velocity) { this->velocity_vector = _new_velocity; }





}