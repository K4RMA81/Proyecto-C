#ifndef PRODUCTOALIMENTICIO_H
#define PRODUCTOALIMENTICIO_H

#include "Producto.h"

class ProductoAlimenticio : public Producto {
private:
    std::string fechaCaducidad;

public:
    ProductoAlimenticio(int _id, const std::string& _nombre, double _precio, int _stock, const std::string& _fechaCaducidad);

    std::string getFechaCaducidad() const;

    void mostrar() const ;
};

#endif // PRODUCTOALIMENTICIO_H
