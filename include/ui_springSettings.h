/********************************************************************************
** Form generated from reading UI file 'springSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRINGSETTINGS_H
#define UI_SPRINGSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpringSettings
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QWidget *SpringSettings)
    {
        if (SpringSettings->objectName().isEmpty())
            SpringSettings->setObjectName(QStringLiteral("SpringSettings"));
        SpringSettings->resize(281, 307);
        formLayout = new QFormLayout(SpringSettings);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(SpringSettings);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinBox = new QSpinBox(SpringSettings);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);


        retranslateUi(SpringSettings);

        QMetaObject::connectSlotsByName(SpringSettings);
    } // setupUi

    void retranslateUi(QWidget *SpringSettings)
    {
        SpringSettings->setWindowTitle(QApplication::translate("SpringSettings", "Form", 0));
        label->setText(QApplication::translate("SpringSettings", "test", 0));
    } // retranslateUi

};

namespace Ui {
    class SpringSettings: public Ui_SpringSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGSETTINGS_H
