#include "../affine_func.h"

/**
 * \brief Функция x_offset изменяет x-координаты вершин в структуре data_t на
 * заданное значение.
 *
 * \param data Указатель на струк, содержащую вершины.
 * \param value_x Значение, на которое будут изменены x-координаты.
 */
void x_offset(data_t* data, double value_x) {
  size_t num_vertices = data->count_vertex;
  if (value_x != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3) data->vertex[i] += value_x;
  }
}