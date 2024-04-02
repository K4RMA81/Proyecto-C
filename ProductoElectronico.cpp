#include "ProductoElectronico.h"
#include <iostream>

ProductoElectronico::ProductoElectronico(int _id, const std::string& _nombre, double _precio, int _stock, const std::string& _modelo)
        : Producto(_id, _nombre, _precio, _stock), modelo(_modelo) {}

std::string ProductoElectronico::getModelo() const {
    return modelo;
}

void ProductoElectronico::mostrar() const {
    std::cout << "ID: " << getId() << " - Nombre: " << getNombre() << " - Precio: " << getPrecio() << " - Stock: " << getStock() << " - Modelo: " << modelo << std::endl;
}
