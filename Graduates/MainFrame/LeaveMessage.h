#ifndef _LEAVE_MESSAGE_H_
#define _LEAVE_MESSAGE_H_


#include <QWidget>

class QTableView;
class QTextEdit;
class QPushButton;
class MySqlModel;
class QTableWidget;

class LeaveMessage : public QWidget
{
	Q_OBJECT
public:
	explicit LeaveMessage(QWidget* parent = 0);
	~LeaveMessage();

	void showList();
	void addData();

private slots:
	void msgBtnClicked();

private:
	bool init();
	void setTableWidget();
	void initStyle();
private:
	QTextEdit* messageEdit;
	QPushButton* msgBtn;
	QTableView* messageTableview;
	MySqlModel* mymodel;

	//因为留言在表中占据位置太宽的原因，所以换成QTableWidget来使用ToolTip
	QTableWidget* messageWidget;
};


#endif //_LEAVE_MESSAGE_H_