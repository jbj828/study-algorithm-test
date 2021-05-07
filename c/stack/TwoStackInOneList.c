#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

typedef struct stack {
  int top1;
  int top2;
  int data[MAX_SIZE];
} Stack;

void StackInitialize(Stack *stk) {
  stk->top1 = -1;
  stk->top2 = MAX_SIZE;
}

void StackPush1(Stack *stk, int value) {
  if (stk->top1 < stk->top2 - 1) {
    stk->data[++stk->top1] = value;
  } else {
    printf("Stack is full\n");
  }
}

void StackPush2(Stack *stk, int value) {
  if (stk->top1 < stk->top2 - 1) {
    stk->data[--stk->top2] = value;
  } else {
    printf("Stack is full\n");
  }
}
