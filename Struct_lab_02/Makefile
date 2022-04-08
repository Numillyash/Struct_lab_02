CC=gcc
CFLAGS=-g -Wall -Wextra -O0
LDFLAGS=
SOURCES=main.c config.h input.c input.h output.c output.h LCG.c LCG.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=work1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@