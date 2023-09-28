#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

const char *tokens[13] = {"IV", "IX", "XL", "XC", "CD", "CM", "I",
                          "V",  "X",  "L",  "C",  "D",  "M"};
const int values[13] = {4, 9, 40, 90, 400, 900, 1, 5, 10, 50, 100, 500, 1000};

int symbolToNum(char *symbol) {
  switch (*symbol) {
  case 'I':
    return 1;
    break;
  case 'V':
    return 5;
    break;
  case 'X':
    return 10;
    break;
  case 'L':
    return 50;
    break;
  case 'C':
    return 100;
    break;
  case 'D':
    return 500;
    break;
  case 'M':
    return 1000;
    break;
  }
  return 0;
}

char *intToRoman(int num) {
  char *dest = (char *)calloc(MAX_SIZE, sizeof(char));
  // how many 'M' do I need?
  int num_to_add = (int)num / 1000;
  for (int i = 0; i < num_to_add; i++) {
    strcat(dest, "M");
  }
  num = num - num_to_add * 1000;

  if (num >= 900) {
    strcat(dest, "CM");
    num = num - 900;
  } else if (num >= 500) {
    strcat(dest, "D");
    num = num - 500;
  } else if (num >= 400) {
    strcat(dest, "CD");
    num = num - 400;
  }
  // how many 'C' do I need?
  num_to_add = (int)num / 100;
  for (int i = 0; i < num_to_add; i++) {
    strcat(dest, "C");
  }
  num = num - num_to_add * 100;

  if (num >= 90) {
    strcat(dest, "XC");
    num = num - 90;
  } else if (num >= 50) {
    strcat(dest, "L");
    num = num - 50;
  } else if (num >= 40) {
    strcat(dest, "XL");
    num = num - 40;
  }
  // how many 'X' do I need?
  num_to_add = (int)num / 10;
  for (int i = 0; i < num_to_add; i++) {
    strcat(dest, "X");
  }
  num = num - num_to_add * 10;

  if (num >= 9) {
    strcat(dest, "IX");
    num = num - 9;
  } else if (num >= 5) {
    strcat(dest, "V");
    num = num - 5;
  } else if (num >= 4) {
    strcat(dest, "IV");
    num = num - 4;
  }
  // how many 'I' do I need?
  num_to_add = (int)num / 1;
  for (int i = 0; i < num_to_add; i++) {
    strcat(dest, "I");
  }
  num = num - num_to_add * 1;

  return dest;
}

void test(int num) {
  char *result = intToRoman(num);
  printf("%d -> %s\n", num, result);
}

int main() {
  int a[] = {3, 58, 1994};
  for (int i = 0; i < 3; i++) {
    test(a[i]);
  }
}
