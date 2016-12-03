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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpringSettings
{
public:
    QFormLayout *formLayout;
    QLabel *label_2;
    QDoubleSpinBox *spin_XLower;
    QLabel *label_3;
    QDoubleSpinBox *spin_XUpper;
    QLabel *label_5;
    QDoubleSpinBox *spin_YLower;
    QLabel *label_6;
    QDoubleSpinBox *spin_YUpper;
    QLabel *label_8;
    QDoubleSpinBox *spin_ZLower;
    QLabel *label_9;
    QDoubleSpinBox *spin_ZUpper;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QWidget *SpringSettings)
    {
        if (SpringSettings->objectName().isEmpty())
            SpringSettings->setObjectName(QStringLiteral("SpringSettings"));
        SpringSettings->resize(313, 333);
        formLayout = new QFormLayout(SpringSettings);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(SpringSettings);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spin_XLower = new QDoubleSpinBox(SpringSettings);
        spin_XLower->setObjectName(QStringLiteral("spin_XLower"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spin_XLower);

        label_3 = new QLabel(SpringSettings);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spin_XUpper = new QDoubleSpinBox(SpringSettings);
        spin_XUpper->setObjectName(QStringLiteral("spin_XUpper"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spin_XUpper);

        label_5 = new QLabel(SpringSettings);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        spin_YLower = new QDoubleSpinBox(SpringSettings);
        spin_YLower->setObjectName(QStringLiteral("spin_YLower"));

        formLayout->setWidget(4, QFormLayout::FieldRole, spin_YLower);

        label_6 = new QLabel(SpringSettings);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        spin_YUpper = new QDoubleSpinBox(SpringSettings);
        spin_YUpper->setObjectName(QStringLiteral("spin_YUpper"));

        formLayout->setWidget(5, QFormLayout::FieldRole, spin_YUpper);

        label_8 = new QLabel(SpringSettings);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        spin_ZLower = new QDoubleSpinBox(SpringSettings);
        spin_ZLower->setObjectName(QStringLiteral("spin_ZLower"));

        formLayout->setWidget(7, QFormLayout::FieldRole, spin_ZLower);

        label_9 = new QLabel(SpringSettings);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        spin_ZUpper = new QDoubleSpinBox(SpringSettings);
        spin_ZUpper->setObjectName(QStringLiteral("spin_ZUpper"));

        formLayout->setWidget(8, QFormLayout::FieldRole, spin_ZUpper);

        label_7 = new QLabel(SpringSettings);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setTextFormat(Qt::RichText);
        label_7->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::SpanningRole, label_7);

        label_4 = new QLabel(SpringSettings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setTextFormat(Qt::RichText);
        label_4->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_4);

        label = new QLabel(SpringSettings);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);


        retranslateUi(SpringSettings);

        QMetaObject::connectSlotsByName(SpringSettings);
    } // setupUi

    void retranslateUi(QWidget *SpringSettings)
    {
        SpringSettings->setWindowTitle(QApplication::translate("SpringSettings", "Form", 0));
        label_2->setText(QApplication::translate("SpringSettings", "Lower Limit", 0));
        label_3->setText(QApplication::translate("SpringSettings", "Upper Limit", 0));
        label_5->setText(QApplication::translate("SpringSettings", "Lower Limit", 0));
        label_6->setText(QApplication::translate("SpringSettings", "Upper Limit", 0));
        label_8->setText(QApplication::translate("SpringSettings", "Lower Limit", 0));
        label_9->setText(QApplication::translate("SpringSettings", "Upper Limit", 0));
        label_7->setText(QApplication::translate("SpringSettings", "<b>Z Axis</b>", 0));
        label_4->setText(QApplication::translate("SpringSettings", "<b>Y Axis</b>", 0));
        label->setText(QApplication::translate("SpringSettings", "<b>X Axis</b>", 0));
    } // retranslateUi

};

namespace Ui {
    class SpringSettings: public Ui_SpringSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGSETTINGS_H
