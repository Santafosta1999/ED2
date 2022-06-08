#include <stdio.h>
#include <stdlib.h>
#include "structure/list.h"

/*
*   (Exercício 2.1) Escreva código para remover duplicatas de uma lista encadeada não ordenada.
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_1.c structure\list.c -o ex_1.exe -ansi -Wall -pedantic -std=c99 
*/

int removeRepeated(LIST *list) {
    NODE *node, *nodeInitial = NULL;
    if (isEmpty(list) == 1)
        return 0;

    nodeInitial = list->first;
    while (nodeInitial != NULL) {
        node = nodeInitial->next;
        while (node != NULL) {
            if (nodeInitial->value == node->value) {
                delete(list, node);
            }
            node = node->next;
        }
        nodeInitial = nodeInitial->next;
    }
    return 1;
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

    removeRepeated(&minhaLista);
    printList(&minhaLista);
    
    no = searchList(&minhaLista, 21);
    printf("\n\n*Node 21:");
    printNode(no);
    no = searchList(&minhaLista, 19);
    printf("\n*Node 19:");
    printNode(no);

    delete(&minhaLista, no);
    printList(&minhaLista);

    return 0;
}