#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

struct Node *newNode() { return (struct Node *)malloc(sizeof(struct Node)); }

struct Node *nodeFromArray(int a[], int n) {
  struct Node *head = newNode();
  head->next = NULL;

  struct Node *current = head;

  for (int i = 0; i < n; i++) {
    current->value = a[i];
    if (i < n - 1) {
      struct Node *next = newNode();
      current->next = next;
      current = next;
    }
  }
  return head;
}

struct Node *reverseNodes(struct Node *root) {
  struct Node *current = root;
  struct Node *reversed = NULL;
  struct Node *next = NULL;
  // the current node will run from
  // the start of the list to the end of the list
  while (current) {
    // store the next pointer here.
    next = current->next;
    //
    current->next = reversed;
    reversed = current;
    current = next;
  }
  return reversed;
}

void showList(struct Node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d", root->value);
  if (root->next != NULL) {
    printf(" -> ");
  }
  showList(root->next);
}

int listLen(struct Node *root) {
  if (!root) {
    return 0;
  }
  if (!root->next) {
    return 1;
  }
  return 1 + listLen(root->next);
}

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  struct Node *nodeA = nodeFromArray(a, 5);
  struct Node *r;
  // assert(listLen(nodeA) == 5);
  showList(nodeA);
  printf("\n");
  r = reverseNodes(nodeA);
  showList(r);
  printf("\n");
}
