#include "springSettings.h"
#include "ui_settings.h"

#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

SpringSettings::SpringSettings(QWidget *parent)
:
    Settings(parent)
{
    initUI();
}

SpringSettings::~SpringSettings()
{
}

void SpringSettings::initUI()
{
    QLabel *label = new QLabel(this);
    label->setObjectName(QStringLiteral("label"));
    label->setText(QString("Testing"));

    ui->formLayout->setWidget(0, QFormLayout::LabelRole, label);

    QSpinBox *spinBox = new QSpinBox(this);
    spinBox->setObjectName(QStringLiteral("spinBox"));

    ui->formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);
}