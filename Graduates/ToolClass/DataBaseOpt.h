#ifndef _DATABASE_OPT_H_
#define _DATABASE_OPT_H_

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

/*
	���ܣ�������Ա�ϵͳ�����ݱ��ò���������ͨ����
*/

class DatabaseOpt
{
public:
	DatabaseOpt();
	~DatabaseOpt();

	void connect();
	void closeConnect();
	void createTable();
	

	//�û�ע�����ز���
	//�����Ƿ��Ѿ�����ע����û�
	bool registerClient(QString no);
	void insertClient(QString no, QString name, QString className, QString admission, QString qqnum, QString password, QString manageclassname);
	bool checkClient(QString no, QString password);
private:

	QSqlDatabase db;
	QSqlQuery qry;
	QSqlRecord rec;

};


#endif //_DATABASE_OPT_H_