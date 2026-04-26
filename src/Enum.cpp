#include "Enums.h"

std::string estadotoString(StatusPedido Estado) {
	switch (Estado) {
	case StatusPedido::Pendiente:
		return "Pendiente";
		break;
	case StatusPedido::Preparando:
		return "Preparando";
		break;
	case StatusPedido::Listo:
		return "Listo";
		break;
	case StatusPedido::Entregado:
		return "Entregado";
		break;
	case StatusPedido::Cancelado:
		return "Cancelado";
		break;
	default:
		return "Desconocido";
	}
};
