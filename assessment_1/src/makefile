CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=DeckOfCardsDemo.cpp Node.cpp LinkedList.cpp DeckOfCards.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core