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
	ui.distanceTxt->setText("50");
	ui.bendTxt->setText("0.5");
	QObject::connect(ui.undoBtn, SIGNAL(clicked()), ui.drawArea, SLOT(Undo()));
	QObject::connect(ui.clearBtn, SIGNAL(clicked()), ui.drawArea, SLOT(Clear()));
	QObject::connect(ui.classifyBtn, SIGNAL(clicked()), ui.drawArea, SLOT(Classify()));
	QObject::connect(ui.distanceTxt, SIGNAL(editingFinished()), this, SLOT(UpdateDistance()));
	QObject::connect(ui.bendTxt, SIGNAL(editingFinished()), this, SLOT(UpdateBend()));

}
void PathClassificationGUI::UpdateDistance()
{
	auto disstr=ui.distanceTxt->text();
	bool ok = false;
	int dis=disstr.toInt(&ok);
	if (ok) {
		ui.drawArea->UpdateDistance(dis);
	}

}
void PathClassificationGUI::UpdateBend()
{
	auto disstr = ui.bendTxt->text();
	bool ok = false;
	double bend = disstr.toDouble(&ok);
	if (ok) {
		ui.drawArea->UpdateBend(bend);
	}
}

