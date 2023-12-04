#ifndef __ALGOS_QUEUE_H__
#define __ALGOS_QUEUE_H__
struct queue_node {
	int value;
	struct queue_node *next;
};

struct queue {
	struct queue_node *front;
	struct queue_node *rear;
};

struct queue *queue_create();
int queue_pop(struct queue *queue);
void queue_push(struct queue *queue, int value);
void queue_destroy(struct queue *queue);
void queue_print(struct queue *queue);
void queue_node_destroy_followers(struct queue_node *node);
#endif // !__ALGOS_QUEUE_H__
