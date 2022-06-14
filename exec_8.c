#include <stdio.h>
#include <stdlib.h>
#include "structure/tree.h"

/*
*   (Exercício 4.4) Implemente uma função para verificar se uma árvore binária está balanceada. Para os propósitos desta questão, 
*   uma árvore balanceada é definida como uma árvore tal que as alturas das duas subárvores de qualquer nó nunca diferem em mais de um.
*
*    O exercício proposto no Livro: Cracking Coding Interview 6th Edition 
* 
*    gcc exec_8.c structure\tree.c -o exec_8.exe -ansi -Wall -pedantic -std=c99
*/

int isBalanced(TREE *root) {
    if (root == NULL) {
        return 1;
    }

    int difHeight = height(root->left) - height(root->right);
    if (abs(difHeight) > 1) {
        return 0;
    } else {
        return (isBalanced(root->left) && isBalanced(root->right));
    }
}

int main()
{
    TREE *root = NULL;
    int h, countNodes, maxNode;
    root = insertTree(root, 14);   
    insertTree(root, 15);
    insertTree(root, 3);
    insertTree(root, 6);
    insertTree(root, 18);

    h = height(root);
    countNodes = count(root);
    maxNode = countMax(root);

    printf("The Binary Tree is %i tall and has %i nodes (%i at most).\n\n", h, countNodes, maxNode);
    printTree(root, 0);
    printf("\n\n\n");

    if (isBalanced(root) == 1) {
        printf("\n\nArvore balanceada");
    } else {
        printf("\n\nArvore desbalanceada");
    }
    
    return 0;
}