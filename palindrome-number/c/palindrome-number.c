#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x) {
  long int rev = 0;
  int temp = x;
  if (x < 0)
    return false;

  while (x) {
    rev = rev * 10 + x % 10;
    x /= 10;
  }

  return (temp == rev);
}

int main() {

  printf("Running tests...\n");
  assert(isPalindrome(141) == true);
  assert(isPalindrome(-141) == false);
  assert(isPalindrome(10) == false);
  assert(isPalindrome(1799999971) == true);
  printf("Passed all tests!\n");

  return 0;
}
