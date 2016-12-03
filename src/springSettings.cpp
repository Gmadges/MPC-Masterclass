#include "springSettings.h"
#include "ui_springSettings.h"

SpringSettings::SpringSettings(QWidget *parent)
:
    Settings(parent),
        ui(new Ui::SpringSettings)
{
    ui->setupUi(this);
    initUI();
}

SpringSettings::~SpringSettings()
{
}

void SpringSettings::initUI()
{
    //TODO
}

ConstraintSettings SpringSettings::getSettings()
{
    ConstraintSettings values;

    values.xUpperLimit = ui->spin_XUpper->value();
    values.xLowerLimit = ui->spin_XLower->value();
    values.xSpringEnabled = ui->check_xSpringEnabled->checkState() == Qt::CheckState::Checked;
    values.xSpringStiffness = ui->spin_xSpringStiff->value();
    values.xSpringDamping = ui->spin_xSpringDamping->value();

    values.yUpperLimit = ui->spin_YUpper->value();
    values.yLowerLimit = ui->spin_YLower->value();
    values.ySpringEnabled = ui->check_ySpringEnabled->checkState() == Qt::CheckState::Checked;
    values.ySpringStiffness = ui->spin_ySpringStiff->value();
    values.ySpringDamping = ui->spin_ySpringDamping->value();

    values.zUpperLimit = ui->spin_ZUpper->value();
    values.zLowerLimit = ui->spin_ZLower->value();
    values.zSpringEnabled = ui->check_zSpringEnabled->checkState() == Qt::CheckState::Checked;
    values.zSpringStiffness = ui->spin_zSpringStiff->value();
    values.zSpringDamping = ui->spin_zSpringDamping->value();

    return values;
}