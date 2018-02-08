/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 8. Feb 09:41:52 2018
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QRadioButton *StupidButton;
    QRadioButton *SortBinButton_2;
    QRadioButton *MergeButton_3;
    QRadioButton *QuickButton_4;
    QGroupBox *groupBox_2;
    QRadioButton *IncreaseButton_5;
    QRadioButton *DecreaseButton_6;
    QGroupBox *groupBox_3;
    QRadioButton *NumberButton_7;
    QRadioButton *FileButton_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QLabel *label;
    QLabel *label_4;
    QWidget *tab_2;
    QTableView *tableView;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(729, 517);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 721, 501));
        tabWidget->setMinimumSize(QSize(700, 0));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 161, 141));
        StupidButton = new QRadioButton(groupBox);
        StupidButton->setObjectName(QString::fromUtf8("StupidButton"));
        StupidButton->setGeometry(QRect(10, 20, 82, 17));
        SortBinButton_2 = new QRadioButton(groupBox);
        SortBinButton_2->setObjectName(QString::fromUtf8("SortBinButton_2"));
        SortBinButton_2->setGeometry(QRect(10, 50, 111, 17));
        MergeButton_3 = new QRadioButton(groupBox);
        MergeButton_3->setObjectName(QString::fromUtf8("MergeButton_3"));
        MergeButton_3->setGeometry(QRect(10, 80, 82, 17));
        QuickButton_4 = new QRadioButton(groupBox);
        QuickButton_4->setObjectName(QString::fromUtf8("QuickButton_4"));
        QuickButton_4->setGeometry(QRect(10, 110, 82, 17));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 160, 161, 81));
        IncreaseButton_5 = new QRadioButton(groupBox_2);
        IncreaseButton_5->setObjectName(QString::fromUtf8("IncreaseButton_5"));
        IncreaseButton_5->setGeometry(QRect(10, 20, 121, 17));
        DecreaseButton_6 = new QRadioButton(groupBox_2);
        DecreaseButton_6->setObjectName(QString::fromUtf8("DecreaseButton_6"));
        DecreaseButton_6->setGeometry(QRect(10, 50, 101, 17));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 260, 161, 80));
        NumberButton_7 = new QRadioButton(groupBox_3);
        NumberButton_7->setObjectName(QString::fromUtf8("NumberButton_7"));
        NumberButton_7->setGeometry(QRect(10, 20, 101, 17));
        FileButton_8 = new QRadioButton(groupBox_3);
        FileButton_8->setObjectName(QString::fromUtf8("FileButton_8"));
        FileButton_8->setGeometry(QRect(10, 50, 101, 17));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 440, 75, 23));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 440, 75, 23));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 10, 101, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 220, 141, 16));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(210, 30, 491, 171));
        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(220, 260, 491, 171));
        textBrowser_3 = new QTextBrowser(tab);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(0, 350, 161, 71));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 10, 181, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 10, 46, 13));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(5, 1, 701, 441));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270:", 0, QApplication::UnicodeUTF8));
        StupidButton->setText(QApplication::translate("MainWindow", "\320\223\320\273\321\203\320\277\320\260\321\217", 0, QApplication::UnicodeUTF8));
        SortBinButton_2->setText(QApplication::translate("MainWindow", "\320\224\320\262\320\276\320\270\321\207\320\275\320\260\321\217 \320\262\321\201\321\202\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        MergeButton_3->setText(QApplication::translate("MainWindow", "\320\235\320\270\321\201\321\205\320\276\320\264\321\217\321\211\320\260\321\217 \320\277\320\276\321\200\320\260\320\267\321\200\321\217\320\264\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8));
        QuickButton_4->setText(QApplication::translate("MainWindow", "\320\221\321\213\321\201\321\202\321\200\320\260\321\217", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\272 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214:", 0, QApplication::UnicodeUTF8));
        IncreaseButton_5->setText(QApplication::translate("MainWindow", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8));
        DecreaseButton_6->setText(QApplication::translate("MainWindow", "\320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\201\320\276\321\200\321\202\320\270\321\200\321\203\320\265\320\274\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205:", 0, QApplication::UnicodeUTF8));
        NumberButton_7->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\270\320\262 \321\207\320\270\321\201\320\265\320\273", 0, QApplication::UnicodeUTF8));
        FileButton_8->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\270\320\262 \320\267\320\260\320\277\320\270\321\201\320\265\320\271", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\262 \320\274\320\260\321\201\321\201\320\270\320\262\320\265:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\245\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\260 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\276\320\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
