#include "Login.h"
#include "RegisterDlialog/RegisterDialog.h"
#include "RegisterDlialog/linklabel.h"
#include "MainFrame/MainWidget.h"
#include <QtWidgets/QtWidgets>
#include "MainFrame/TR.h"
#include "ToolClass/DataBaseOpt.h"

#include <QSqlError>


Login::Login(QDialog* parent /*= 0*/)
{
	this->setFixedSize(344, 263);
	accountLabel = NULL;
	accountEdit = NULL;
	passwordLabel = NULL;
	passWordEdit = NULL;

	registerLabel = NULL;
	loginBtn = NULL;
 	DatabaseOpt opt;
 	opt.createTable();
	initFile();
	init();
}

Login::~Login()
{

}

bool Login::init()
{
	QFont font;
	font.setFamily(TR("Î¢ÈíÑÅºÚ"));
	font.setPointSize(13);
	if (!accountLabel)
	{
		accountLabel = new QLabel();
		accountLabel->setText(TR("ÕË ºÅ:"));
		accountLabel->setFont(font);
	}

	if (!accountEdit)
	{
		accountEdit = new QLineEdit();
		accountEdit->setFont(font);
		accountEdit->setFixedWidth(150);
	}

	if (!passwordLabel)
	{
		passwordLabel = new QLabel();
		passwordLabel->setText(TR("ÃÜ Âë:"));
		passwordLabel->setFont(font);
	}

	if (!passWordEdit)
	{
		passWordEdit = new QLineEdit();
		passWordEdit->setFixedWidth(150);
		passWordEdit->setFont(font);
		passWordEdit->setEchoMode(QLineEdit::Password);
	}

	if (!registerLabel)
	{
		registerLabel = new LinkLabel();
		registerLabel->setCheckable(false);
		registerLabel->setFont(font);
		registerLabel->setText(TR("×¢ ²á"));
		connect(registerLabel, SIGNAL(clicked()), this, SLOT(registerAccount()));
	}

	if (!loginBtn)
	{
		loginBtn = new QPushButton();
		loginBtn->setText(TR("µÇ Â¼"));
		loginBtn->setFont(font);
		loginBtn->setFixedSize(89, 30);
		loginBtn->setObjectName("loginBtn");
		connect(loginBtn, SIGNAL(clicked()), this, SLOT(logginBtnClicked()));
	}

	QHBoxLayout* accountLayout = new QHBoxLayout();
	accountLayout->addWidget(accountLabel);
	accountLayout->addWidget(accountEdit);
	accountLayout->setSpacing(0);
	QHBoxLayout* passwordLayout = new QHBoxLayout();
	passwordLayout->addWidget(passwordLabel);
	passwordLayout->addWidget(passWordEdit);
	passwordLayout->setSpacing(0);

	QVBoxLayout* containLayout = new QVBoxLayout();
	containLayout->addLayout(accountLayout);
	containLayout->addLayout(passwordLayout);
	QWidget* contain = new QWidget();
	contain->setFixedWidth(250);
	contain->setLayout(containLayout);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	/*mainLayout->addLayout(accountLayout);
	mainLayout->addLayout(passwordLayout);*/
	mainLayout->addWidget(contain);

	QWidget* registerWidget = new QWidget();
	QHBoxLayout* centerLayout = new QHBoxLayout();
	centerLayout->addWidget(registerLabel);
	registerWidget->setLayout(centerLayout);

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget(loginBtn);
	QWidget* containerWidget = new QWidget();
	containerWidget->setLayout(layout);

	mainLayout->addWidget(registerWidget);
	mainLayout->addWidget(containerWidget);
	mainLayout->setAlignment(Qt::AlignCenter);
	this->setLayout(mainLayout);

	return true;
}

void Login::logginBtnClicked()
{
	DatabaseOpt opt;
	opt.connect();
	if (opt.checkClient(accountEdit->text(), passWordEdit->text()))
 	{
		MainWidget *w = new MainWidget;
		w->show();
		this->hide();
	}
}

void Login::registerAccount()
{
	RegisterDialog* registerAccount = new RegisterDialog();
	registerAccount->setModal(true);
	registerAccount->show();
}

void Login::initFile()
{
	QFile file(":/Graduates/Resources/login.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}
