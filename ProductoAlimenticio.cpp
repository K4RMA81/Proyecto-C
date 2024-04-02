#include "ProductoAlimenticio.h"
#include <iostream>

ProductoAlimenticio::ProductoAlimenticio(int _id, const std::string& _nombre, double _precio, int _stock, const std::string& _fechaCaducidad)
        : Producto(_id, _nombre, _precio, _stock), fechaCaducidad(_fechaCaducidad) {}

std::string ProductoAlimenticio::getFechaCaducidad() const {
    return fechaCaducidad;
}

void ProductoAlimenticio::mostrar() const {
    std::cout << "ID: " << getId() << " - Nombre: " << getNombre() << " - Precio: " << getPrecio() << " - Stock: " << getStock() << " - Fecha de Caducidad: " << fechaCaducidad << std::endl;
}
