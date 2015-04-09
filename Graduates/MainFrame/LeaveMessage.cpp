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
	font.setFamily(TR("΢���ź�"));
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
		msgBtn->setText(TR("   ����"));
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
			QMessageBox::information(0, TR("��ʾ"), TR("������Ϣʧ��"));
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

	mymodel->setTable("Message");      //����ĳ�ű�
	mymodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	mymodel->setHeaderData(0, Qt::Horizontal, TR("��������"));
	mymodel->setHeaderData(1, Qt::Horizontal, TR("����"));
	mymodel->setHeaderData(2, Qt::Horizontal, TR("�༶"));
	
	mymodel->select();

	messageTableview->setModel(mymodel);
	messageTableview->setEditTriggers(QAbstractItemView::NoEditTriggers);  //���ܶԱ��༭
	messageTableview->setSortingEnabled(true);     //������
	//messageTableview->setSelectionBehavior(QAbstractItemView::SelectRows);     //ѡ����
	messageTableview->setSelectionMode(QAbstractItemView::SingleSelection);    //������������е����ĵ�Ԫ��
	messageTableview->setShowGrid(false);          //��������
	messageTableview->verticalHeader()->hide();    //���ش�ֱ��ͷ
	messageTableview->setAlternatingRowColors(true);           //�������ɫ��ͬ


	messageTableview->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	messageTableview->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	messageTableview->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

	messageTableview->horizontalHeader()->setSectionsClickable(false);
	messageTableview->resizeColumnsToContents();   //���������ݵ������
}

void LeaveMessage::setTableWidget()
{
	messageWidget->setColumnCount(3);
	//messageWidget->horizontalHeader()->setDefaultSectionSize(150);
	//messageWidget->horizontalHeader()->setClickable(false); //���ñ�ͷ���ɵ����Ĭ�ϵ�����������
	//���ñ�ͷ����
	QStringList header;
	header << TR("��������") << TR("����") << TR("�༶");
	messageWidget->setHorizontalHeaderLabels(header);

	//���ñ�ͷ����Ӵ�
	QFont font = messageWidget->horizontalHeader()->font();
	font.setFamily(TR("΢���ź�"));
	font.setBold(true);
	messageWidget->horizontalHeader()->setFont(font);
	messageWidget->horizontalHeader()->setStretchLastSection(true); //���ó�������
	messageWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	messageWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	messageWidget->verticalHeader()->setDefaultSectionSize(10); //�����и�
	messageWidget->setFrameShape(QFrame::NoFrame); //�����ޱ߿�
	messageWidget->setShowGrid(false); //���ò���ʾ������
	messageWidget->verticalHeader()->setVisible(false); //���ô�ֱͷ���ɼ�
	messageWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);  //�ɶ�ѡ��Ctrl��Shift��  Ctrl+A�����ԣ�
	messageWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ����Ϊʱÿ��ѡ��һ��
	messageWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭
	
	//messageWidget->horizontalHeader()->sectionResizeMode(0);
	//messageWidget->setColumnWidth(0, 400);
	//messageWidget->setColumnWidth(1, 100);
	//messageWidget->setColumnWidth(2, 100);
	messageWidget->horizontalHeader()->setSectionsClickable(false);
	messageWidget->horizontalHeader()->setFixedHeight(25); //���ñ�ͷ�ĸ߶�
	messageWidget->setStyleSheet("selection-background-color:rgb(0,0,0);color:rgb(255,255,255);"); //����ѡ�б���ɫ
	messageWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,0,0);color:rgb(255,255,255)}"); //���ñ�ͷ����ɫ

	//����ˮƽ����ֱ��������ʽ
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
		QMessageBox::information(0, TR("��ʾ"), TR("��ȡ����ʧ��"));
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

