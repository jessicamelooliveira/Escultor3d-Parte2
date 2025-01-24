cmake_minimum_required(VERSION 3.5)

project(Escultor3d-Parte2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Escultor3d-Parte2 main.cpp
    FiguraGeometrica.h
    FiguraGeometrica.cpp
    PutVoxel.h
    PutVoxel.cpp
    Sculptor.h
    Sculptor.cpp)

include(GNUInstallDirs)
install(TARGETS Escultor3d-Parte2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
