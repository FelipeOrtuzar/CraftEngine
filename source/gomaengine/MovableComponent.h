#pragma once
#include "Utils.h"

namespace gomaengine {



	class MovableComponent
	{
	public:
		MovableComponent();
		~MovableComponent();

	private:
		Vector velocity_vector = Vector(0.0f, 0.0f);
		Vector target_position = Vector(0.0f, 0.0f);
	};











}