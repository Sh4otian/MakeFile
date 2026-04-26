CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

TARGET   = restaurante

SRC_DIR  = src
OBJ_DIR  = obj

SRCS     = $(SRC_DIR)/main.cpp \
           $(SRC_DIR)/Enum.cpp \
           $(SRC_DIR)/Pedido.cpp \
           $(SRC_DIR)/Restaurante.cpp

OBJS     = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

cleanall: clean
	rm -f Pedidos.txt

.PHONY: all clean cleanall
