#ifndef _REGISTER_DIALOG_H_
#define  _REGISTER_DIALOG_H_

/*
	���ܣ� ʵ���û���Ϣ��ע��
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
	//�о�ע���ʱ�򣬻�����Ҫѧ���ֶΣ�Ҫ�������ж����ݿ������ظ�
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