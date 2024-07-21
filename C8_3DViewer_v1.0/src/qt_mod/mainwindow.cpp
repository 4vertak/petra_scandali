#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  free_memory_data(&ui->openGLWidget->data);
  delete ui;
}

void MainWindow::on_select_obj_clicked() {
  QString QString_filename = QFileDialog::getOpenFileName(
      this, tr("Open .obj file:"), "~/", tr("Obj Files (*.obj)"));
  ui->file_path->setText(QString_filename);
}

void MainWindow::on_render_clicked() {
  if (obj_loaded == true) {
    free_memory_data(&ui->openGLWidget->data);
  }
  std::string std_filename = ui->file_path->text().toStdString();
  ui->openGLWidget->filename = (char *)std_filename.c_str();
  ui->openGLWidget->parse_obj();
  obj_loaded = true;
}

void MainWindow::on_projection_type_currentIndexChanged(int arg1) {
  ui->openGLWidget->projection_type = arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_vertex_type_currentIndexChanged(int index) {
  ui->openGLWidget->vertex_type = index;
  ui->openGLWidget->update();
}

void MainWindow::on_vertex_size_valueChanged(int arg1) {
  ui->openGLWidget->vertex_thickness = arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_line_type_currentIndexChanged(int index) {
  ui->openGLWidget->edge_type = index;
  ui->openGLWidget->update();
}

void MainWindow::on_line_thickness_valueChanged(int arg1) {
  ui->openGLWidget->edge_thickness = arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_x_move_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    double increment = 5;
    if (arg1 - x_offset_current_value < 0) {
      increment *= -1;
    }
    double value = increment / ui->openGLWidget->scale_value;
    x_offset(&ui->openGLWidget->data,
             value * ui->openGLWidget->norm_coef / 50.0);
    x_offset_current_value = arg1;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_y_move_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    double increment = 5;
    if (arg1 - y_offset_current_value < 0) {
      increment *= -1;
    }
    double value = increment / ui->openGLWidget->scale_value;
    y_offset(&ui->openGLWidget->data,
             value * ui->openGLWidget->norm_coef / 50.0);
    y_offset_current_value = arg1;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_z_move_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    double increment = 5;
    if (arg1 - z_offset_current_value < 0) {
      increment *= -1;
    }
    double value = increment / ui->openGLWidget->scale_value;
    z_offset(&ui->openGLWidget->data,
             value * ui->openGLWidget->norm_coef / 50.0);
    z_offset_current_value = arg1;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_x_turn_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    double increment = 50;
    if (arg1 - x_rotation_current_value < 0) {
      increment *= -1;
    }
    double value = increment / ui->openGLWidget->scale_value;
    rotation_x(&ui->openGLWidget->data,
               value * ui->openGLWidget->norm_coef / 10.0);
    x_rotation_current_value = arg1;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_y_turn_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    double increment = 50;
    if (arg1 - y_rotation_current_value < 0) {
      increment *= -1;
    }
    double value = increment / ui->openGLWidget->scale_value;
    rotation_y(&ui->openGLWidget->data,
               value * ui->openGLWidget->norm_coef / 10.0);
    y_rotation_current_value = arg1;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_z_turn_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    double increment = 50;
    if (arg1 - z_rotation_current_value < 0) {
      increment *= -1;
    }
    double value = increment / ui->openGLWidget->scale_value;
    rotation_z(&ui->openGLWidget->data,
               value * ui->openGLWidget->norm_coef / 10.0);
    z_rotation_current_value = arg1;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_scale_spinbox_valueChanged(int arg1) {
  if (arg1 > 0 && arg1 < 100) {
    int direction = 0;
    double increment = ui->openGLWidget->norm_coef / 10;
    double scale_temp = scale_current_value;
    if (scale_current_value > arg1) {
      direction = -1;
    } else if (scale_current_value < arg1) {
      direction = 1;
    }
    scale_current_value = arg1;

    if ((int)(scale_current_value + direction * increment) > 0) {
      scale_current_value += direction * increment;
      scaling(&ui->openGLWidget->data, scale_current_value / scale_temp);
      ui->openGLWidget->update();
    }
  }
}

