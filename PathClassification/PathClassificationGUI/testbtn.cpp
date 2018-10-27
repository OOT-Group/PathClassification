
#include "testbtn.h"
#include "PathClassificationGUI.h"
testbtn::testbtn()
{
}

testbtn::testbtn(QWidget * parent):QPushButton(parent)
{

	QMetaObject::Connection  c= QObject::connect(this, SIGNAL(clicked()),this , SLOT(test()));
	
}

void testbtn::test()
{
		this->setText("Hello World");
		
	return ;
}


testbtn::~testbtn()
{
}
