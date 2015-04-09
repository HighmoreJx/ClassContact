#include "linklabel.h"
#include <QDesktopServices>
#include <QFile>
#include <QtWidgets/QtWidgets>
/*
	�»�����ɫLabel
*/
LinkLabel::LinkLabel(QWidget *parent)
	: QToolButton(parent)
{
	setObjectName("LinkLabel");
	initStyle();
	setCursor(Qt::PointingHandCursor);		//���������״
	m_isLink = true;
}

LinkLabel::~LinkLabel()
{
}
void LinkLabel::initStyle()  // ����qss 
{
	QFile file(":/Graduates/Resources/tab.qss");
	//QFile file(":/tab.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}