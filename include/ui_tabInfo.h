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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "springSettings.h"

QT_BEGIN_NAMESPACE

class Ui_TabInfo
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    SpringSettings *widget_springSettings;
    QCheckBox *check_showMesh;
    QCheckBox *check_showPhys;
    QPushButton *button_reset;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *check_sphereIntersect;
    QLabel *label_4;
    QSpinBox *spin_maxSpheres;
    QFrame *line;
    QFrame *line_2;
    QPushButton *button_applySettings;
    QLabel *label_5;
    QComboBox *combo_constType;

    void setupUi(QWidget *TabInfo)
    {
        if (TabInfo->objectName().isEmpty())
            TabInfo->setObjectName(QStringLiteral("TabInfo"));
        TabInfo->resize(336, 287);
        gridLayout_2 = new QGridLayout(TabInfo);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        widget_springSettings = new SpringSettings(TabInfo);
        widget_springSettings->setObjectName(QStringLiteral("widget_springSettings"));

        formLayout->setWidget(13, QFormLayout::SpanningRole, widget_springSettings);

        check_showMesh = new QCheckBox(TabInfo);
        check_showMesh->setObjectName(QStringLiteral("check_showMesh"));
        check_showMesh->setChecked(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, check_showMesh);

        check_showPhys = new QCheckBox(TabInfo);
        check_showPhys->setObjectName(QStringLiteral("check_showPhys"));
        check_showPhys->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, check_showPhys);

        button_reset = new QPushButton(TabInfo);
        button_reset->setObjectName(QStringLiteral("button_reset"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, button_reset);

        label = new QLabel(TabInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(10, QFormLayout::SpanningRole, label);

        label_2 = new QLabel(TabInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::SpanningRole, label_2);

        label_3 = new QLabel(TabInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        check_sphereIntersect = new QCheckBox(TabInfo);
        check_sphereIntersect->setObjectName(QStringLiteral("check_sphereIntersect"));

        formLayout->setWidget(7, QFormLayout::FieldRole, check_sphereIntersect);

        label_4 = new QLabel(TabInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        spin_maxSpheres = new QSpinBox(TabInfo);
        spin_maxSpheres->setObjectName(QStringLiteral("spin_maxSpheres"));

        formLayout->setWidget(8, QFormLayout::FieldRole, spin_maxSpheres);

        line = new QFrame(TabInfo);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        formLayout->setWidget(9, QFormLayout::SpanningRole, line);

        line_2 = new QFrame(TabInfo);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        formLayout->setWidget(5, QFormLayout::SpanningRole, line_2);

        button_applySettings = new QPushButton(TabInfo);
        button_applySettings->setObjectName(QStringLiteral("button_applySettings"));

        formLayout->setWidget(15, QFormLayout::SpanningRole, button_applySettings);

        label_5 = new QLabel(TabInfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_5);

        combo_constType = new QComboBox(TabInfo);
        combo_constType->setObjectName(QStringLiteral("combo_constType"));

        formLayout->setWidget(11, QFormLayout::FieldRole, combo_constType);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);


        retranslateUi(TabInfo);

        QMetaObject::connectSlotsByName(TabInfo);
    } // setupUi

    void retranslateUi(QWidget *TabInfo)
    {
        TabInfo->setWindowTitle(QApplication::translate("TabInfo", "Form", 0));
        check_showMesh->setText(QApplication::translate("TabInfo", "show Mesh", 0));
        check_showPhys->setText(QApplication::translate("TabInfo", "show Phys", 0));
        button_reset->setText(QApplication::translate("TabInfo", "Reset", 0));
        label->setText(QApplication::translate("TabInfo", "<b>Constraints</b>", 0));
        label_2->setText(QApplication::translate("TabInfo", "<b>Spheres</b>", 0));
        label_3->setText(QApplication::translate("TabInfo", "Enable Intersections", 0));
        check_sphereIntersect->setText(QString());
        label_4->setText(QApplication::translate("TabInfo", "Max Spheres", 0));
        button_applySettings->setText(QApplication::translate("TabInfo", "Apply", 0));
        label_5->setText(QApplication::translate("TabInfo", "Type", 0));
    } // retranslateUi

};

namespace Ui {
    class TabInfo: public Ui_TabInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABINFO_H
