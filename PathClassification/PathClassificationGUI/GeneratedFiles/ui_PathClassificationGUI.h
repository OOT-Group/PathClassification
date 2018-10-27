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
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "TestLab.h"
#include "testbtn.h"

QT_BEGIN_NAMESPACE

class Ui_PathClassificationGUIClass
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    testbtn *pushButton;
    TestLab *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PathClassificationGUIClass)
    {
        if (PathClassificationGUIClass->objectName().isEmpty())
            PathClassificationGUIClass->setObjectName(QStringLiteral("PathClassificationGUIClass"));
        PathClassificationGUIClass->resize(600, 400);
        centralWidget = new QWidget(PathClassificationGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 601, 341));
        frame->setCursor(QCursor(Qt::ArrowCursor));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new testbtn(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 180, 75, 23));
        label = new TestLab(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 150, 54, 12));
        PathClassificationGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PathClassificationGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        PathClassificationGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PathClassificationGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PathClassificationGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PathClassificationGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PathClassificationGUIClass->setStatusBar(statusBar);

        retranslateUi(PathClassificationGUIClass);
        QObject::connect(pushButton, SIGNAL(clicked()), label, SLOT(test()));

        QMetaObject::connectSlotsByName(PathClassificationGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *PathClassificationGUIClass)
    {
        PathClassificationGUIClass->setWindowTitle(QApplication::translate("PathClassificationGUIClass", "PathClassificationGUI", nullptr));
        pushButton->setText(QApplication::translate("PathClassificationGUIClass", "PushButton", nullptr));
        label->setText(QApplication::translate("PathClassificationGUIClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathClassificationGUIClass: public Ui_PathClassificationGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHCLASSIFICATIONGUI_H
