#include "AnimationComponent.h"



namespace gomaengine {

	AnimationComponent::AnimationComponent(std::string _path_to_animation, Vector _position_in_world,
		Vector _shape_size, Vector _start_position, int _n_sprites, Vector _scale, Vector _dist_textures) {
		texture = new sf::Texture();
		sprite = new sf::Sprite();
		
		scale = _scale.to_sfVector();
		position = _position_in_world.to_sfVector();
		path_to_animation = _path_to_animation;
		shape_size = _shape_size;

		offset_position = _start_position;
		n_sprites = _n_sprites;
		this->dist_between_texture = _dist_textures;

		
		
	}

	AnimationComponent::AnimationComponent() {
		texture = new sf::Texture();
		sprite = new sf::Sprite();
	

		scale = sf::Vector2f(0, 0);
		position = sf::Vector2f(0, 0);
		path_to_animation = "";
		shape_size = Vector(0, 0);

		offset_position = Vector(0, 0);
		n_sprites = 0;
	}

	void AnimationComponent::load_resources() {
		
		if (!texture->loadFromFile(path_to_animation, sf::IntRect(offset_position.x, offset_position.y, shape_size.x, shape_size.y))) {
			printf("Error loading animation. Is the path correct?");
		}
		else {
			printf("Animation loaded succesfully\n");
			//printf(get_path_to_texture().c_str());
		}
		sprite->setTexture(*texture);
		sprite->setPosition(position);
		sprite->setOrigin(10.0, 10.0);
		sprite->setScale(scale);
		printf("\nAnimation setted");
	
	
	}

	void AnimationComponent::set_object_angle(float _angle) { this->object_angle = _angle; }

	//int AnimationComponent::get_closest(int _value, std::list<int> _list) {

	//	int min_delta = 500000;
	//	int pos_value = 0;
	//	std::list <int> ::iterator it;
	//	for (it = _list.begin(); it != _list.end(); ++it) {
	//		int dif = std::abs(_value - *it);
	//		if (dif < min_delta) {
	//			min_delta = dif;
	//			pos_value = *it;
	//		}
	//	}
	//	return pos_value;
	//}

	void AnimationComponent::update_animation(sf::RenderWindow& _window, int _facing_angle, Vector _new_pos) {

		object_angle = _facing_angle;
		position = _new_pos.to_sfVector();

		

		//update frame
		start_change += change_rate;
		if (start_change >= 1.0f) {
			
			bool found_ani_det = 0;
			int initial_angle = int(object_angle / angle_delta) * angle_delta;
			//int loop_angle = initial_angle;

			//std::list lista;
			int min_delta = 500000;
			int pos_value = 0;
			for (auto const& [key, val] : map_to_anim_detail)
			{
				int dif = std::abs(initial_angle - key);
				if (dif < min_delta) {
					min_delta = dif;
					pos_value = key;
				}

			}
			//std::cout << pos_value << "\n";
			Animation_detail anim_det = map_to_anim_detail.at(int(pos_value));
			int crnt_frame = anim_det.get_frame();


			//std::cout << crnt_frame;
			float pos_x = offset_position.x + (anim_det.sprite_pos.x + crnt_frame - 1) * dist_between_texture.x;
			float pos_y = offset_position.y + (anim_det.sprite_pos.y - 1) * dist_between_texture.y;// +dist_between_texture.y / 2;

			//std::cout << "Pos_x: " << pos_x << "Pos_y" << pos_y << "\n";


			if (!texture->loadFromFile(path_to_animation, sf::IntRect(pos_x, pos_y, shape_size.x, shape_size.y))) {

			}
			else {
				//printf(get_path_to_texture().c_str());
			}
			sprite->setTexture(*texture);
			sprite->setPosition(position);
			sprite->setOrigin(shape_size.x/2, shape_size.y / 2);
			sprite->setScale(scale);

			map_to_anim_detail.at(int(pos_value)).next_frame();
			start_change = 0.0f;

			




			//while (!found_ani_det) {

			//	found_ani_det = map_to_anim_detail.contains(loop_angle);
			//	if (found_ani_det) {
			//		Animation_detail anim_det = map_to_anim_detail.at(loop_angle);
			//		int crnt_frame = anim_det.get_frame();


			//		//std::cout << crnt_frame;
			//		float pos_x = (anim_det.sprite_pos.x + crnt_frame - 1) * dist_between_texture.x;
			//		float pos_y = anim_det.sprite_pos.y * dist_between_texture.y + dist_between_texture.y / 2;

			//		std::cout << "Pos_x: " << pos_x << "Pos_y" << pos_y << "\n";


			//		if (!texture->loadFromFile(path_to_animation, sf::IntRect(pos_x, pos_y, shape_size.x, shape_size.y))) {

			//		}
			//		else {
			//			//printf(get_path_to_texture().c_str());
			//		}
			//		sprite->setTexture(*texture);
			//		sprite->setPosition(position);
			//		sprite->setOrigin(10.0, 10.0);
			//		sprite->setScale(scale);

			//		map_to_anim_detail.at(this->object_angle).next_frame();
			//		start_change = 0.0f;

			//		_window.draw(*sprite);
			//	}

			//	


			//	loop_angle += angle_delta;

			//	if (loop_angle == initial_angle) {
			//		std::cout << "Error: couldnt find sprite";
			//	}

			//}
			//loop_angle -= angle_delta;

		}
		_window.draw(*sprite);
	}


	void AnimationComponent::link_dir_with_detail(int _angle, Vector _position, int _nframes) {
		
		map_to_anim_detail[_angle] = Animation_detail{ _nframes - 1, _position, 0};
	
	}

}