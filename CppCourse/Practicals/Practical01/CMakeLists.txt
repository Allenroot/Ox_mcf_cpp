file(GLOB sourcefiles "Src/*.cpp")
file(GLOB headerfiles "*.hpp")
add_executable(Practical01 ${sourcefiles} ${headerfiles}
        Src/NormFunctions.cpp
        Src/MonteCarlos.cpp)

target_link_libraries(Practical01 Utils)
