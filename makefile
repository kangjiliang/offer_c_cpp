SOURCES = $(wildcard ./*.cpp)

INCLUDE = -I./

CXX     = g++
LIBS    =
FLAGS   = -Wall -g
TARGET  = main


.PHONY: $(TARGET)


$(TARGET):
	$(CXX) -o $(TARGET) $(SOURCES) $(INCLUDE) $(FLAGS) $(LIBS)
	./$(TARGET)

clean:
	rm -rf $(TARGET)

