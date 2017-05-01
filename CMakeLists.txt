cmake_minimum_required(VERSION 3.0.0)
project(hepp)


# Build dir
set(BUILD_DIR build)

# googletest
add_subdirectory(
	vendor/googletest
	${BUILD_DIR}
	)




