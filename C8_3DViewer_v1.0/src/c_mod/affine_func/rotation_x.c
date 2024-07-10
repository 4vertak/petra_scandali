#include "../affine_func.h"

/**
 * @brief Функция поворота вершин по оси X
 *
 * @param data Указатель на структуру данных, содержащую массив вершин
 * @param value Угол поворота в градусах
 */
void rotation_x(data_t* data, double value) {
  size_t num_vertices = data->count_vertex;
  for (size_t i = 0; i < 3 * num_vertices; i += 3) {
    double tmp_y = data->vertex[i + 1];
    double tmp_z = data->vertex[i + 2];
    data->vertex[i + 1] =
        cos(value * (M_PI / 180)) * tmp_y - sin(value * (M_PI / 180)) * tmp_z;
    data->vertex[i + 2] =
        sin(value * (M_PI / 180)) * tmp_y - cos(value * (M_PI / 180)) * tmp_z;
  }
}