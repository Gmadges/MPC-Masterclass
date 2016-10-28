#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // link the buttons to their methods
    connect(ui->button_toggleSim, &QPushButton::clicked, ui->scene, &GLScene::toggleSim);
    connect(ui->button_resetSim, &QPushButton::clicked, ui->scene, &GLScene::resetSim);
    connect(ui->check_showMesh, &QCheckBox::clicked, ui->scene, &GLScene::showMesh);
    connect(ui->check_showPhys, &QCheckBox::clicked, ui->scene, &GLScene::showPhys);
}

MainWindow::~MainWindow()
{
    delete ui;
}
