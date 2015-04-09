#include "ToolClass/ToolClass.h"
#include <QModelIndex>
#include <QtWidgets/QtWidgets>
#include "MainFrame/TR.h"


QVariant MySqlModel::data(const QModelIndex& item, int role) const
{
	QVariant value = QSqlTableModel::data(item, role);
	if (role == Qt::TextAlignmentRole)
	{
		value = (Qt::AlignCenter);
		return value;
	}

	return value;

}



CreateClassDialog::CreateClassDialog(QDialog* parent /*= 0*/)
{
	inputEdit = NULL;
	sureBtn = NULL;
	cancelBtn = NULL;
	infoLabel = NULL;

	init();
}

bool CreateClassDialog::init()
{
	if (!inputEdit)
		inputEdit = new QLineEdit();

	if (!sureBtn)
	{
		sureBtn = new QPushButton();
		sureBtn->setText(TR("ȷ��"));
		connect(sureBtn, SIGNAL(clicked()), this, SLOT(sureBtnClicked()));
	}

	if (!cancelBtn)
	{
		cancelBtn = new QPushButton();
		cancelBtn->setText(TR("ȡ��"));
		connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtnClicked()));
	}

	if (!infoLabel)
	{
		infoLabel = new QLabel();
		infoLabel->setText(TR("�����봴���༶����:"));
	}

	QHBoxLayout* btnLayout = new QHBoxLayout();
	btnLayout->addWidget(sureBtn);
	btnLayout->addWidget(cancelBtn);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(infoLabel);
	mainLayout->addWidget(inputEdit);
	mainLayout->addLayout(btnLayout);

	this->setLayout(mainLayout);

	return true;
}

void CreateClassDialog::sureBtnClicked()
{
	emit classCreateSig(inputEdit->text());
}

void CreateClassDialog::cancelBtnClicked()
{
	this->close();
}
