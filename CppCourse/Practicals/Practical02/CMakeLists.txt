file(GLOB sourcefiles "Src/*.cpp")
file(GLOB headerfiles "*.hpp")
add_executable(Practical02 ${sourcefiles} ${headerfiles}
        Src/Practical02Solutions.cpp)

target_link_libraries(Practical02 Utils)
