# A Busca por Caminhos Mágicos

No reino de Xulambis, entre Mysthollow e Luminae, existem caminhos mágicos. A nossa missão é encontrar os k caminhos mais curtos de Mysthollow para Luminae, enfrentando perigos e desvendando segredos. 

---

## Input
1. A primeira linha de entrada contém três inteiros **N**, **M** e **K**: o número de cidades, o número de voos e o parâmetro **K**. As cidades são numeradas de 1 a **N**, onde 1 é Mysthollow e N é Luminae.

2. A segunda entrada possui **M** linhas descrevendo os voos. Cada linha contém três inteiros **A**,
**B** e **C**: um voo começa na cidade **A**, termina na cidade **B**, e seu preço é **C**. Todos os voos são voos de apenas uma direção.

## Output
Na saída deve ser imprimido **K** inteiros: os preços das **K** rotas mais baratas, ordenadas de acordo com seus preços.

---

## Sistema de Pastas
O nosso trabaho foi organizado no seguinte sistema de arquivos:

+ **src/**: pasta contendo todos os "**.c**".
+ **include/**: pasta contendo todos os "**.h**".
+ **obj/**: pasta contendo todos os "**.o**".
+ **bin/**: pasta onde o executável ficará.
+ **data/**: pasta contendo 2 exemplos de entrada, um passado no trabalho e outro com os valores máximos, e um arquivo de saída.
+ **doc/**: pasta onde está a documentação do trabalho.

---

## Compilação e Execução

Além de tudo isso, o arquivo também contém um **Makefile** para o programa ser compilado pelo usuário. Para executá-lo, você deve escrever em seu terminal o seguinte comando na pasta principal do projeto:

``` sh
Usuario@Usuario-PC: ~/Downloads/PAA_TP1/$ make 
```

Depois disso, os arquivos serão gerados e enviadas para as pastas antes descritas. Para executar o programa, você deve acessar a pasta **bin/** e executar o seguinte comando:

``` sh
Usuario@Usuario-PC: ~/Downloads/PAA_TP1/bin/$ ./Programa -i data/Input_1.txt -o data/Ouput.txt
```

Onde o arquivo após **-i** é o *arquivo de entrada* e o arquivo após o **-o** é o *arquivo de saída*. Sem especificar os caminhos, o programa não executará!

---

**Integrantes do trabalho:**
+ Nome - Github
+ Braian Melo - *BraianMelo*
+ Gustavo Campos - *GustavoH-C*