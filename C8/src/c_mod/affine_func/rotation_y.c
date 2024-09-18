#include "../affine_func.h"

/**
 * @brief Функция поворота вершин по оси Y
 *
 * @param data Указатель на структуру данных, содержащую массив вершин
 * @param value Угол поворота в градусах
 * to-do: решить что будем передавать градусы или радианы?
 */
void rotation_y(data_t* data, double value) {
  if (data == NULL || data->vertex == NULL) {
        return; // Проверка на NULL
    }
  size_t num_vertices = data->count_vertex;
  for (size_t i = 0; i < 3 * num_vertices; i += 3) {
    double tmp_x = data->vertex[i];
    double tmp_z = data->vertex[i + 2];
    data->vertex[i] = cos(value * (M_PI / 180)) * tmp_x + sin(value * (M_PI / 180)) * tmp_z; // Изменено
    data->vertex[i + 2] = -sin(value * (M_PI / 180)) * tmp_x + cos(value * (M_PI / 180)) * tmp_z; // Изменено
  }
}
