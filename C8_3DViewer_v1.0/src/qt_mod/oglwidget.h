#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#pragma once
#include <QFileDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QSurfaceFormat>
#include <QTimer>
#include <QWheelEvent>

#include "mainwindow.h"

extern "C" {
#include "../c_mod/loader.h"
#include "../c_mod/affine_func.h"
}

class OGLWidget: public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OGLWidget(QWidget *parent = nullptr);

    char *filename;

    data_t data = {0, 0, NULL, NULL};

    int projection_type = 0;

    void parse_obj();
    void restore_default_vals();
    double normalized_coeff;

    double v_red = 255.0f;
    double v_green = 255.0f;
    double v_blue = 255.0f;

    double e_red = 255.0f;
    double e_green = 255.0f;
    double e_blue = 255.0f;

    double bg_red = 0.0f;
    double bg_green = 0.0f;
    double bg_blue= 0.0f;

    int edge_thickness = 3;

    double scale_val = 5;

    ~OGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void paint_lines();
};

#endif // OGLWIDGET_H
