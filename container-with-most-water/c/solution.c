#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int maxArea(int *height, int heightSize) {
  if (heightSize == 1) {
    return height[0];
  }
  if (heightSize == 2) {
    return height[0] < height[1] ? pow(height[0], 2) : pow(height[1], 2);
  }

  int area = 0;
  int left_value = height[0];
  int right_value = height[0];
  int left_pos = 0;
  int right_pos = 0;
  while (left_pos < heightSize) {
    while (right_pos < heightSize) {
      right_pos++;
      right_value = height[right_pos];
      int min_value = fmin(left_value, right_value);
      int current_area = min_value * min_value;
      area = fmax(current_area, area);
      printf("current: %d | max %d\n", current_area, area);
    }
    left_pos++;
    left_value = height[left_pos];
    right_pos = left_pos;
  }

  return area;
}

int main() {
  int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int heightSize = 9;
  int area = maxArea(height, heightSize);
  printf("Calculated max area: ");
  printf("%d\n", area);
}
