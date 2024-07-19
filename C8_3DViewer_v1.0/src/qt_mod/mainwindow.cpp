#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
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

