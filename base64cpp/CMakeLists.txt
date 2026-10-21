
find_package(boost_program_options CONFIG REQUIRED)

add_library(base64cpp_lib 
	uint24_t.hpp
	uint24_t.cpp
	cmdpar.hpp
	cmdpar.cpp
)

target_link_libraries(base64cpp_lib
	PUBLIC
		Boost::program_options
)

target_include_directories(base64cpp_lib
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(base64cpp 
	main.cpp
)

target_link_libraries(base64cpp
	PRIVATE
		base64cpp_lib
)
