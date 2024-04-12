CC = g++

CFLAGS = -Wall -std=c++11

SOURCES = main.cpp src/GameObject/GameObject.cpp src/Player/Walikota.cpp src/Item/Item.cpp src/Item/Plant.cpp src/Item/Produk.cpp src/Item/Animal.cpp src/Item/Bangunan.cpp

OUTPUT_FOLDER = bin

OBJECTS = $(patsubst %.cpp,$(OUTPUT_FOLDER)/%.o,$(SOURCES))

EXECUTABLE = $(OUTPUT_FOLDER)/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OUTPUT_FOLDER)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTPUT_FOLDER)

.PHONY: all clean build
