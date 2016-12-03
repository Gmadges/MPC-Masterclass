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
    //TODO
    return ConstraintSettings();
}