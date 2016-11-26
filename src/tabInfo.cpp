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
    ui->combo_constType->addItem("6DoF");
    ui->combo_constType->addItem("Spring");
    //default to fixed
    ui->combo_constType->setCurrentIndex(0);

    // add the settings for each type
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
   // probably shouldnt do this based on index but we know their order, its hardcoded
   // TODO make this nicer

   BodyConstraintType type;

   if(idx == 0)
   {
       type = BodyConstraintType::FIXED;
   }
   else if(idx == 1)
   {
       type = BodyConstraintType::SLIDER;
   }
   else if(idx == 2)
   {
       type = BodyConstraintType::SIX_DOF;
   }
   else if(idx == 3)
   {
       type = BodyConstraintType::SPRING;
   }
   
   pModel->createConstraints(type); 
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
    // TODO make this take into account constraint type
    pModel->reset();
}