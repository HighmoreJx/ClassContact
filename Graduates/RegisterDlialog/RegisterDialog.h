#ifndef _REGISTER_DIALOG_H_
#define  _REGISTER_DIALOG_H_

/*
	功能： 实现用户信息的注册
*/

#include <QDialog>

class QWidget;
class QLabel;
class QPushButton;
class QLineEdit;

class RegisterDialog : public QDialog
{
	Q_OBJECT

public:
	RegisterDialog(QDialog *parent = 0);
	~RegisterDialog();

private:
	bool init();
	void initStyle();

private slots:
	void sureBtnClicked();
	void cancelBtnClicked();
private:
	//感觉注册的时候，还是需要学号字段，要不不好判断数据库内容重复
	QLabel* noLabel;
	QLineEdit* noEdit;


	QLabel* nameLabel;
	QLineEdit* nameEdit;
	QLabel* passWordLabel;
	QLineEdit* passwordEdit;
	QLabel* checkPasswordLabel;
	QLineEdit* checkPassword;
	QLabel* contactInfoLabel;
	QLineEdit* contactInfoEdit;
	QLabel* admissionLabel;
	QLineEdit* admissionEdit;

	QPushButton* sureButton;
	QPushButton* cancelButton;
};


#endif //_REGISTER_DIALOG_H_