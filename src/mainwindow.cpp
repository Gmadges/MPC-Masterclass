#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include "tabInfo.h"
#include "modelController.h"
#include "model.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set spinbox
    ui->spin_simStep->setValue(1);
    ui->scene->setSimSteps(1);

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

    //checkboxes
    connect(ui->check_showMesh, &QCheckBox::clicked, ui->scene, &GLScene::showMesh);
    connect(ui->check_showPhys, &QCheckBox::clicked, ui->scene, &GLScene::showPhys);

    // TODO change the max amount spheres based on this. when GPU enabled it shouldnt do more than 100;
    connect(ui->check_useGPUSkinning, &QCheckBox::clicked, ui->scene, &GLScene::useGPUSkinning);

    // load file
    connect(ui->button_loadObject, &QPushButton::clicked, this, &MainWindow::loadObject);

    //closing tabs
    connect(ui->tabWidget_settings, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);

    //simulation steps
    connect(ui->spin_simStep, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), ui->scene, &GLScene::setSimSteps);
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

        //may regret this...
        std::shared_ptr<ModelController> pModelController = ui->scene->getModelController();
        std::shared_ptr<Model> pModel = pModelController->getModel(pModelController->getNumModels()-1);

        // loaded an object lets show the data to the user
        addObjectSetting(fileName, pModel);
    }
}

void MainWindow::addObjectSetting(std::string fileName, std::shared_ptr<Model> pModel)
{
    // TODO make this more elegant, very bad
    QStringList pathParts = QString(fileName.c_str()).split("/");
    QString file = pathParts.at(pathParts.size()-1);
    QStringList fileParts = file.split(".");
    QString name = fileParts.at(fileParts.size()-2);

    // add to tabWidget
    ui->tabWidget_settings->addTab(new TabInfo(pModel), name);
}

void MainWindow::closeTab(int idx)
{
    //remove from controller
    ui->scene->getModelController()->removeModel(idx);

    //remove the tab
    ui->tabWidget_settings->removeTab(idx);
}
