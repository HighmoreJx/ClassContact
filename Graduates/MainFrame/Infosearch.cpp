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
	
	//这里待优化
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
	font.setFamily(TR("微软雅黑"));
	font.setPointSize(10);

	if (!nameLabel){
		nameLabel = new QLabel();
		nameLabel->setText(TR("姓名:"));
		nameLabel->setFont(font);
	}
	if (!nameEdit){
		nameEdit = new QLineEdit();
		nameEdit->setObjectName("SearchEdit");
		nameEdit->setFont(font);
	}
	if (!classLabel){
		classLabel = new QLabel();
		classLabel->setText(TR("班级:"));
		classLabel->setFont(font);
	}
	if (!classEdit){
		classEdit = new QLineEdit();
		classEdit->setObjectName("SearchEdit");
		classEdit->setFont(font);
	}
	if (!admissionLabel){
		admissionLabel = new QLabel();
		admissionLabel->setText(TR("入校日期:"));
		admissionLabel->setFont(font);
	}
	if (!admission){
		admission = new QLineEdit();
		admission->setObjectName("SearchEdit");
		admission->setFont(font);
	}
	if (!searchBtn){
		searchBtn = new QPushButton();
		searchBtn->setText(TR("搜索"));
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
	
	model->setTable("ClientExits");      //设置某张表
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setHeaderData(1, Qt::Horizontal, TR("姓名"));
	model->setHeaderData(2, Qt::Horizontal, TR("班级"));
	model->setHeaderData(3, Qt::Horizontal, TR("入校日期"));
	model->setHeaderData(4, Qt::Horizontal, TR("联系方式")); 
	model->setHeaderData(6, Qt::Horizontal, TR("管理班级"));

	//model->setHeaderData(4, Qt::Horizontal, TR("备注"));

	model->select();      //在筛选和排序的条件下，将数据库中符合要求的在mode表格中显示出来

	infoTableView->setModel(model);
	infoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //不能对表格编辑
	infoTableView->setSortingEnabled(true);     //可排序
	infoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);     //选中行
	infoTableView->setSelectionMode(QAbstractItemView::SingleSelection);    //可以浏览到表中单独的单元格
	infoTableView->setShowGrid(false);          //网线隐藏
	infoTableView->verticalHeader()->hide();    //隐藏垂直表头
	infoTableView->setAlternatingRowColors(true);           //间隔行颜色不同

	infoTableView->setColumnHidden(0, true);
	infoTableView->setColumnHidden(5, true);

	infoTableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	infoTableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
	infoTableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
	infoTableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);



	infoTableView->horizontalHeader()->setSectionsClickable(false);
	infoTableView->resizeColumnsToContents();   //根据列内容调整宽度

	//设置表头字体加粗
	QFont font = infoTableView->horizontalHeader()->font();
	font.setFamily(TR("微软雅黑"));
	font.setBold(true);
	infoTableView->horizontalHeader()->setFont(font);
	infoTableView->setFont(font);



	infoTableView->setStyleSheet("selection-background-color:rgb(0,0,0);color:gray;"); //设置选中背景色
	infoTableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(0,0,0);color:rgb(255,255,255)}"); //设置表头背景色

	//设置水平、垂直滚动条样式
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
