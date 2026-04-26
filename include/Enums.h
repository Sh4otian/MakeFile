#ifndef Enus
#define Enus
#include <string>

enum class TipProd { Bebida, Entrada, PlatoFuerte, Postre};
enum class StatusPedido { Pendiente, Preparando, Listo, Entregado, Cancelado };
std::string estadotoString(StatusPedido Estado);

#endif //Enum
