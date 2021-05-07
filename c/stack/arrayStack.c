#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 30

typedef struct stack {
  int top;
  int data[MAX_CAPACITY];
} Stack;

void StackInitialize(Stack *stk) { stk->top = -1; }

int StackIsEmpty(Stack *stk) { return (stk->top == -1); }

int StackSize(Stack *stk) { return stk->top + 1; }

void StackPrint(Stack *stk) {
  printf("Stack :: ");
  for (int i = stk->top; i >= 0; i--) {
    printf("%d ", stk->data[i]);
  }
  printf("\n");
}

void StackPush(Stack *stk, int value) {
  if (stk->top < MAX_CAPACITY - 1) {
    stk->top++;
    stk->data[stk->top] = value;
  } else {
    printf("stack overflow\n");
  }
}

int StackPop(Stack *stk) {
  if (stk->top == -1) {
    printf("Stack is empty\n");
    return -1;
  }

  int value = stk->data[stk->top];
  stk->top--;
  return value;
}

int StackTop(Stack *stk) {
  int value = stk->data[stk->top];
  return value;
}

void sortedInsert(Stack *stk, int element) {
  int temp;
  if (StackIsEmpty(stk) || element > StackTop(stk)) {
    StackPush(stk, element);
  } else {
    temp = StackPop(stk);
    sortedInsert(stk, element);
    StackPush(stk, temp);
  }
}

void sortStack(Stack *stk) {
  int temp;
  if (StackIsEmpty(stk) == 0) {
    temp = StackPop(stk);
    sortStack(stk);
    sortedInsert(stk, temp);
  }
}

void bottomInsert(Stack *stk, int element) {
  int temp;

  if (StackIsEmpty(stk)) {
    StackPush(stk, element);
  } else {
    temp = StackPop(stk);
    bottomInsert(stk, temp);
    StackPush(stk, element);
  }
}

int main() {
  Stack stk;
  StackInitialize(&stk);
  StackPush(&stk, 1);
  StackPush(&stk, 2);
  //   StackPush(&stk, 3);
  StackPush(&stk, 4);
  StackPush(&stk, 5);
  bottomInsert(&stk, 6);

  StackPrint(&stk);
  return 0;
}