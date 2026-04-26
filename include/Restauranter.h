#ifndef Restau
#define Restau
#include "Pedido.h"

class Restaurante {
private:
	std::vector<Pedido> Pedidos;
	int contador = 1;
public:
	void CrearPedido();
	Pedido* BuscarPedido(int ID);
	void MostrarUnP(int ID);
	void MostrarTodo();
	void GuardarpedidosArch();
	void LecturaArch();
};
 

#endif // Restau