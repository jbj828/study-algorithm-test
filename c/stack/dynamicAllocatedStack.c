#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int *data;
  int capacity;
  int min;
} Stack;

void StackInitialize(Stack *stk, int size) {
  stk->data = (int *)malloc(sizeof(int) * size);
  stk->top = -1;
  stk->capacity = size;
  stk->min = size;
}

void StackPush(Stack *stk, int value) {
  if (stk->top < stk->capacity - 1) {
    stk->top++;
    stk->data[stk->top] = value;
    printf("value push : %d\n", value);
  } else {
    stk->capacity = stk->capacity * 2;
    stk->data = (int *)realloc(stk->data, stk->capacity * sizeof(int));
    printf("스택 크기가 두 배가 되었습니다\n");
    printf("스택 용량 %d\n", stk->capacity);
    StackPush(stk, value);
  }
}

int StackPop(Stack *stk) {
  if (stk->top >= 0) {
    int value = stk->data[stk->top];
    stk->top--;

    if (stk->top < (stk->capacity / 2) && stk->capacity > stk->min) {
      stk->capacity = stk->capacity / 2;
      stk->data = (int *)realloc(stk->data, stk->capacity * sizeof(int));
      printf("스택 크기가 반으로 줄었습니다\n");
    }
    return value;
  }
  printf("스택이 비었습니다\n");
}