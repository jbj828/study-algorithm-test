#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void reverseStack(Stack *stk) {
  int temp;
  if (StackIsEmpty(stk) == 0) {
    temp = StackPop(stk);
    reverseStack(stk);
    bottomInsert(stk, temp);
  }
}

// 괄호들의 짝이 맞으면 1 아니면 0
int isBalancedParenthesis(char *expn, int size) {
  Stack *stk;
  StackInitialize(stk);
  char ch;
  for (int i = 0; i < size; i++) {
    ch = expn[i];
    if (ch == '{' || ch == '[' || ch == '(') {
      StackPush(stk, ch);
    } else if (ch == '}') {
      if (StackPop(stk) != '{') {
        return 0;
      }
    } else if (ch == ']') {
      if (StackPop(stk) != '[') {
        return 0;
      }
    } else if (ch == ')') {
      if (StackPop(stk) != '(') {
        return 0;
      }
    }
  }

  return (StackSize(stk) == 0);
}

int maxDepthParenthesis(char *expn, int size) {
  int maxDepth = 0;
  int tempDepth = 0;

  Stack *stk;
  StackInitialize(stk);

  for (int i = 0; i < size; i++) {
    if (expn[i] == '(') {
      StackPush(stk, expn[i]);
      tempDepth++;
    } else if (expn[i] == ')') {
      StackPop(stk);
      tempDepth--;
    }
    if (tempDepth > maxDepth) {
      maxDepth = tempDepth;
    }
  }
  return maxDepth;
}

int longestContBalParen(char *string, int size) {
  int maxDepth = 0;
  int tempDepth = 0;

  Stack *stk;
  StackInitialize(stk);

  for (int i = 0; i < size; i++) {
    if (string[i] == '(') {
      StackPush(stk, string[i]);
      tempDepth++;
    } else if (string[i] == ')') {
      StackPop(stk);
      tempDepth--;
    }
    if (tempDepth > maxDepth) {
      maxDepth = tempDepth;
    }
  }
  return maxDepth * 2;
}

int main() {
  // Stack stk;
  // StackInitialize(&stk);
  // StackPush(&stk, 1);
  // StackPush(&stk, 2);
  // //   StackPush(&stk, 3);
  // StackPush(&stk, 4);
  // StackPush(&stk, 5);
  // bottomInsert(&stk, 6);
  // reverseStack(&stk);
  // StackPrint(&stk);

  printf("\n");

  char *expn = "(())((()))";
  int length = strlen(expn);
  maxDepthParenthesis(expn, length);
  return 0;
}