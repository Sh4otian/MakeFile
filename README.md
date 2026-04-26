#  Uso de Makefiles

**Escuela Superior de Cómputo (ESCOM) - IPN**
Ingeniería en Sistemas Computacionales

---

## 1. Análisis del reposorio de ejemplo

El Makefile presentado en clase muestra un proceso organizado en el que se delega al sistema de construcción la tarea de ejecutar el compilador `gcc`. En vez de introducir manualmente cada instrucción de compilación, este archivo reúne toda la configuración necesaria: qué archivos compilar, qué opciones utilizar y en qué secuencia hacerlo. Esto ayuda a evitar errores al escribir comandos repetitivos y asegura que todos los miembros del equipo generen exactamente el mismo ejecutable al utilizar `make`.

## Explicación y funcionamiento del código

### Definición de variables (macros)

- `CC = gcc` — Especifica el compilador que se usará.  
- `CFLAGS = -Wall -Wextra -O2` — Define opciones de compilación que habilitan advertencias adicionales y optimización.  
- `TARGET = hola` — Indica el nombre del programa final.  
- `SRCS = main.c` y `OBJS = $(SRCS:.c=.o)` — Realiza la conversión automática de archivos fuente a archivos objeto mediante sustitución de extensiones.  

### Objetivos falsos (.PHONY)

Señala que `all`, `run`, `clean`, `help` y `rebuild` son comandos del Makefile y no archivos reales.

### Reglas de automatización

- `all: $(TARGET)` — Es la regla principal que se ejecuta por defecto al usar `make`.  
- `%.o: %.c` — Regla genérica que define cómo transformar cualquier archivo `.c` en `.o`.  
- `$(TARGET): $(OBJS)` — Indica cómo enlazar los archivos objeto para generar el ejecutable.  
- `run:`, `clean:`, `rebuild:` — Reglas auxiliares que permiten ejecutar el programa, eliminar archivos generados o recompilar todo desde cero.

## Resultados de ejecución

Al correr los comandos en la terminal, se observó el siguiente comportamiento automático:

1. `make help` — Mostró la lista de objetivos disponibles.  
2. `make` — Ejecutó las instrucciones necesarias con gcc para crear `main.o` y el ejecutable `hola`.  
3. `make run` — Compiló (si hubo cambios) y ejecutó `./hola`, mostrando los mensajes de prueba.  
4. `make clean` — Eliminó los archivos generados (`main.o` y `hola`) usando `rm -f`.  

---

## 2. Proyecto Propio: Sistema de Gestión de Pedidos en C++

### Descripción del Proyecto

Este proyecto consiste en un sistema de gestión de pedidos para un restaurante, implementado en C++ y organizado en múltiples archivos fuente. El código se distribuye en cuatro archivos de implementación (`main.cpp`, `Enum.cpp`, `Pedido.cpp`, `Restaurante.cpp`) y cinco cabeceras (`Enums.h`, `Producto.h`, `ItemsPedido.h`, `Pedido.h`, `Restauranter.h`), separados en los directorios `src/` e `include/` respectivamente. El objetivo es demostrar cómo un Makefile gestiona las dependencias entre todos estos módulos y recompila únicamente los archivos que han sido modificados, optimizando el tiempo de construcción.

### Funcionalidades del Sistema

- **Crear pedidos** — cada uno recibe un ID autoincremental único.
- **Agregar productos** — se asocian a un pedido existente indicando nombre, precio, cantidad y tipo (Bebida, Entrada, Plato Fuerte o Postre).
- **Mostrar pedidos** — visualización individual o de todos los pedidos con su total calculado.
- **Cambiar estado** — los pedidos transitan por los estados: `Pendiente → Preparando → Listo → Entregado / Cancelado`.
- **Persistencia en archivo** — los pedidos se guardan en `Pedidos.txt` y se recuperan al iniciar el programa.

### Explicación del Makefile

El archivo `Makefile` de este repositorio está estructurado de la siguiente manera:

- **Variables (`CXX`, `CXXFLAGS`, `TARGET`, `OBJS`):** Centralizan la configuración del compilador, las banderas y los archivos requeridos. La bandera `-Iinclude` indica al compilador dónde encontrar los archivos de cabecera.
- **Regla genérica de compilación:** La regla patrón `$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp` compila cualquier `.cpp` de `src/` a su correspondiente `.o` en `obj/`, sin necesidad de una regla por cada archivo.
- **Regla de enlazado:** Une todos los archivos objeto generados para producir el ejecutable final `restaurante`.
- **Reglas de utilidad:** `clean` elimina `obj/` y el ejecutable; `cleanall` elimina adicionalmente `Pedidos.txt` para reiniciar el entorno por completo.

### Instrucciones de Ejecución (Linux)

```bash
make            # Compilar el proyecto
./restaurante   # Ejecutar el programa
make clean      # Limpiar archivos generados
make cleanall   # Limpiar todo, incluyendo datos guardados
```

### Instrucciones de Ejecución (Windows)

Para compilar en PowerShell utilizando el compilador de MinGW/Code::Blocks sin modificar las variables de entorno del sistema, primero ejecuta:

```powershell
$env:Path = "C:\Program Files\CodeBlocks\MinGW\bin;" + $env:Path
```

Luego compila y ejecuta:

```powershell
make
.\restaurante.exe
```

---

## 📁 Estructura del Proyecto

```
restaurante/
├── Makefile
├── README.md
├── .gitignore
├── include/
│   ├── Enums.h
│   ├── Producto.h
│   ├── ItemsPedido.h
│   ├── Pedido.h
│   └── Restauranter.h
└── src/
    ├── main.cpp
    ├── Enum.cpp
    ├── Pedido.cpp
    └── Restaurante.cpp
```

---

## 👤 Autor

Desarrollado por **Sebastian Martínez Marín** — ESCOM IPN.
