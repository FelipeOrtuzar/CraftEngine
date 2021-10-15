/*
	This field was automatically created with CMake please don't modify it
*/
#pragma once

#include <filesystem>

namespace gomaengine
{
	
static const char * const source_directory = "C:/Users/felip/OneDrive/Documentos/GitHub/CraftEngine/";

static std::filesystem::path getPath(const std::string &relative_path){
	return source_directory + relative_path;
}
	
} // Grafica
