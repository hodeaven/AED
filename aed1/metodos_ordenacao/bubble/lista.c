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

void trocar(lista *lista, int i, int j)
{
    int temp;
    temp = lista->dados[i];
    lista->dados[i] = lista->dados[j];
    lista->dados[j] = temp;
}

void bubbleSort(lista *lista) 
{
    int i, j;
    for(j=0; j < lista->marcador - 1; j++) 
    {
        for(i = lista->marcador-1; i > j; i--) 
        {
            if(lista->dados[i] < lista->dados[i-1] ) 
            {
                trocar(lista, i, i-1);
            }
        }
    }
}


