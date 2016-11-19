/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glscene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *button_toggleSim;
    QPushButton *button_resetSim;
    QPushButton *button_loadFile;
    QCheckBox *check_showMesh;
    QCheckBox *check_showPhys;
    QSpacerItem *verticalSpacer;
    GLScene *scene;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1084, 713);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        button_toggleSim = new QPushButton(centralWidget);
        button_toggleSim->setObjectName(QStringLiteral("button_toggleSim"));

        verticalLayout->addWidget(button_toggleSim);

        button_resetSim = new QPushButton(centralWidget);
        button_resetSim->setObjectName(QStringLiteral("button_resetSim"));

        verticalLayout->addWidget(button_resetSim);

        button_loadFile = new QPushButton(centralWidget);
        button_loadFile->setObjectName(QStringLiteral("button_loadFile"));

        verticalLayout->addWidget(button_loadFile);

        check_showMesh = new QCheckBox(centralWidget);
        check_showMesh->setObjectName(QStringLiteral("check_showMesh"));
        check_showMesh->setChecked(true);

        verticalLayout->addWidget(check_showMesh);

        check_showPhys = new QCheckBox(centralWidget);
        check_showPhys->setObjectName(QStringLiteral("check_showPhys"));
        check_showPhys->setChecked(true);

        verticalLayout->addWidget(check_showPhys);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);

        scene = new GLScene(centralWidget);
        scene->setObjectName(QStringLiteral("scene"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scene->sizePolicy().hasHeightForWidth());
        scene->setSizePolicy(sizePolicy);
        scene->setMinimumSize(QSize(0, 0));
        scene->setMaximumSize(QSize(1920, 1080));

        gridLayout->addWidget(scene, 0, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        button_toggleSim->setText(QApplication::translate("MainWindow", "Toggle Sim", 0));
        button_resetSim->setText(QApplication::translate("MainWindow", "Reset", 0));
        button_loadFile->setText(QApplication::translate("MainWindow", "Load File", 0));
        check_showMesh->setText(QApplication::translate("MainWindow", "show mesh", 0));
        check_showPhys->setText(QApplication::translate("MainWindow", "show phys", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
