
#include <gomaengine/aplication.h>
#include <gomaengine/model.h>

int main() {
    namespace ge = gomaengine;
    

	// Se hace la ventana
	int win_size_x = 1200;
	int win_size_y = 600;
	ge::Window window = { win_size_x, win_size_y };

 //   std::string absolute_path = "C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\";

	//std::map<std::string, ge::Model> model_map;

	/////////////////textures////////////////
 //   //boo def
 //   std::string boo_path = absolute_path + "imgs\\CABALLO_1.png";
 //   int boo_pos_x = 200.0; int boo_pos_y = 300.0;
 //   int boo_scale_x = 4; int boo_scale_y = 4;
 //   int boo_speed = 20;
 //   int boo_dir = 1;
 //   ge::Model boo_model = ge::Model(
 //       ge::Vector(boo_pos_x, boo_pos_y),
 //       ge::Texture(boo_path,
 //           ge::Vector(boo_pos_x, boo_pos_y),
 //           ge::Vector(boo_scale_x, boo_scale_y))
 //   
 //   );


 //   //pony def
 //   std::string pony_path = absolute_path + "imgs\\CABALLO_2.png";
 //   int pony_pos_x = 600.0; int pony_pos_y = 200.0;
 //   int pony_scale_x = 4; int pony_scale_y = 4;
 //   int pony_speed = 20;
 //   int pony_dir = 1;
 //   ge::Model pony_model = ge::Model(
 //       ge::Vector(pony_pos_x, pony_pos_y),
 //       ge::Texture(pony_path,
 //           ge::Vector(pony_pos_x, pony_pos_y),
 //           ge::Vector(pony_scale_x, pony_scale_y))

 //   );


 //   //mouse def
 //   std::string mouse_path = absolute_path + "imgs\\CABALLO_3.png";
 //   int mouse_pos_x = 200.0; int mouse_pos_y = 300.0;
 //   int mouse_scale_x = 4; int mouse_scale_y = 4;
 //   int mouse_speed = 20;
 //   int mouse_dir = 1;
 //   ge::Model mouse_model = ge::Model(
 //       ge::Vector(mouse_pos_x, mouse_pos_y),
 //       ge::Texture(mouse_path,
 //           ge::Vector(mouse_pos_x, mouse_pos_y),
 //           ge::Vector(mouse_scale_x, mouse_scale_y))

 //   );

 //   //rectUI def
 //   std::string rectUI_path = absolute_path + "imgs\\RECTANGULO_1.png";
 //   int rectUI_pos_x = 0.0; int rectUI_pos_y = 450.0;
 //   int rectUI_scale_x = 1.4; int rectUI_scale_y = 2;
 //   int rectUI_speed = 20;
 //   int rectUI_dir = 1;
 //   ge::Model rectUI_model = ge::Model(
 //       ge::Vector(rectUI_pos_x, rectUI_pos_y),
 //       ge::Texture(rectUI_path,
 //           ge::Vector(rectUI_pos_x, rectUI_pos_y),
 //           ge::Vector(rectUI_scale_x, rectUI_scale_y))

 //   );

 //   //grass def
 //   std::string grass_path = absolute_path + "imgs\\grass.png";
 //   int grass_pos_x = 0.0; int grass_pos_y = 0.0;
 //   int grass_scale_x = 7; int grass_scale_y = 7;
 //   int grass_speed = 20;
 //   int grass_dir = 1;
 //   ge::Model grass_model = ge::Model(
 //       ge::Vector(grass_pos_x, grass_pos_y),
 //       ge::Texture(grass_path,
 //           ge::Vector(grass_pos_x, grass_pos_y),
 //           ge::Vector(grass_scale_x, grass_scale_y))

 //   );

    //model_map["Grass"] = grass_model;
    //model_map["Boo"] = boo_model;
    //model_map["Pony"] = pony_model;
    //model_map["Mouse"] = mouse_model;
    //model_map["RectUI"] = rectUI_model;

	//ge::Aplication ge_app = ge::Aplication(window, model_map);
    ge::Aplication ge_app = ge::Aplication(window);
	ge_app.update();
}