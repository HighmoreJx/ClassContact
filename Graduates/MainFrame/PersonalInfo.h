#ifndef _PERSONAL_INFO_H_
#define _PERSONAL_INFO_H_

/*
	功能： 个人信息管理
*/

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;

class PersonalInfo : public QWidget
{
	Q_OBJECT
public:
	explicit PersonalInfo(QWidget* parent = 0);
	~PersonalInfo();

	void updateInfo();
private:
	bool init();
private slots:
	void saveInfoBtnClicked();

private:
	QLabel* picLabel;
	QLabel* nameLabel;
	QLabel* classLabel;
	QLabel* admissionLabel;
	QLabel* qqnumberLabel;
	QLineEdit* nameEdit;
	QLineEdit* classEdit;
	QLineEdit* admission;
	QLineEdit* qqnumber;

	QPushButton* saveInfoBtn;
};


#endif //_PERSONAL_INFO_H_