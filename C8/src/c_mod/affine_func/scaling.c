#include "../affine_func.h"

/**
 * @brief Функция scaling масштабирует все вершины в соответствии с
 * заданным значением scale_value.
 *
 * @param data Указатель на структуру данных, содержащую информацию о вершинах.
 * @param scale_value Значение, будут умножены все вершины.
 */
void scaling(data_t* data, double scale_value) {
  if (scale_value != 0.0) {
    size_t num_vertices = data->count_vertex;
    for (size_t i = 0; i < 3 * num_vertices; i++) {
      data->vertex[i] *= scale_value;
    }
  }
}
