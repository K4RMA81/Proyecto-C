cmake_minimum_required(VERSION 3.26)
project(Proyecto_C___2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_C___2 main.cpp
        Tienda.cpp
        Tienda.h
        Producto.cpp
        Producto.h
        ProductoAlimenticio.cpp
        ProductoAlimenticio.h
        ProductoElectronico.cpp
        ProductoElectronico.h
)
