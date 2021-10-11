#include "model.h";
#include <iostream>;

namespace gomaengine {

	Texture Model::get_Path_to_texture() { return texture; }
	Vector_pos Model::get_Position() { return position; }

	void Model::set_Path_to_texture(Texture _texture) { texture = _texture; }
	void Model::set_Position(Vector_pos _vector_pos) { this->position = _vector_pos; }


	Model::Model(Vector_pos _vector_pos, Texture _texture) {
		set_Path_to_texture(_texture);
		set_Position(_vector_pos);
	}
}