CC=g++
CFLAGS=-std=c++20 -Wall -Wextra -Iinclude -fsanitize=address
EXECUTABLE=ram_simulator

OBJ=Utils Tape Operand instruction/AbstractInstruction Instruction ProgramMemory DataMemory ProcessUnit RAM

all: src/main.cc $(OBJ:%=build/%.o)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $^

build/%.o: src/%.cc include/%.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o build/$*.o src/$*.cc

clean:
	rm build/*.o

.PHONY: clean
