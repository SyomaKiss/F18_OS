#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *next;
} Node;

Node *head = NULL;

void print_list(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%d\n", current->x);
        current = current->next;
    }
}

void insert_node(Node **head, int value, int position){
    Node *new = malloc(sizeof(Node));
    new->x = value;
    new->next = NULL;
    if (*head == NULL){
        *head = new;
        return;
    }
    if (position == 0){
        new->next = *head;
        *head = new;
        return;
    }
    Node *current = *head;
    for (int i = 0; i < position-1; ++i){
        if (current->next == NULL){
            printf("%s\n", "Index out of range");
            return;
        }
        current = current->next;
    }
    if (current-> next == NULL) {
        current->next = new;
    } else {
        new->next = current->next;
        current->next = new;
    }
}

int delete_node(Node **head, int position){
    if (*head == NULL){
        return -1;
    }
    if (position == 0){
        int value = (*head)->x;
        *head = (*head)->next;
        return value;
    }
    Node *current = *head;
    for (int i = 0; i < position-1; ++i){
        if (current->next == NULL){
            printf("%s\n", "Index out of range");
            return -1;
        }
        current = current->next;
    }
    if (current-> next == NULL) {
        printf("%s\n", "Index out of range");
        return -1;
    } else {
        current->next = current->next->next;
    }
}



int main(){
    insert_node(&head, 0, 0);
    insert_node(&head, 1, 1);
    insert_node(&head, 2, 2);
    insert_node(&head, 3, 3);
    insert_node(&head, 4, 4);
    print_list(head);
    printf("\n");

    delete_node(&head, 3);
    print_list(head);


}