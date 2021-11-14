#pragma once
#include "Utils.h"
#include "model.h"

namespace gomaengine {



	class MovableComponent
	{
	public:
		MovableComponent(Model* _model);
		~MovableComponent();
		void update();
		set_target_position(Vector _new_target);
		set_velocity(Vector _new_velocity);



	private:
		Vector velocity_vector = Vector(0.0f, 0.0f);
		Vector target_position = Vector(0.0f, 0.0f);
		Model* model;
	};











}