#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct queue *queue_create()
{
	struct queue *queue = malloc(sizeof(struct queue));

	queue->front = queue->rear = NULL;

	return queue;
}

int queue_pop(struct queue *queue)
{
	struct queue_node *popped_node = queue->front;
	int return_value = popped_node->value;
	queue->front = queue->front->next;
	free(popped_node);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	return return_value;
}

void queue_push(struct queue *queue, int value)
{
	struct queue_node *node = malloc(sizeof(struct queue_node));
	node->value = value;
	node->next = NULL;

	if (queue->front == NULL) {
		queue->front = queue->rear = node;
	} else {
		queue->rear->next = node;
		queue->rear = node;
	}
}

void queue_destroy(struct queue *queue)
{
	queue_node_destroy_followers(queue->front);
	free(queue);
}

void queue_print(struct queue *queue)
{
	printf("queue = [");
	struct queue_node *head = queue->front;
	while (head) {
		printf("%d, ", head->value);
		head = head->next;
	}
	printf("]\n");
}

void queue_node_destroy_followers(struct queue_node *node)
{
	if (node != NULL) {
		queue_node_destroy_followers(node->next);
		free(node);
	}
}
