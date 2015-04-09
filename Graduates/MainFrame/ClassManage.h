#ifndef _CLASS_MANAGE_H_
#define _CLASS_MANAGE_H_

/*
	功能：实现班级管理的功能
*/

#include <QWidget>
#include "ToolClass/ToolClass.h"
#include <map>
#include <memory>

class QLabel;
class QListWidget;
class QPushButton;
class QStackedWidget;
class ClientInfo;
class QListWidgetItem;

#include <QPushButton>

class clientListItem : public QWidget
{
	Q_OBJECT
public:
	clientListItem(QString className, bool multi = true, QWidget* parent = 0);
	~clientListItem(){};

	void setText(QString btnText){ itemBtn->setText(btnText); }

	void setBtnShow(bool val)
	{
		if (val)
			itemBtn->show();
		else
			itemBtn->hide();
	}

	void setClientName(QString val) { clientName_ = val; }
	void setClientId(int val) { clientId_ = val; }
	QString getClientName(){ return clientName_; }
	int getClientId() { return clientId_; }
	
private slots:
	void itemBtnClicked();
	void agrBtnClicked();
	void disAgrBtnClicked();

signals:
	void chooseClassName(QString sigClassName);
	void cancelClassName(QString sigClassName);

	void agreeClassSig(QString sigClassName, int sigClientId, QString sigClientName);
	void disagreeClassSig(QString sigClassName, int sigClientId, QString sigClientName);
	void quitClass(QString sigQuitClass);
	void endClass(QString sigEndClass);

private:
	QString className_;
	QPushButton* itemBtn;

	QPushButton* agreeBtn;
	QPushButton* disagreeBtn;

	QString clientName_;
	int clientId_;
};

class ClassManage : public QWidget
{
	Q_OBJECT
public:
	explicit ClassManage(QWidget* parent = 0);
	~ClassManage();

	void initStyle();


private slots:
	void ownClassBtnClicked();
	void joinedClassBtnClicked();
	void createListBtnClicked();

	void createClassSlot(QString classname);


	void allClassItemClicked(QListWidgetItem* item);
	void ownClassItemClicked(QListWidgetItem* item);
	//void joinedClassItemClicked(QListWidgetItem* item);
	void applyToClass(QString classname);
	void cancelApply(QString classname);

	void agreeJoinClass(QString className, int clientNo, QString clientName);
	void disagreeJoinClass(QString className, int clientNo, QString clientName);

	void quitJoinedClass(QString className);
	void endJoinedClass(QString className);
private:
	bool init();
	void initOwnClassList();
	void initJoinClassList();
	void initAllClassList();
	void getData();
	void insertoAllClasslist(QString classname);

	//从申请list中删除对应的项目
	void eraseFromList(QString clientNo);
private:
	QPushButton* ownClassBtn;
	QPushButton* joinedClassBtn;
	QStackedWidget* classTableWidget;
	QListWidget* joinedList;
	QListWidget* ownList;
	QLabel* classesLabel;
	QListWidget* classesList;
	QPushButton* createListBtn;
	QListWidget* detailList;

	CreateClassDialog* dialog;

	//键为班级的名称，值为对应的一个班级成员个体
	//multimap可以运行键重复
	std::multimap<std::string , std::shared_ptr<ClientInfo>> clientMap;
};


#endif //_CLASS_MANAGE_H_