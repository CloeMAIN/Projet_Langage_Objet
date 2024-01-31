CC=g++
CFLAGS=-c
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopenal
SOURCES=$(wildcard ../Sources/*.cc) $(wildcard ../tests/*.cc)
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=mon_programme

EXCLUDE_FILE=../Sources/main.cc  # Ajoutez le nom du fichier que vous souhaitez exclure

all: $(EXECUTABLE)

$(EXECUTABLE): $(filter-out $(EXCLUDE_FILE:.cc=.o), $(OBJECTS))
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.depend:
	g++ $(CCFLAGS) $(INCLUDES) -MM $(SOURCES) > .depends

-include .depends

clean:
	rm -f $(OBJ_TEST) mon_programme ../Sources/*.o ../tests/*.o .depends