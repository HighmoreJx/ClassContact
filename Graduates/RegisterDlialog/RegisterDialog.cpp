#include "RegisterDialog.h"
#include "MainFrame/TR.h"
#include <QRegExp>
#include <QValidator>
#include "ToolClass/DataBaseOpt.h"

#include <qtwidgets/qtwidgets>

RegisterDialog::RegisterDialog(QDialog *parent /*= 0*/)
{
	this->setFixedSize(312, 372);
	noLabel = NULL;
	noEdit = NULL;

	nameLabel = NULL;
	nameEdit = NULL;
	passWordLabel = NULL;
	passwordEdit = NULL;
	checkPasswordLabel = NULL;
	checkPassword = NULL;
	contactInfoLabel = NULL;
	contactInfoEdit = NULL;
	sureButton = NULL;
	cancelButton = NULL;

	admissionLabel = NULL;
	admissionEdit = NULL;
	initStyle();
	init();
}

RegisterDialog::~RegisterDialog()
{
	
}

bool RegisterDialog::init()
{
	if (!nameLabel)
	{
		nameLabel = new QLabel();
		nameLabel->setText(TR("姓 名:        "));
	}
	if (!nameEdit)
	{
		nameEdit = new QLineEdit();
	}
	if (!passWordLabel)
	{
		passWordLabel = new QLabel();
		passWordLabel->setText(TR("设置密码: "));
	}
	if (!passwordEdit)
	{
		passwordEdit = new QLineEdit();
		passwordEdit->setEchoMode(QLineEdit::Password);
	}
	if (!checkPasswordLabel)
	{
		checkPasswordLabel = new QLabel();
		checkPasswordLabel->setText(TR("再输一次: "));
	}
	if (!checkPassword)
	{
		checkPassword = new QLineEdit();
		checkPassword->setEchoMode(QLineEdit::Password);
	}
	if (!contactInfoLabel)
	{
		contactInfoLabel = new QLabel();
		contactInfoLabel->setText(TR("联系方式: "));
	}
	if (!contactInfoEdit)
	{
		contactInfoEdit = new QLineEdit();
	}
	if (!sureButton)
	{
		sureButton = new QPushButton();
		sureButton->setText(TR("确 定"));
		sureButton->setObjectName("loginBtn");
		sureButton->setFixedSize(89, 30);
		connect(sureButton, SIGNAL(clicked()), this, SLOT(sureBtnClicked()));
	}
	if (!cancelButton)
	{
		cancelButton = new QPushButton();
		cancelButton->setText(TR("取 消"));
		cancelButton->setObjectName("loginBtn");
		cancelButton->setFixedSize(89, 30);
		connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelBtnClicked()));
	}
	if (!noLabel)
	{
		noLabel = new QLabel();
		noLabel->setText(TR("学 号:        "));
	}
	if (!noEdit)
	{
		noEdit = new QLineEdit();
		QRegExp regx("[0-9]+$");
		QValidator *validator = new QRegExpValidator(regx, noEdit);
		noEdit->setValidator(validator);
	}

	if (!admissionLabel)
	{
		admissionLabel = new QLabel();
		admissionLabel->setText(TR("入学时间: "));
	}
	if (!admissionEdit)
	{
		admissionEdit = new QLineEdit();
	}

	QHBoxLayout* noLayout = new QHBoxLayout();
	noLayout->addWidget(noLabel);
	noLayout->addWidget(noEdit);

	QHBoxLayout* nameLayout = new QHBoxLayout();
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameEdit);

	QHBoxLayout* passwordLayout = new QHBoxLayout();
	passwordLayout->addWidget(passWordLabel);
	passwordLayout->addWidget(passwordEdit);

	QHBoxLayout* checkLayout = new QHBoxLayout();
	checkLayout->addWidget(checkPasswordLabel);
	checkLayout->addWidget(checkPassword);

	QHBoxLayout* contactLayout = new QHBoxLayout();
	contactLayout->addWidget(contactInfoLabel);
	contactLayout->addWidget(contactInfoEdit);

	QHBoxLayout* admissionLayout = new QHBoxLayout();
	admissionLayout->addWidget(admissionLabel);
	admissionLayout->addWidget(admissionEdit);

	QHBoxLayout* btnLayout = new QHBoxLayout();
	btnLayout->addWidget(sureButton);
	btnLayout->addWidget(cancelButton);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(noLayout);
	mainLayout->addLayout(nameLayout);
	mainLayout->addLayout(passwordLayout);
	mainLayout->addLayout(checkLayout);
	mainLayout->addLayout(contactLayout);
	mainLayout->addLayout(admissionLayout);
	mainLayout->addLayout(btnLayout);
	
	this->setLayout(mainLayout);
	
	return true;
}


void RegisterDialog::sureBtnClicked()
{
	if (nameEdit->text() == "" || noEdit->text() == "" || passwordEdit->text() == "" ||
		checkPassword->text() == "" || contactInfoEdit->text() == "" || admissionEdit->text() == "")
		QMessageBox::information(0, TR("提示"), TR("亲，还没有填完哦！"));
	if (passwordEdit->text() != checkPassword->text())
		QMessageBox::information(0, TR("提示"), TR("两次密码输入不一致"));
 	DatabaseOpt opt;

	if (opt.registerClient(noEdit->text()))
	{
		opt.insertClient(noEdit->text(), nameEdit->text(), "", admissionEdit->text(), contactInfoEdit->text(), passwordEdit->text(), "");
		this->close();
	}
	else
	{
		QMessageBox::information(0, TR("提示"), TR("用户已经注册.")); return;
	}
}

void RegisterDialog::cancelBtnClicked()
{
	this->close();
}

void RegisterDialog::initStyle()
{
	QFile file(":/Graduates/Resources/login.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}
