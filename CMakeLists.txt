cmake_minimum_required(VERSION 3.5)

project(Escultor3d-Parte2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Escultor3d-Parte2 main.cpp
    atualizar_data.sh
    CutBox.cpp
    CutBox.h
    CutEllipsoid.cpp
    CutEllipsoid.h
    CutSphere.cpp
    CutSphere.h
    cutVoxel.cpp
    cutVoxel.h
    FiguraGeometrica.cpp
    FiguraGeometrica.h
    PutBox.cpp
    PutBox.h
    PutEllipsoid.cpp
    PutEllipsoid.h
    PutSphere.cpp
    PutSphere.h
    PutVoxel.cpp
    PutVoxel.h
    README.md
    Sculptor.cpp
    Sculptor.h
    .gitignore
)

include(GNUInstallDirs)
install(TARGETS Escultor3d-Parte2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
