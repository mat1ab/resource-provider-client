CXX = g++
CXXFLAGS = -std=c++20 -Wall -Iinclude

CURRENT_DIR = $(shell pwd)
OBJ_DIR = $(CURRENT_DIR)/build

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
MAIN_OBJECT = $(OBJ_DIR)/main.o
EXECUTABLE = rpc_server

all: $(EXECUTABLE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJECT)
	$(CXX) $^ -o $@

$(MAIN_OBJECT): main.cpp | $(OBJ_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)
