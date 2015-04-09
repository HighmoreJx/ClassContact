/********************************************************************************
** Form generated from reading UI file 'graduates.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADUATES_H
#define UI_GRADUATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraduatesClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraduatesClass)
    {
        if (GraduatesClass->objectName().isEmpty())
            GraduatesClass->setObjectName(QStringLiteral("GraduatesClass"));
        GraduatesClass->resize(600, 400);
        menuBar = new QMenuBar(GraduatesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GraduatesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraduatesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GraduatesClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GraduatesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GraduatesClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GraduatesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GraduatesClass->setStatusBar(statusBar);

        retranslateUi(GraduatesClass);

        QMetaObject::connectSlotsByName(GraduatesClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraduatesClass)
    {
        GraduatesClass->setWindowTitle(QApplication::translate("GraduatesClass", "Graduates", 0));
    } // retranslateUi

};

namespace Ui {
    class GraduatesClass: public Ui_GraduatesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADUATES_H
