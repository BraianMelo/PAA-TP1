all: obj/Programa.o obj/Lista_Cidades.o obj/Cidades.o
	gcc obj/Programa.o obj/Lista_Cidades.o obj/Cidades.o -o Programa
	mv Programa bin/

obj/Programa.o: src/Programa.c
	gcc src/Programa.c -c
	mv Programa.o obj/

obj/Lista_Cidades.o: src/Lista_Cidades.c include/Lista_Cidades.h
	gcc src/Lista_Cidades.c -c
	mv Lista_Cidades.o obj/

obj/Cidades.o:  src/Cidades.c include/Cidades.h
	gcc src/Cidades.c -c
	mv Cidades.o obj/

apagar:
	rm obj/* bin/Programa