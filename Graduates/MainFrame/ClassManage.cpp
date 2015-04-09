#include "MainFrame/ClassManage.h"
#include <QtWidgets/QtWidgets>
#include "MainFrame/TR.h"
#include "ToolClass/DataBaseOpt.h"
#include "ToolClass/ToolClass.h"
#include <QSqlError>


ClassManage::ClassManage(QWidget* parent /*= 0*/)
{
	ownClassBtn = NULL;
	joinedClassBtn = NULL;
	classTableWidget = NULL;
	joinedList = NULL;
	ownList = NULL;
	classesLabel = NULL;
	classesList = NULL;
	createListBtn = NULL;
	detailList = NULL;
	initStyle();
	init();
	getData();
	initAllClassList();
	initOwnClassList();
	initJoinClassList();
}

ClassManage::~ClassManage()
{}

bool ClassManage::init()
{
	QFont font;
	font.setFamily(TR("΢���ź�"));
	font.setPointSize(12);
	if (!ownClassBtn)
	{
		ownClassBtn = new QPushButton();
		ownClassBtn->setText(TR("����༶"));
		ownClassBtn->setFixedSize(110, 25);
		ownClassBtn->setObjectName("classmanageTab");
		ownClassBtn->setCheckable(true);
		ownClassBtn->setChecked(true);
		ownClassBtn->setFlat(true);
		ownClassBtn->setFont(font);
		//ownClassBtn->setObjectName("choiceBtn");
		connect(ownClassBtn, SIGNAL(clicked()), this, SLOT(ownClassBtnClicked()));
	}
	if (!joinedClassBtn)
	{
		joinedClassBtn = new QPushButton();
		joinedClassBtn->setText(TR("����༶"));
		joinedClassBtn->setFixedSize(110, 25);
		joinedClassBtn->setObjectName("classmanageTab");
		joinedClassBtn->setCheckable(true);
		joinedClassBtn->setChecked(false);
		joinedClassBtn->setFlat(true);
		joinedClassBtn->setFont(font);
		connect(joinedClassBtn, SIGNAL(clicked()), this, SLOT(joinedClassBtnClicked()));
	}

	if (!classTableWidget)
	{
		classTableWidget = new QStackedWidget();
	}
	if (!ownList)
	{
		ownList = new QListWidget();
		classTableWidget->addWidget(ownList);
		ownList->setFont(font);
		connect(ownList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ownClassItemClicked(QListWidgetItem*)));
	}
	if (!joinedList)
	{
		joinedList = new QListWidget();
		joinedList->setFont(font);
		classTableWidget->addWidget(joinedList);
		connect(joinedList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(allClassItemClicked(QListWidgetItem*)));
	}
	if (!classesLabel)
	{
		classesLabel = new QLabel();
		classesLabel->setText(TR("���а༶:"));
		classesLabel->setFont(font);
	}
	if (!classesList)
	{
		classesList = new QListWidget();
		classesList->setFont(font);
		connect(classesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(allClassItemClicked(QListWidgetItem*)));
	}
	if (!createListBtn)
	{
		createListBtn = new QPushButton();
		createListBtn->setText(TR("�����༶"));
		createListBtn->setFixedWidth(150);
		createListBtn->setObjectName("choiceBtn");
		createListBtn->setFont(font);
		connect(createListBtn, SIGNAL(clicked()), this, SLOT(createListBtnClicked()));
	}
	if (!detailList)
	{
		detailList = new QListWidget();
		detailList->setFont(font);
	}

	QWidget* containerWidget = new QWidget();
	//containerWidget->setStyleSheet("background:transparent");
	containerWidget->setFixedSize(220, 25);
	QHBoxLayout* btnLayout = new QHBoxLayout();
	btnLayout->addWidget(ownClassBtn);
	btnLayout->addWidget(joinedClassBtn);
	btnLayout->setSpacing(0);
	btnLayout->setContentsMargins(0, 0, 0, 0);
	containerWidget->setLayout(btnLayout);

	QVBoxLayout* leftLayout = new QVBoxLayout();
	leftLayout->addWidget(containerWidget);
	leftLayout->addWidget(classTableWidget);
	leftLayout->addWidget(classesLabel);
	leftLayout->addWidget(classesList);

	QVBoxLayout* rightLayout = new QVBoxLayout();
	rightLayout->addWidget(createListBtn);
	rightLayout->addWidget(detailList);

	QHBoxLayout* mainLayout = new QHBoxLayout();
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	this->setLayout(mainLayout);
	
	classTableWidget->setCurrentIndex(0);
	return true;
}


void ClassManage::ownClassBtnClicked()
{
	////ֱ�Ӵ�ȫ�ֱ�����ȡ������list�оͺ�
	//QListWidgetItem* item = new QListWidgetItem();
	//item->setText(gclassName);

	if (ownClassBtn->isChecked())
	{
		ownClassBtn->setChecked(true);
		joinedClassBtn->setChecked(false);
	}
	else
	{
		ownClassBtn->setChecked(false);
		joinedClassBtn->setChecked(true);
	}

	classTableWidget->setCurrentIndex(0);
}

void ClassManage::joinedClassBtnClicked()
{

	if (joinedClassBtn->isChecked())
	{
		ownClassBtn->setChecked(false);
		joinedClassBtn->setChecked(true);
	}
	else
	{
		ownClassBtn->setChecked(true);
		joinedClassBtn->setChecked(false);
	}

	classTableWidget->setCurrentIndex(1);
}

void ClassManage::createListBtnClicked()
{
	if (gclassName != "")
	{
		QMessageBox::information(0, TR("��ʾ"), TR("���Ѿ�����༶���޷���������"));
		return;
	}	
	dialog = new CreateClassDialog();
	connect(dialog, SIGNAL(classCreateSig(QString)), this, SLOT(createClassSlot(QString)));
	dialog->show();
}


/*��ʼ��������ص��б�*/
void ClassManage::initOwnClassList()
{
	if (gmanageClassName == "")
		return;


	QListWidgetItem* item = new QListWidgetItem();
	item->setText(gmanageClassName);
	ownList->addItem(item);
}

//��ʼ�����м���İ༶��Ϣ
void ClassManage::initJoinClassList()
{
	if (gclassName == "")
		return;
	else
	{
		clientListItem* item = new clientListItem(gclassName);
		if (gclassName == gmanageClassName)
		{
			//֤���Ǽ���༶�Ĺ���Ա
			item->setText(TR("��ɢ"));
		}
		else
		{
			item->setText(TR("�˳�"));
		}

		//����ȥ���ݿ�����ȡ�ˣ�ȫ�ֱ���
		QListWidgetItem* listItem = new QListWidgetItem();
		listItem->setText(gclassName);
		connect(item, SIGNAL(quitClass(QString)), this, SLOT(quitJoinedClass(QString)));
		connect(item, SIGNAL(endClass(QString)), this, SLOT(endJoinedClass(QString)));
		joinedList->addItem(listItem);
		joinedList->setItemWidget(listItem, item);
	}
}

void ClassManage::initAllClassList()
{
	DatabaseOpt opt;
	QSqlQuery myquery;
	myquery.prepare("SELECT * FROM Class");
	if (!myquery.exec())
		QMessageBox::information(0, TR("��ʾ"), TR("��ȡ�༶��Ϣʧ��"));
	else
	{
		while (myquery.next())
		{
			//�Լ�����İ༶���ǲ�Ҫ��ʾ������
			if (gmanageClassName != "" && gmanageClassName == myquery.value("classname").toString())
				continue;

			clientListItem* item = new clientListItem(myquery.value("classname").toString());
			connect(item, SIGNAL(chooseClassName(QString)), this, SLOT(applyToClass(QString)));
			connect(item, SIGNAL(cancelClassName(QString)), this, SLOT(cancelApply(QString)));
			QListWidgetItem* listItem = new QListWidgetItem();
			listItem->setText(myquery.value("classname").toString());
			item->setText(myquery.value("classname").toString());
			if (gclassName == "")
			{
				item->setText(TR("����"));
				item->setBtnShow(true);
			}
			else
			{
				item->setBtnShow(false);
			}
			classesList->addItem(listItem);
			classesList->setItemWidget(listItem, item);
		}
	}
}

void ClassManage::getData()
{
	DatabaseOpt opt;

	QSqlQuery myquery;
	myquery.prepare("SELECT * FROM ClientExits");
	if (!myquery.exec()){
		QMessageBox::information(0, TR("��ʾ"), TR("��ȡ�û�ʧ��"));
	}
	else
	{
		while (myquery.next())
		{
			int clientid(myquery.value("id").toUInt());
			std::string clientname(myquery.value("name").toString().toStdString());
			//��δ�������༶��ͬѧ������ֵΪ "��δ����༶"
			std::string classname = "";
			if (myquery.value("classname").toString().toStdString() == "")
			{
				classname = "��δ����༶";
			}
			else
			{
				classname = myquery.value("classname").toString().toStdString();
			}
			std::string clientAdmission(myquery.value("admission").toString().toStdString());
			std::string clientQQ(myquery.value("QQ").toString().toStdString());

			std::shared_ptr<ClientInfo> client(new ClientInfo(clientid, clientname, classname,clientAdmission, clientQQ));
			clientMap.insert(make_pair(classname, client));
		}
	}
}

void ClassManage::createClassSlot(QString classname)
{
	//����Ѿ��иð༶����
	if (clientMap.find(classname.toStdString()) != clientMap.end())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�ð༶�Ѿ�������"));
		return;
	}
	DatabaseOpt opt;
	QSqlQuery myquery;
	myquery.prepare("INSERT INTO Class VALUES(?, ?, ?)");
	myquery.bindValue(0, classname);
	myquery.bindValue(1, gclientNo);
	myquery.bindValue(2, gclientName);
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�������༶ʧ��"));
	}
	std::shared_ptr<ClientInfo> client(new ClientInfo(gclientNo, gclientName.toStdString(), gclassName.toStdString(), gadmission.toStdString(), gQQ.toStdString()));
	clientMap.insert(make_pair(classname.toStdString(), client));
	myquery.clear();
	myquery.prepare("UPDATE ClientExits set classname=:classname,manageclassname=:manageclassname where id=:id");
	myquery.bindValue(":classname", classname);
	myquery.bindValue(":manageclassname", classname);
	myquery.bindValue(":id", gclientNo);
	gclassName = classname;
	gmanageClassName = classname;
	if (!myquery.exec())
	{
		QSqlError err = myquery.lastError();
		QString errorinfo = err.text();
		QMessageBox::information(0, TR("����"), TR("�����û��༶��Ϣʧ��"));
	}

	insertoAllClasslist(classname);
	initJoinClassList();
	initOwnClassList();
	dialog->close();
}

void ClassManage::insertoAllClasslist(QString classname)
{
	//�о�������Լ������İ༶��û�б�Ҫ��ʾ�����а༶�б���
	/*clientListItem* item = new clientListItem(classname);
	QListWidgetItem* listItem = new QListWidgetItem();
	item->setText(classname);
	if (gclassName == "")
	{
		item->setText(TR("����"));
		item->setBtnShow(true);
	}
	else
	{
		if (gclassName == myquery.value("classname").toString())
		{
			item->setText(TR("�˳�"));
			item->setBtnShow(true);
		}
		else
			item->setBtnShow(false);


	}
	joinedList->addItem(listItem);
	joinedList->setItemWidget(listItem, item);*/
}

void ClassManage::allClassItemClicked(QListWidgetItem* item)
{
	detailList->clear();
	QString itemClassName = item->text();

	auto ret = clientMap.equal_range(itemClassName.toStdString());
	for (auto iter = ret.first; iter != ret.second; ++iter)
	{
		QListWidgetItem* item = new QListWidgetItem();
		item->setText(QString::fromStdString(iter->second->getClientName()));
		detailList->addItem(item);
	}
}

//��ӵ������б���
void ClassManage::applyToClass(QString classname)
{
	DatabaseOpt opt;
	QSqlQuery myquery;
	myquery.prepare("SELECT name FROM ApplyList WHERE id=:id AND applyClassName=:applyClassName");
	myquery.bindValue(0, gclientNo);
	myquery.bindValue(1, classname);
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("����"), TR("��ѯ�����б�ʧ��."));
	}
	else
	{
		while (myquery.next())
		{
			if (myquery.value("result").toInt() == 1)
			{
				//��ʾ���ܾ�
				QMessageBox::information(0, TR("����"), TR("���Ѿ����༶����Ա�ܾ�."));
				//Ȼ����������ɾ��������¼
				myquery.prepare("DETETE FROM ApplyList WHERE id=:id AND applyClassName=:applyClassName");
				myquery.bindValue(0, gclientNo);
				myquery.bindValue(1, classname);
				if (!myquery.exec())
				{
					QMessageBox::information(0, TR("����"), TR("ɾ����¼ʧ��."));
					return;
				}
			}
			else{
				QMessageBox::information(0, TR("����"), TR("���Ѿ������˸ð༶."));
			}
			return;
		}
	}
	myquery.clear();
	myquery.prepare("INSERT INTO ApplyList VALUES(?, ?, ?,?)");
	myquery.bindValue(0, gclientNo);
	myquery.bindValue(1, gclientName);
	myquery.bindValue(2, classname);
	myquery.bindValue(3, 0);

	if (!myquery.exec())
	{
		QSqlError error = myquery.lastError();
		QString test = error.text();
		QMessageBox::information(0, TR("����"), TR("��ӵ��������б�ʧ��"));
	}
	else
	{
		QMessageBox::information(0, TR("����"), TR("����ɹ�,�����ĵȴ��ظ�"));
	}
}

void ClassManage::ownClassItemClicked(QListWidgetItem* item)
{
	DatabaseOpt opt;

	QSqlQuery myquery;
	myquery.prepare("SELECT * FROM ApplyList WHERE applyClassName=:applyClassName");
	myquery.bindValue(":applyClassName", item->text());
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("����"), TR("��ѯ������Աʧ��"));
	}
	else
	{
		detailList->clear();
		while (myquery.next())
		{
			//�������Ϣ�Ѿ�������ˣ��Ͳ���ʾ���б�����
			if (myquery.value("result").toInt() == 1 || myquery.value("result").toInt() == 2)
				continue;
			QListWidgetItem* item = new QListWidgetItem();
			item->setText(myquery.value("name").toString());
			item->setWhatsThis(myquery.value("id").toString());
			clientListItem* itemWidget = new clientListItem(myquery.value("applyClassName").toString(), false);
			itemWidget->setClientId(myquery.value("id").toInt());
			itemWidget->setClientName(myquery.value("name").toString());
			connect(itemWidget, SIGNAL(agreeClassSig(QString, int, QString)), this, SLOT(agreeJoinClass(QString, int, QString)));
			connect(itemWidget, SIGNAL(disagreeClassSig(QString, int, QString)), this, SLOT(disagreeJoinClass(QString, int, QString)));
		//	connect(itemWidget, SIGNAL(quitClass(QString)), this, SLOT(quitJoinedClass(QString)));
		//	connect(itemWidget, SIGNAL(endClass(QString)), this, SLOT(endJoinedClass(QString)));
			detailList->addItem(item);
			detailList->setItemWidget(item, itemWidget);

		}
	}
}

void ClassManage::cancelApply(QString classname)
{
	DatabaseOpt opt;
	QSqlQuery myquery;
	myquery.prepare("SELECT classname FROM ClientExites WHERE id=:id");
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("cancelApply Failed"));
		return;
	}
	else
	{
		if (myquery.value("classname").toString() != "")
		{
			QMessageBox::information(0, TR("��ʾ"), TR("���ύ�������ѱ��༶����Ա����"));
			return;
		}
	}

	myquery.prepare("DELETE FROM ApplyList WHERE id=:id, applyClassName=:applyClassName");
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("ClassManage.cpp 415"));
	}
	else
	{
		initAllClassList();
	}
}

void ClassManage::agreeJoinClass(QString className, int clientNo, QString clientName)
{
	DatabaseOpt opt;
	QSqlQuery myquery;

	myquery.prepare("UPDATE ApplyList set result = 2 WHERE id = :clientNo AND applyClassName=:applyClassName");
	myquery.bindValue(":clientNo",clientNo);
	myquery.bindValue(":applyClassName", className);
	if (!myquery.exec())
	{
		QSqlError err = myquery.lastError();
		QString test = err.text();
		QMessageBox::information(0, TR("��ʾ"), TR("ͬ������ʧ��"));
		return;
	}

	myquery.prepare("DELETE FROM ApplyList WHERE id=:id");
	myquery.bindValue(":id", clientNo);
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�������б����ݿ���ɾ����Ϣʧ��"));
		return;
	}

	myquery.prepare("UPDATE ClientExits SET classname = :classname WHERE id = :id");
	myquery.bindValue(":classname", className);
	myquery.bindValue(":id", clientNo);
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�����û��༶��Ϣʧ��"));
		return;
	}
	clientMap.clear();
	getData();
	eraseFromList(QString::number(clientNo));
}

void ClassManage::disagreeJoinClass(QString className, int clientNo, QString clientName)
{
	DatabaseOpt opt;
	QSqlQuery myquery;

	myquery.prepare("UPDATE ApplyList set result = 1 WHERE id = :clientNo AND applyClassName=:applyClassName");
	myquery.bindValue(":clientNo", clientNo);
	myquery.bindValue(":applyClassName", className);
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�ܾ�����ʧ��"));
		return;
	}
	eraseFromList(QString::number(clientNo));
}

void ClassManage::eraseFromList(QString clientNo)
{
	for (int i = 0; i < detailList->count(); ++i)
	{
		if (detailList->item(i)->whatsThis() == clientNo)
		{
			detailList->takeItem(i);
			return;
		}
	}
}

void ClassManage::quitJoinedClass(QString className)
{
	detailList->clear();

	DatabaseOpt opt;
	QSqlQuery myquery;
	myquery.prepare("UPDATE ClientExits SET classname = :newname WHERE id=:id AND classname=:classname");
	myquery.bindValue(":id", gclientNo);
	myquery.bindValue(":classname", className);
	myquery.bindValue(":newname", "");
	if (!myquery.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�˳��༶ʧ��."));
		return;
	}
	//�������а༶
	clientMap.clear();
	classesList->clear();
	getData();
	initAllClassList();
	joinedList->clear();
}

void ClassManage::endJoinedClass(QString className)
{
	DatabaseOpt opt;
	QSqlQuery myquery;
	

	//����ClientExits�����������
	myquery.prepare("UPDATE ClientExits SET classname =:newname,manageclassname=:manageclassname WHERE classname=:classname");
	myquery.bindValue(":classname", className);
	myquery.bindValue(":manageclassname", "");
	myquery.bindValue("newname", "");
	if (!myquery.exec())
	{
		QSqlError error = myquery.lastError();
		QString test = error.text();
		QMessageBox::information(0, TR("��ʾ"), TR("����ClientExits�����������ʧ��"));
		return;
	}


	//ɾ��class�����������
	myquery.prepare("DELETE FROM Class WHERE classname = :className");
	myquery.bindValue(":className", className);
	if (!myquery.exec())
	{
		QSqlError error = myquery.lastError();
		QString test = error.text();
		QMessageBox::information(0, TR("��ʾ"), TR("ɾ��class�����������ʧ��"));
		return;
	}
	//�������а༶
	clientMap.clear();
	classesList->clear();
	getData();
	initAllClassList();


	//ɾ������༶
	joinedList->clear();

	//ɾ������༶
	ownList->clear();

	//ɾ��detail���������
	detailList->clear();
}

void ClassManage::initStyle()
{
	QFile file(":/Graduates/Resources/mainFrame.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}

void clientListItem::itemBtnClicked()
{
	QString test = itemBtn->text();
	if (itemBtn->text() == TR("ȡ��"))
	{
		emit cancelClassName(className_);
	}
	else if (itemBtn->text() == TR("�˳�"))
	{
		emit quitClass(className_);
	}
	else if (test == TR("��ɢ"))
	{
		emit endClass(className_);
	}
	else
	{
		if (gclassName != "" || gmanageClassName != "")
		{
			QMessageBox::information(0, TR("��ʾ"), TR("���Ѿ��������༶�����ܼ����ύ����."));
			return;
		}
		emit chooseClassName(className_);
	}
	
}

clientListItem::clientListItem(QString className, bool multi /*= false*/, QWidget* parent /*= 0*/)
{
	if (multi)
	{
		className_ = className;
		itemBtn = new QPushButton();
		itemBtn->setObjectName("choiceBtn");
		itemBtn->setFixedWidth(40);
		connect(itemBtn, SIGNAL(clicked()), this, SLOT(itemBtnClicked()));
		QHBoxLayout* layout = new QHBoxLayout();
		layout->setContentsMargins(0, 0, 0, 0);
		layout->setAlignment(Qt::AlignRight);
		layout->addWidget(itemBtn);
		this->setLayout(layout);
	}
	else
	{
		className_ = className;
		agreeBtn = new QPushButton();
		agreeBtn->setFixedWidth(40);
		agreeBtn->setText(TR("ͬ��"));
		agreeBtn->setObjectName("choiceBtn");
		disagreeBtn = new QPushButton();
		disagreeBtn->setFixedWidth(40);
		disagreeBtn->setText(TR("�ܾ�"));
		disagreeBtn->setObjectName("choiceBtn");
		connect(agreeBtn, SIGNAL(clicked()), this, SLOT(agrBtnClicked()));
		connect(disagreeBtn, SIGNAL(clicked()), this, SLOT(disAgrBtnClicked()));

		QHBoxLayout* layout = new QHBoxLayout();
		layout->setContentsMargins(0, 0, 0, 0);
		layout->setAlignment(Qt::AlignRight);
		layout->addWidget(agreeBtn);
		layout->addWidget(disagreeBtn);
		this->setLayout(layout);
	}
}

void clientListItem::agrBtnClicked()
{
	emit agreeClassSig(className_, clientId_, clientName_);
}

void clientListItem::disAgrBtnClicked()
{
	emit disagreeClassSig(className_, clientId_, clientName_);
}
