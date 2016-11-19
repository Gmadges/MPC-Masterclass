#include "tabInfo.h"
#include "model.h"
#include "ui_tabInfo.h"

TabInfo::TabInfo(std::shared_ptr<Model> _model, QWidget *parent) :
    QWidget(parent),
    pModel(_model),
    ui(new Ui::TabInfo)
{
    ui->setupUi(this);

    initConnections();
}

TabInfo::~TabInfo()
{
}

void TabInfo::initConnections()
{   
    //checkboxes
    connect(ui->check_showMesh, &QCheckBox::clicked, this, &TabInfo::setShowMesh);
    connect(ui->check_showPhys, &QCheckBox::clicked, this, &TabInfo::setShowPhys);

    //reset
    connect(ui->button_reset, &QPushButton::clicked, this, &TabInfo::reset);
}

void TabInfo::setShowMesh(bool set)
{
    pModel->setShowMesh(set);
}

void TabInfo::setShowPhys(bool set)
{
    pModel->setShowPhys(set);
}

void TabInfo::reset()
{
    pModel->reset();
}