CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=Blackjack.cpp Card.cpp DeckOfCards.cpp HandOfCards.cpp Node.h LinkedList.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Blackjack

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core