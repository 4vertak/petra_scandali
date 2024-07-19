#include "oglwidget.h"

OGLWidget::OGLWidget(QWidget *parent) : QOpenGLWidget{parent} {}

void OGLWidget::parse_obj() {
  free_memory_data(&this->data);
  if (this->filename[0] != '\0') {
    loader(&this->data, this->filename);
    update();
  }
}

OGLWidget::~OGLWidget() { free_memory_data(&data); }

void OGLWidget::initializeGL() {
  glClearColor(bg_red, bg_green, bg_blue, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

void OGLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void OGLWidget::paintGL() {
  glClearColor(bg_red, bg_green, bg_blue, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glVertexPointer(3, GL_DOUBLE, 0, data.vertex);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glEnableClientState(GL_VERTEX_ARRAY);
  paint_edges();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OGLWidget::paint_edges() {
  glLineWidth(this->edge_thickness);
  glColor3f(e_red, e_green, e_blue);
  glDrawElements(GL_LINES, data.count_edges * 2, GL_UNSIGNED_INT,
                 data.edges_points);
}
