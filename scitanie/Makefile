#variables
CC = gcc
CFLAGS = -std=c11
LDLIBS = -lm
OUTPUT = main
#targets
all: $(OUTPUT)
$(OUTPUT): main.o
	$(CC) $(CFLAGS) main.o $(LDLIBS) -o $(OUTPUT)
main.o: main.c
	$(CC) $(CFLAGS) main.c -c $(LDLIBS) -o main.o
clean:
	rm -rf $(OUTPUT)
	rm -rf main.o
