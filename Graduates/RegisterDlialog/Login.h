#ifndef _LOGIN_H_
#define  _LOGIN_H_

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
class LinkLabel;

class Login : public QDialog
{
	Q_OBJECT
public:
	explicit Login(QDialog* parent = 0);
	~Login();


private:
	bool init();
	void initFile();

private slots:
	void logginBtnClicked();
	void registerAccount();

private:
	QLabel* accountLabel;
	QLineEdit* accountEdit;
	QLabel* passwordLabel;
	QLineEdit* passWordEdit;

	LinkLabel* registerLabel;
	QPushButton* loginBtn;
};


#endif //_LOGIN_H_
