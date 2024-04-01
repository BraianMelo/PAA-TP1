all: obj/Programa.o obj/Lista_Cidades.o obj/Cidade.o obj/Dijkstra.o obj/Lista_Caminhos.o obj/Caminho.o
	gcc obj/Programa.o obj/Lista_Cidades.o obj/Cidade.o obj/Dijkstra.o obj/Lista_Caminhos.o obj/Caminho.o -o Programa
	mv Programa bin/

obj/Programa.o: src/Programa.c
	gcc src/Programa.c -c
	mv Programa.o obj/

obj/Lista_Cidades.o: src/Lista_Cidades.c include/Lista_Cidades.h
	gcc src/Lista_Cidades.c -c
	mv Lista_Cidades.o obj/

obj/Cidade.o:  src/Cidade.c include/Cidade.h
	gcc src/Cidade.c -c
	mv Cidade.o obj/

obj/Dijkstra.o: src/Dijkstra.c include/Dijkstra.h
	gcc src/Dijkstra.c -c 
	mv Dijkstra.o obj/

obj/Lista_Caminhos.o: src/Lista_Caminhos.c include/Lista_Caminhos.h
	gcc src/Lista_Caminhos.c -c
	mv Lista_Caminhos.o obj/

obj/Caminho.o: src/Caminho.c include/Caminho.h
	gcc src/Caminho.c -c
	mv Caminho.o obj/

apagar:
	rm obj/* bin/Programa