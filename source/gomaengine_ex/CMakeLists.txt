function(MakeExample TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER gomaengine_ex)
	target_link_libraries(${TARGETNAME} PRIVATE gomaengine)
	target_include_directories(${TARGETNAME} PRIVATE ${GOMAENGINE_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})

endfunction(MakeExample)

MakeExample(wg_test wg_test.cpp)
