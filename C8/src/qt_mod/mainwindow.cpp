#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

    settings = new QSettings(0, 0, this);
    timer = new QTimer(0);
    connect(timer, SIGNAL(timeout()), this, SLOT(make_gif()));

    load_settings();
    connect(ui->v_red_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_vertexes()));
    connect(ui->v_green_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_vertexes()));
    connect(ui->v_blue_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_vertexes()));

    connect(ui->e_red_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_edges()));
    connect(ui->e_green_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_edges()));
    connect(ui->e_blue_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_edges()));

    connect(ui->bg_red_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_background()));
    connect(ui->bg_green_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_background()));
    connect(ui->bg_blue_spinbox, SIGNAL(valueChanged(int)), this,
            SLOT(repaint_background()));
}

MainWindow::~MainWindow() {
    save_settings();
  free_memory_data(&ui->openGLWidget->data);
  delete ui;
}

void MainWindow::save_settings() {
    settings->setValue("settings_saved", 1);

    settings->setValue("projection_type", ui->openGLWidget->projection_type);

    settings->setValue("vertex_type", ui->openGLWidget->vertex_type);
    settings->setValue("vertex_thickness", ui->openGLWidget->vertex_thickness);

    settings->setValue("edge_type", ui->openGLWidget->edge_type);
    settings->setValue("edge_thickness", ui->openGLWidget->edge_thickness);

    settings->setValue("v_red", ui->openGLWidget->v_red);
    settings->setValue("v_green", ui->openGLWidget->v_green);
    settings->setValue("v_blue", ui->openGLWidget->v_blue);
    settings->setValue("e_red", ui->openGLWidget->e_red);
    settings->setValue("e_green", ui->openGLWidget->e_green);
    settings->setValue("e_blue", ui->openGLWidget->e_blue);
    settings->setValue("bg_red", ui->openGLWidget->bg_red);
    settings->setValue("bg_green", ui->openGLWidget->bg_green);
    settings->setValue("bg_blue", ui->openGLWidget->bg_blue);
}

void MainWindow::load_settings() {
    if (settings->value("settings_saved").toInt()) {
        ui->openGLWidget->projection_type =
            settings->value("projection_type").toInt();

        ui->openGLWidget->vertex_type = settings->value("vertex_type").toInt();
        ui->openGLWidget->vertex_thickness =
            settings->value("vertex_thickness").toInt();

        ui->openGLWidget->edge_type = settings->value("edge_type").toInt();
        ui->openGLWidget->edge_thickness =
            settings->value("edge_thickness").toInt();

        ui->openGLWidget->v_red = settings->value("v_red").toDouble();
        ui->openGLWidget->v_green = settings->value("v_green").toDouble();
        ui->openGLWidget->v_blue = settings->value("v_blue").toDouble();
        ui->openGLWidget->e_red = settings->value("e_red").toDouble();
        ui->openGLWidget->e_green = settings->value("e_green").toDouble();
        ui->openGLWidget->e_blue = settings->value("e_blue").toDouble();
        ui->openGLWidget->bg_red = settings->value("bg_red").toDouble();
        ui->openGLWidget->bg_green = settings->value("bg_green").toDouble();
        ui->openGLWidget->bg_blue = settings->value("bg_blue").toDouble();

        set_settings_in_window();

        repaint_vertexes();
        repaint_edges();
        repaint_background();
    }
}

void MainWindow::set_settings_in_window() {
    ui->projection_type->setCurrentIndex(ui->openGLWidget->projection_type);

    ui->vertex_type->setCurrentIndex(ui->openGLWidget->vertex_type);
    ui->vertex_size->setValue(ui->openGLWidget->vertex_thickness);

    ui->line_type->setCurrentIndex(ui->openGLWidget->edge_type);
    ui->line_thickness->setValue(ui->openGLWidget->edge_thickness);

    ui->v_red_spinbox->setValue((int)(ui->openGLWidget->v_red * 255));
    ui->v_green_spinbox->setValue((int)(ui->openGLWidget->v_green * 255));
    ui->v_blue_spinbox->setValue((int)(ui->openGLWidget->v_blue * 255));
    ui->e_red_spinbox->setValue((int)(ui->openGLWidget->e_red * 255));
    ui->e_green_spinbox->setValue((int)(ui->openGLWidget->e_green * 255));
    ui->e_blue_spinbox->setValue((int)(ui->openGLWidget->e_blue * 255));
    ui->bg_red_spinbox->setValue((int)(ui->openGLWidget->bg_red * 255));
    ui->bg_green_spinbox->setValue((int)(ui->openGLWidget->bg_green * 255));
    ui->bg_blue_spinbox->setValue((int)(ui->openGLWidget->bg_blue * 255));
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

  ui->filename_info->setText(QFileInfo(ui->file_path->text()).fileName());
  ui->count_vertex_info->setText(QString::number(ui->openGLWidget->data.count_vertex));
  ui->count_edge_info->setText(QString::number(ui->openGLWidget->data.count_edges));
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

// void MainWindow::on_scale_spinbox_valueChanged(int arg1) {
//   if (arg1 > 0 && arg1 < 100) {
//     int direction = 0;
//     double increment = ui->openGLWidget->norm_coef / 10;
//     double scale_temp = scale_current_value;
//     if (scale_current_value > arg1) {
//       direction = -1;
//     } else if (scale_current_value < arg1) {
//       direction = 1;
//     }
//     scale_current_value = arg1;

//     if ((int)(scale_current_value + direction * increment) > 0) {
//       scale_current_value += direction * increment;
//       scaling(&ui->openGLWidget->data, scale_current_value / scale_temp);
//       ui->openGLWidget->update();
//     }
//   }
// }

void MainWindow::repaint_vertexes() {
    QString red = QString::number(ui->v_red_spinbox->value());
    QString green = QString::number(ui->v_green_spinbox->value());
    QString blue = QString::number(ui->v_blue_spinbox->value());
    ui->v_color_prev->setStyleSheet(
        "QLabel{"
        "background-color:rgb(" +
        red + "," + green + "," + blue +
        ");"
        "}");
    ui->openGLWidget->v_red = ui->v_red_spinbox->value() / 255.0f;
    ui->openGLWidget->v_green = ui->v_green_spinbox->value() / 255.0f;
    ui->openGLWidget->v_blue = ui->v_blue_spinbox->value() / 255.0f;
    ui->openGLWidget->update();
}

void MainWindow::repaint_edges() {
    QString red = QString::number(ui->e_red_spinbox->value());
    QString green = QString::number(ui->e_green_spinbox->value());
    QString blue = QString::number(ui->e_blue_spinbox->value());
    ui->e_color_prev->setStyleSheet(
        "QLabel{"
        "background-color:rgb(" +
        red + "," + green + "," + blue +
        ");"
        "}");
    ui->openGLWidget->e_red = ui->e_red_spinbox->value() / 255.0f;
    ui->openGLWidget->e_green = ui->e_green_spinbox->value() / 255.0f;
    ui->openGLWidget->e_blue = ui->e_blue_spinbox->value() / 255.0f;
    ui->openGLWidget->update();
}

void MainWindow::repaint_background() {
    QString red = QString::number(ui->bg_red_spinbox->value());
    QString green = QString::number(ui->bg_green_spinbox->value());
    QString blue = QString::number(ui->bg_blue_spinbox->value());
    ui->bg_color_prev->setStyleSheet(
        "QLabel{"
        "background-color:rgb(" +
        red + "," + green + "," + blue +
        ");"
        "}");
    ui->openGLWidget->bg_red = ui->bg_red_spinbox->value() / 255.0f;
    ui->openGLWidget->bg_green = ui->bg_green_spinbox->value() / 255.0f;
    ui->openGLWidget->bg_blue = ui->bg_blue_spinbox->value() / 255.0f;
    ui->openGLWidget->update();
}

void MainWindow::on_screenshot_btn_clicked() {
    if (obj_loaded) {
        QFileDialog dialogConnectImage(this);
        QDateTime curr_date = QDateTime::currentDateTime();
        QString time_date_formatted = curr_date.toString("yyyy-MM-dd hh-mm-ss");
        QString name_template = "Screenshot " + time_date_formatted + ".jpeg";
        QString image_name = dialogConnectImage.getSaveFileName(
            this, tr("Save screenshot"), name_template,
            tr("Images (*.jpeg *.bmp)"));

        if (image_name.length() >= 1) {
            QImage img = ui->openGLWidget->grabFramebuffer();
            img.save(image_name);
            QMessageBox messageBoxImage;
            messageBoxImage.information(0, "", "Screenshot was created successfully");
        }
    } else {
        QMessageBox warning = QMessageBox();
        warning.setWindowTitle("Error");
        warning.setText("Select .obj file to take a screenshot.");
        warning.setIcon(QMessageBox::Warning);
        warning.exec();
    }
}

void MainWindow::on_gif_btn_clicked() {
    if (obj_loaded) {
        QFileDialog dialogConnectImage(this);
        QDateTime curr_date = QDateTime::currentDateTime();
        QString time_date_formatted = curr_date.toString("yyyy-MM-DD hh:mm:ss");
        QString name_template = "Screencast " + time_date_formatted + ".gif";
        gif_name = dialogConnectImage.getSaveFileName(
            this, tr("Save gif"), name_template, tr("gif (*.gif)"));
        if (gif_name.length() >= 1) {
            ui->gif_btn->setDisabled(true);
            gif_frame = new QGifImage;
            gif_frame->setDefaultDelay(10);
            timer->setInterval(100);
            timer->start();
        }
    } else {
        QMessageBox warning = QMessageBox();
        warning.setWindowTitle("Error");
        warning.setText("Select .obj file to take a screencast.");
        warning.setIcon(QMessageBox::Warning);
        warning.exec();
    }
}

void MainWindow::make_gif() {
    frames_counter++;
    QImage image = ui->openGLWidget->grabFramebuffer();
    QSize image_size(640, 480);
    QImage scaled_image = image.scaled(image_size);
    gif_frame->addFrame(scaled_image);
    if (frames_counter >= 50) {
        timer->stop();
        gif_frame->save(gif_name);
        frames_counter = 0;
        QMessageBox messageBoxImage;
        messageBoxImage.information(
            0, "", "Screencast was created successfully as .gif file");
        delete gif_frame;
        ui->gif_btn->setText("");
        ui->gif_btn->setEnabled(true);
    }
}

