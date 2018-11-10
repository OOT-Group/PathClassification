#include "PathClassificationGUI.h"

PathClassificationGUI::PathClassificationGUI(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	Init();
}

Ui::PathClassificationGUIClass* PathClassificationGUI::GetUi()
{
	return &ui;
}

void PathClassificationGUI::Init()
{
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮

	setFixedSize(this->width(), this->height());                     // 禁止拖动窗口大小
	ui.drawArea->setStyleSheet("background: white;");
	ui.drawArea->Init();

	QObject::connect(ui.undoBtn, SIGNAL(clicked()), ui.drawArea, SLOT(Undo()));
	QObject::connect(ui.clearBtn, SIGNAL(clicked()), ui.drawArea, SLOT(Clear()));
	QObject::connect(ui.classifyBtn, SIGNAL(clicked()), ui.drawArea, SLOT(Classify()));
}

