#include <stdio.h>
#include <stdlib.h>
#include "structure/stack.h"

/*
*   (Exercício 3.5) Escreva um programa para ordenar uma pilha de forma que os menores itens fiquem no topo. Você pode usar uma pilha temporária adicional, 
*    mas não pode copiar os elementos em nenhuma outra estrutura de dados. A pilha suporta as seguintes operações: push, pop, peek e isEmpty.
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_5.c structure\stack.c -o exec_5.exe -ansi -Wall -pedantic -std=c99
*/

STACK *ascStack(STACK *list) {
    STACK temp;
    initStack(&temp);

    while(!isEmpty(list)) {
        char aux = pop(list);
        while(!isEmpty(&temp) && peek(&temp)->next->value > aux) {
            push(list, pop(&temp));
        }
        push(&temp, aux);
    }

    while (!isEmpty(&temp)) {
        push(list, pop(&temp));
    }
    
    return list;   
}

int main()
{
    STACK myStack;

    initStack(&myStack);

    push(&myStack, 'A');
    push(&myStack, 'C');
    push(&myStack, 'E');
    push(&myStack, 'G');
    push(&myStack, 'I');
    push(&myStack, 'K');
    push(&myStack, 'M');
    push(&myStack, 'O');
    push(&myStack, 'Q');
    push(&myStack, 'S');
    push(&myStack, 'U');
    push(&myStack, 'W');

    printStack(&myStack);

    printf("\n\n--------------------------------------------------\n\n");

    printStack(ascStack(&myStack));
    return 1;
}