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
    connect(ui->button_clearSim, &QPushButton::clicked, ui->scene, &GLScene::clearSim);

    //checkboxes
    connect(ui->check_showMesh, &QCheckBox::clicked, ui->scene, &GLScene::showMesh);
    connect(ui->check_showPhys, &QCheckBox::clicked, ui->scene, &GLScene::showPhys);

    // load file
    connect(ui->button_loadObject, &QPushButton::clicked, this, &MainWindow::loadObject);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::browseFiles()
{
    //limiting this to obj's for now, TODO change later
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Models (*.obj)"));

    return fileName.toStdString();
}

void MainWindow::loadObject()
{
    std::string fileName = browseFiles();

    if(!fileName.empty())
    {
        ui->scene->loadObject(fileName);
    }
}
