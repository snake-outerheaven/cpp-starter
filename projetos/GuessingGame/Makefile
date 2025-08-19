#compilador e flags

CXX := g++
CXXFLAGS := -Wall -Wextra -march=native -O2


# estrutura de pastas

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

#nome do executável

TARGET := $(BIN_DIR)/GuessingGame.exe


#listar todos o sarquivos .cpp da pasta de códigos fonte

SRCS:=$(wildcard $(SRC_DIR)/*.cpp)

#converte para arquivos objetos dentro de build/

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)


#gerar executável

all: $(TARGET)


#como gerar o executável a partir dos objetos
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

#como gerar cada objeto a partir do .cpp correspondente

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


#executar o programa

run: $(TARGET)
	./$(TARGET)


clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)


.PHONY: all run clean
