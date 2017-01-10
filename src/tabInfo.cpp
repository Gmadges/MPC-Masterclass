#include "tabInfo.h"
#include "model.h"
#include "ui_tabInfo.h"

TabInfo::TabInfo(std::shared_ptr<Model> _model, QWidget *parent) :
    QWidget(parent),
    pModel(_model),
    ui(new Ui::TabInfo),
    pCurrentSettings(nullptr)
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
    ui->combo_constType->addItem("Spring");
    //default to fixed
    ui->combo_constType->setCurrentIndex(0);

    //set all our default sphere values;
    ui->check_sphereOverlap->setCheckState(Qt::CheckState::Checked);
    pModel->setSphereOverlap(true);

    ui->spin_maxSphereCount->setValue(1000);
    pModel->setMaxSphereCount(1000);

    ui->spin_maxSphereSize->setValue(1000000000.0);
    pModel->setMaxSphereSize(1000000000.0);

    ui->spin_minSphereSize->setValue(1.0);
    pModel->setMinSphereSize(1.0);

    // and apply this to the model
    pModel->reset();

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

    //sphere settings
    connect(ui->check_sphereOverlap, &QCheckBox::clicked, this, &TabInfo::setSphereOverlap);
    connect(ui->spin_maxSphereCount, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &TabInfo::setMaxSphereCount);
    connect(ui->spin_maxSphereSize, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &TabInfo::setSphereMaxSize);
    connect(ui->spin_minSphereSize, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged), this, &TabInfo::setSphereMinSize);

    //apply settings
    connect(ui->button_applySettings, &QPushButton::clicked, this, &TabInfo::applyConstraintSettings);
}

void TabInfo::setConstraintType(int idx)
{  
    BodyConstraintType type = getConstType(idx);

    pModel->setConstraintType(type);

    // show correct constraints
    displaySettings(type);

    if(pCurrentSettings != nullptr)
    {
        ConstraintSettings settings = pCurrentSettings->getSettings();

        // pass them down the line
        pModel->setConstraintSettings(settings);
    }

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
            pCurrentSettings = nullptr;
            break;
        }
        case BodyConstraintType::SPRING :
        {
            ui->widget_springSettings->show();
            ui->button_applySettings->show();
            pCurrentSettings = dynamic_cast<Settings*>(ui->widget_springSettings);
            break;
        }
        default :
        {
            // default to fixed
            ui->widget_springSettings->hide();
            ui->button_applySettings->hide();

            pCurrentSettings = nullptr;
            break;
        }
    }
}

void TabInfo::setMaxSphereCount(int num)
{
    pModel->setMaxSphereCount(num);
    pModel->reset();
}

void TabInfo::setSphereOverlap(bool enable)
{
    pModel->setSphereOverlap(enable);
    pModel->reset();
}

void TabInfo::setSphereMaxSize(double size)
{
    pModel->setMaxSphereSize(size);
    pModel->reset();
}

void TabInfo::setSphereMinSize(double size)
{
    pModel->setMinSphereSize(size);
    pModel->reset();
}

void TabInfo::applyConstraintSettings()
{
    if(pCurrentSettings == nullptr) return;

    ConstraintSettings settings = pCurrentSettings->getSettings();

    // pass them down the line
    pModel->setConstraintSettings(settings);

    pModel->createConstraints(); 
}
