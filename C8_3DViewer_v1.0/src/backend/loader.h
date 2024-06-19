#ifndef LOADER_H_
#define LOADER_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int count_vertex;
  int count_edges;
  double* vertex;
  int* edges_points;
} data_t;

int loader(data_t* data, char* file_name);
int calc_count(char* str);
#endif