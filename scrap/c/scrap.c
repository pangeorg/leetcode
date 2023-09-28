#include <stdio.h>
#include <stdlib.h>

struct AStruct {
  int value;
};

int main() {
  int a[] = {1, 2, 3, 4, 5};
  int *ptr = &a[0];

  printf("Values: \n");
  printf("Address of a[0]: %p\n", ptr);
  printf("Value of a[0]: %d\n", *ptr);
  printf("Address ptr: %p\n", &ptr);

  printf("Struct: \n");
  struct AStruct astruct;
  astruct.value = 1;
  printf("Address of astruct: %p\n", &astruct);
  printf("Address of astruct.value: %p\n", &(astruct.value));

  printf("Array: \n");
  printf("|  addr        |  value  |\n");
  for (int i = 0; i < 4; i++) {
    printf("|%8p|%9d|\n", &a[i], a[i]);
  }

  return 0;
}
