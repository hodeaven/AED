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

    } 
    
    lista->dados[lista->marcador] = valor;
    lista->marcador ++;
    return 1;
    
}


void insertionSort(lista *lista) 
{
    int n = lista->marcador;
    lista->marcador = 1;
    for(;lista -> marcador < n; ) //pecorrer a lista até o fim dela
    {
    	inserirOrdem(lista, lista -> dados[lista -> marcador]);
    }   
}

int inserirPosicao(lista * lista, int n, int posicao)
{
   int tam;
   
   tam = lista -> marcador;
   
   for(; tam > posicao;tam--)
   {
   	lista -> dados[tam] = lista -> dados[tam-1];
   }
   
   lista -> dados[posicao] = n;
   lista -> marcador ++;
   
}

void inserirOrdem (lista * lista, int n)
{
   int i;
   
   if( lista -> marcador == 0)
   {
     inserir(lista, n);   
   }
	if(lista -> dados[lista -> marcador - 1] < n)
	{
	    inserir(lista, n);
	}
        else 
        {
           for(i = 0; i < lista -> marcador; i++)
           {
   	      if(lista -> dados[i] > n)
   	      {
   	         inserirPosicao(lista, n, i);
   	         break;
   	      } 
           } 
        } 
}



