#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "Producto.h"
#include <stdexcept>



class Tienda {
private:
    std::vector<Producto*> inventario;

public:
    ~Tienda();

    void agregarProducto(Producto* producto);
    void eliminarProducto(int id);
    Producto* buscarProducto(int id);
    void mostrarProductos() const;
    std::vector<Producto*> filtrarProductosPorPrecio(double precioMin, double precioMax) const;

};

#endif // TIENDA_H
