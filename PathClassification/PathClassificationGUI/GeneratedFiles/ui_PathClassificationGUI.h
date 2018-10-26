/********************************************************************************
** Form generated from reading UI file 'PathClassificationGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHCLASSIFICATIONGUI_H
#define UI_PATHCLASSIFICATIONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathClassificationGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PathClassificationGUIClass)
    {
        if (PathClassificationGUIClass->objectName().isEmpty())
            PathClassificationGUIClass->setObjectName(QStringLiteral("PathClassificationGUIClass"));
        PathClassificationGUIClass->resize(600, 400);
        menuBar = new QMenuBar(PathClassificationGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PathClassificationGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PathClassificationGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PathClassificationGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PathClassificationGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PathClassificationGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PathClassificationGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PathClassificationGUIClass->setStatusBar(statusBar);

        retranslateUi(PathClassificationGUIClass);

        QMetaObject::connectSlotsByName(PathClassificationGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *PathClassificationGUIClass)
    {
        PathClassificationGUIClass->setWindowTitle(QApplication::translate("PathClassificationGUIClass", "PathClassificationGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathClassificationGUIClass: public Ui_PathClassificationGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHCLASSIFICATIONGUI_H
