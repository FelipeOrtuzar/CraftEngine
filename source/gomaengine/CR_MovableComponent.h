#pragma once
#include "Utils.h"
#include "model.h"

namespace gomaengine {



	class CR_MovableComponent
	{
	public:
		CR_MovableComponent();
		~CR_MovableComponent();

		void insert_data(float _velocity);
		void update(Model* _model);
		//void update();
		void set_target_position(Vector _new_target);
		void set_velocity(float _new_velocity);


	private:
		float velocity = 0.0f;
		Vector target_position = Vector(0.0f, 0.0f);

	};



};
