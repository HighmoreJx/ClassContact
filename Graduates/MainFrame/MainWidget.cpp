#include "MainFrame/MainWidget.h"
#include "MainFrame/PersonalInfo.h"
#include "MainFrame/ClassManage.h"
#include "MainFrame/Infosearch.h"
#include "MainFrame/LeaveMessage.h"
#include "MainFrame/TR.h"

MainWidget::MainWidget(QWidget* parent)
{
	personalInfo = NULL;
	classManage = NULL;
	infoSearch = NULL;
	leaveMessage = NULL;
	infoBtn = NULL;
	classManageBtn = NULL;
	infoSearchBtn = NULL;
	leaveMsgBtn = NULL;
	vline = NULL;
	manageStackedWidget = NULL;
	initStyle();
	init();
}

MainWidget::~MainWidget()
{

}

bool MainWidget::init()
{

	if (!manageStackedWidget)
	{
		manageStackedWidget = new QStackedWidget();
	}

	if (!personalInfo)
	{
		personalInfo = new PersonalInfo();
		manageStackedWidget->addWidget(personalInfo);
	}
	if (!classManage)
	{
		classManage = new ClassManage();
		manageStackedWidget->addWidget(classManage);
	}
	if (!infoSearch)
	{
		infoSearch = new InfoSearch();
		manageStackedWidget->addWidget(infoSearch);
	}
	if (!leaveMessage)
	{
		leaveMessage = new LeaveMessage();
		manageStackedWidget->addWidget(leaveMessage);
	}
	QFont font;
	font.setFamily(TR("华文彩云"));
	font.setPointSize(13);
	if (!infoBtn)
	{
		infoBtn = new QPushButton();
		infoBtn->setFont(font);
		infoBtn->setText(TR("个人信息"));
		infoBtn->setObjectName("choiceBtn");
		infoBtn->setFixedSize(105, 37);
		connect(infoBtn, SIGNAL(clicked()), this, SLOT(infoBtnClicked()));
	}
	if (!classManageBtn)
	{
		classManageBtn = new QPushButton();
		classManageBtn->setText(TR("班级管理"));
		classManageBtn->setFont(font);
		classManageBtn->setObjectName("choiceBtn");
		classManageBtn->setFixedSize(105, 37);
		connect(classManageBtn, SIGNAL(clicked()), this, SLOT(classManageBtnClicked()));
	}
	if (!infoSearchBtn)
	{
		infoSearchBtn = new QPushButton();
		infoSearchBtn->setText(TR("信息检索"));
		infoSearchBtn->setFont(font);
		infoSearchBtn->setObjectName("choiceBtn");
		infoSearchBtn->setFixedSize(105, 37);
		connect(infoSearchBtn, SIGNAL(clicked()), this, SLOT(infoSearchBtnClicked()));
	}
	if (!leaveMsgBtn)
	{
		leaveMsgBtn = new QPushButton();
		leaveMsgBtn->setText(TR("留 言"));
		leaveMsgBtn->setFont(font);
		leaveMsgBtn->setObjectName("choiceBtn");
		leaveMsgBtn->setFixedSize(105, 37);
		connect(leaveMsgBtn, SIGNAL(clicked()), this, SLOT(leaveMsgBtnClicked()));
	}
	if (!vline)
	{
		vline = new QFrame();
		vline->setFrameStyle(QFrame::VLine);
		vline->setFrameShadow(QFrame::Sunken);
	}

	QVBoxLayout* btnLayout = new QVBoxLayout();
	btnLayout->addWidget(infoBtn);
	btnLayout->addWidget(classManageBtn);
	btnLayout->addWidget(infoSearchBtn);
	btnLayout->addWidget(leaveMsgBtn);

	QHBoxLayout* mainLayout = new QHBoxLayout();
	mainLayout->addLayout(btnLayout);
	mainLayout->addWidget(vline);
	mainLayout->addWidget(manageStackedWidget);

	QWidget* mainWidget = new QWidget();
	mainWidget->setLayout(mainLayout);
	this->setCentralWidget(mainWidget);
	
	infoBtnClicked();
	return true;
}

void MainWidget::infoBtnClicked()
{
	manageStackedWidget->setCurrentIndex(0);
	personalInfo->updateInfo();
}

void MainWidget::classManageBtnClicked()
{
	manageStackedWidget->setCurrentIndex(1);
}

void MainWidget::infoSearchBtnClicked()
{
	manageStackedWidget->setCurrentIndex(2);
	infoSearch->update();
}

void MainWidget::leaveMsgBtnClicked()
{
	manageStackedWidget->setCurrentIndex(3);
}

void MainWidget::initStyle()
{
	QFile file(":/Graduates/Resources/mainFrame.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}

