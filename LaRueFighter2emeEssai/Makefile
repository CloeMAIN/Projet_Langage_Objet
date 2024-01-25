CC=g++
CFLAGS=-c
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES= $(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=mon_programme

all: run

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run : $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)