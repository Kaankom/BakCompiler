OBJECTS= ./build/compiler.o ./build/cprocess.o
INCLUDES= -I./

all: ${OBJECTS}
	gcc src/main.c ${INCLUDES} ${OBJECTS} -g -o ./main

./build/compiler.o: ./src/compiler.c
	gcc src/compiler.c ${INCLUDES} -o ./build/compiler.o -g -c

./build/cprocess.o: ./src/cprocess.c
	gcc src/cprocess.c ${INCLUDES} -o ./build/cprocess.o -g -c

clean:
	rm ./main
	rm -rf ${OBJECTS}

