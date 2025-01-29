#include <stdio.h>

#define MAX 512

int main() {
  int array[MAX] = {0};
  int count = 0;
  int break_flag = 0;
  int n = -1;
  while (break_flag != 1) {
    int is_valid = scanf("%d", &n);
    if (!is_valid) {
      printf("n/a");
      return 0;
    } else {
      if (n == -1)
        break_flag = 1;
      else
        array[count++] = n;
    }
  }
  for (int i = count - 1; i >= 0; --i) printf("%d ", array[i]);

  return 0;
}