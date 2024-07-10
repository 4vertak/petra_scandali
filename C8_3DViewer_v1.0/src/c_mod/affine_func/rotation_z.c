#include "../affine_func.h"

/**
 * \brief Функция поворота вершин по оси Z.
 *
 * \param data Указатель на структуру данных, содержащую вершины.
 * \param value Значение угла поворота в градусах.
 */
void rotation_z(data_t* data, double value) {
  size_t num_vertices = data->count_vertex;
  for (size_t i = 0; i < 3 * num_vertices; i += 3) {
    double tmp_x = data->vertex[i];
    double tmp_y = data->vertex[i + 1];
    data->vertex[i] =
        cos(value * (M_PI / 180)) * tmp_x - sin(value * (M_PI / 180)) * tmp_y;
    data->vertex[i + 1] =
        sin(value * (M_PI / 180)) * tmp_x - cos(value * (M_PI / 180)) * tmp_y;
  }
}