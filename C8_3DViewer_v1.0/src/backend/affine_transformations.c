#include "./affine_transformations.h"

//смещение по осям x/y/z , где value_x/y/z - значения насколько должна быть смещена исходная точка 

void translation_x(data_t* data, double value_x) {
  size_t num_vertices = data->count_vertex;
  if (value_x != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i] += value_x;
  }
}

void translation_y(data_t* data, double value_y) {
  size_t num_vertices = data->count_vertex;
    if (value_y != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i] += value_y;
  }
}

void translation_y(data_t* data, double value_z) {
  size_t num_vertices = data->count_vertex;
    if (value_z != 0.0) {
    for (size_t i = 0; i < 3 * num_vertices; i += 3)
      data->vertex[i] += value_z;
  }
}

//  вращение по осям x/y/z, value - значение угла поворота

void rotation_x(data_t* data, double value){
    size_t num_vertices = data->count_vertex;
    for (size_t i = 0; i < 3 * num_vertices; i += 3){
      double tmp_y = data->vertex[i + 1];
      double tmp_z = data->vertex[i + 2];
      data->vertex[i + 1] = cos(value * (M_PI/180)) * tmp_y - sin(value * (M_PI/180)) * tmp_z;
      data->vertex[i + 2] = sin(value * (M_PI/180)) * tmp_y - cos(value * (M_PI/180)) * tmp_z;
    }
}

void rotation_y(data_t* data, double value){
    size_t num_vertices = data->count_vertex;
    for (size_t i = 0; i < 3 * num_vertices; i += 3){
      double tmp_x = data->vertex[i];
      double tmp_z = data->vertex[i + 2];
      data->vertex[i] = cos(value * (M_PI/180)) * tmp_y - sin(value * (M_PI/180)) * tmp_z;
      data->vertex[i + 2] = sin(value * (M_PI/180)) * tmp_y - cos(value * (M_PI/180)) * tmp_z;
    }
}

void rotation_z(data_t* data, double value){
    size_t num_vertices = data->count_vertex;
    for (size_t i = 0; i < 3 * num_vertices; i += 3){
      double tmp_x = data->vertex[i];
      double tmp_y = data->vertex[i + 1];
      data->vertex[i] = cos(value * (M_PI/180)) * tmp_y - sin(value * (M_PI/180)) * tmp_z;
      data->vertex[i + 1] = sin(value * (M_PI/180)) * tmp_y - cos(value * (M_PI/180)) * tmp_z;
    }
}

//масштабирование просто умножаем на значение масштаба ))

void scaling(data_t* data, double scale_value){
    if (scale_value != 0.0) {
      size_t num_vertices = data->count_vertex;
      for (size_t i = 0; i < 3 * num_vertices; i++){
        data->vertex[i] *= scale_value;
    }
}
