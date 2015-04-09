#ifndef LINKLABEL_H
#define LINKLABEL_H

#include <QToolButton>

class LinkLabel : public QToolButton
{
	Q_OBJECT
public:
	LinkLabel(QWidget *parent = 0);
	~LinkLabel();
private:
	void initStyle();  // º”‘ÿqss 
private:
	bool m_isLink;
};

#endif // LINKLABEL_H
