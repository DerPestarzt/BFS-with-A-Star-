#include "fila.h"

#define modulo(X)(X >= 0 ? X : -(X))

void FFVazia(tFila *f)
{
	f->first = (tBlock *)malloc(sizeof(tBlock));
	f->last = f->first;
	f->first->prox = NULL;
}

void Enfileira(tFila *f, tItem pos)
{
	f->last->prox = (tBlock *)malloc(sizeof(tBlock));
	f->last = f->last->prox;
	f->last->pos = pos;
	f->last->prox = NULL;
}

void Desenfileira(tFila *f, tItem *pos)
{
	tBlock *aux;

	if (f->first == f->last || f == NULL || f->first->prox == NULL)
	{
		printf("FILA VAZIA!\n");
		return;
	}

	aux = f->first->prox;
	f->first->prox = aux->prox;
	pos->x = aux->pos.x;
	pos->y = aux->pos.y;
	free(aux);
}

void FImprime(tFila *f)
{
	tBlock *aux;

	aux = f->first->prox;
	while (aux != NULL)
	{
		printf("%d %d\n", aux->pos.x, aux->pos.y);
		aux = aux->prox;
	}
}

void ImprimirMatriz(int tam, int **matriz)
{
	
	for (int i = 0; i < tam; i++)
	{
		printf("\n");
		for (int j = 0; j < tam; j++)
		{
			if (matriz[i][j] == -1) {
				printf("#\t");
			} else {
				printf("%d\t", matriz[i][j]);
			}
		}
	}
	printf("\n\n");
}

void BFS(int **matriz, int tam)
{
	if(matriz[0][0] != 0 || matriz[tam-1][tam-1] !=0){
		printf("\nA primeira ou ultima posicao e uma parede\n");
		return;
	}
	int countP = 1;
	matriz[0][0] = countP++;

	tItem aux;
	tFila f;
	FFVazia(&f);

	int i, j, aux_i, aux_j, count, count_caminho;
	int val;
	double val2;
	
	aux.x = i;
	aux.y = j;

	i = j = aux_i = aux_j = count = count_caminho = 0;

	// printf("%d\n", potencia(2, 5));

	// return;
	
	while (i < tam && j < tam) {
		count_caminho++;
		
		if(i == 0) {
			if(matriz[i + 1][j] == 0) {
				matriz[i + 1][j] = countP++;

				aux.x = i + 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(j < tam - 1 && matriz[i][j + 1] == 0) {
				matriz[i][j + 1] = countP++;

				aux.x = i;
				aux.y = j + 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(j > 0 && matriz[i][j - 1] == 0) {
				matriz[i][j - 1] = countP++;

				aux.x = i;
				aux.y = j - 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
		}
		else if(j == 0) {
			if(i < tam - 1 && matriz[i + 1][j] == 0) {
				matriz[i + 1][j] = countP++;

				aux.x = i + 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i][j + 1] == 0) {
				matriz[i][j + 1] = countP++;

				aux.x = i;
				aux.y = j + 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i - 1][j] == 0) {
				matriz[i - 1][j] = countP++;

				aux.x = i - 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
		}
		else if(j == tam - 1) {
			if(i < tam - 1 && matriz[i + 1][j] == 0) {
				matriz[i + 1][j] = countP++;

				aux.x = i + 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i - 1][j] == 0) {
				matriz[i - 1][j] = countP++;

				aux.x = i - 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i][j - 1] == 0) {
				matriz[i][j - 1] = countP++;

				aux.x = i;
				aux.y = j - 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
		}
		else if(i == tam - 1) {
			if(matriz[i][j + 1] == 0) {
				matriz[i][j + 1] = countP++;

				aux.x = i;
				aux.y = j + 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i - 1][j] == 0) {
				matriz[i - 1][j] = countP++;

				aux.x = i - 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i][j - 1] == 0) {
				matriz[i][j - 1] = countP++;

				aux.x = i;
				aux.y = j - 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
		}
		else {
			if(matriz[i + 1][j] == 0) {
				matriz[i + 1][j] = countP++;

				aux.x = i + 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i][j + 1] == 0) {
				matriz[i][j + 1] = countP++;

				aux.x = i;
				aux.y = j + 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i - 1][j] == 0) {
				matriz[i - 1][j] = countP++;

				aux.x = i - 1;
				aux.y = j;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
			if(matriz[i][j - 1] == 0) {
				matriz[i][j - 1] = countP++;

				aux.x = i;
				aux.y = j - 1;
				Enfileira(&f, aux);

				val = manhattan(aux.x, tam - 1, aux.y, tam - 1);
				val2 = euclidiana(aux.x, tam - 1, aux.y, tam - 1);

				printf("[%d:%d] - (%2d : %lf)\n", aux.x, aux.y, val, val2);
			}
		}
		Desenfileira(&f, &aux);

		// printf("final: [%d:%d] - [%d:%d]\n", i, j, aux.x, aux.y);
		i = aux.x;
		j = aux.y;

		if(i == tam - 1 && j == tam - 1) break;
	}
	printf("\n BFS %d interacoes!\n", count_caminho);
}

int manhattan(int x1, int x2, int y1, int y2) {
	return modulo((x1 - x2)) + modulo(y1 - y2);
}

double euclidiana(int x1, int x2, int y1, int y2) {
	double a = potencia(x1 - x2, 2);
	double b = potencia(y1 - y2, 2);
	return raiz(a + b);
}

double raiz(double val) {
	double precisao = 0.000001;
	double res = 1;
	double b = val, a = 1;

	while((b - a) >= precisao) {
		b = (a + b) / 2;
		a = val / b;
	}
	return b;
}

double potencia(double val, double exp) {
	double res = 1;

	while(exp > 0) {
		res = res * val;
		exp--;
	}
	return res;
}
