#include "MainFrame/PersonalInfo.h"
#include <QtWidgets/QtWidgets>
#include "MainFrame/TR.h"
#include <QSqlQuery>
#include <QSqlError>
#include "ToolClass/DataBaseOpt.h"

PersonalInfo::PersonalInfo(QWidget* parent /*= 0*/)
{
	picLabel = NULL;
	nameLabel = NULL;
	classLabel = NULL;
	admissionLabel = NULL;
	qqnumberLabel = NULL;
	nameEdit = NULL;
	classEdit = NULL;
	admission = NULL;
	qqnumber = NULL;
	saveInfoBtn = NULL;
	init();
}

PersonalInfo::~PersonalInfo()
{}

bool PersonalInfo::init()
{
	picLabel = NULL;
	nameLabel = NULL;
	classLabel = NULL;
	admissionLabel = NULL;
	qqnumberLabel = NULL;
	nameEdit = NULL;
	classEdit = NULL;
	admission = NULL;
	qqnumber = NULL;
	saveInfoBtn = NULL;

	QFont font;
	font.setFamily(TR("微软雅黑"));
	font.setPointSize(13);
	if (!picLabel)
	{
		picLabel = new QLabel();
		QPixmap pix = QPixmap(":/Graduates/Resources/pic.png");
		picLabel->setPixmap(pix);
		picLabel->setFixedSize(250, 250);
	}
	if (!nameLabel)
	{
		nameLabel = new QLabel();
		nameLabel->setFont(font);
		nameLabel->setText(TR("姓    名:"));
	}
	if (!classLabel)
	{
		classLabel = new QLabel();
		classLabel->setFont(font);
		classLabel->setText(TR("班    级:"));
	}
	if (!admissionLabel)
	{
		admissionLabel = new QLabel();
		admissionLabel->setFont(font);
		admissionLabel->setText(TR("入校时间:"));
	}
	if (!qqnumberLabel)
	{
		qqnumberLabel = new QLabel();
		qqnumberLabel->setFont(font);
		qqnumberLabel->setText(TR("联系方式:"));
	}
	if (!nameEdit)
	{
		nameEdit = new QLineEdit();
		nameEdit->setFont(font);
		nameEdit->setFixedSize(110, 30);
	}
	if (!classEdit)
	{
		classEdit = new QLineEdit();
		classEdit->setFont(font);
		classEdit->setDisabled(true);
		classEdit->setFixedSize(110, 30);
	}
	if (!admission)
	{
		admission = new QLineEdit();
		admission->setFont(font);
		admission->setFixedSize(110, 30);
	}
	if (!qqnumber)
	{
		qqnumber = new QLineEdit();
		qqnumber->setFont(font);
		qqnumber->setFixedSize(110, 30);
	}
	if (!saveInfoBtn)
	{
		saveInfoBtn = new QPushButton();
		saveInfoBtn->setText(TR("保存"));
		saveInfoBtn->setFont(font);
		saveInfoBtn->setObjectName("saveBtn");
		saveInfoBtn->setFixedSize(110, 30);
		connect(saveInfoBtn, SIGNAL(clicked()), this, SLOT(saveInfoBtnClicked()));
	}


	QHBoxLayout* nameLayout = new QHBoxLayout();
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameEdit);
	nameLayout->setSpacing(10);

	QHBoxLayout* classLayout = new QHBoxLayout();
	classLayout->addWidget(classLabel);
	classLayout->addWidget(classEdit);
	classLayout->setSpacing(10);

	QHBoxLayout* admissionLayout = new QHBoxLayout();
	admissionLayout->addWidget(admissionLabel);
	admissionLayout->addWidget(admission);
	admissionLayout->setSpacing(10);

	QHBoxLayout* contactLayou = new QHBoxLayout();
	contactLayou->addWidget(qqnumberLabel);
	contactLayou->addWidget(qqnumber);
	contactLayou->setSpacing(10);

	QVBoxLayout* vlayout = new QVBoxLayout();
	vlayout->addLayout(nameLayout);
	vlayout->addLayout(classLayout);
	vlayout->addLayout(admissionLayout);
	vlayout->addLayout(contactLayou);

	QWidget* infoContainerWidget = new QWidget();
	infoContainerWidget->setFixedWidth(250);
	infoContainerWidget->setFixedHeight(250);
	infoContainerWidget->setLayout(vlayout);

	QHBoxLayout* topLayout = new QHBoxLayout();
	topLayout->addWidget(picLabel);
	topLayout->addWidget(infoContainerWidget);
	topLayout->setSpacing(0);

	QHBoxLayout* btnLayout = new QHBoxLayout();
	btnLayout->addWidget(saveInfoBtn);
	QWidget* containWidegt = new QWidget();
	containWidegt->setFixedHeight(60);
	containWidegt->setLayout(btnLayout);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(topLayout);
	mainLayout->addWidget(containWidegt);
	mainLayout->setSpacing(0);

	this->setLayout(mainLayout);

	return true;
}

void PersonalInfo::saveInfoBtnClicked()
{
	gclientName = nameEdit->text();
	gclassName = classEdit->text();
	gadmission = admission->text();
	gQQ = qqnumber->text();

	//更新数据库
	DatabaseOpt opt;
	QString updateSql = "UPDATE ClientExits set name=:name,classname=:classname,admission=:admission,QQ=:qq where id = :id";
	QSqlQuery mysqr;
	mysqr.prepare(updateSql);
	mysqr.bindValue(":name", gclientName);
	mysqr.bindValue(":classname", gclassName);
	mysqr.bindValue(":admission", gadmission);
	mysqr.bindValue(":qq", gQQ);
	mysqr.bindValue(":id", gclientNo);
	if (!mysqr.exec())
	{
		QSqlError err = mysqr.lastError();
		QString errorinfo = err.text();
		QMessageBox::information(0, TR("提醒"), TR("更改数据失败"));
	}
	else
	{
		QMessageBox::information(0, TR("提示"), TR("信息修改成功"));
		updateInfo();
	}
}

void PersonalInfo::updateInfo()
{
	nameEdit->setText(gclientName);
	admission->setText(gadmission);
	classEdit->setText(gclassName);
	qqnumber->setText(gQQ);
}
