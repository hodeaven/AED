#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "lista.h"


int main(int argc, char* argv[]) 
{
    int n, i;
    int quantidade;
    lista lista;
    inicializar(&lista);
    
    FILE * arquivo = fopen("/home/hodeaven/AED/MetodosOrdenacao/ok/listas/1.000.000.txt","r");
    
    fscanf(arquivo,"%d", &quantidade);
    
    for(i = 0; i < quantidade; i++)
    {
    	fscanf(arquivo,"%d", &n);
    	inserir(&lista, n);
    }
    
    fclose(arquivo);
    merge_sort(&lista, 0, lista.marcador);
           
}
