#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#pragma once
#include <QFileDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QWheelEvent>

#include "mainwindow.h"

extern "C" {
#include "../c_mod/affine_func.h"
#include "../c_mod/loader.h"
}

class OGLWidget : public QOpenGLWidget {

  Q_OBJECT

 public:
  explicit OGLWidget(QWidget *parent = nullptr);

  char *filename;

  data_t data = {0, 0, NULL, NULL};

  int projection_type = 0;

  double v_red;
  double v_green;
  double v_blue;

  double e_red;
  double e_green;
  double e_blue;

  double bg_red;
  double bg_green;
  double bg_blue;

  int vertex_type = 0;
  int vertex_thickness = 3;

  int edge_type = 0;
  int edge_thickness = 3;

  double scale_value = 1;
  double norm_coef;

  void parse_obj();

  ~OGLWidget();

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void paint_edges();
  void paint_points();

  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;

  private:
  void normalized_coef();

  QPoint current_position;
  QPoint new_position;

};

#endif  // OGLWIDGET_H
