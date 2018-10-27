#include "PathClassificationGUI.h"

PathClassificationGUI::PathClassificationGUI(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	
}

Ui::PathClassificationGUIClass* PathClassificationGUI::GetUi()
{
	return &ui;
}
