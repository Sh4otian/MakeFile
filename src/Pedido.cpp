#include "Pedido.h"
#include <iostream>
#include <string>
#include <sstream>

Pedido::Pedido(int i) : id(i), Estados(StatusPedido::Pendiente) {}

int Pedido::GetId() const {
    return id;
}

double Pedido::CalcularTotal() const {
    double Total = 0.0;

    for (const auto& item : Solicitado) {
        Total += item.CalcularSubTotal();
    }

    return Total;
}

void Pedido::Mostrar() const {
    std::cout << "\n Pedido ID: " << id << std::endl;
    std::cout << "Estado: " << estadotoString(Estados) << std::endl;
    std::cout << "Productos: \n";

    for (const auto& item : Solicitado) {
        // CON TODO VERIFICAR QUE PASA CON Y SIN &
        item.Mostrar();
    }

    std::cout << "Total $ " << CalcularTotal() << std::endl;
}

void Pedido::cambiarEstado() {
    int Opc = 0;

    std::cout << estadotoString(Pedido::Estados) << std::endl;

    do {
        if (Estados == StatusPedido::Entregado) {
            std::cout << "Error: no se puede modificar un pedido entregado" << std::endl;
        }
        else {
            std::cout << "Ingrese el status a cambiar: (0=Pendiente, 1= Preparacion\n 2=Listo, 3=Entregado, 4=Cancelado)" << std::endl;
            std::cin >> Opc;

            switch (Opc) {
            case 0: Estados = StatusPedido::Pendiente; break;
            case 1: Estados = StatusPedido::Preparando; break;
            case 2: Estados = StatusPedido::Listo; break;
            case 3: Estados = StatusPedido::Entregado; break;
            case 4: Estados = StatusPedido::Cancelado; break;
            default:
                std::cout << "Opcion no valida. Vuelva a intentarlo" << std::endl;
                break;
            }
        }
    } while (Opc > 4 || Opc < 0);
}

void Pedido::cambiarEstado(StatusPedido e) {
    Estados = e;
}

void Pedido::AgregarProducto(Producto P, int cantidad) {
    if (cantidad <= 0) {
        std::cout << "Cantidad Invalida" << std::endl;
        return;
    }

    Solicitado.push_back(ItemsPedido(P, cantidad));
}

std::string Pedido::Guardar() const {
    std::string Todo;

    Todo = std::to_string(id) + " " +
        std::to_string(static_cast<int>(Estados)) + " " +
        std::to_string(Solicitado.size()) + "\n";

    for (const auto& Item : Solicitado) {
        Todo.append(Item.Devolver());
    }

    return Todo;
}

void Pedido::CargarI(std::ifstream& archivo, int tamano) {
    std::string Parrafo;

    for (int i = 0; i < tamano; i++) {
        std::getline(archivo, Parrafo);
        std::stringstream ss(Parrafo);

        std::string Nombre;
        double Precio;
        int tipo, cantidad;
        
        std::getline(ss, Nombre, ';');
        ss >> Precio;
        ss.ignore();
        ss >> tipo;
        ss.ignore();
        ss >> cantidad;

        Producto prod(Nombre, Precio, static_cast<TipProd>(tipo));
        AgregarProducto(prod, cantidad);
    }
}
/*
Pedido Pedido::Cargar(std::ifstream& archivo) {
    std::string Parrafo;

    if (std::getline(archivo, Parrafo)) {
        std::stringstream ss(Parrafo);
        int id, Estado, tamano;

        ss >> id >> Estado >> tamano;
        Pedido p(id);
        p.cambiarEstado(static_cast<StatusPedido>(Estado));

        std::string Nombre;
        double Precio;
        int tipo, cantidad;
        
        for (int i = 0; i < tamano; i++) {
            std::getline(ss, Nombre, ';');
            ss >> Precio;
            ss.ignore();
            ss >> tipo;
            ss.ignore();
            ss >> cantidad;

            Producto prod(Nombre, Precio, static_cast<TipProd>(tipo));
            p.AgregarProducto(prod, cantidad);
        }
    }
    
}
*/