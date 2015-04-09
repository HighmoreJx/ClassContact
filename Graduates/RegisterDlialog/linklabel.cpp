#include "linklabel.h"
#include <QDesktopServices>
#include <QFile>
#include <QtWidgets/QtWidgets>
/*
	下划线蓝色Label
*/
LinkLabel::LinkLabel(QWidget *parent)
	: QToolButton(parent)
{
	setObjectName("LinkLabel");
	initStyle();
	setCursor(Qt::PointingHandCursor);		//设置鼠标形状
	m_isLink = true;
}

LinkLabel::~LinkLabel()
{
}
void LinkLabel::initStyle()  // 加载qss 
{
	QFile file(":/Graduates/Resources/tab.qss");
	//QFile file(":/tab.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}