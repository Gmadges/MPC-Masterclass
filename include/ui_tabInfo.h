/********************************************************************************
** Form generated from reading UI file 'tabInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABINFO_H
#define UI_TABINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "springSettings.h"

QT_BEGIN_NAMESPACE

class Ui_TabInfo
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QCheckBox *check_showPhys;
    QCheckBox *check_showMesh;
    QPushButton *button_reset;
    QComboBox *combo_constType;
    SpringSettings *widget_springSettings;

    void setupUi(QWidget *TabInfo)
    {
        if (TabInfo->objectName().isEmpty())
            TabInfo->setObjectName(QStringLiteral("TabInfo"));
        TabInfo->resize(336, 226);
        gridLayout_2 = new QGridLayout(TabInfo);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        check_showPhys = new QCheckBox(TabInfo);
        check_showPhys->setObjectName(QStringLiteral("check_showPhys"));
        check_showPhys->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, check_showPhys);

        check_showMesh = new QCheckBox(TabInfo);
        check_showMesh->setObjectName(QStringLiteral("check_showMesh"));
        check_showMesh->setChecked(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, check_showMesh);

        button_reset = new QPushButton(TabInfo);
        button_reset->setObjectName(QStringLiteral("button_reset"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, button_reset);

        combo_constType = new QComboBox(TabInfo);
        combo_constType->setObjectName(QStringLiteral("combo_constType"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, combo_constType);

        widget_springSettings = new SpringSettings(TabInfo);
        widget_springSettings->setObjectName(QStringLiteral("widget_springSettings"));

        formLayout->setWidget(4, QFormLayout::LabelRole, widget_springSettings);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);


        retranslateUi(TabInfo);

        QMetaObject::connectSlotsByName(TabInfo);
    } // setupUi

    void retranslateUi(QWidget *TabInfo)
    {
        TabInfo->setWindowTitle(QApplication::translate("TabInfo", "Form", 0));
        check_showPhys->setText(QApplication::translate("TabInfo", "show Phys", 0));
        check_showMesh->setText(QApplication::translate("TabInfo", "show Mesh", 0));
        button_reset->setText(QApplication::translate("TabInfo", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class TabInfo: public Ui_TabInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABINFO_H
