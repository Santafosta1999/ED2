#include <stdio.h>
#include <stdlib.h>
#include "structure/tree.h"

#define MAXTAM 11

/*
*   (Exercício 4.2) Dado um array ordenado (ordem crescente) com elementos inteiros únicos, escreva um algoritmo para criar uma árvore de busca binária com altura mínima.
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_7.c structure\tree.c -o exec_7.exe -ansi -Wall -pedantic -std=c99
*/

TREE *createMinimal(int array[], int start, int end) {
    TREE *new = NULL;

    if (end < start) {
        return NULL;
    }

    int aux = (start + end) / 2;
    new = insertTree(new, array[aux]);
    new->left = createMinimal(array, start, aux - 1);
    new->right = createMinimal(array, aux + 1, end);

    return new;
}

TREE *createMinimalTree(int array[]) {
    int i, j, min, aux;
    for (i = 0; i < (MAXTAM - 1); i++)
    {
        min = i;
        for (j = i + 1; j < MAXTAM; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }

    return createMinimal(array, 0, MAXTAM - 1);
}

int main()
{
    int arr[MAXTAM] = {4, 14, 15, 53, 9, 18, 7, 16, 5, 17, 20};


    printf("\n\nArvore Binaria de busca derivada do array:\n");
    printf("{4, 14, 15, 53, 9, 18, 7, 16, 5, 17, 20}\n\n");
    
    printTree(createMinimalTree(arr), 0);

    return 0;
}