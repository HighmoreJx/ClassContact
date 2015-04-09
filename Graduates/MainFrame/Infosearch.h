#ifndef _INFO_SEARCH_H_
#define _INFO_SEARCH_H_

/*
	对应个人信息检索功能
*/

#include <QWidget>

class QLineEdit;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;

class MySqlModel;
class QTableView;

class InfoSearch : public QWidget
{
	Q_OBJECT
public:
	explicit InfoSearch(QWidget* parent = 0);
	~InfoSearch();

	void showData();
	void updateInfo();

private slots:
	void searchBtnClicked();
private:
	
	bool init();

private:

	QLabel* nameLabel;
	QLineEdit* nameEdit;
	QLabel* classLabel;
	QLineEdit* classEdit;
	QLabel* admissionLabel;
	QLineEdit* admission;

	QPushButton* searchBtn;

	QWidget* containterWidget;
	QTableWidget* infoTableWidget;
	QTableView* infoTableView;
	MySqlModel* model;

};


#endif //_INFO_SEARCH_H_