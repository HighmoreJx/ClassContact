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
		QMessageBox::information(0, TR("��ʾ"), TR("�������ݿ�ʧ��!"));
		return;
	}
	//db.exec("PRAGMA locking_mode = EXCLUSIVE");
}

void DatabaseOpt::createTable()
{
	//�༶�����
	if (!db.isOpen())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("���ݿ⿪��ʧ��.")); return;
	}
	QSqlQuery myqry;
	myqry.prepare("CREATE TABLE IF NOT EXISTS Class(classname VARCHAR(20) PRIMARY  KEY, managerId INTEGER, managerName VARCHAR(20))");
	if (!myqry.exec())
	{
		QSqlError error = myqry.lastError();
		QString temp = error.text();
		QMessageBox::information(0, TR("��ʾ"), TR("�༶�������ʧ��.")); return;
	}
	//�û�ע���
	myqry.prepare("CREATE TABLE IF NOT EXISTS ClientExits(id INTEGER PRIMARY KEY, name VARCHAR(20), classname VARCHAR(20), admission VARCHAR(20), QQ VARCHAR(10), paswd VARCHAR(20), manageclassname VARCHAR(20), FOREIGN KEY(classname) references Class(classname))");
	if (!myqry.exec())
	{
		QSqlError error = myqry.lastError();
		QString temp = error.text();
		QMessageBox::information(0, TR("��ʾ"), TR("�û�ע�����ʧ��.")); return;
	}
	//�û����Ա�
	myqry.prepare("CREATE TABLE IF NOT EXISTS Message(content TEXT, name VARCHAR(20), class VARCHAR(20))");
	if (!myqry.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("���Ա���ʧ��.")); return;
	}

	//�༶�����
	myqry.prepare("CREATE TABLE IF NOT EXISTS ApplyList(id INTEGER, name VARCHAR(20), applyClassName VARCHAR(20), result INTEGER)");
	if (!myqry.exec())
	{
		QMessageBox::information(0, TR("��ʾ"), TR("�������б���ʧ��.")); return;
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
		QMessageBox::information(0, TR("����"), TR("��ѯע���û�ʧ��"));
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
		QMessageBox::information(0, TR("��ʾ"), TR("�����û�ʧ��.")); return;
	}
	QMessageBox::information(0, TR("��ʾ"), TR("�û�ע��ɹ�."));
}

bool DatabaseOpt::checkClient(QString no, QString password)
{
	QSqlQuery qry;
	if (!qry.exec("SELECT * FROM ClientExits WHERE id = " + no))
	{
		QMessageBox::information(0, TR("��ʾ"), TR("���˺�δע��.")); return false;
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
				QMessageBox::information(0, TR("��ʾ"), TR("�����������.")); return false;
			}
		}
	}
	QMessageBox::information(0, TR("��ʾ"), TR("���˺�δע��.")); return false;
}