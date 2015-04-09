#ifndef _DATABASE_OPT_H_
#define _DATABASE_OPT_H_

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

/*
	功能：这是针对本系统的数据表常用操作，不具通用性
*/

class DatabaseOpt
{
public:
	DatabaseOpt();
	~DatabaseOpt();

	void connect();
	void closeConnect();
	void createTable();
	

	//用户注册表相关操作
	//查找是否已经存在注册的用户
	bool registerClient(QString no);
	void insertClient(QString no, QString name, QString className, QString admission, QString qqnum, QString password, QString manageclassname);
	bool checkClient(QString no, QString password);
private:

	QSqlDatabase db;
	QSqlQuery qry;
	QSqlRecord rec;

};


#endif //_DATABASE_OPT_H_