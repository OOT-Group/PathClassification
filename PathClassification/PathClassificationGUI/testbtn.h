#pragma once
#include <QtWidgets/QPushButton>
class testbtn:public QPushButton
{
	Q_OBJECT
public:
	testbtn();
	testbtn(QWidget *parent = Q_NULLPTR);
	~testbtn();
	public slots:
	void test();
};

