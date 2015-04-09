#ifndef _TOOL_CLASS_H_
#define  _TOOL_CLASS_H_

#include <QSqlTableModel>
#include <string>
#include <QDialog>

class QLineEdit;
class QPushButton;
class QLabel;

class MySqlModel : public QSqlTableModel
{
public:
	QVariant data(const QModelIndex& item, int role) const;
private:

};


//为了减少读写数据库的次数，所以将客户信息整合成一个类，以存放于内存中
class ClientInfo
{
public:
	ClientInfo(int clientid, std::string clientName, std::string className, std::string admission, std::string QQ):
		clientId_(clientid), clientName_(clientName), className_(className), admission_(admission), QQ_(QQ)
	{};
	~ClientInfo(){};

	void setClientID(int val){ clientId_ = val; }
	int getClientID() { return clientId_; }

	void setClientName(std::string val){ clientName_ = val; }
	std::string getClientName(){ return clientName_; }

	void setClassName(std::string val){ clientName_ = val; }
	std::string getClassName() { return className_; }

	void setAdmission(std::string val){ admission_ = val; }
	std::string getAdmission() { return admission_; }

	void setQQ(std::string val){ QQ_ = val; }
	std::string getQQ() { return QQ_; }

private:
	int clientId_;
	std::string clientName_;
	std::string className_;
	std::string admission_;
	std::string QQ_;
};


class CreateClassDialog : public QDialog
{
	Q_OBJECT
public:
	explicit CreateClassDialog(QDialog* parent = 0);
	~CreateClassDialog(){};

	bool init();

signals:
	void classCreateSig(QString classname);
private slots:
	void sureBtnClicked();
	void cancelBtnClicked();

private:
	QLineEdit* inputEdit;;
	QPushButton* sureBtn;
	QPushButton* cancelBtn;
	QLabel* infoLabel;
};

#endif //_TOOL_CLASS_H