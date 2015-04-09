#include "ToolClass/DataBaseOpt.h"
#include "MainFrame/TR.h"
#include <QMessageBox>
#include <QVariant>
#include <QSqlError>


#include <string>

DatabaseOpt::DatabaseOpt()
{
	connect();
}

DatabaseOpt::~DatabaseOpt()
{
	closeConnect();
}

void DatabaseOpt::connect()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("./graduates.db");
	if (!db.open())
	{
		QMessageBox::information(0, TR("提示"), TR("连接数据库失败!"));
		return;
	}
	//db.exec("PRAGMA locking_mode = EXCLUSIVE");
}

void DatabaseOpt::createTable()
{
	//班级管理表
	if (!db.isOpen())
	{
		QMessageBox::information(0, TR("提示"), TR("数据库开启失败.")); return;
	}
	QSqlQuery myqry;
	myqry.prepare("CREATE TABLE IF NOT EXISTS Class(classname VARCHAR(20) PRIMARY  KEY, managerId INTEGER, managerName VARCHAR(20))");
	if (!myqry.exec())
	{
		QSqlError error = myqry.lastError();
		QString temp = error.text();
		QMessageBox::information(0, TR("提示"), TR("班级管理表创建失败.")); return;
	}
	//用户注册表
	myqry.prepare("CREATE TABLE IF NOT EXISTS ClientExits(id INTEGER PRIMARY KEY, name VARCHAR(20), classname VARCHAR(20), admission VARCHAR(20), QQ VARCHAR(10), paswd VARCHAR(20), manageclassname VARCHAR(20), FOREIGN KEY(classname) references Class(classname))");
	if (!myqry.exec())
	{
		QSqlError error = myqry.lastError();
		QString temp = error.text();
		QMessageBox::information(0, TR("提示"), TR("用户注册表创建失败.")); return;
	}
	//用户留言表
	myqry.prepare("CREATE TABLE IF NOT EXISTS Message(content TEXT, name VARCHAR(20), class VARCHAR(20))");
	if (!myqry.exec())
	{
		QMessageBox::information(0, TR("提示"), TR("留言表创建失败.")); return;
	}

	//班级申请表
	myqry.prepare("CREATE TABLE IF NOT EXISTS ApplyList(id INTEGER, name VARCHAR(20), applyClassName VARCHAR(20), result INTEGER)");
	if (!myqry.exec())
	{
		QMessageBox::information(0, TR("提示"), TR("申请人列表创建失败.")); return;
	}
}

void DatabaseOpt::closeConnect()
{
	db.close();
}

bool DatabaseOpt::registerClient(QString no)
{
	QString search = "SELECT id FROM ClientExits WHERE id = " + no;
	QSqlQuery myqry;
	myqry.prepare(search);
	if (!myqry.exec())
	{
		QMessageBox::information(0, TR("提醒"), TR("查询注册用户失败"));
	}
	else
	{
		while (myqry.next())
		{
			return false;
		}
	}
	return true;
}

void DatabaseOpt::insertClient(QString no, QString name, QString className, QString admission, QString qqnum, QString password, QString manageclassname)
{
	QSqlQuery myqry;
	myqry.prepare("INSERT INTO ClientExits VALUES(?, ?, ?, ?, ?,?,?)");
	myqry.bindValue(0, no);
	myqry.bindValue(1, name);
	myqry.bindValue(2, className);
	myqry.bindValue(3, admission);
	myqry.bindValue(4, qqnum);
	myqry.bindValue(5, password);
	myqry.bindValue(6, manageclassname);

	if (!myqry.exec())
	{
		QSqlError error = myqry.lastError();
		QString temp = error.text();
		QMessageBox::information(0, TR("提示"), TR("插入用户失败.")); return;
	}
	QMessageBox::information(0, TR("提示"), TR("用户注册成功."));
}

bool DatabaseOpt::checkClient(QString no, QString password)
{
	QSqlQuery qry;
	if (!qry.exec("SELECT * FROM ClientExits WHERE id = " + no))
	{
		QMessageBox::information(0, TR("提示"), TR("该账号未注册.")); return false;
	}
	else
	{
		while (qry.next())
		{
			if (password == qry.value("paswd"))
			{
				gclientNo = qry.value("id").toInt();
				gclientName = qry.value("name").toString();
				gclassName = qry.value("classname").toString();
				gadmission = qry.value("admission").toString();
				gQQ = qry.value("QQ").toString();
				gmanageClassName = qry.value("manageclassname").toString();
				return true;
			}
			else
			{
				QMessageBox::information(0, TR("提示"), TR("密码输入错误.")); return false;
			}
		}
	}
	QMessageBox::information(0, TR("提示"), TR("该账号未注册.")); return false;
}