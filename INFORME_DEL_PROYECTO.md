Informe sobre el Proyecto de Gestión de Tienda en C++
Problemática:---
El proyecto de Gestión de Tienda en C++ tiene como objetivo simular el funcionamiento básico de una tienda, permitiendo al usuario realizar diversas operaciones como agregar productos, eliminar productos, buscar productos, mostrar el inventario y 
filtrar productos por precio. La problemática abordada se centra en la necesidad de gestionar eficientemente el inventario de una tienda, brindando al usuario herramientas para realizar estas operaciones de manera fácil y eficaz.
Aplicación de POO (Programación Orientada a Objetos):---
La POO se aplica en este proyecto mediante el uso de clases y objetos para modelar entidades del mundo real. Por ejemplo, la clase Tienda representa una tienda, la clase Producto representa un producto genérico, y las clases ProductoAlimenticio 
y ProductoElectronico heredan de Producto y representan productos específicos. Se utiliza encapsulación para ocultar los detalles internos de las clases y proporcionar una interfaz consistente para interactuar con los objetos.
Aplicación de STL (Standard Template Library):---
La STL de C++ se utiliza en este proyecto para proporcionar estructuras de datos y algoritmos útiles para manipular y operar sobre los objetos del proyecto. Por ejemplo, se utilizan contenedores como std::vector para almacenar los productos 
en el inventario de la tienda, y algoritmos como std::find_if y std::copy_if para buscar y filtrar productos en el inventario, respectivamente.
Aplicación de Sobrecarga de Operadores:
Se aplica la sobrecarga de operadores en este proyecto para proporcionar una interfaz más intuitiva y conveniente para manipular objetos. Por ejemplo, se sobrecarga el operador de asignación (=) en la clase Producto, lo que permite asignar un 
objeto Producto a otro de manera más directa y legible. Esto simplifica el código y mejora la legibilidad.
Aplicación de Programación Funcional:---
La programación funcional se utiliza en cierta medida en este proyecto. Por ejemplo, se utiliza la función std::copy_if en la clase Tienda para filtrar productos por precio. Esto permite separar la lógica de filtrado de la manipulación directa del 
contenedor de productos, lo que mejora la legibilidad y mantenibilidad del código.

Diagrama de Clases
El diagrama de clases del proyecto consta de tres clases principales: Tienda, Producto y sus clases derivadas ProductoAlimenticio y ProductoElectronico. Aquí está una representación simplificada del diagrama de clases:

        +------------------------------------------+
        |               Tienda                     |
        +------------------------------------------+
        | - inventario: vector<Producto*>          |
        +------------------------------------------+
                       |
                       |
                       v
        +------------------------------------+                       +--------------------------+
        |              Producto              |---------------------> | ProductoAlimenticio      |
        +------------------------------------+                       +--------------------------+
        | - id: int                          |                       | - fechaCaducidad: string |
        | - nombre: string                   |                       +--------------------------+
        | - precio: double                   |                        +-----------------------+
        | - stock: int                       |----------------------> |   ProductoElectronico |
        +------------------------------------+                        +-----------------------+
                                                                      |- modelo: string       |
                                                                      +-----------------------+
                                           

