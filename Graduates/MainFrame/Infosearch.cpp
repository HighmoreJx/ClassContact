#include "MainFrame/Infosearch.h"
#include "MainFrame/TR.h"
#include <QtWidgets/QtWidgets>
#include <QSqlTableModel>
#include "ToolClass/DataBaseOpt.h"

#include "ToolClass/ToolClass.h"


InfoSearch::InfoSearch(QWidget* parent /*= 0*/)
{
	nameLabel = NULL;
	nameEdit = NULL;
	classLabel = NULL;
	classEdit = NULL;
	admissionLabel = NULL;
	admission = NULL;
	searchBtn = NULL;
	infoTableWidget = NULL;

	init();
}

InfoSearch::~InfoSearch()
{

}

void InfoSearch::searchBtnClicked()
{
	DatabaseOpt opt;
	
	//������Ż�
	if (nameEdit->text() != "" && classEdit->text() != "" && admission->text() != "")
	{
		model->setFilter(QObject::tr("name='%1' AND classname='%2' AND admission='%3'").arg(nameEdit->text()).arg(classEdit->text()).arg(admission->text()));
	}
	else if (nameEdit->text() != "" && classEdit->text() != "")
	{
		model->setFilter(QObject::tr("name='%1' AND classname='%2'").arg(nameEdit->text()).arg(classEdit->text()));
	}
	else if (nameEdit->text() != "" && admission->text() != "")
	{
		model->setFilter(QObject::tr("name='%1' AND admission='%2'").arg(nameEdit->text()).arg(admission->text()));
	}
	else if (classEdit->text() != "" && admission->text() != "")
	{
		model->setFilter(QObject::tr("classname='%1' AND admission='%2'").arg(classEdit->text()).arg(admission->text()));
	}
	else if (nameEdit->text() != "")
	{
		model->setFilter(QObject::tr("name='%1'").arg(nameEdit->text()));
	}
	else if (classEdit->text() != "")
	{
		model->setFilter(QObject::tr("classname='%1'").arg(classEdit->text()));
	}
	else if (admission->text() != "")
	{
		model->setFilter(QObject::tr("admission='%1'").arg(admission->text()));
	}
	else
	{
		model->setFilter(QObject::tr(""));
	}
// 	if (classEdit->text() != "")
// 	{
// 		model->setFilter(QObject::tr("classname='%1'").arg(classEdit->text()));
// 	}
// 	if (admission->text() != "")
// 	{
// 		model->setFilter(QObject::tr("admission='%1'").arg(admission->text()));
// 	}
	model->select();
}

bool InfoSearch::init()
{
	QFont font;
	font.setFamily(TR("΢���ź�"));
	font.setPointSize(10);

	if (!nameLabel){
		nameLabel = new QLabel();
		nameLabel->setText(TR("����:"));
		nameLabel->setFont(font);
	}
	if (!nameEdit){
		nameEdit = new QLineEdit();
		nameEdit->setObjectName("SearchEdit");
		nameEdit->setFont(font);
	}
	if (!classLabel){
		classLabel = new QLabel();
		classLabel->setText(TR("�༶:"));
		classLabel->setFont(font);
	}
	if (!classEdit){
		classEdit = new QLineEdit();
		classEdit->setObjectName("SearchEdit");
		classEdit->setFont(font);
	}
	if (!admissionLabel){
		admissionLabel = new QLabel();
		admissionLabel->setText(TR("��У����:"));
		admissionLabel->setFont(font);
	}
	if (!admission){
		admission = new QLineEdit();
		admission->setObjectName("SearchEdit");
		admission->setFont(font);
	}
	if (!searchBtn){
		searchBtn = new QPushButton();
		searchBtn->setText(TR("����"));
		searchBtn->setFixedWidth(50);
		searchBtn->setObjectName("choiceBtn");
		searchBtn->setFont(font);
		connect(searchBtn, SIGNAL(clicked()), this, SLOT(searchBtnClicked()));
	}
	if (!infoTableWidget){
		infoTableWidget = new QTableWidget();
	}

	QHBoxLayout* topLayout = new QHBoxLayout();
	topLayout->addWidget(nameLabel);
	topLayout->addWidget(nameEdit);
	topLayout->addWidget(classLabel);
	topLayout->addWidget(classEdit);
	topLayout->addWidget(admissionLabel);
	topLayout->addWidget(admission);
	topLayout->addWidget(searchBtn);

	containterWidget = new QWidget();
	showData();

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(topLayout);
	mainLayout->addWidget(containterWidget);
	this->setLayout(mainLayout);

	

	return true;
}

void InfoSearch::showData()
{
	DatabaseOpt opt;
	infoTableView = new QTableView();
	model = new MySqlModel();
	
	model->setTable("ClientExits");      //����ĳ�ű�
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setHeaderData(1, Qt::Horizontal, TR("����"));
	model->setHeaderData(2, Qt::Horizontal, TR("�༶"));
	model->setHeaderData(3, Qt::Horizontal, TR("��У����"));
	model->setHeaderData(4, Qt::Horizontal, TR("��ϵ��ʽ")); 
	model->setHeaderData(6, Qt::Horizontal, TR("����༶"));

	//model->setHeaderData(4, Qt::Horizontal, TR("��ע"));

	model->select();      //��ɸѡ������������£������ݿ��з���Ҫ�����mode�������ʾ����

	infoTableView->setModel(model);
	infoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //���ܶԱ��༭
	infoTableView->setSortingEnabled(true);     //������
	infoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);     //ѡ����
	infoTableView->setSelectionMode(QAbstractItemView::SingleSelection);    //������������е����ĵ�Ԫ��
	infoTableView->setShowGrid(false);          //��������
	infoTableView->verticalHeader()->hide();    //���ش�ֱ��ͷ
	infoTableView->setAlternatingRowColors(true);           //�������ɫ��ͬ

	infoTableView->setColumnHidden(0, true);
	infoTableView->setColumnHidden(5, true);

	infoTableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	infoTableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	infoTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	infoTableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);



	infoTableView->horizontalHeader()->setSectionsClickable(false);
	infoTableView->resizeColumnsToContents();   //���������ݵ������

	//���ñ�ͷ����Ӵ�
	QFont font = infoTableView->horizontalHeader()->font();
	font.setFamily(TR("΢���ź�"));
	font.setBold(true);
	infoTableView->horizontalHeader()->setFont(font);
	infoTableView->setFont(font);



	infoTableView->setStyleSheet("selection-background-color:rgb(0,0,0);color:gray;"); //����ѡ�б���ɫ
	infoTableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,0,0);color:rgb(255,255,255)}"); //���ñ�ͷ����ɫ

	//����ˮƽ����ֱ��������ʽ
	infoTableView->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	infoTableView->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");


	QHeaderView *header = infoTableView->horizontalHeader();
	header->setStretchLastSection(true);
	QHBoxLayout* mainLayout = new QHBoxLayout();
	mainLayout->addWidget(infoTableView);
	containterWidget->setLayout(mainLayout);
}

void InfoSearch::updateInfo()
{
	//model->select();
	model->clear();
	showData();
}
