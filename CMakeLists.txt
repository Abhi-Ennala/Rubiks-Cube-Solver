cmake_minimum_required(VERSION 3.20)
project(rubiks_cube_solver)

set(CMAKE_CXX_STANDARD 17)

include_directories(Model)

add_executable(rubiks_cube_solver
    main.cpp
    Model/RubiksCube.cpp
    Model/RubiksCube3dArray.cpp
    Model/RubiksCube1dArray.cpp
    Model/RubiksCube.h
    Solver/BFSSolver.h
    Solver/DFSSolver.h
    Solver/IDDFSSolver.h
    # add only files that exist right now...
)