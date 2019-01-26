/*
Semen Kiselev @All rights reserved
Used sources: 
https://gist.github.com/RenatoUtsch/4162787
*/

#include <stdlib.h>
#include <stdio.h>

#if !defined(__bool_true_false_are_defined) && !defined(__cplusplus)
typedef int bool;
#define true 1
#define false 0
#define __bool_true_false_are_defined
#endif

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct Stack{
    Node *head;
    int size;
} Stack;

Stack *create(){
    Stack *stack = (Stack *) malloc(sizeof *stack);
    if(stack == NULL)
        return NULL;
    
    stack->size = 0;
    stack->head = NULL;
    
    return stack;
}

bool empty(Stack *stack){
    return stack->head == NULL ? true : false;
}

int stack_size(Stack *stack){
    return stack->size;
}

int top(Stack *stack){
    return stack->head->value;
}

bool push(Stack *stack, int value){
    Node *newNode = (Node *) malloc(sizeof *newNode);
    if(newNode == NULL)
        return false;
    
    newNode->value = value;
    newNode->next = stack->head;
    stack->head = newNode;
    
    stack->size += 1;
    return true;
}

int pop(Stack *stack){
    Node *prevHead;
    int value;
    
    if(stack->head == NULL)
        printf("%s\n", "Error");
        return 0;
    
    prevHead = stack->head;
    value = prevHead->value;
    stack->head = prevHead->next;
    free(prevHead);
    prevHead = NULL;
    
    stack->size -= 1;
    return value;
}

void display(Stack *stack){
    Node *node = stack->head;
    while(node != NULL){
        printf("%d\n", node->value);
        node = node->next;
    }
}

int main(){
	int action = 0, check = 1;
    int value = 0;


    Stack *stack = create();
    push(stack, 1111232323);
    push(stack, 1111232323);
    push(stack, 1111232323);
    int a = top(stack);
    printf("%d\n", a);
    display(stack);






	while (check) {
        printf("Menu: \n");
        printf("1) Peek: \n");
        printf("2) Push: \n");
        printf("3) Pop: \n");
        printf("4) Is empty?: \n");
        printf("5) Display: \n");
        printf("6) Create: \n");
        printf("7) Stack size: \n");
        printf("8) Exit: \n");

        printf("Enter your action: \n");
        scanf("%d", &action);
        switch (action) {
            case 1:
                printf("1\n");
                break;
            case 2:
                printf("2\n");
                break;
            case 3:
                printf("3\n");
                break;
            case 4:
                printf("4\n");
                break;
            case 5:
                printf("5\n");
                break;
            case 6:
                printf("6\n");
                break;
            case 7:
                printf("7\n");
                break;
            case 8:
                printf("8\n");
                check = 0;
                break;
        }
    }
}