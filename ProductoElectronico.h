#ifndef PRODUCTOELECTRONICO_H
#define PRODUCTOELECTRONICO_H

#include "Producto.h"

class ProductoElectronico : public Producto {
private:
    std::string modelo;

public:
    ProductoElectronico(int _id, const std::string& _nombre, double _precio, int _stock, const std::string& _modelo);

    std::string getModelo() const;

    void mostrar() const ;
};

#endif // PRODUCTOELECTRONICO_H

