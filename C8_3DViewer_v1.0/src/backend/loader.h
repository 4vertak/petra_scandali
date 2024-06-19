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
void calc_count_vertex_edges(FILE* f, data_t* data, char* str);
int calc_count(char* str);
#endif