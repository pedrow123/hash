OBJECTS = hash.c main.c saida.c

all: ${OBJECTS} hash.h saida.h
	gcc ${OBJECTS} -o myht -lm

purge: myht
	rm myht
