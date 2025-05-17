/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QLabel *currencyValueLabel;
    QPushButton *openLinkButton;
    QLabel *background;
    QLabel *eurusdValueLabel;
    QLabel *jpyusdValueLabel;
    QLabel *zarusdValueLabel;
    QLabel *usdrubIndicator;
    QLabel *eurusdIndicator;
    QLabel *jpyusdIndicator;
    QLabel *zarusdIndicator;
    QPushButton *newLinkButton1;
    QPushButton *newLinkButton2;
    QPushButton *newLinkButton3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(270, 390, 251, 51));
        QFont font;
        font.setPointSize(20);
        startButton->setFont(font);
        currencyValueLabel = new QLabel(centralwidget);
        currencyValueLabel->setObjectName("currencyValueLabel");
        currencyValueLabel->setGeometry(QRect(20, 10, 741, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(20);
        currencyValueLabel->setFont(font1);
        openLinkButton = new QPushButton(centralwidget);
        openLinkButton->setObjectName("openLinkButton");
        openLinkButton->setGeometry(QRect(600, 20, 191, 31));
        QFont font2;
        font2.setPointSize(15);
        openLinkButton->setFont(font2);
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(-20, -30, 991, 721));
        eurusdValueLabel = new QLabel(centralwidget);
        eurusdValueLabel->setObjectName("eurusdValueLabel");
        eurusdValueLabel->setGeometry(QRect(20, 90, 481, 41));
        eurusdValueLabel->setFont(font);
        jpyusdValueLabel = new QLabel(centralwidget);
        jpyusdValueLabel->setObjectName("jpyusdValueLabel");
        jpyusdValueLabel->setGeometry(QRect(20, 170, 491, 51));
        jpyusdValueLabel->setFont(font);
        zarusdValueLabel = new QLabel(centralwidget);
        zarusdValueLabel->setObjectName("zarusdValueLabel");
        zarusdValueLabel->setGeometry(QRect(20, 250, 511, 51));
        zarusdValueLabel->setFont(font);
        usdrubIndicator = new QLabel(centralwidget);
        usdrubIndicator->setObjectName("usdrubIndicator");
        usdrubIndicator->setGeometry(QRect(530, 20, 63, 20));
        usdrubIndicator->setAutoFillBackground(false);
        eurusdIndicator = new QLabel(centralwidget);
        eurusdIndicator->setObjectName("eurusdIndicator");
        eurusdIndicator->setGeometry(QRect(530, 100, 63, 20));
        jpyusdIndicator = new QLabel(centralwidget);
        jpyusdIndicator->setObjectName("jpyusdIndicator");
        jpyusdIndicator->setGeometry(QRect(530, 180, 63, 20));
        zarusdIndicator = new QLabel(centralwidget);
        zarusdIndicator->setObjectName("zarusdIndicator");
        zarusdIndicator->setGeometry(QRect(530, 260, 63, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        zarusdIndicator->setFont(font3);
        newLinkButton1 = new QPushButton(centralwidget);
        newLinkButton1->setObjectName("newLinkButton1");
        newLinkButton1->setGeometry(QRect(600, 100, 191, 31));
        newLinkButton1->setFont(font2);
        newLinkButton2 = new QPushButton(centralwidget);
        newLinkButton2->setObjectName("newLinkButton2");
        newLinkButton2->setGeometry(QRect(600, 180, 191, 31));
        newLinkButton2->setFont(font2);
        newLinkButton3 = new QPushButton(centralwidget);
        newLinkButton3->setObjectName("newLinkButton3");
        newLinkButton3->setGeometry(QRect(600, 260, 191, 31));
        newLinkButton3->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        background->raise();
        startButton->raise();
        currencyValueLabel->raise();
        openLinkButton->raise();
        eurusdValueLabel->raise();
        jpyusdValueLabel->raise();
        zarusdValueLabel->raise();
        usdrubIndicator->raise();
        eurusdIndicator->raise();
        jpyusdIndicator->raise();
        zarusdIndicator->raise();
        newLinkButton1->raise();
        newLinkButton2->raise();
        newLinkButton3->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start Monitoring", nullptr));
        currencyValueLabel->setText(QCoreApplication::translate("MainWindow", "Currency Value USD/RUB: N/A", nullptr));
        openLinkButton->setText(QCoreApplication::translate("MainWindow", "Open USD/RUB", nullptr));
        background->setText(QString());
        eurusdValueLabel->setText(QCoreApplication::translate("MainWindow", "Currency Value EUR/USD: N/A", nullptr));
        jpyusdValueLabel->setText(QCoreApplication::translate("MainWindow", "Currency Value  JPY/USD: N/A", nullptr));
        zarusdValueLabel->setText(QCoreApplication::translate("MainWindow", "Currency Value ZAR/USD: N/A", nullptr));
        usdrubIndicator->setText(QString());
        eurusdIndicator->setText(QString());
        jpyusdIndicator->setText(QString());
        zarusdIndicator->setText(QString());
        newLinkButton1->setText(QCoreApplication::translate("MainWindow", "Open  EUR/USD", nullptr));
        newLinkButton2->setText(QCoreApplication::translate("MainWindow", "Open JPY/USD", nullptr));
        newLinkButton3->setText(QCoreApplication::translate("MainWindow", "Open ZAR/USD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
