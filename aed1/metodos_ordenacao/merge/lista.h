#ifndef LISTA_H
#define LISTA_H


//Definição da lista sequencial (array) de livros 
typedef struct lista_numeros {
    int *dados;
    int marcador;  
    int capacidade;  
} lista;

//Segundo passo: Definição da assinatura das funções
void inicializar(lista *lista);
int inserir(lista *lista, int valor);
int procurar(lista *lista, int valor);
void exibir(lista *lista);
void merge_sort(lista * lista, int inicio, int fim);
void merge(lista * lista, int inicio, int meio, int fim);
void trocar(lista *lista, int i, int j);
int procurarPosicaoMenorAPartirDe(lista *lista, int i);
#endif
