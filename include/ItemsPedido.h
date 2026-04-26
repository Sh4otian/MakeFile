#ifndef ItemPedido
#define ItemPedido
#include "Producto.h"

class ItemsPedido {
private:
	Producto Peticion;
	int Cantidad;
public:
	ItemsPedido(Producto P, int Cant) : Peticion(P), Cantidad(Cant) {}
	double CalcularSubTotal() const {
		return Peticion.GetPrecio() * Cantidad;
	}
	void Mostrar() const {
		std::cout << Peticion.GetNombre() << " Cant: " << Cantidad << " = $ " << CalcularSubTotal() << std::endl;
	}
	std::string Devolver() const {
		return Peticion.GetNombre() +  ";" + std::to_string(Peticion.GetPrecio()) + ";" + std::to_string(static_cast<int>(Peticion.GetTipo())) + ";" + std::to_string(Cantidad) + "\n";
	}
};
#endif //ItemPedido