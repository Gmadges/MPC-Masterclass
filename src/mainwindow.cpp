#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

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

    connect(ui->button_loadFile, &QPushButton::clicked, this, &MainWindow::browse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::browseFiles()
{
    //limiting this to obj's for now, TODO change later
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Models (*.obj)"));

    return filename.toStdString();
}
