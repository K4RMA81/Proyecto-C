#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    int id;
    std::string nombre;
    double precio;
    int stock;

public:
    Producto(int _id, const std::string& _nombre, double _precio, int _stock);

    int getId() const;
    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    void setPrecio(double _precio);
    void setStock(int _stock);

    void mostrar() const;

    // Sobrecarga del operador de asignación
    Producto& operator=(const Producto& otro);
};

#endif // PRODUCTO_H
