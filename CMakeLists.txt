cmake_minimum_required(VERSION 2.6)

project(GCP_Assignment)

include_directories(
	contrib/include
)

link_directories(
	${CMAKE_SOURCE_DIR}/contrib/lib
)

add_executable(GCP_Assignment
	src/main.cpp
)

target_link_libraries(GCP_Assignment SDL2)

add_custom_command(TARGET GCP_Assignment
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	"${PROJECT_SOURCE_DIR}/contrib/lib/SDL2.dll"
	$<TARGET_FILE_DIR:GCP_Assignment>
)
