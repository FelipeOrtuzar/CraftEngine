
#include <gomaengine/aplication.h>
//#include <gomaengine/model.h>

int main() {
	// Se hace la ventana
	int win_size_x = 1200;
	int win_size_y = 600;
	gomaengine::Window window = { win_size_x, win_size_y };
	//Se agrega la posicion de un modelo
	//gomaengine::Vector_pos boo_pos_vector = { 600, 300 };
	//Se agrega la textura del modelo
	std::string texture_path = "C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\imgs\\boo.png";
	//gomaengine::Texture boo_texture = { &texture_path };
	////Se agrega lo anterior al modelo
	//gomaengine::Model boo = gomaengine::Model(boo_pos_vector, boo_texture);
	//
	//gomaengine::Model_vect model_vector;
	////Se agrega el modelo a la lista de modelos
	//model_vector.model_vector.push_back(boo);

	//std::string path_to_texture = "C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\imgs\\boo.png";
	//std::vector<std::string> paths_to_texture;
	//paths_to_texture.push_back(path_to_texture);

	//gomaengine::Aplication ge_app = gomaengine::Aplication(window, model_vector);
	gomaengine::Aplication ge_app = gomaengine::Aplication(window);
	ge_app.update();
}