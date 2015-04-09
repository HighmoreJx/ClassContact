#ifndef GRADUATES_H
#define GRADUATES_H

#include <QtWidgets/QMainWindow>
#include "ui_graduates.h"

class Graduates : public QMainWindow
{
	Q_OBJECT

public:
	Graduates(QWidget *parent = 0);
	~Graduates();

private:
	Ui::GraduatesClass ui;
};

#endif // GRADUATES_H
