# Exercício de Tipo Abstrato de Dados Labirinto - BFS e DFS (Implementação do algoritmo A*)

![Linguagem C](https://img.shields.io/badge/Linguagem-C-green.svg)




<h1>Problema </h1>
<b> Deverá ser entregue um trabalho contemplando as modificações necessárias do <code>BFS </code> para torna-lo um algoritmo heurístico, chamado <code>A* </code>. </b>
<br></br>
* Entregar a codificação devidamente elaborada sob o modelo de execução estabelecido, bem como, a comparação do algoritmo <code> A* </code> para as heurísticas euclidiâna e manhattan
<br></br>
* Um relatório contemplando uma discussão comparativa entre <code> BFS, DFS e A* </code>. Espera-se que este documento apresente fatores comparativos de velocidade de execução e quantidade de passos para a finalização do labirinto. Além disso, espera-se que cada dupla aprofunde em uma apresentação adequada do modelo de funcionamento de cada um e os motivos que tornam uma das soluções a melhor opção.
<br></br>



<h1> BFS e DFS</h1>

A busca em profundidade é um algoritomo utilizado para percorrer ou buscar itens dentro das estrutura de dados. Suas características básicas é percorrer o mais profundo possível para somente depois retroceder. Existem várias formas de implementar uma busca em profundidade. Pela natureza, uma solução natural é utilizar recursão ou um algoritmo interativo e utilizar uma pilha.
<br></br>
A busca em largura pode ser implementada de várias formas. As mais utilizadas são atráves de recursão, que utiliza uma fila ou seja, o último a entrar é o primeiro a sair.
<br></br>
<h2>BUSCA HEURÍSTICA </h2>
A busca heurística é uma
estratégia que utiliza o conhecimento específico do problema, podendo encontrar
soluções de forma mais eficiente que uma estratégia sem informação. A heurística é uma técnica eficiente em um
processo de busca. A heurística é útil, pois leva a direcionamentos interessantes,
mesmo que possa ignorar pontos de interesse para alguém. Em geral, as heurísticas
melhoram os caminhos a serem percorridos, porém pode ocorrer de ignorar o melhor
caminho. Pode-se obter boas soluções usando uma boa heurística em problemas
difíceis.
Dentre os métodos existentes são apresentados: o algoritmo A*, o algoritmo A*
adaptado e o busca em profundidade adaptado. 
<br></br>

<h2> O algoritmo A*</h2>
O algoritmo A* deve encontrar um caminho
entre dois vértices. Existem muitos algoritmos de busca, mas o A*
encontra o menor caminho, se existir, e fará isto relativamente rápido – é isto que o
diferencia dos outros.
O algoritmo A* atravessa o grafo marcando vértices que correspondem às
várias posições exploradas. Esses vértices gravam o progresso da busca. 



A <b>heurísticas</b> desse algoritmo baseia-se na tática utilizada para tomar determinadas decisões em sua execução, o algoritmo apresentado utiliza dois tipos de *heurísticas*, sendo elas a distância Euclidiana e a distância de Manhattan.

A <b><u>distância Euclidiana</u></b> consiste na utilização do <b>Teorema de Pitágoras</b> para descobrir a distância em linha reta do determinado ponto (posição atual) até o ponto final e utilizado pela seguinte fórmula:

$Distância = \sqrt{|x_1 - x_2|^2 + |y_1 - y_2|^2} $  </u>

A <b><u>distância de Manhattan</u></b> consiste no cálculo do valor da soma de quantos blocos faltam, na vertical e na horizontal, para chegar ao objetivo, sendo a distância de cada bloco dada pela fórmula: 

$Distância = |x_1 - x_2| + |y_1 - y_2|$ </u>
<br></br>
<h2> A* x BFS</h2>
O algoritmo A* é mais eficiente que o BFS. Ao usar uma função heurística para fornecer uma estimativa do custo do caminho entre cada nó e o nó de destino, ele pode fazer melhores escolhas sobre o próximo caminho a seguir e encontrar o caminho mais curto.
<br></br>

<h1> Resultados</h1>

-> É pedido ao usuário selecionar uma das opções entre os algoritmos manhattan e euclidiâna)
<br></br>
<br></br>
-> Através do arquivo matriz.txt fazemos a leitura por meio do fopen() e tokenizar para salvar as posições dos obstáculos e do tipo de busca.
<br></br>
<br></br>
-> Por fim é apresentado ao usuário a matriz contendo o caminho percorrido e número de interações.
<br></br>





# Compilação e Execução


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
|  `make r`            | Compila e Executa o programa da pasta build após a realização da compilação                                 |
Autores: [Gabriel Marcondes](https://github.com/DerPestarzt) e [Ygor Vieira](https://github.com/eplaie).
