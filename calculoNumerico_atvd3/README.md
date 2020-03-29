Esse projeto tem por objetivo dar a resolução de sistemas lineares passados através de arquivos no formato de matriz aumentada. 
Os sistemas resolvidos devem ser determinados, ou seja, matrizes **nx(n+1)**, em que a ultima coluna possui as constantes do sistema. Arquivos exemplo de matrizes estão disponibilizados na pasta **data**.


**Compilando**

O binário executável pode ser gerado da seguinte forma, pelo terminal:

g++ --std=c++11 src/driver_SistemaLinear.cpp src/SistemaLinear.cpp -I include/ -o bin/output

Ao executar o binário, passar o caminho das matrizes. 
Exemplo:

./bin/output ./data/m1.in ./data/m2.in [...]
