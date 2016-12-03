#include "tabInfo.h"
#include "model.h"
#include "ui_tabInfo.h"

TabInfo::TabInfo(std::shared_ptr<Model> _model, QWidget *parent) :
    QWidget(parent),
    pModel(_model),
    ui(new Ui::TabInfo)
{
    initUI();

    initConnections();
}

TabInfo::~TabInfo()
{
}

void TabInfo::initUI()
{
    ui->setupUi(this);

    // set up combo box
    ui->combo_constType->addItem("Fixed");
    ui->combo_constType->addItem("Slider");
    ui->combo_constType->addItem("Spring");
    //default to fixed
    ui->combo_constType->setCurrentIndex(0);

    //settings
    //hide all settings because we default to fixed
    ui->widget_springSettings->hide();

    // hide the apply button
    ui->button_applySettings->hide();
}

void TabInfo::initConnections()
{   
    //checkboxes
    connect(ui->check_showMesh, &QCheckBox::clicked, this, &TabInfo::setShowMesh);
    connect(ui->check_showPhys, &QCheckBox::clicked, this, &TabInfo::setShowPhys);

    //reset
    connect(ui->button_reset, &QPushButton::clicked, this, &TabInfo::reset);

    //combo box
    // need c++14 for the new qOverload stuff so we'll old skool it for now
    connect(ui->combo_constType, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TabInfo::setConstraintType);
}

void TabInfo::setConstraintType(int idx)
{  
    BodyConstraintType type = getConstType(idx);

    pModel->setConstraintType(type);

    // show correct constraints
    displaySettings(type);

    //TODO
    // apply whatever settings we already have stored, could just be default

    pModel->createConstraints(); 
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

BodyConstraintType TabInfo::getConstType(int idx)
{
    // probably shouldnt do this based on index but we know their order, its hardcoded
    // TODO make this nicer

    if(idx == 0)
    {
        return BodyConstraintType::FIXED;
    }
    else if(idx == 1)
    {
        return BodyConstraintType::SLIDER;
    }
    else if(idx == 2)
    {
        return BodyConstraintType::SPRING;
    }
    else
    {
        // default to fixed
        return BodyConstraintType::FIXED;
    }
}

void TabInfo::displaySettings(BodyConstraintType type)
{
    switch(type)
    {
        case BodyConstraintType::FIXED :
        {
            ui->widget_springSettings->hide();
            ui->button_applySettings->hide();
            break;
        }
        case BodyConstraintType::SLIDER :
        {
            ui->widget_springSettings->hide();
            ui->button_applySettings->hide();
            break;
        }
        case BodyConstraintType::SPRING :
        {
            ui->widget_springSettings->show();
            ui->button_applySettings->show();
            break;
        }
        default :
        {
            // default to fixed
            ui->widget_springSettings->hide();
            ui->button_applySettings->hide();
            break;
        }
    }
}