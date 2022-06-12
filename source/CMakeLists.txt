project(Mastermind)

###

add_library(GameSession_lib STATIC 
	src/GameSession.cpp
)

target_include_directories(GameSession_lib
	PUBLIC 
		${PROJECT_SOURCE_DIR}/include
)

###

add_executable(Mastermind 
	src/Mastermind.cpp
)

target_link_libraries(Mastermind 
	PRIVATE 
		GameSession_lib
)

#set(BINARY ${CMAKE_PROJECT_NAME})
#file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
#set(SOURCES ${SOURCES})
#add_executable(${BINARY}_run ${SOURCES})
#add_library(${BINARY}_lib STATIC ${SOURCES})
