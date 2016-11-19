#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include "tabInfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initConnections();

    initStyleSheet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initStyleSheet()
{
    //load up stylesheet
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        this->setStyleSheet(ts.readAll());
    }
}

void MainWindow::initConnections()
{
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

        // loaded an object lets show the data to the user
        addObjectSetting(fileName);
    }
}

void MainWindow::addObjectSetting(std::string fileName)
{
    // get name from file name

    QStringList parts = QString(fileName.c_str()).split("/");
    QString name = parts.at(parts.size()-1);

    // create widget with settings
    QWidget *test = new TabInfo();

    // add to tabWidget
    ui->tabWidget_settings->addTab(test, name);
}
