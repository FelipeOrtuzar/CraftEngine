function(MakeExample TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER examples_goma)
	target_link_libraries(${TARGETNAME} PRIVATE GomaeronEngine)
	target_include_directories(${TARGETNAME} PRIVATE ${GOMAERON_ENGINE_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})

endfunction(MakeExample)

MakeExample(ex_texture_boo ex_texture_boo.cpp)