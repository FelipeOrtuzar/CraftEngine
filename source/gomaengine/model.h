
#include <iostream>

namespace gomaengine {

	struct Vector_pos {
		int pos_x;
		int pos_y;
	};
	struct Texture {
		std::string* path_to_texture;
	};

	class Model {
		private:
			Vector_pos position;
			Texture texture;
		public:
			Vector_pos get_Position();
			Texture get_Path_to_texture();
			void set_Position(Vector_pos _vector_pos);
			void set_Path_to_texture(Texture _texture);
			Model(Vector_pos _vector_pos, Texture _texture);

	};
	


}