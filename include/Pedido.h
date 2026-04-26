#ifndef Ped
#define Ped
#include "ItemsPedido.h"
#include <vector>
#include <fstream>

class Pedido {
private:
	const int id;
	std::vector<ItemsPedido> Solicitado;
	StatusPedido Estados;
public:
	Pedido(int i);
	int GetId() const;
	double CalcularTotal() const;
	void Mostrar() const;
	void cambiarEstado();
	void cambiarEstado(StatusPedido e);
	void AgregarProducto(Producto P, int cantidad);
	std::string Guardar() const;
	static Pedido Cargar(std::ifstream& archivo);
	void CargarI(std::ifstream& archivo,int tamano);
};

#endif //Ped
