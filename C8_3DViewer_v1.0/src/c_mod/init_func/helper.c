#include "../loader.h"

/**
 * @brief Функция для подсчета количества вершин и ребер в файле.
 *
 * @param f Указатель на файл.
 * @param data Указатель на структуру данных, в которой будут храниться
 * результаты подсчета.
 */
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

/**
 * @fn handle_data(FILE* f, data_t* data)
 * @brief Главная функция для обработки данных из файла
 *
 * @param f Указатель на файл для чтения
 * @param data Указатель структуру для хранения данных
 *
 * @return Код ошибки: 0 - успех, 1 - ошибка
 */

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
  center_position(data, &min_max);
  return error_code;
}

/**
 * @brief Функция центрирования позиции вершин.
 *
 * @param data Указатель на структуру данных, содержащую информацию о вершинах.
 * @param min_max Указатель на структуру данных, содержащую информацию о
 * минимальных максимальных значениях координат вершин.
 */
void center_position(data_t* data, min_max_t* min_max) {
  size_t num_vertices = data->count_vertex;
  if (-((min_max->max_x + min_max->min_x) / 2) != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3) {
      data->vertex[i] += -((min_max->max_x + min_max->min_x) / 2);
    }
  }
  if (-((min_max->max_y + min_max->min_y) / 2) != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i + 1] += -((min_max->max_y + min_max->min_y) / 2);
  }
  if (-((min_max->max_z + min_max->min_z) / 2) != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i + 2] += -((min_max->max_z + min_max->min_z) / 2);
  }
}

/**
 * @brief Функция allocate_memory_data выделяет память под массивы vertex и
 * edges_points.
 * @param data Указатель на структуру данных data_t.
 * @return Код ошибки. 0 - успешное выполнение, 2 - выделения памяти.
 */
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

/**
 * @brief Функция освобождает память, выделенную для данных.
 *
 * @param data Указатель на структуру данных.
 */
void free_memory_data(data_t* data) {
  if (data->vertex) free(data->vertex);
  if (data->edges_points) free(data->edges_points);
  data->count_vertex = 0;
  data->count_edges = 0;
  data->vertex = NULL;
  data->edges_points = NULL;
}
