#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QTimer>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSettings>
#include <QSurfaceFormat>
#include <QWheelEvent>

#include "oglwidget.h"
#include "qgifimage.h"

extern "C" {
#include "../c_mod/loader.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const char *file_name;

private slots:
    void on_select_obj_clicked();
    void on_render_clicked();

    void on_projection_type_currentIndexChanged(int index);

    void on_vertex_type_currentIndexChanged(int index);
    void on_vertex_size_valueChanged(int arg1);

    void on_line_type_currentIndexChanged(int index);
    void on_line_thickness_valueChanged(int arg1);

    void on_x_move_spinbox_valueChanged(int arg1);
    void on_y_move_spinbox_valueChanged(int arg1);
    void on_z_move_spinbox_valueChanged(int arg1);

    void on_x_turn_spinbox_valueChanged(int arg1);
    void on_y_turn_spinbox_valueChanged(int arg1);
    void on_z_turn_spinbox_valueChanged(int arg1);

    // void on_scale_spinbox_valueChanged(int arg1);

    void repaint_vertexes();
    void repaint_edges();
    void repaint_background();
    void make_gif();
    void on_screenshot_btn_clicked();
    void on_gif_btn_clicked();

private:
    Ui::MainWindow *ui;

    QPoint curr_pos;
    QPoint new_pos;
    QString gif_name;
    QGifImage *gif_frame;
    QTimer *timer;
    QSettings *settings;

    int frames_counter = 0;

    bool obj_loaded = false;

    int x_offset_current_value = 50;
    int y_offset_current_value = 50;
    int z_offset_current_value = 50;

    int x_rotation_current_value = 50;
    int y_rotation_current_value = 50;
    int z_rotation_current_value = 50;

    int scale_current_value = 5;

    void save_settings();
    void load_settings();
    void set_settings_in_window();
};
#endif // MAINWINDOW_H
