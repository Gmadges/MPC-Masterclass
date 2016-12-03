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

    values.yUpperLimit = ui->spin_YUpper->value();
    values.yLowerLimit = ui->spin_YLower->value();

    values.zUpperLimit = ui->spin_ZUpper->value();
    values.zLowerLimit = ui->spin_ZLower->value();

    return values;
}