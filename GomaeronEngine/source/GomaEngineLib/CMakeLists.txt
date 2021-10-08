set(GOMAERON_ENGINE_HEADERS 
		basic_shapes.h
		easy_shaders.h
		gpu_shape.h
		load_shaders.h
		shape.h
		transformations.h
		)
set(GOMAERON_ENGINE_SOURCES
		basic_shapes.cpp
		easy_shaders.cpp
		gpu_shape.cpp
		load_shaders.cpp
		shape.cpp
		transformations.cpp
		)

add_library(GomaeronEngine STATIC ${GOMAERON_ENGINE_SOURCES} ${GOMAERON_ENGINE_HEADERS} GomaeronEngine.h ${Shaders})
if (MSVC)
    target_compile_options(GomaeronEngine PUBLIC /wd5033)
endif(MSVC)
target_include_directories(GomaeronEngine PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} GOMAERON_ENGINE_INCLUDE_DIRECTORY)
target_link_libraries(GomaeronEngine PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET GomaeronEngine PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GOMAERON_ENGINE_SOURCES} ${GOMAERON_ENGINE_HEADERS})

