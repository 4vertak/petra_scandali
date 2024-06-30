#ifndef AFFINE_TRANSFORMATIONS_H_
#define AFFINE_TRANSFORMATIONS_H_

#include "./loader.h"

void translation_x(data_t* data, double value_x);

void translation_y(data_t* data, double value_y);

void translation_z(data_t* data, double value_z);

//  вращение по осям x/y/z, value - значение угла поворота

void rotation_x(data_t* data, double value);

void rotation_y(data_t* data, double value);

void rotation_z(data_t* data, double value);

// масштабирование просто умножаем на значение масштаба ))

void scaling(data_t* data, double scale_value);

#endif