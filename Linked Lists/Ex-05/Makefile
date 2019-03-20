SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))
output: $(OBJ)
	gcc -o $@ $(OBJ) -Wall
clean:
	rm *.o output
