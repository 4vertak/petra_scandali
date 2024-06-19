#include "./loader.h"

int loader(data_t* data, char* file_name) {
  FILE* f;
  f = fopen(file_name, "r");
  if (f != NULL) {
    char str[100];
    calc_count_vertex_edges(f, data, str);
    handle_file(data, f, file_name, str);
  }
  return 0;
}

void handle_file(data_t* data, FILE* f, char* file_name, char* str) {
  data->vertex = (double*)calloc(data->count_vertex * 3, sizeof(double));
  data->edges_points = (int*)calloc(data->count_edges * 2, sizeof(int));
  int edges_numb = 0, numb = 0;
  char c;
  f = fopen(file_name, "r");
  while (fgets(str, 100, f)) {
    if (str[0] == 'v' && str[1] == ' ') {
      sscanf(str, "%c %lf %lf %lf", &c, &data->vertex[numb],
             &data->vertex[numb + 1], &data->vertex[numb + 2]);
      numb += 3;
    }
    if (str[0] == 'f' && str[1] == ' ') {
      int value = 0, count_edges_in_str = 0;
      count_edges_in_str = calc_count(str);
      int e_tmp = 0;
      int tmp_val = 0;
      for (size_t i = 2; i < strlen(str); i++) {
        if (str[i] == '/') {
          while (str[i] != ' ') {
            i++;
          }
        }
        if (isdigit(str[i])) {
          char arr[8] = {0};
          int j = 0;
          for (int k = i;;) {
            if ((str[i] >= 48) && (str[k] <= 57)) {
              arr[j] = str[k];
              j++, k++;
            } else {
              break;
            }
          }
          value = atoi(arr);
          i += j - 1;
          value -= 1;

          data->edges_points[edges_numb] = value;
          if (e_tmp == 0) {
            tmp_val = value;
            e_tmp++;
          } else if (edges_numb > 0 && count_edges_in_str != 0) {
            edges_numb++;
            data->edges_points[edges_numb] = value;
          }
          count_edges_in_str--;
          edges_numb++;
          if (count_edges_in_str == 0) {
            data->edges_points[edges_numb] = tmp_val;
            edges_numb++;
          }
        }
      }
    }
  }
  fclose(f);
}

void calc_count_vertex_edges(FILE* f, data_t* data, char* str) {
  int count_vertex = 0, count_edges = 0;
  while (fgets(str, 100, f)) {
    if (str[0] == 'v' && str[1] == ' ') {
      count_vertex++;
    }
    if (str[0] == 'f' && str[1] == ' ') {
      count_edges += calc_count(str);
    }
  }
  fclose(f);
  data->count_vertex = count_vertex;
  data->count_edges = count_edges;
}

int calc_count(char* str) {
  int in_digit = 0, count = 0;
  for (size_t i = 2; i < strlen(str); i++) {
    if (str[i] == '/') {
      while (str[i] != ' ') {
        i++;
      }
    }
    if (isdigit(str[i])) {
      if (!in_digit) {
        count++;
        in_digit = 1;
      }
    } else {
      in_digit = 0;
    }
  }
  return count;
}
