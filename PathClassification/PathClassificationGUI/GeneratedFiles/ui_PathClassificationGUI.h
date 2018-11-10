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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "drawwidget.h"

QT_BEGIN_NAMESPACE

class Ui_PathClassificationGUIClass
{
public:
    QWidget *centralWidget;
    DrawWidget *drawArea;
    QPushButton *clearBtn;
    QPushButton *undoBtn;
    QPushButton *classifyBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PathClassificationGUIClass)
    {
        if (PathClassificationGUIClass->objectName().isEmpty())
            PathClassificationGUIClass->setObjectName(QStringLiteral("PathClassificationGUIClass"));
        PathClassificationGUIClass->resize(600, 400);
        centralWidget = new QWidget(PathClassificationGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        drawArea = new DrawWidget(centralWidget);
        drawArea->setObjectName(QStringLiteral("drawArea"));
        drawArea->setGeometry(QRect(0, 0, 601, 321));
        clearBtn = new QPushButton(centralWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setGeometry(QRect(20, 330, 75, 23));
        undoBtn = new QPushButton(centralWidget);
        undoBtn->setObjectName(QStringLiteral("undoBtn"));
        undoBtn->setGeometry(QRect(160, 330, 75, 23));
        classifyBtn = new QPushButton(centralWidget);
        classifyBtn->setObjectName(QStringLiteral("classifyBtn"));
        classifyBtn->setGeometry(QRect(320, 330, 75, 23));
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
        clearBtn->setText(QApplication::translate("PathClassificationGUIClass", "Clear", nullptr));
        undoBtn->setText(QApplication::translate("PathClassificationGUIClass", "Undo", nullptr));
        classifyBtn->setText(QApplication::translate("PathClassificationGUIClass", "Classify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathClassificationGUIClass: public Ui_PathClassificationGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHCLASSIFICATIONGUI_H
