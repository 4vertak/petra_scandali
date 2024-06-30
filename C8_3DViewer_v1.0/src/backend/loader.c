#include "./loader.h"

int loader(data_t* data, const char* file_name) {
  int error_code = 0;
  if (!file_name || !data) return 1;

  FILE* f = fopen(file_name, "r");
  if (f == NULL) {
    error_code = 1;
    printf("Error 2: %d\n", error_code);
  } else {
    calc_count(f, data);
    error_code = handle_data(f, data);
    fclose(f);
  }
  if (error_code != 0) free_memory_data(data);
  return error_code;
}

void calc_count(FILE* f, data_t* data) {
  char* str = NULL;
  size_t lenght = 0;
  while (getline(&str, &lenght, f) != EOF) {
    if (strncmp(str, "v ", 2) == 0) {
      data->count_vertex++;
    } else if (strncmp(str, "f ", 2) == 0) {
      char* token = strtok(str + 2, " ");
      while (token) {
        if (atoi(token)) data->count_edges++;
        token = strtok(NULL, " ");
      }
    }
  }
  if (str) free(str);
  fseek(f, 0, SEEK_SET);
}

int handle_data(FILE* f, data_t* data) {
  int error_code = allocate_memory_data(data);
  min_max_t min_max = {DBL_MAX, DBL_MAX, DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX};
  if (error_code == 0) {
    char* str = NULL;
    size_t lenght = 0, index_v = 0, index_f = 0, tmp_count_vertex = 0;
    while (getline(&str, &lenght, f) != EOF && error_code == 0) {
      if (strncmp(str, "v ", 2) == 0) {
        double x = 0, y = 0, z = 0;
        if (sscanf(str, "v %lf %lf %lf", &x, &y, &z) == 3) {
          data->vertex[index_v] = x;
          index_v += 1;
          data->vertex[index_v] = y;
          index_v += 1;
          data->vertex[index_v] = z;
          index_v += 1;
          tmp_count_vertex += 1;
          min_max.min_x = fmin(min_max.min_x, x);
          min_max.min_y = fmin(min_max.min_y, y);
          min_max.min_z = fmin(min_max.min_z, z);
          min_max.max_x = fmax(min_max.max_x, x);
          min_max.max_y = fmax(min_max.max_y, y);
          min_max.max_z = fmax(min_max.max_z, z);
        } else
          error_code = 1;
      } else if (strncmp(str, "f ", 2) == 0) {
        char* token = strtok(str + 2, " ");
        unsigned first_index = 0;
        bool is_first_index = true;
        while (token) {
          long index = atoi(token);
          if (index < 0)
            index += tmp_count_vertex;
          else
            index -= 1;
          if (is_first_index && atoi(token)) {
            first_index = index;
            data->edges_points[index_f] = first_index;
            index_f += 1;
            is_first_index = false;
          } else if (atoi(token)) {
            data->edges_points[index_f] = index;
            index_f += 1;
            data->edges_points[index_f] = index;
            index_f += 1;
          }
          token = strtok(NULL, " ");
        }
        data->edges_points[index_f] = first_index;
        index_f += 1;
      }
    }
    if (str) free(str);
  }
  // center_position(data, &min_max);
  return error_code;
}

void center_position(data_t* data, min_max_t* min_max) {
  size_t num_vertices = data->count_vertex;
  if (-((min_max->min_x + min_max->min_x) / 2) != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i] += -((min_max->min_x + min_max->min_x) / 2);
  }
  if (-((min_max->min_y + min_max->min_y) / 2) != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i + 1] += -((min_max->min_y + min_max->min_y) / 2);
  }
  if (-((min_max->min_z + min_max->min_z) / 2) != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i + 2] += -((min_max->min_z + min_max->min_z) / 2);
  }
}

int allocate_memory_data(data_t* data) {
  int error_code = 0;
  data->vertex = calloc(data->count_vertex * 10, sizeof(double));
  data->edges_points = calloc(data->count_edges * 10, sizeof(unsigned));
  if (!data->vertex || !data->edges_points) {
    error_code = 2;
    free_memory_data(data);
  }
  return error_code;
}

void free_memory_data(data_t* data) {
  if (data->vertex) free(data->vertex);
  if (data->edges_points) free(data->edges_points);
  data->count_vertex = 0;
  data->count_edges = 0;
  data->vertex = NULL;
  data->edges_points = NULL;
}