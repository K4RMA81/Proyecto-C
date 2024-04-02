#include "Producto.h"
#include <iostream>

Producto::Producto(int _id, const std::string& _nombre, double _precio, int _stock)
        : id(_id), nombre(_nombre), precio(_precio), stock(_stock) {}

int Producto::getId() const {
    return id;
}

std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getStock() const {
    return stock;
}

void Producto::setPrecio(double _precio) {
    precio = _precio;
}

void Producto::setStock(int _stock) {
    stock = _stock;
}

void Producto::mostrar() const {
    std::cout << "ID: " << id << " - Nombre: " << nombre << " - Precio: " << precio << " - Stock: " << stock << std::endl;
}

// Implementación de la sobrecarga del operador de asignación
Producto& Producto::operator=(const Producto& otro) {
    if (this != &otro) {
        id = otro.id;
        nombre = otro.nombre;
        precio = otro.precio;
        stock = otro.stock;
    }
    return *this;
}
