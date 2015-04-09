#include "RegisterDlialog/Login.h"
//#include "MainFrame/MainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Login w;
	//RegisterDialog w;
	Login w;
	w.show();
	return a.exec();
}
 