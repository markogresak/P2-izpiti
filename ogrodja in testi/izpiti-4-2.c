// izpiti komplet 4/5 - naloga 2.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define ST_ELEMENTOV 10

typedef struct node {
  int value;
  struct node *next;
} node;

node* addItemEnd(node *, int);
node* duplicateList(node *);
void print(node *);

int main(int argc, char const *argv[])
{
  node *list = NULL;
  for(int i = 1; i <= ST_ELEMENTOV; i++)
    list = addItemEnd(list, i);

  print(list);

  printf("------ Podvojen: ------\n");

  node *duplicated = duplicateList(list);
  print(duplicated);

  free(duplicated);
  free(list);
  return 0;
}

// za testi rezultatov, NE BO POTREBNA NA IZPITU - vsaj upam :)
void print(node *list) {
  node *next = list;
  if(next == NULL)
    printf("Seznam je prazen\n");
  else
    while(next != NULL) {
      printf("%d\n", next->value);
      next = next->next;
    }
}

// to funckijo boste na izpitu morali napisati sami
node* addItemEnd(node *list, int value) {
  if(list == NULL) {
    list = (node *) malloc(sizeof(node));
    list->value = value;
    list->next = NULL;
    return list;
  }
  else
    list->next = addItemEnd(list->next, value);
  return list;
}

node* duplicateList(node *list) {
  return NULL;
}
