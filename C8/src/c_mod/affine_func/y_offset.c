#include "../affine_func.h"

/**
 * \brief Функция y_offset изменяет y-координаты вершин в структуре data_t на
 * заданное значение.
 *
 * \param data Указатель на струк, содержащую вершины.
 * \param value_y Значение, на которое будут изменены y-координаты.
 */
void y_offset(data_t* data, double value_y) {
  size_t num_vertices = data->count_vertex;
  if (value_y != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i + 1] += value_y;
  }
}