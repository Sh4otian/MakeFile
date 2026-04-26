#ifndef Produc
#define Produc
#include "Enums.h"
#include <iostream>

class Producto {
private:
	std::string Nombre;
	double Precio;
	TipProd Tipos;
public:
	Producto(std::string Nom, double Pre, TipProd Tip) : Nombre(Nom), Precio(Pre), Tipos(Tip) {}
	std::string GetNombre() const {
		return Nombre;
	}
	double GetPrecio() const {
		return Precio;
	}
	TipProd GetTipo() const {
		return Tipos;
	}
};
#endif //Produc
