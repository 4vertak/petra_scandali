#ifndef LOADER_H_
#define LOADER_H_

#define _GNU_SOURCE

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define INITIAL_SIZE 128

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

typedef struct {
  unsigned count_vertex;
  unsigned count_edges;
  double* vertex;
  unsigned* edges_points;
} data_t;

typedef struct {
  double min_x;
  double min_y;
  double min_z;
  double max_x;
  double max_y;
  double max_z;
} min_max_t;

int loader(data_t* data, const char* file_name);
int handle_data(FILE* f, data_t* data);
void calc_count(FILE* f, data_t* data);
void center_position(data_t* data, min_max_t* min_max);

size_t s21_getline(char **lineptr, size_t *n, FILE *stream);

int allocate_memory_data(data_t* data);
void free_memory_data(data_t* data);
#endif
