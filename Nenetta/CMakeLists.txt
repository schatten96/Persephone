set(TARGET template)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
			  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
		  	  )
add_executable(${TARGET} ${sources})
