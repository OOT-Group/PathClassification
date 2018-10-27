#pragma once
#include <QtWidgets/qlabel.h>
class TestLab:public QLabel
{
	Q_OBJECT
public:
	TestLab(QWidget * parent);

	~TestLab();
	public slots:
	void test();
};

