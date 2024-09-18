#include "../affine_func.h"

/**
 * \brief Функция z_offset изменяет z-координаты вершин в структуре data_t на
 * заданное значение.
 *
 * \param data Указатель на струк, содержащую вершины.
 * \param value_z Значение, на которое будут изменены z-координаты.
 */
void z_offset(data_t* data, double value_z) {
  size_t num_vertices = data->count_vertex;
  if (value_z != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i + 2] += value_z;
  }
}