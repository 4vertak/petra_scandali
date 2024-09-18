#include "oglwidget.h"

OGLWidget::OGLWidget(QWidget *parent) : QOpenGLWidget{parent} {}

void OGLWidget::parse_obj() {
  free_memory_data(&this->data);
  if (this->filename[0] != '\0') {
    loader(&this->data, this->filename);
      normalized_coef();
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

  if (this->projection_type == 0) {
      glOrtho(-1 * norm_coef, 1 * norm_coef, -1 * norm_coef,
              1 * norm_coef, -1 * norm_coef,
              1000 * norm_coef);
      glTranslatef(0, -norm_coef / 2, 0);

  } else {
      glFrustum(-1 * norm_coef, 1 * norm_coef,
                -1 * norm_coef, 1 * norm_coef, norm_coef,
                1000 * norm_coef);
      glTranslatef(0, 0, -2 * norm_coef);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  if (this->vertex_type != 0) {
      paint_points();
  }
  paint_edges();
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OGLWidget::paint_edges() {
    if (this->edge_type == 1) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
    }
  glLineWidth(this->edge_thickness);
  glColor3f(e_red, e_green, e_blue);
  glDrawElements(GL_LINES, data.count_edges * 2, GL_UNSIGNED_INT,
                 data.edges_points);
  if (this->edge_type == 1) {
      glDisable(GL_LINE_STIPPLE);
  }
}

void OGLWidget::paint_points()
{
    if (this->vertex_type == 1) {
        glEnable(GL_POINT_SMOOTH);
    }
    glPointSize(this->vertex_thickness);
    glColor3f(v_red, v_green, v_blue);

    glDrawArrays(GL_POINTS, 0, data.count_vertex);
    if (this->vertex_type == 1) {
        glDisable(GL_POINT_SMOOTH);
    }
}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{
  current_position = event->globalPosition().toPoint();
}

void OGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    new_position = QPoint(event->globalPosition().toPoint() - current_position);

    if (event->buttons() & Qt::LeftButton) {
        x_offset(&this->data, new_position.x() * this->norm_coef / 5000.0);
        y_offset(&this->data, -new_position.y() * this->norm_coef / 5000.0);
        update();
    } else if (event->buttons() & Qt::RightButton) {
        rotation_x(&this->data, -new_position.y() * 0.01);
        rotation_y(&this->data, -new_position.x() * 0.01);
        update();
    }
}

void OGLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint degrees_val = event->angleDelta() / 120;
    double increment = norm_coef / 10;
    double tmp_scale_value = scale_value;

    if ((int)(scale_value + degrees_val.y() * increment) > 0) {
        scale_value += degrees_val.y() * increment;
        scaling(&this->data, scale_value / tmp_scale_value);
        update();
    }
}

void OGLWidget::normalized_coef()
{
    norm_coef = -1;
    for (size_t i = 0; i < data.count_vertex * 3; i++) {
        if (fabs(data.vertex[i]) > norm_coef) {
            norm_coef = fabs(data.vertex[i]);
        }
    }
}
