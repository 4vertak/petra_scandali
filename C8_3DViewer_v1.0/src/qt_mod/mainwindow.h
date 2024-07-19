#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QDateTime>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSettings>
#include <QSurfaceFormat>
#include <QWheelEvent>

#include "oglwidget.h"

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

private:
    Ui::MainWindow *ui;
    bool obj_loaded = false;
};
#endif // MAINWINDOW_H
