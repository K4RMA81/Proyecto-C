#include <iostream>
#include <cctype>
#include "Tienda.h"
#include "Producto.h"
#include "ProductoAlimenticio.h"
#include "ProductoElectronico.h"
#include <sstream>

bool contieneSoloLetras(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}
bool contieneSoloDigitos(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool esNumeroDecimal(const std::string& str) {
    std::istringstream iss(str);
    double temp;
    iss >> std::noskipws >> temp;
    return iss.eof() && !iss.fail();
}


int main() {
    Tienda tienda;

    int opcion;
    do {
        //Menu Principal del programa
        std::cout << "\n=== MENU ===" << std::endl;
        std::cout << "1. Agregar Producto" << std::endl;
        std::cout << "2. Eliminar Producto" << std::endl;
        std::cout << "3. Buscar Producto" << std::endl;
        std::cout << "4. Mostrar Inventario" << std::endl;
        std::cout << "5. Filtrar Productos por Precio" << std::endl;
        std::cout << "6. Copiar Producto" << std::endl;
        std::cout << "7. Salir" << std::endl;
        std::cout << "Seleccione una opcion:\n ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                //Agregar producto
                std::string idStr;
                int id;
                std::string nombre;
                std::string precioStr;
                double precio;
                int stock;
                std::string fechaCaducidad;
                std::string modelo;
                int tipoProducto;
                //Menu de tipo de productos
                do {
                    std::cout << "Ingrese el tipo de producto\n 1-Producto\n 2-Producto Alimenticio\n 3-Producto Electronico\nSeleccione una opcion:\n ";
                    std::cin >> tipoProducto;
                } while (tipoProducto < 1 || tipoProducto > 3);
                //Pedir al usuario q ingrese el ID del producto hasta q contenga solo numeros
                do {
                    std::cout << "Ingrese el ID del producto:\n ";
                    std::cin >> idStr;
                    if (!contieneSoloDigitos(idStr)) {
                        std::cerr << "El ID del producto debe contener solo digitos." << std::endl;
                    }
                } while (!contieneSoloDigitos(idStr));

                // Convertir la cadena de ID a entero
                id = std::stoi(idStr);

                // Pedir al usuario q ingrese el nombre hasta q contenga solo letras
                do {
                    std::cout << "Ingrese el nombre del producto:\n ";
                    std::cin >> nombre;
                    if (!contieneSoloLetras(nombre)) {
                        std::cerr << "El nombre del producto debe contener solo letras." << std::endl;
                    }
                } while (!contieneSoloLetras(nombre));
                //Pedir al usuario q ingrese el precio del producto hasta q contenga solo numeros
                do {
                    std::cout << "Ingrese el precio del producto:\n ";
                    std::cin >> precioStr;
                    if (!esNumeroDecimal(precioStr)) {
                        std::cerr << "El precio del producto debe ser un numero." << std::endl;
                    }
                } while (!esNumeroDecimal(precioStr));
                precio = std::stod(precioStr); // Convertir la cadena de precio a double
                //Pedir al usuario q ingrese el stock del producto hasta q contenga solo numeros
                do {
                    std::cout << "Ingrese el stock del producto:\n ";
                    std::cin >> stock;
                    if (!esNumeroDecimal(std::to_string(stock))) {
                        std::cerr << "El stock del producto debe ser un número entero." << std::endl;
                    }
                } while (!esNumeroDecimal(std::to_string(stock)));

                if (tipoProducto == 2) {
                    std::cout << "Ingrese la fecha de caducidad del producto alimenticio: ";
                    std::cin >> fechaCaducidad;
                    tienda.agregarProducto(new ProductoAlimenticio(id, nombre, precio, stock, fechaCaducidad));
                } else if (tipoProducto == 3) {
                    std::cout << "Ingrese el modelo del producto electronico: ";
                    std::cin >> modelo;
                    tienda.agregarProducto(new ProductoElectronico(id, nombre, precio, stock, modelo));
                } else {
                    tienda.agregarProducto(new Producto(id, nombre, precio, stock));
                }

                break;
            }
            case 2: {
                int id;
                std::cout << "Ingrese el ID del producto a eliminar:\n ";
                std::cin >> id;
                tienda.eliminarProducto(id);
                break;
            }
            case 3: {
                //Buscar producto por ID
                int id;
                std::cout << "Ingrese el ID del producto a buscar:\n ";
                std::cin >> id;
                Producto* encontrado = tienda.buscarProducto(id);
                if (encontrado) {
                    std::cout << "Producto encontrado:\n ";
                    encontrado->mostrar();
                } else {
                    std::cerr << "Producto no encontrado." << std::endl;
                }
                break;
            }
            case 4:
                //Inventario de la tienda
                std::cout << "\n=== Inventario de la Tienda ===" << std::endl;
                try {
                    tienda.mostrarProductos();
                } catch (const std::logic_error& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                break;

            case 5: {
                // Filtrar productos por precio
                double precioMin, precioMax;
                std::cout << "Ingrese el precio minimo: ";
                std::cin >> precioMin;
                std::cout << "Ingrese el precio maximo: ";
                std::cin >> precioMax;
                std::vector<Producto *> productosFiltrados = tienda.filtrarProductosPorPrecio(precioMin, precioMax);
                std::cout << "\n=== Productos filtrados por precio ===" << std::endl;
                for (Producto *producto: productosFiltrados) {
                    producto->mostrar();
                }
            }
                break;
            case 6: {
                // Copiar producto
                int idOrigen, idDestino;
                std::cout << "Ingrese el ID del producto origen: ";
                std::cin >> idOrigen;
                std::cout << "Ingrese el ID del producto destino: ";
                std::cin >> idDestino;

                Producto *productoOrigen = tienda.buscarProducto(idOrigen);
                Producto *productoDestino = tienda.buscarProducto(idDestino);

                if (productoOrigen && productoDestino) {
                    *productoDestino = *productoOrigen;
                    std::cout << "Producto copiado exitosamente." << std::endl;
                } else {
                    std::cerr << "Al menos uno de los productos especificados no existe en el inventario."
                              << std::endl;
                }
            }
                break;
            case 7:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cerr << "Opcion invalida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 7);

    return 0;
}

