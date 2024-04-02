#include "Tienda.h"
#include <algorithm>
#include <functional>
#include <iostream>
Tienda::~Tienda() {
    // Liberar memoria
    for (auto& producto : inventario) {
        delete producto;
    }
}

void Tienda::agregarProducto(Producto* producto) {
    inventario.push_back(producto);
}

void Tienda::eliminarProducto(int id) {
    auto it = std::find_if(inventario.begin(), inventario.end(), [id](const Producto* p) { return p->getId() == id; });
    if (it == inventario.end()) {
        std::cerr << "Error: El ID del producto a eliminar no existe en el inventario." << std::endl;
        return;
    }
    inventario.erase(it);
}

Producto* Tienda::buscarProducto(int id) {
    auto it = std::find_if(inventario.begin(), inventario.end(), [id](const Producto* p) { return p->getId() == id; });
    if (it != inventario.end()) {
        return *it;
    }
    return nullptr;
}

void Tienda::mostrarProductos() const {
    for (const auto& producto : inventario) {
        producto->mostrar();
    }
}

std::vector<Producto*> Tienda::filtrarProductosPorPrecio(double precioMin, double precioMax) const {
    std::vector<Producto*> productosFiltrados;
    std::copy_if(inventario.begin(), inventario.end(), std::back_inserter(productosFiltrados), [&](Producto* producto) {
        double precio = producto->getPrecio();
        return precio >= precioMin && precio <= precioMax;
    });
    return productosFiltrados;
}
