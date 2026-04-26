#include "Restauranter.h" // "../sadasd/asdasd/asdasd/asd/.h"
#include <fstream>
#include <sstream>

void Restaurante::CrearPedido() {
	Pedidos.push_back(Pedido(contador));
	std::cout << "Pedido creado con el ID:" << contador << std::endl;
	contador++;
}

Pedido* Restaurante::BuscarPedido(int ID) {
	for (auto& p : Pedidos) {
		if (p.GetId() == ID) {
			std::cout << "Se encontro el pedido" << std::endl;
			return &p;
		}
	}
	return nullptr;
}

void Restaurante::MostrarUnP(int ID) {
	Pedido* p = BuscarPedido(ID);
	if (p != nullptr) {
		p->Mostrar();
	}
	else {
		std::cout << "El pedido no fue encontrado" << std::endl;
		std::cout << "¿Desea realizar otro pedido? Yes=1, No=0;" << std::endl;

	}
}

void Restaurante::MostrarTodo() {
	for (auto& p : Pedidos) {
		p.Mostrar();
	}
}

void Restaurante::GuardarpedidosArch() {
	std::ofstream archivo("Pedidos.txt");

	for (const auto& p : Pedidos) {
		std::string Todo;
		Todo = p.Guardar();
		archivo << Todo;
	}
	archivo.close();
}

void Restaurante::LecturaArch() {
	std::ifstream archivo("Pedidos.txt");
	std::string Parrafo;

	while (std::getline(archivo, Parrafo)) {
		
		std::stringstream ss(Parrafo);
		int id, Estado, tamano;


		ss >> id >> Estado >> tamano;
		Pedido p(id);
		p.cambiarEstado(static_cast<StatusPedido>(Estado));

		p.CargarI(archivo,tamano);
		Pedidos.push_back(p);
		if (id >= contador) {
			contador++;
		}
	
	}
	/*
	Pedido p = Pedido::Cargar(archivo);
	if (p.GetId() != -1) {
		Pedidos.push_back(p);
		contador++;
	}
		*/
}
//Formato blanco para el manual.

/*
* if (archivo.is_open()) {
		while (!archivo.eof()) {
			Pedido p = Pedido::Cargar(archivo);
			if (p.GetId() != -1) {
				Pedidos.push_back(p);
				contador++;
			}
		}
	}
*/
