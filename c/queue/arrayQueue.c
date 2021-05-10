#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 30

typedef struct Queue_t {
  int front;
  int back;
  int size;
  int data[MAX_CAPACITY];
} Queue;

void QueueIntialize(Queue *que) {
  que->back = 0;
  que->front = 0;
  que->size = 0;
}

void QueueAdd(Queue *que, int value) {
  if (que->size >= MAX_CAPACITY) {
    printf("\n큐가 꽉 찼습니다");
    return;
  } else {
    que->size++;
    que->data[que->back] = value;
    que->back = (que->back + 1) % (MAX_CAPACITY - 1);
  }
}

int QueueRemove(Queue *que) {
  int value;
  if (que->size <= 0) {
    printf("\n큐가 비어있습니다.");
    return -1;
  } else {
    que->size--;
    value = que->data[que->front];
    que->front = (que->front + 1) % (MAX_CAPACITY - 1);
  }
  return value;
}

int QueueSize(Queue *que) { return que->size; }

int QueueFront(Queue *que) { return que->data[que->front]; }

int QueueFront(Queue *que) { return que->data[que->back - 1]; }

int QueueIsEmpty(Queue *que) { return que->size == 0; }

int QueueRemoveBack(Queue *que) {
  int value;
  if (que->size <= 0) {
    printf("\n큐가 비어있습니다.");
    return -1;
  } else {
    que->size--;
    value = que->data[que->back - 1];
    que->back = (que->back - 1) % (MAX_CAPACITY - 1);
  }
  return value;
}

int main() {
  Queue *que;
  QueueIntialize(que);
  QueueAdd(que, 1);
  QueueAdd(que, 2);
  QueueAdd(que, 3);
  QueueAdd(que, 4);

  QueueRemove(que);
}