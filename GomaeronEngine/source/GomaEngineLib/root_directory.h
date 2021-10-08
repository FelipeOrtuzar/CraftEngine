/*
	This field was automatically created with CMake please don't modify it
*/
#pragma once

#include <filesystem>

namespace GomaeronEngine
{
	
static const char * const source_directory = "C:/Felipe/Universidad/Arquitectura de motores de juegos/GomaeronEngine/";

static std::filesystem::path getPath(const std::string &relative_path){
	return source_directory + relative_path;
}
	
} // Grafica
