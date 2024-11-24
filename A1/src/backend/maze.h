#ifndef SRC_BACKEND_MAZE_H
#define SRC_BACKEND_MAZE_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50
#define kEmpty 0
// #define PRINT_DEBAG

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  int **map;  // Основная карта
  int rows;   // Количество строк
  int cols;   // Количество колонок
} Pathway_t;

typedef struct {
  int rows;
  int cols;
  int **v_walls;
  int **h_walls;
  int *sideLine;
  int counter;
} Maze_t;

/*-----------------------Навигатор---------------------------*/

// Функция выделения памяти для карты
void allocateMap(Pathway_t *way);

// Функция инициализации структуры Pathway_t
void initializePathway_t(Pathway_t *way, Maze_t *maze);

// Функция освобождения памяти карты
void destroyMap(Pathway_t *way);

// Функция для изменения ячейки
int changeTheCell(int value, int cell);

// Функция для нахождения возможных шагов
int takePossibleSteps(Pathway_t *way, int step, Maze_t *maze);

// Функция для нахождения пути
void findWay(Pathway_t *way, Position begin, Position end, Position **path,
             int *pathLength, Maze_t *maze);

/*-----------Выделение и освобождеие памяти---------------*/

void free_walls(int **walls, int rows);

void free_maze(Maze_t *maze);

int **allocate_2d_array(int rows, int cols);

/*----------Создание объекта Maze_t------------------*/

Maze_t *create_empty_maze();

Maze_t *create_maze(int rows, int cols);

int resize_maze(Maze_t *maze, int new_rows, int new_cols);

/*---------Загрузка файла лабиринт------------*/

bool load_maze(const char *filename, Maze_t *maze);

/*--------Генерации лабиринта-----------*/

/* Заполним вектор пустым значением */
void fillEmptyValue(Maze_t *maze);

void assignUniqueSet(Maze_t *maze);

bool randomBool();

/* Объединение ячеек в одно множество */

void mergeSet(Maze_t *maze, int index, int element);

/* Добавление правой вертикальной стенки */
void addingVerticalWalls(Maze_t *maze, int row);

/* Подсчет ячеек, которые содержаться в уникальном множестве */
int calculateUniqueSet(Maze_t *maze, int element);

/* Добавление нижней горизонтальной стенки */
void addingHorizontalWalls(Maze_t *maze, int row);

/* Подсчет горизонтальных стен у ячеек уникального множества */

int calculateHorizontalWalls(Maze_t *maze, int element, int row);

/* Проверка условие 4.1 и 4.2 */
void checkedHorizontalWalls(Maze_t *maze, int row);

void preparatingNewLine(Maze_t *maze, int row);

/* Проверка условий на добавление последней строки */
void checkedEndLine(Maze_t *maze);

/* Добавление последней строки */
void addingEndLine(Maze_t *maze);

/* Метод генерации лабиринта */
void generateMaze_t(Maze_t *maze);

/*---------------Принт Дебаг---------------------*/

void print_test(Maze_t *maze);

void print_maze_t(const Maze_t *maze);

void print_maze_t_path(const Maze_t *maze, const Position *path,
                       int pathLength);

#endif  // SRC_BACKEND_MAZE_H