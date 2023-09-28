#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *ListNodeFromArray(int a[], int n) {
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
  head->next = NULL;

  struct ListNode *current = head;

  for (int i = 0; i < n; i++) {
    current->val = a[i];
    struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
    current->next = next;
    current = next;
  }
  return head;
}

void showList(struct ListNode *root) {
  struct ListNode *current = root;
  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

void showArray(int a[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d,", a[i]);
  }
  printf("]");
}

int listLen(struct ListNode *root) {
  int count = 0;
  struct ListNode *current = root;
  while (current != NULL) {
    current = current->next;
    count++;
  }
  return count;
}

bool isPalindrome(struct ListNode *head) {
  int len = listLen(head) - 1;
  int *ptr = (int *)malloc(len * sizeof(int));

  if (ptr == NULL) {
    printf("Memory not allocated.\n");
    return false;
  }

  for (int i = 0; i < len; i++) {
    ptr[i] = head->val;
    head = head->next;
  }

  for (int i = 0; i < len; i++) {
    if (ptr[i] != ptr[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int a[4] = {1, 2, 3, 4};
  struct ListNode *nodes1 = ListNodeFromArray(a, 4);
  assert(isPalindrome(nodes1) == false);

  int b[4] = {1, 2, 2, 1};
  struct ListNode *nodes2 = ListNodeFromArray(b, 4);
  showList(nodes2);
  assert(isPalindrome(nodes2) == true);

  int c[4] = {1, 0, 0};
  struct ListNode *nodes3 = ListNodeFromArray(c, 4);
  assert(isPalindrome(nodes3) == false);
}
