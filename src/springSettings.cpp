#include "springSettings.h"
#include "ui_springSettings.h"

SpringSettings::SpringSettings(QWidget *parent)
:
    QWidget(parent),
    ui(new Ui::SpringSettings)
{
    ui->setupUi(this);
}

SpringSettings::~SpringSettings()
{

}