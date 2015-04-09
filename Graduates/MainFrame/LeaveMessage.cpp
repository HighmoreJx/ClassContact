#include "MainFrame/LeaveMessage.h"

#include <QtWidgets/QtWidgets>
#include "ToolClass/DataBaseOpt.h"
#include <QTableView>
#include <QTableWidget>
#include "ToolClass/ToolClass.h"
#include "MainFrame/TR.h"

LeaveMessage::LeaveMessage(QWidget* parent /*= 0*/)
{
	messageEdit = NULL;
	msgBtn = NULL;
	messageTableview = NULL;
	mymodel = NULL;

	messageWidget = NULL;
	initStyle();
	init();
	addData();
}

LeaveMessage::~LeaveMessage()
{}

bool LeaveMessage::init()
{
	QFont font;
	font.setFamily(TR("微软雅黑"));
	if (!messageEdit){
		messageEdit = new QTextEdit();
		messageEdit->setObjectName("MessageEdit");
		messageEdit->setFont(font);
		messageEdit->setFixedHeight(100);
	}
	if (!msgBtn){
		msgBtn = new QPushButton();
		msgBtn->setObjectName("msgBtn");
		msgBtn->setFixedHeight(27);
		msgBtn->setFixedWidth(75);
		msgBtn->setFont(font);
		msgBtn->setText(TR("   留言"));
		connect(msgBtn, SIGNAL(clicked()), this, SLOT(msgBtnClicked()));
	}
	QHBoxLayout* msgLayout = new QHBoxLayout();
	msgLayout->addWidget(messageEdit);
	msgLayout->addWidget(msgBtn);
	
	//showList();

	if (!messageWidget)
	{
		messageWidget = new QTableWidget();
		messageWidget->setFont(font);
	}
	setTableWidget();

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(msgLayout);
	mainLayout->addWidget(messageWidget);
	this->setLayout(mainLayout);

	return true;
}

void LeaveMessage::msgBtnClicked()
{
	if (messageEdit->toPlainText().size() != 0)
	{
		DatabaseOpt opt;
		QSqlQuery myquery;

		myquery.prepare("INSERT INTO Message VALUES(?, ?, ?)");
		myquery.bindValue(0, messageEdit->toPlainText());
		myquery.bindValue(1, gclientName);
		myquery.bindValue(2, gclassName);
		if (!myquery.exec())
		{
			QMessageBox::information(0, TR("提示"), TR("发布消息失败"));
			return;
		}
		else
		{
			int rowCount = messageWidget->rowCount();
			messageWidget->insertRow(rowCount);
			QTableWidgetItem *item = new QTableWidgetItem();
			item->setText(messageEdit->toPlainText());
			item->setToolTip(messageEdit->toPlainText());
			QTableWidgetItem *item1 = new QTableWidgetItem();
			item1->setText(gclientName);
			QTableWidgetItem *item2 = new QTableWidgetItem();
			item2->setText(gclassName);

			messageEdit->clear();
			messageWidget->setItem(rowCount, 0, item);
			messageWidget->setItem(rowCount, 1, item1);
			messageWidget->setItem(rowCount, 2, item2);
			QColor color("gray");
			item1->setTextColor(color);
			item2->setTextColor(color);
			item->setTextColor(color);

			messageWidget->item(rowCount, 0)->setTextAlignment(Qt::AlignCenter);
			messageWidget->item(rowCount, 1)->setTextAlignment(Qt::AlignCenter);
			messageWidget->item(rowCount, 2)->setTextAlignment(Qt::AlignCenter);
		}
	}
}

void LeaveMessage::showList()
{
	DatabaseOpt opt;

	messageTableview = new QTableView();
	mymodel = new MySqlModel();

	mymodel->setTable("Message");      //设置某张表
	mymodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	mymodel->setHeaderData(0, Qt::Horizontal, TR("留言内容"));
	mymodel->setHeaderData(1, Qt::Horizontal, TR("姓名"));
	mymodel->setHeaderData(2, Qt::Horizontal, TR("班级"));
	
	mymodel->select();

	messageTableview->setModel(mymodel);
	messageTableview->setEditTriggers(QAbstractItemView::NoEditTriggers);  //不能对表格编辑
	messageTableview->setSortingEnabled(true);     //可排序
	//messageTableview->setSelectionBehavior(QAbstractItemView::SelectRows);     //选中行
	messageTableview->setSelectionMode(QAbstractItemView::SingleSelection);    //可以浏览到表中单独的单元格
	messageTableview->setShowGrid(false);          //网线隐藏
	messageTableview->verticalHeader()->hide();    //隐藏垂直表头
	messageTableview->setAlternatingRowColors(true);           //间隔行颜色不同


	messageTableview->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	messageTableview->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	messageTableview->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

	messageTableview->horizontalHeader()->setSectionsClickable(false);
	messageTableview->resizeColumnsToContents();   //根据列内容调整宽度
}

void LeaveMessage::setTableWidget()
{
	messageWidget->setColumnCount(3);
	//messageWidget->horizontalHeader()->setDefaultSectionSize(150);
	//messageWidget->horizontalHeader()->setClickable(false); //设置表头不可点击（默认点击后进行排序）
	//设置表头内容
	QStringList header;
	header << TR("留言内容") << TR("姓名") << TR("班级");
	messageWidget->setHorizontalHeaderLabels(header);

	//设置表头字体加粗
	QFont font = messageWidget->horizontalHeader()->font();
	font.setFamily(TR("微软雅黑"));
	font.setBold(true);
	messageWidget->horizontalHeader()->setFont(font);
	messageWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
	messageWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	messageWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	messageWidget->verticalHeader()->setDefaultSectionSize(10); //设置行高
	messageWidget->setFrameShape(QFrame::NoFrame); //设置无边框
	messageWidget->setShowGrid(false); //设置不显示格子线
	messageWidget->verticalHeader()->setVisible(false); //设置垂直头不可见
	messageWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  //可多选（Ctrl、Shift、  Ctrl+A都可以）
	messageWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
	messageWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
	
	//messageWidget->horizontalHeader()->sectionResizeMode(0);
	//messageWidget->setColumnWidth(0, 400);
	//messageWidget->setColumnWidth(1, 100);
	//messageWidget->setColumnWidth(2, 100);
	messageWidget->horizontalHeader()->setSectionsClickable(false);
	messageWidget->horizontalHeader()->setFixedHeight(25); //设置表头的高度
	messageWidget->setStyleSheet("selection-background-color:rgb(0,0,0);color:rgb(255,255,255);"); //设置选中背景色
	messageWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,0,0);color:rgb(255,255,255)}"); //设置表头背景色

	//设置水平、垂直滚动条样式
	messageWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	messageWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
}

void LeaveMessage::addData()
{
	DatabaseOpt opt;
	QSqlQuery query("SELECT * FROM Message");
	if (!query.exec())
	{
		QMessageBox::information(0, TR("提示"), TR("提取留言失败"));
		return;
	}
	else
	{
		while (query.next())
		{
			int rowCount = messageWidget->rowCount();
			messageWidget->insertRow(rowCount);
			QTableWidgetItem *item = new QTableWidgetItem();
			item->setText(query.value(0).toString());
			item->setToolTip(query.value(0).toString());
			QTableWidgetItem *item1 = new QTableWidgetItem();
			item1->setText(query.value(1).toString());
			QTableWidgetItem *item2 = new QTableWidgetItem();
			item2->setText(query.value(2).toString());
			messageWidget->setItem(rowCount, 0, item);
			messageWidget->setItem(rowCount, 1, item1);
			messageWidget->setItem(rowCount, 2, item2);
			QColor color("gray");
			item1->setTextColor(color);
			item2->setTextColor(color);
			item->setTextColor(color);

			messageWidget->item(rowCount, 0)->setTextAlignment(Qt::AlignCenter);
			messageWidget->item(rowCount, 1)->setTextAlignment(Qt::AlignCenter);
			messageWidget->item(rowCount, 2)->setTextAlignment(Qt::AlignCenter);
		}
	}
}

void LeaveMessage::initStyle()
{
	QFile file(":/Graduates/Resources/mainFrame.qss");
	file.open(QFile::ReadOnly);
	QString style = QString(file.readAll());
	this->setStyleSheet(style);
	file.close();
}

