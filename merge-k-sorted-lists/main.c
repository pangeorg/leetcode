#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int val;
  struct node_t *next;
} ListNode;

ListNode *node_alloc() {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  node->next = NULL;
  node->val = INT_MIN;
  return node;
}

void node_free(ListNode *node) {
  if (node->next != NULL) {
    node_free(node->next);
  }
  free(node);
}

void insert_sorted(ListNode **head_ref, int val) {
  ListNode *new_node = node_alloc();
  new_node->val = val;
  ListNode *current;

  /* Special case for the head end */
  if (*head_ref == NULL || (*head_ref)->val >= new_node->val) {
    new_node->next = *head_ref;
    *head_ref = new_node;
  } else {
    /* Locate the node before the point of insertion */
    current = *head_ref;
    while (current->next != NULL && current->next->val < new_node->val) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void print_node(ListNode *node) {
  ListNode *c = node;
  while (c != NULL) {
    printf("%d->", c->val);
    c = c->next;
  }
  printf("\n");
  return;
}

ListNode *mergeKLists(ListNode **lists, int listsSize) {
  ListNode *new = node_alloc();
  for (int i = 0; i < listsSize; ++i) {
    ListNode *cur = lists[i];
    while (cur != NULL) {
      insert_sorted(&new, cur->val);
      cur = cur->next;
    }
  }
  return new->next;
}

ListNode *node_from_array(int *a, int len) {
  ListNode *head = node_alloc();
  ListNode *current = head;

  for (int i = 0; i < len; i++) {
    current->val = a[i];
    if (i < len - 1) {
      ListNode *next = node_alloc();
      current->next = next;
      current = next;
    }
  }
  return head;
}

void test_insert_sorted() {
  int a[5] = {1, 4, 3, 8, 10};
  ListNode *unsorted = node_from_array(a, 5);
  print_node(unsorted);
  ListNode *sorted = node_alloc();
  for (int i = 0; i < 5; ++i) {
    insert_sorted(&sorted, a[i]);
  }
  print_node(sorted);
}

void test_leetcode() {
  int a[3] = {1, 4, 5};
  int b[3] = {1, 3, 4};
  int c[3] = {2, 6};
  ListNode *one = node_from_array(a, 3);
  ListNode *two = node_from_array(b, 3);
  ListNode *three = node_from_array(c, 2);
  ListNode *lists[3] = {one, two, three};
  ListNode *sorted = mergeKLists(lists, 3);
  print_node(sorted);
}

int main(void) { test_insert_sorted(); }
