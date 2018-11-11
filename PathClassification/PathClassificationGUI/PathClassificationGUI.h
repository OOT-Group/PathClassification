#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PathClassificationGUI.h"

class PathClassificationGUI : public QMainWindow
{
	Q_OBJECT

public:
	PathClassificationGUI(QWidget *parent = Q_NULLPTR);
	Ui::PathClassificationGUIClass* GetUi();
	void Init();
	public slots:
	void UpdateDistance();
	void UpdateBend();
private:
	Ui::PathClassificationGUIClass ui;
};
