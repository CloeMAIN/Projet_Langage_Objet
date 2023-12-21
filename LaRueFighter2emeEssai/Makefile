CC=g++
CFLAGS=-c
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES= $(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=mon_programme

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	./$(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)