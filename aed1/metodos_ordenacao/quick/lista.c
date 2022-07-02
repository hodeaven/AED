#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//Terceiro Passo: Implementar o corpo das funções
void inicializar(lista *lista) 
{
    int capacidade = 1;
    lista->dados = (int *) malloc(sizeof(int) * capacidade);
    lista->marcador = 0;
    lista->capacidade = capacidade;
}

int inserir(lista *lista, int valor)
{
    //verificar se existe espaço na lista l
    if(lista->marcador >= lista->capacidade) 
    {
        int *dados_antigos;
        dados_antigos = lista->dados;

        lista->capacidade = 2 * lista->capacidade;
        lista->dados = (int *) malloc(sizeof(int) * lista->capacidade);
        //Custo computacional alto
        memmove(lista->dados, dados_antigos, sizeof(int)* lista->capacidade / 2);

        free(dados_antigos);
        //
    } 
    
    lista->dados[lista->marcador] = valor;
    lista->marcador ++;
    return 1;
    
}

void exibir(lista *lista)
{
   int i;
   system("clear");
   printf("------- LISTA ------- \n");
   for(i=0; i<lista->marcador; i++) 
   {
        printf("[%d]", lista->dados[i]);
    }
    printf("\n");
}



void trocar(lista *lista, int i, int j)
{
    int temp;
    temp = lista->dados[i];
    lista->dados[i] = lista->dados[j];
    lista->dados[j] = temp;
}

int particao(lista * lista, int inicio, int fim) {
    int pivo = lista->dados[fim];
    int i = (inicio - 1);
    int j;

    for (j=inicio; j < fim; j++) {
        if (lista->dados[j] < pivo) {
            i++;
            trocar(lista, i, j);
        }
    }
    trocar(lista, (i+1), fim);
    return (i+1);
}

void quickSort(lista * lista, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particao(lista, inicio, fim);

        quickSort(lista, inicio, pivo-1);
        quickSort(lista, pivo+1, fim);
    }
}

     

