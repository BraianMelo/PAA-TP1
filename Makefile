all: obj/Programa.o obj/Tempo.o obj/Cidade.o obj/Lista_Cidades.o obj/Heap_Prioridade.o obj/Dijkstra.o
	gcc obj/Programa.o obj/Tempo.o obj/Lista_Cidades.o obj/Cidade.o obj/Heap_Prioridade.o obj/Dijkstra.o -o Programa
	mv Programa bin/

obj/Programa.o: src/Programa.c
	gcc src/Programa.c -c
	mv Programa.o obj/

obj/Tempo.o: src/Tempo.c include/Tempo.h 
	gcc src/Tempo.c -c 
	mv Tempo.o obj/

obj/Cidade.o:  src/Cidade.c include/Cidade.h
	gcc src/Cidade.c -c
	mv Cidade.o obj/

obj/Lista_Cidades.o: src/Lista_Cidades.c include/Lista_Cidades.h
	gcc src/Lista_Cidades.c -c
	mv Lista_Cidades.o obj/

obj/Heap_Prioridade.o: src/Heap_Prioridade.c include/Heap_Prioridade.h
	gcc src/Heap_Prioridade.c -c
	mv Heap_Prioridade.o obj/

obj/Dijkstra.o: src/Dijkstra.c include/Dijkstra.h 
	gcc src/Dijkstra.c -c
	mv Dijkstra.o obj/

apagar:
	rm obj/* bin/Programa