all: obj/Programa.o obj/Cidades.o
	gcc obj/Programa.o obj/Cidades.o -o Programa
	mv Programa bin/

obj/Programa.o: src/Programa.c
	gcc src/Programa.c -c
	mv Programa.o obj/

obj/Cidades.o: src/Cidades.c include/Cidades.h
	gcc src/Cidades.c include/Cidades.h -c 
	mv Cidades.o obj/