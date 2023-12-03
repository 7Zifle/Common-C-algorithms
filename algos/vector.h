#ifndef __ALGOS_VECTOR_H__
#define __ALGOS_VECTOR_H__
struct vector {
	int *data;
	int lenth;
	int capacity;
};

struct vector *create_vector(int init_size);
void vector_push(struct vector *v, int value);
void vector_destroy(struct vector *v);
#endif // !__ALGOS_VECTOR_H__
