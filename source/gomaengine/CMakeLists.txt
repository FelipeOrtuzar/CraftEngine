set(GOMAENGINE_HEADERS
	aplication.h
	GameObject.h
	GraphicComponent.h
	#InputComponent.h
	SoundComponent.h
	#CR_MovableComponent.h
	AnimationComponent.h
	Utils.h
 )

set(GOMAENGINE_SOURCES
	aplication.cpp
	GameObject.cpp
	GraphicComponent.cpp
	AnimationComponent.cpp
	#InputComponent.cpp
	SoundComponent.cpp
	#CR_MovableComponent.cpp
	Utils.cpp

 )

add_library(gomaengine STATIC ${GOMAENGINE_SOURCES} ${GOMAENGINE_HEADERS} gomaengine.h root_directory.h)
if (MSVC)
    target_compile_options(gomaengine PUBLIC /wd5033)
endif(MSVC)
target_include_directories(gomaengine PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} GOMAENGINE_INCLUDE_DIRECTORY)
target_link_libraries(gomaengine PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET gomaengine PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GOMAENGINE_SOURCES} ${GOMAENGINE_HEADERS})