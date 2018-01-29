CC=gcc
CFLAGS=-g  

all: instruction_generator
instruction_generator: instruction_generator.o
	$(CC) $< -o $@
	rm $<
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -rf *.o instruction_generator
