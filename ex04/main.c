#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	struct s_queue *queue = queueInit();
	printf("isEmpty: %d\n", isEmpty(queue));
	printf("dequeue: %s\n", dequeue(queue));
	enqueue(queue, "hi");
	printf("peek: %s\n", peek(queue));
	enqueue(queue, "one");
	printf("peek: %s\n", peek(queue));
	enqueue(queue, "2");
	printf("peek: %s\n", peek(queue));
	enqueue(queue, "333333333333333");
	printf("peek: %s\n", peek(queue));
	printf("isEmpty: %d\n", isEmpty(queue));	
	enqueue(queue, "");
	printf("peek: %s\n", peek(queue));	
	enqueue(queue, NULL);
	printf("peek: %s\n", peek(queue));		
	while (!isEmpty(queue))
		printf("dequeue: %s\n", dequeue(queue));
	printf("isEmpty: %d\n", isEmpty(queue));
	return (0);
}



// Function used for the test
// Don't go further :)

