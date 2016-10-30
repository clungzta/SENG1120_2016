CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=StudentResults.cpp ClassroomOfStudents.cpp Student.cpp ClassroomOfStudents.h Student.h BTree.h BTNode.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=StudentResults

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core