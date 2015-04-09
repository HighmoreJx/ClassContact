#ifndef _MAIN_WIDGET_H_
#define _MAIN_WIDGET_H_


/*
	功能： 系统主界面，包括个人信息管理，班级管理，信息检索，留言
*/


#include <QMainWindow>
#include <QtWidgets/QtWidgets>

class QFrame;
class PersonalInfo;
class ClassManage;
class InfoSearch;
class LeaveMessage;

class MainWidget :  public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWidget(QWidget* parent = 0);
	~MainWidget();

private:
	bool init();
	void initStyle();
	

private slots:
	void infoBtnClicked();
	void classManageBtnClicked();
	void infoSearchBtnClicked();
	void leaveMsgBtnClicked();
private:
	QStackedWidget* manageStackedWidget;

	PersonalInfo* personalInfo;
	ClassManage* classManage;
	InfoSearch* infoSearch;
	LeaveMessage* leaveMessage;

	QPushButton* infoBtn;
	QPushButton* classManageBtn;
	QPushButton* infoSearchBtn;
	QPushButton* leaveMsgBtn;

	QFrame* vline;
};

#endif //_MAIN_WIDGET_H_