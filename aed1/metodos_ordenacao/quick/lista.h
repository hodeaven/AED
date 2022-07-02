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
void trocar(lista *lista, int i, int j);
void quickSort(lista * lista, int inicio, int fim);
#endif
