#include <stdio.h>
#include <stdlib.h>
#include "structure/list.h"

/*
*   (Exercício 2.2) Implemente um algoritmo para encontrar o n últimos elemento de uma lista encadeada.
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    
*/

void printNElements(LIST *list, int n) {
    int sizeList = size(list);

    if (sizeList < n) {
        printf("\n\nPosição inexistente na lista.\n\n");
    } else {
        printf("\n\nImprimindo os ultimos %i elementos da lista:", n);

        NODE *node = list->first;
        int aux = 0;

        while (node != NULL) {
            if (aux > (sizeList - n) - 1) {
                printNode(node);               
            }
            node = node->next;
            aux++;
        }
    }
    return;
}

int main() {
    NODE *no;
    LIST minhaLista;
    
    initList(&minhaLista);
    printf("Fila criada");

    insert(&minhaLista, 17);
    printList(&minhaLista);

    insert(&minhaLista, 21);
    printList(&minhaLista);

    insert(&minhaLista, 19);
    printList(&minhaLista);

    insert(&minhaLista, 11);
    printList(&minhaLista);

    insert(&minhaLista, 17);
    printList(&minhaLista);

    insert(&minhaLista, 11);
    printList(&minhaLista);

    insert(&minhaLista, 11);
    printList(&minhaLista);

    insert(&minhaLista, 17);
    printList(&minhaLista);
    
    no = searchList(&minhaLista, 21);
    printf("\n\n*Node 21:");
    printNode(no);
    no = searchList(&minhaLista, 19);
    printf("\n*Node 19:");
    printNode(no);

    delete(&minhaLista, no);
    printList(&minhaLista);

    printNElements(&minhaLista, 2);

    return 0;
}