#include "./main_test.h"

/*---------------Принт Дебаг---------------------*/

void print_test(Maze_t *maze) {
  printf("\n");
  printf("----Print Maze_t %d x %d----\n", maze->rows, maze->cols);
  printf("\n");

  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      printf("%d ", maze->v_walls[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      printf("%d ", maze->h_walls[i][j]);
    }
    printf("\n");
  }
}