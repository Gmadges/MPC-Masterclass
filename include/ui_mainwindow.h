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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glscene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    GLScene *scene;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *button_toggleSim;
    QPushButton *button_resetSim;
    QPushButton *button_loadObject;
    QCheckBox *check_showMesh;
    QCheckBox *check_showPhys;
    QTabWidget *tabWidget_settings;

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

        MainWindow->setCentralWidget(centralWidget);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        button_toggleSim = new QPushButton(dockWidgetContents);
        button_toggleSim->setObjectName(QStringLiteral("button_toggleSim"));

        verticalLayout->addWidget(button_toggleSim);

        button_resetSim = new QPushButton(dockWidgetContents);
        button_resetSim->setObjectName(QStringLiteral("button_resetSim"));

        verticalLayout->addWidget(button_resetSim);

        button_loadObject = new QPushButton(dockWidgetContents);
        button_loadObject->setObjectName(QStringLiteral("button_loadObject"));

        verticalLayout->addWidget(button_loadObject);

        check_showMesh = new QCheckBox(dockWidgetContents);
        check_showMesh->setObjectName(QStringLiteral("check_showMesh"));
        check_showMesh->setEnabled(false);
        check_showMesh->setChecked(true);

        verticalLayout->addWidget(check_showMesh);

        check_showPhys = new QCheckBox(dockWidgetContents);
        check_showPhys->setObjectName(QStringLiteral("check_showPhys"));
        check_showPhys->setEnabled(false);
        check_showPhys->setChecked(true);

        verticalLayout->addWidget(check_showPhys);

        tabWidget_settings = new QTabWidget(dockWidgetContents);
        tabWidget_settings->setObjectName(QStringLiteral("tabWidget_settings"));
        tabWidget_settings->setTabsClosable(true);

        verticalLayout->addWidget(tabWidget_settings);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        retranslateUi(MainWindow);

        tabWidget_settings->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        button_toggleSim->setText(QApplication::translate("MainWindow", "Toggle Sim", 0));
        button_resetSim->setText(QApplication::translate("MainWindow", "Reset", 0));
        button_loadObject->setText(QApplication::translate("MainWindow", "Load Object", 0));
        check_showMesh->setText(QApplication::translate("MainWindow", "show all meshes", 0));
        check_showPhys->setText(QApplication::translate("MainWindow", "show all phys", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
