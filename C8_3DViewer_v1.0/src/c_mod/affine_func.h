#ifndef AFFINE_TRANSFORMATIONS_H_
#define AFFINE_TRANSFORMATIONS_H_

#include "./loader.h"

void x_offset(data_t* data, double value_x);

void y_offset(data_t* data, double value_y);

void z_offset(data_t* data, double value_z);

void rotation_x(data_t* data, double value);

void rotation_y(data_t* data, double value);

void rotation_z(data_t* data, double value);

void scaling(data_t* data, double scale_value);

#endif