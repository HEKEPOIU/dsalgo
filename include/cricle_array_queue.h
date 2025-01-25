#ifndef DSAL_CRICLE_ARRAY_QUEUE
#define DSAL_CRICLE_ARRAY_QUEUE

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int *data;
  size_t front;
  size_t que_capaciay;
  size_t que_size;

} CA_Queue;

CA_Queue *new_ca_queue(size_t cap);
void del_ca_queue(CA_Queue **q);
_Bool is_caq_empty(const CA_Queue *const q);
int caq_peek(const CA_Queue *const q);
void caq_push(CA_Queue *const q, int value);
int caq_pop(CA_Queue *const q);

CA_Queue *new_ca_queue(size_t cap) {
  CA_Queue *q = malloc(sizeof(CA_Queue));
  q->data = malloc(sizeof(int) * cap);
  q->front = 0;
  q->que_capaciay = cap;
  q->que_size = 0;
  return q;
}

void del_ca_queue(CA_Queue **q) {
  free((*q)->data);
  free(*q);
  *q = NULL;
}

_Bool is_caq_empty(const CA_Queue *const q) { return q->que_size == 0; }

int caq_peek(const CA_Queue *const q) {
  assert(q->que_size > 0);
  return q->data[q->front];
}

void caq_push(CA_Queue *const q, int value) {
  if (q->que_size == q->que_capaciay) {
    printf("queue full");
    return;
  }
  size_t rear = (q->front + q->que_size) % q->que_capaciay;
  q->data[rear] = value;
  q->que_size++;
}

int caq_pop(CA_Queue *const q) {
  int h = caq_peek(q);
  q->front = (q->front + 1) % q->que_capaciay;
  q->que_size--;

  return h;
}

#endif // !DSAL_CRICLE_ARRAY_QUEUE
