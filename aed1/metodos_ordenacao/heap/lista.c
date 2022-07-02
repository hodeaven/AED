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


int procurar(lista *lista, int valor) 
{
    int i;
    int posicao = -1;    
    for(i=0; i<lista->marcador; i++) 
    {
        if(lista->dados[i] == valor) 
        {
            //return i;
            posicao = i;
            break;
        } 
    }
    //if(i == lista->marcador)
    return posicao;
}


void swap(int *a, int *b)
   {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
void heapify(lista * lista, int n, int i) {
    
    int pai = i;
    int esquerdo= 2 * i + 1;
    int direito = 2 * i + 2;
  
    if (esquerdo < n && lista -> dados [esquerdo] > lista -> dados[pai])
      pai = esquerdo;
  
    if (direito < n && lista -> dados[direito] > lista -> dados[pai])
      pai = direito;
  
    
    if (pai != i) {
      swap(&lista -> dados[i], &lista -> dados[pai]);
      heapify(lista, n, pai);
    }
  }

void heapSort(lista *lista, int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(lista, n, i);

    for (int i = n - 1; i >= 0; i--) {
      swap(&lista -> dados[0], &lista -> dados[i]);
  
     
      heapify(lista, i, 0);
    }
  }
  
 

