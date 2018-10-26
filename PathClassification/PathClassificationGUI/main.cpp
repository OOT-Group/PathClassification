#include "PathClassificationGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PathClassificationGUI w;
	w.show();
	return a.exec();
}
