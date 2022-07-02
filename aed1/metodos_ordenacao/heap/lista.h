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
void swap(int *a, int *b);
void heapSort(lista *lista, int n);
void heapify(lista * lista, int n, int i);
#endif
