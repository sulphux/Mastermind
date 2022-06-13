# includes
include_directories(include)


file(GLOB Sources "src/*.cpp")
file(GLOB Headers "include/*.h")

add_library(${PROJECT_NAME}_lib STATIC ${Sources} ${Headers})

add_executable(${PROJECT_NAME} "Mastermind.cpp" ${Headers} )

target_link_libraries(${PROJECT_NAME} Mastermind_lib)