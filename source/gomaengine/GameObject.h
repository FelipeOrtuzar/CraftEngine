#pragma once

namespace gomaengine {


	class GameObject {

	private:
		GraphicComponent* _graphic;
		SoundComponent* _sound;

		float pos_x, pos_y, vel_x, vel_y;

	public:
		GameObject(GraphicComponent* _graphic, SoundComponent* _sound);

		void update(Scene& _scene);
	}
	};





}