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
#include <QtWidgets/QCheckBox>
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
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *spin_XLower;
    QLabel *label_3;
    QDoubleSpinBox *spin_XUpper;
    QLabel *label_10;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *spin_YLower;
    QLabel *label_6;
    QDoubleSpinBox *spin_YUpper;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *spin_ZLower;
    QLabel *label_9;
    QDoubleSpinBox *spin_ZUpper;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *spin_xSpringStiff;
    QDoubleSpinBox *spin_xSpringDamping;
    QCheckBox *check_xSpringEnabled;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QCheckBox *check_zSpringEnabled;
    QDoubleSpinBox *spin_zSpringStiff;
    QDoubleSpinBox *spin_zSpringDamping;
    QCheckBox *check_ySpringEnabled;
    QDoubleSpinBox *spin_ySpringStiff;
    QDoubleSpinBox *spin_ySpringDamping;

    void setupUi(QWidget *SpringSettings)
    {
        if (SpringSettings->objectName().isEmpty())
            SpringSettings->setObjectName(QStringLiteral("SpringSettings"));
        SpringSettings->resize(302, 558);
        formLayout = new QFormLayout(SpringSettings);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(SpringSettings);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        label_2 = new QLabel(SpringSettings);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spin_XLower = new QDoubleSpinBox(SpringSettings);
        spin_XLower->setObjectName(QStringLiteral("spin_XLower"));
        spin_XLower->setMinimum(-1e+07);
        spin_XLower->setMaximum(1e+07);

        formLayout->setWidget(1, QFormLayout::FieldRole, spin_XLower);

        label_3 = new QLabel(SpringSettings);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spin_XUpper = new QDoubleSpinBox(SpringSettings);
        spin_XUpper->setObjectName(QStringLiteral("spin_XUpper"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spin_XUpper);

        label_10 = new QLabel(SpringSettings);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_10);

        label_4 = new QLabel(SpringSettings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setTextFormat(Qt::RichText);
        label_4->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::SpanningRole, label_4);

        label_5 = new QLabel(SpringSettings);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        spin_YLower = new QDoubleSpinBox(SpringSettings);
        spin_YLower->setObjectName(QStringLiteral("spin_YLower"));
        spin_YLower->setMinimum(-1e+07);
        spin_YLower->setMaximum(1e+07);

        formLayout->setWidget(7, QFormLayout::FieldRole, spin_YLower);

        label_6 = new QLabel(SpringSettings);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        spin_YUpper = new QDoubleSpinBox(SpringSettings);
        spin_YUpper->setObjectName(QStringLiteral("spin_YUpper"));
        spin_YUpper->setMinimum(-1e+07);
        spin_YUpper->setMaximum(1e+07);

        formLayout->setWidget(8, QFormLayout::FieldRole, spin_YUpper);

        label_7 = new QLabel(SpringSettings);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setTextFormat(Qt::RichText);
        label_7->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(12, QFormLayout::SpanningRole, label_7);

        label_8 = new QLabel(SpringSettings);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_8);

        spin_ZLower = new QDoubleSpinBox(SpringSettings);
        spin_ZLower->setObjectName(QStringLiteral("spin_ZLower"));
        spin_ZLower->setMinimum(-1e+07);
        spin_ZLower->setValue(0);

        formLayout->setWidget(13, QFormLayout::FieldRole, spin_ZLower);

        label_9 = new QLabel(SpringSettings);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(14, QFormLayout::LabelRole, label_9);

        spin_ZUpper = new QDoubleSpinBox(SpringSettings);
        spin_ZUpper->setObjectName(QStringLiteral("spin_ZUpper"));
        spin_ZUpper->setMinimum(-1e+07);
        spin_ZUpper->setMaximum(1e+07);

        formLayout->setWidget(14, QFormLayout::FieldRole, spin_ZUpper);

        label_11 = new QLabel(SpringSettings);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(SpringSettings);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_12);

        spin_xSpringStiff = new QDoubleSpinBox(SpringSettings);
        spin_xSpringStiff->setObjectName(QStringLiteral("spin_xSpringStiff"));
        spin_xSpringStiff->setMinimum(-1e+07);
        spin_xSpringStiff->setMaximum(1e+07);

        formLayout->setWidget(4, QFormLayout::FieldRole, spin_xSpringStiff);

        spin_xSpringDamping = new QDoubleSpinBox(SpringSettings);
        spin_xSpringDamping->setObjectName(QStringLiteral("spin_xSpringDamping"));
        spin_xSpringDamping->setMinimum(-1e+07);
        spin_xSpringDamping->setMaximum(1e+07);

        formLayout->setWidget(5, QFormLayout::FieldRole, spin_xSpringDamping);

        check_xSpringEnabled = new QCheckBox(SpringSettings);
        check_xSpringEnabled->setObjectName(QStringLiteral("check_xSpringEnabled"));

        formLayout->setWidget(3, QFormLayout::FieldRole, check_xSpringEnabled);

        label_13 = new QLabel(SpringSettings);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(SpringSettings);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(SpringSettings);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(SpringSettings);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout->setWidget(15, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(SpringSettings);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout->setWidget(16, QFormLayout::LabelRole, label_17);

        label_18 = new QLabel(SpringSettings);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout->setWidget(17, QFormLayout::LabelRole, label_18);

        check_zSpringEnabled = new QCheckBox(SpringSettings);
        check_zSpringEnabled->setObjectName(QStringLiteral("check_zSpringEnabled"));

        formLayout->setWidget(15, QFormLayout::FieldRole, check_zSpringEnabled);

        spin_zSpringStiff = new QDoubleSpinBox(SpringSettings);
        spin_zSpringStiff->setObjectName(QStringLiteral("spin_zSpringStiff"));
        spin_zSpringStiff->setMinimum(-1e+07);
        spin_zSpringStiff->setMaximum(1e+07);

        formLayout->setWidget(16, QFormLayout::FieldRole, spin_zSpringStiff);

        spin_zSpringDamping = new QDoubleSpinBox(SpringSettings);
        spin_zSpringDamping->setObjectName(QStringLiteral("spin_zSpringDamping"));
        spin_zSpringDamping->setMinimum(-1e+07);
        spin_zSpringDamping->setMaximum(1e+07);

        formLayout->setWidget(17, QFormLayout::FieldRole, spin_zSpringDamping);

        check_ySpringEnabled = new QCheckBox(SpringSettings);
        check_ySpringEnabled->setObjectName(QStringLiteral("check_ySpringEnabled"));

        formLayout->setWidget(9, QFormLayout::FieldRole, check_ySpringEnabled);

        spin_ySpringStiff = new QDoubleSpinBox(SpringSettings);
        spin_ySpringStiff->setObjectName(QStringLiteral("spin_ySpringStiff"));
        spin_ySpringStiff->setMinimum(-1e+07);
        spin_ySpringStiff->setMaximum(1e+07);

        formLayout->setWidget(10, QFormLayout::FieldRole, spin_ySpringStiff);

        spin_ySpringDamping = new QDoubleSpinBox(SpringSettings);
        spin_ySpringDamping->setObjectName(QStringLiteral("spin_ySpringDamping"));
        spin_ySpringDamping->setMinimum(-1e+07);
        spin_ySpringDamping->setMaximum(1e+07);

        formLayout->setWidget(11, QFormLayout::FieldRole, spin_ySpringDamping);


        retranslateUi(SpringSettings);

        QMetaObject::connectSlotsByName(SpringSettings);
    } // setupUi

    void retranslateUi(QWidget *SpringSettings)
    {
        SpringSettings->setWindowTitle(QApplication::translate("SpringSettings", "Form", 0));
        label->setText(QApplication::translate("SpringSettings", "<b>X Axis</b>", 0));
        label_2->setText(QApplication::translate("SpringSettings", "Lower Limit", 0));
        label_3->setText(QApplication::translate("SpringSettings", "Upper Limit", 0));
        label_10->setText(QApplication::translate("SpringSettings", "Enable Spring", 0));
        label_4->setText(QApplication::translate("SpringSettings", "<b>Y Axis</b>", 0));
        label_5->setText(QApplication::translate("SpringSettings", "Lower Limit", 0));
        label_6->setText(QApplication::translate("SpringSettings", "Upper Limit", 0));
        label_7->setText(QApplication::translate("SpringSettings", "<b>Z Axis</b>", 0));
        label_8->setText(QApplication::translate("SpringSettings", "Lower Limit", 0));
        label_9->setText(QApplication::translate("SpringSettings", "Upper Limit", 0));
        label_11->setText(QApplication::translate("SpringSettings", "Spring Stiffness", 0));
        label_12->setText(QApplication::translate("SpringSettings", "Spring Damping", 0));
        check_xSpringEnabled->setText(QString());
        label_13->setText(QApplication::translate("SpringSettings", "Enable Spring", 0));
        label_14->setText(QApplication::translate("SpringSettings", "Spring Stiffness", 0));
        label_15->setText(QApplication::translate("SpringSettings", "Spring Damping", 0));
        label_16->setText(QApplication::translate("SpringSettings", "Enable Spring", 0));
        label_17->setText(QApplication::translate("SpringSettings", "Spring Stiffness", 0));
        label_18->setText(QApplication::translate("SpringSettings", "Spring Damping", 0));
        check_zSpringEnabled->setText(QString());
        check_ySpringEnabled->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SpringSettings: public Ui_SpringSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGSETTINGS_H
