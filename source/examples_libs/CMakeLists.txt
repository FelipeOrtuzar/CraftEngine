function(MakeExample TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER examples_libs)
	target_link_libraries(${TARGETNAME} PRIVATE grafica)
	target_include_directories(${TARGETNAME} PRIVATE ${GRAFICA_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})

endfunction(MakeExample)

MakeExample(ex_sfml_window ex_sfml_window.cpp)