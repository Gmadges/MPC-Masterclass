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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "springSettings.h"

QT_BEGIN_NAMESPACE

class Ui_TabInfo
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QPushButton *button_reset;
    QCheckBox *check_showMesh;
    QCheckBox *check_showPhys;
    QFrame *line_2;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *check_sphereOverlap;
    QLabel *label_4;
    QSpinBox *spin_maxSphereCount;
    QLabel *label_6;
    QDoubleSpinBox *spin_maxSphereSize;
    QLabel *label_7;
    QDoubleSpinBox *spin_minSphereSize;
    QFrame *line;
    QLabel *label;
    QLabel *label_5;
    QComboBox *combo_constType;
    QScrollArea *scrollArea;
    SpringSettings *widget_springSettings;
    QPushButton *button_applySettings;

    void setupUi(QWidget *TabInfo)
    {
        if (TabInfo->objectName().isEmpty())
            TabInfo->setObjectName(QStringLiteral("TabInfo"));
        TabInfo->resize(336, 434);
        gridLayout_2 = new QGridLayout(TabInfo);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        button_reset = new QPushButton(TabInfo);
        button_reset->setObjectName(QStringLiteral("button_reset"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, button_reset);

        check_showMesh = new QCheckBox(TabInfo);
        check_showMesh->setObjectName(QStringLiteral("check_showMesh"));
        check_showMesh->setChecked(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, check_showMesh);

        check_showPhys = new QCheckBox(TabInfo);
        check_showPhys->setObjectName(QStringLiteral("check_showPhys"));
        check_showPhys->setChecked(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, check_showPhys);

        line_2 = new QFrame(TabInfo);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        formLayout->setWidget(5, QFormLayout::SpanningRole, line_2);

        label_2 = new QLabel(TabInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::SpanningRole, label_2);

        label_3 = new QLabel(TabInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        check_sphereOverlap = new QCheckBox(TabInfo);
        check_sphereOverlap->setObjectName(QStringLiteral("check_sphereOverlap"));

        formLayout->setWidget(7, QFormLayout::FieldRole, check_sphereOverlap);

        label_4 = new QLabel(TabInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_4);

        spin_maxSphereCount = new QSpinBox(TabInfo);
        spin_maxSphereCount->setObjectName(QStringLiteral("spin_maxSphereCount"));
        spin_maxSphereCount->setMinimum(1);
        spin_maxSphereCount->setMaximum(2147483647);

        formLayout->setWidget(8, QFormLayout::FieldRole, spin_maxSphereCount);

        label_6 = new QLabel(TabInfo);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_6);

        spin_maxSphereSize = new QDoubleSpinBox(TabInfo);
        spin_maxSphereSize->setObjectName(QStringLiteral("spin_maxSphereSize"));
        spin_maxSphereSize->setMaximum(1e+18);

        formLayout->setWidget(9, QFormLayout::FieldRole, spin_maxSphereSize);

        label_7 = new QLabel(TabInfo);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_7);

        spin_minSphereSize = new QDoubleSpinBox(TabInfo);
        spin_minSphereSize->setObjectName(QStringLiteral("spin_minSphereSize"));
        spin_minSphereSize->setMinimum(0.01);
        spin_minSphereSize->setMaximum(1e+14);

        formLayout->setWidget(10, QFormLayout::FieldRole, spin_minSphereSize);

        line = new QFrame(TabInfo);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        formLayout->setWidget(11, QFormLayout::SpanningRole, line);

        label = new QLabel(TabInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(12, QFormLayout::SpanningRole, label);

        label_5 = new QLabel(TabInfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_5);

        combo_constType = new QComboBox(TabInfo);
        combo_constType->setObjectName(QStringLiteral("combo_constType"));

        formLayout->setWidget(13, QFormLayout::FieldRole, combo_constType);

        scrollArea = new QScrollArea(TabInfo);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        widget_springSettings = new SpringSettings();
        widget_springSettings->setObjectName(QStringLiteral("widget_springSettings"));
        widget_springSettings->setGeometry(QRect(0, 0, 314, 73));
        scrollArea->setWidget(widget_springSettings);

        formLayout->setWidget(15, QFormLayout::SpanningRole, scrollArea);

        button_applySettings = new QPushButton(TabInfo);
        button_applySettings->setObjectName(QStringLiteral("button_applySettings"));

        formLayout->setWidget(16, QFormLayout::SpanningRole, button_applySettings);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);


        retranslateUi(TabInfo);

        QMetaObject::connectSlotsByName(TabInfo);
    } // setupUi

    void retranslateUi(QWidget *TabInfo)
    {
        TabInfo->setWindowTitle(QApplication::translate("TabInfo", "Form", 0));
        button_reset->setText(QApplication::translate("TabInfo", "Reset", 0));
        check_showMesh->setText(QApplication::translate("TabInfo", "show Mesh", 0));
        check_showPhys->setText(QApplication::translate("TabInfo", "show Phys", 0));
        label_2->setText(QApplication::translate("TabInfo", "<b>Spheres</b>", 0));
        label_3->setText(QApplication::translate("TabInfo", "Enable Overlap", 0));
        check_sphereOverlap->setText(QString());
        label_4->setText(QApplication::translate("TabInfo", "Max Sphere Count", 0));
        label_6->setText(QApplication::translate("TabInfo", "Max Sphere Size", 0));
        label_7->setText(QApplication::translate("TabInfo", "Min Sphere Size", 0));
        label->setText(QApplication::translate("TabInfo", "<b>Constraints</b>", 0));
        label_5->setText(QApplication::translate("TabInfo", "Type", 0));
        button_applySettings->setText(QApplication::translate("TabInfo", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class TabInfo: public Ui_TabInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABINFO_H
