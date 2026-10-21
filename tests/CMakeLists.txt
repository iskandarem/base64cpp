
find_package(Catch2 CONFIG REQUIRED)

add_executable(base64cpp_tests
	main_test.cpp
)

target_link_libraries(base64cpp_tests
	PRIVATE
		Catch2::Catch2WithMain
)

include(Catch)

catch_discover_tests(
	base64cpp_tests
	WORKING_DIRECTORY "$<TARGET_FILE_DIR:base64cpp_tests>"
)

