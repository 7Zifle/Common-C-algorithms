#include "vector.h"
#include <stdlib.h>

struct vector *create_vector(int init_size)
{
	struct vector *vector = malloc(sizeof(struct vector));

	vector->data = malloc(sizeof(int) * init_size);
	vector->capacity = init_size;
	vector->lenth = 0;

	return vector;
}

void vector_push(struct vector *v, int value)
{
	if (v->lenth == v->capacity) {
		v->data = realloc(v->data, v->capacity * 2);
		v->capacity *= 2;
	}

	v->data[v->lenth++] = value;
}

void vector_destroy(struct vector *v)
{
	free(v->data);
	free(v);
}
