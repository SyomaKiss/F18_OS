/*
Semen Kiselev @All rights reserved
Used sources: 
https://gist.github.com/RenatoUtsch/4162787
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

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

int peek(Stack *stack){
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
	int n = 0;
	printf("Stack content is the following:\n");
	while(node != NULL){
		printf("%d) %d \n", n, node->value);
		n++;
		node = node->next;
	}
}
//_______________________________________


int main(){
	int action = 0, check = 1;
	int value = 0;

	pid_t pid;
	int fd[2], nbytes;
	pipe(fd);
	char *message = "Initial message";
	char got_message[80];

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, 35);
	sigprocmask(SIG_BLOCK, &set, NULL);
	int *signal_ptr = malloc(sizeof(int)), r_value;

	pid  = fork();
   	if (pid > 0){//parent
   		// printf("PArent %d, child %d\n", getpid(),pid);
   		while (check) {
   			printf("Menu: \n");
   			printf("1) Peek; ");
   			printf("2) Push; ");
   			printf("3) Pop; ");
   			printf("4) Is empty?; \n");
   			printf("5) Display; ");
   			printf("6) Create; ");
   			printf("7) Stack size; ");
   			printf("8) Exit;\n");
   			printf("Enter the number of your action: \n");

   			scanf("%d", &action);
   			switch (action) {
   				case 1:
   				printf("1\n");
   				message = "1 0";
   				break;
   				case 2:
   				printf("You've chosen to push the data onto the stack, pls enter the NUMERIC value\n");
   				scanf("%d", &value);
   				message = malloc(sizeof(int) * 4 + sizeof(char) + 1);
   				sprintf(message, "%d %d", 2, value);
   				break;
   				case 3:
   				printf("3\n");
   				message = "3 0";
   				break;
   				case 4:
   				printf("4\n");
   				message = "4 0";
   				break;
   				case 5:
   				printf("5\n");
   				message = "5 0";
   				break;
   				case 6:
   				printf("6\n");
   				message = "6 0";
   				break;
   				case 7:
   				printf("7\n");
   				message = "7 0";
   				break;
   				case 8:
   				printf("8\n");
   				
   				check = 0;
   				break;
   			}


   			// close(fd[0]);
   			write(fd[1], message, strlen(message)+1);
   			kill(pid, 35);
   			sleep(2);
   		}
   		
   	} else {//child
   		while(1){
   			r_value = sigwait(&set, signal_ptr);
   			
   			if(r_value == -1)
   				perror("sigwait failed\n");
   			else {
   				if(*signal_ptr == 35){
   					// printf("Child..SIGNAL from parent was received\n");
					Stack *stack;		
   					nbytes = read(fd[0], got_message, sizeof(got_message));
   					// printf("INFO||Error:: %d, %s| Bytes received:: %d\n", errno, strerror(errno), nbytes);
   					// printf("Here is the sent message: %s\n", got_message);
   					int x1, x2;
   					sscanf(got_message, "%d %d", &x1, &x2);	
   					// printf("VALUES||%d %d\n", x1,x2);
   					switch (x1) {
   						case 1:
   						printf("The upper element is: %d\n", peek(stack));
   						break;
   						case 2:
   						push(stack, x2);
   						break;
   						case 3:
   						printf("The deleted value is: %d\n", pop(stack));
   						break;
   						case 4:
   						printf("Stack is empty(1/0): %d\n", empty(stack));
   						break;
   						case 5:
   						display(stack);
   						break;
   						case 6:
   						stack = create();
   						break;
   						case 7:
   						printf("Stack size is: %d\n", stack_size(stack));
   						break;
   						default:
   						printf("Error\n");
   					}
   					fflush(stdout);	
   				}else printf("sigwait returned with sig: %d\n", *signal_ptr);
   			}
   		}
   	}
   }