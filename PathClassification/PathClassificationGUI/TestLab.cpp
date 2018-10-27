#include "TestLab.h"



TestLab::TestLab(QWidget * parent):QLabel(parent)
{

}


TestLab::~TestLab()
{
}
void TestLab::test()
{
	this->setText("Hello World");
	
	return;
}
