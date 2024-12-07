#ifndef SRC_BACKEND_BACKEND_H
#define SRC_BACKEND_BACKEND_H

#include <limits.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50
#define kEmpty 0
#define ESCAPE 27
#define PRINT_DEBAG
#define DEAD 0
#define ALIVE 1

typedef struct {
  int rows;
  int cols;
  int **map;
  int birthLimit;
  int bornLimit;
} Cave_t;

typedef struct {
  int y;
  int x;
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

typedef enum {
  START,
  SELECT_GENERATE,
  SELECT_LOAD,
  SELECT_DISPLAY_WAY,

  GENERATE_MAZE,
  SAVE_MAZE_IN_FILE,
  LOAD_MAZE_FROM_FILE,
  FIND_PATHAWAY,
  MAZE_PRINTING,

  GENERATE_CAVE,
  SAVE_CAVE_IN_FILE,
  LOAD_CAVE_FROM_FILE,
  CAVE_PRINTING,
  CAVE_PRINTING_STEP_BY_STEP,
  CAVE_PRINTING_AUTO,

  EXIT
} State_t;

typedef enum {
  Start,
  Generate,
  Load,
  Save,
  Pathfinding,
  Terminate,
  ShowPathfindingMap,
  selectMaze,
  selectCave,
  nextStep,
  speedDown,
  speedUp,
  NOSIG
} UserAction_t;

/*-----------------------Навигатор---------------------------*/

Pathway_t *ways(void);

Position *wayOut(void);

bool *pathfindingState(void);

bool *showPathfindingMapState(void);

bool checkPosition(Position *path);

// Функция выделения памяти для карты
void allocationOfPathMapMemory(Pathway_t *ways);

// Функция инициализации структуры Pathway_t
void initializePathway_t(Pathway_t *ways, Maze_t *maze);

// Функция освобождения памяти карты
void freeingPathMapMemory(Pathway_t *ways);

// Функция для изменения ячейки
int changeTheCell(int value, int cell);

// Функция для нахождения возможных шагов
int takePossibleSteps(Pathway_t *ways, int step, Maze_t *maze);

// Функция для нахождения пути
void findWay(Pathway_t *ways, Position begin, Position end, Position **path,
             int *pathLength, Maze_t *maze);

/*-----------Выделение и освобождеие памяти---------------*/

void freeWalls(int **walls, int rows);

void freeMaze(Maze_t *maze);

int **allocateArray(int rows, int cols);

/*----------Создание объекта Maze_t------------------*/
Maze_t *currentMaze();

Maze_t *createMaze(int rows, int cols);

int resizeMaze(Maze_t *maze, int new_rows, int new_cols);

bool *sizeInputState(void);

/*---------Загрузка файла лабиринт------------*/

bool *mazeLoadingState(void);

bool loadMaze(const char *filename, Maze_t *maze);

/*-----------------Сохранение лабиринта в файл--------------------------*/

bool *mazeSaveState(void);

bool saveMaze(const char *filename, Maze_t *maze);

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

/*-----------------FSM Logic----------------------------*/
State_t *currentState(void);

UserAction_t getSignal(int user_input);
void gameLoop();

void userInput(UserAction_t action, State_t *state);

void updateCurrentState(State_t *state);

// void onGenerateMaze();

// void onLoadingMaze();

// void onFindPathway(Position *path, int pathLength);

/*--------------------CAVE------------------------*/

Cave_t *currentCave(void);
void allocateMap(Cave_t *cave);
int resizeCave(Cave_t *cave, int new_rows, int new_cols);

bool readFile(Cave_t *cave, const char *fileName);

int findNeighbours(Cave_t *cave, int rowPos, int colPos);

void updateMap(Cave_t *cave);

void generateMap(Cave_t *cave, int chance);

void setLimits(Cave_t *cave, int birth, int death);

void freeCave(Cave_t *cave);

#endif  // SRC_BACKEND_BACKEND_H