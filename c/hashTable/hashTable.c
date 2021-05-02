#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
  char name[MAX_NAME];
  int age;
} person;

// 포인터로 해시테이블을 지정하는 이유는 계속해서 요소를 늘릴 수 있기 때문이고
// 둘째로, 해시테이블의 첫째 인자를 Null로 지정해서 확인할 때 첫째인자만
// 확인하여, 나머지 해시테이블의 요소가 비어있는지 확인할 수 있기 때문
person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;
  for (int i = 0; i < length; i++) {
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}

void init_hash_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
  // table is empty
}

void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
}

bool hash_table_insert(person *p) {
  if (p == NULL) return false;
  int index = hash(p->name);
  if (hash_table[index] != NULL) {
    return false;
  }
  hash_table[index] = p;
  return true;
}
// find a person in the table by their name
person *hash_table_lookup(char *name) {
  int index = hash(name);
  if (hash_table[index] != NULL &&
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
    return hash_table[index];
  } else {
    return NULL;
  }
}

person *hash_table_delete(char *name) {
  int index = hash(name);
  if (hash_table[index] != NULL &&
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
    person *tmp = hash_table[index];
    hash_table[index] = NULL;
    return tmp;
  } else {
    return NULL;
  }
}

int main() {
  init_hash_table();
  print_table();

  person jacob = {.name = "Jacob", .age = 25};
  person kate = {.name = "Kate", .age = 28};
  person mpho = {.name = "Mpho", .age = 23};
  person sarah = {.name = "Sarah", .age = 23};
  person eliza = {.name = "Eliza", .age = 23};
  person jane = {.name = "Jane", .age = 23};
  person robert = {.name = "Robert", .age = 23};

  hash_table_insert(&jacob);
  hash_table_insert(&kate);
  hash_table_insert(&mpho);
  hash_table_insert(&sarah);
  hash_table_insert(&eliza);
  hash_table_insert(&jane);
  hash_table_insert(&robert);
  print_table();

  person *tmp = hash_table_lookup("Mpho");
  if (tmp == NULL) {
    printf("Not Found\n");
  } else {
    printf("Found %s.\n", tmp->name);
  }

  tmp = hash_table_lookup("George");
  if (tmp == NULL) {
    printf("Not Found\n");
  } else {
    printf("Found %s.\n", tmp->name);
  }

  hash_table_delete("Mpho");
  tmp = hash_table_lookup("Mpho");
  if (tmp == NULL) {
    printf("Not Found\n");
  } else {
    printf("Found %s.\n", tmp->name);
  }
  return 0;
}