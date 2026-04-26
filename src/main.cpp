#include <iostream>
#include "Restauranter.h"

int main()
{ 
    Restaurante Nuevo;
    Nuevo.LecturaArch();
    int Opc = 0;
    std::string Nombre;
    Pedido* p = nullptr;
    std::cout << "RESTAURAN SEBASTIAN's " << std::endl;
    do {
        std::cout << "\n 1.- Crear Pedido\n2.-Agregar Productos\n3.- Mostrar Pedidos\n4.-Cambiar Estado.\n0.-Salir\n";
        std::cin >> Opc;

        switch (Opc) {
        case 1:
            Nuevo.CrearPedido();
            break;
        case 2:
            int id, cantidad, tipInt;
            double Precio;
            std::cout << "ID del Pedido: ";
            std::cin >> id;
            std::cin.ignore();
            p = Nuevo.BuscarPedido(id);
            if (p != nullptr) {
                std::cout << "Nombre del Producto:";
                getline(std::cin, Nombre);
                std::cout << "Precio:";
                std::cin >> Precio;
                std::cout << "Cantidad:";
                std::cin >> cantidad;
                std::cout << "Tipo (0=Bebida,1=Entrada, 2=Plato Fuerte, 3=Postre):";
                std::cin >>tipInt;

                TipProd tipo = static_cast<TipProd>(tipInt);

                Producto prod(Nombre, Precio, tipo);
                p->AgregarProducto(prod,cantidad);
            }
            else {
                std::cout << "No se encontro el Pedido Especificado." << std::endl;
            }
            break;
        case 3:
            Nuevo.MostrarTodo();
            break;
        case 4:
            std::cout << "ID del Pedido:";
            std::cin >> id;
            p = Nuevo.BuscarPedido(id);
            Nuevo.MostrarUnP(id);
            if (p != nullptr) {
                p->cambiarEstado();
            }
            else {
                std::cout << "No se encontro el Pedido Especificado." << std::endl;
            }
            break;
        case 0:
            std::cout << "Ha salido" << std::endl;
            break;
        default:
            std::cout << "Opcion no encontrada" << std::endl;
        }
        Nuevo.GuardarpedidosArch();
    } while (Opc != 0);
    /*
    for (int i = 0; i < 3; i++) {
        Nuevo.CrearPedido();
    }
    for (int i = 1; i < 7; i++) { 
        Nuevo.MostrarUnP(i);
    }

    Nuevo.MostrarTodo();
    */
    /*
    Pedido Nuevo(1);
    Producto New("Coca-Cola 600ml",21,TipProd::Bebida);
    Nuevo.Mostrar();
    Nuevo.AgregarProducto(New, 0);
    Nuevo.cambiarEstado();
    Nuevo.cambiarEstado();
    Nuevo.Mostrar();
    */
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
