#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPalette>
#include <QUrl>
#include <QDesktopServices>

// Конструктор класса MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUi();

    webMonitor = new WebMonitor(this);

    connect(webMonitor, &WebMonitor::parameterValueChanged, this, &MainWindow::updateParameterValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Метод для дополнительной настройки UI
void MainWindow::setupUi()
{
    // Находим элементы UI по их именам
    startButton = findChild<QPushButton*>("startButton");
    currencyValueLabel = findChild<QLabel*>("currencyValueLabel");// Лейбы для отображения курса валют
    eurusdValueLabel = findChild<QLabel*>("eurusdValueLabel");
    jpyusdValueLabel = findChild<QLabel*>("jpyusdValueLabel");
    zarusdValueLabel = findChild<QLabel*>("zarusdValueLabel");

    // Индикаторы
    usdrubIndicator = findChild<QLabel*>("usdrubIndicator");
    eurusdIndicator = findChild<QLabel*>("eurusdIndicator");
    jpyusdIndicator = findChild<QLabel*>("jpyusdIndicator");
    zarusdIndicator = findChild<QLabel*>("zarusdIndicator");

    //кнопки для открытия ссылок на сайты по данным курсам валют
    openLinkButton = findChild<QPushButton*>("openLinkButton");
    newLinkButton1 = findChild<QPushButton*>("newLinkButton1");
    newLinkButton2 = findChild<QPushButton*>("newLinkButton2");
    newLinkButton3 = findChild<QPushButton*>("newLinkButton3");
    background = findChild<QLabel*>("background");

    //подключение кнопок
    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartStopButtonClicked);
    connect(openLinkButton, &QPushButton::clicked, this, &MainWindow::openYahooFinanceLink);
    connect(newLinkButton1, &QPushButton::clicked, this, &MainWindow::openLink1);
    connect(newLinkButton2, &QPushButton::clicked, this, &MainWindow::openLink2);
    connect(newLinkButton3, &QPushButton::clicked, this, &MainWindow::openLink3);

    // Установка начальных цветов точек
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(Qt::black));

    auto setupIndicator = [&](QLabel* indicator) {
        indicator->setAutoFillBackground(true);
        palette.setColor(QPalette::Window, QColor(Qt::black)); // Явно устанавливаем черный цвет
        indicator->setPalette(palette);
        indicator->setFixedSize(20, 20); // Явно устанавливаем размер

        indicator->update();
    };

    setupIndicator(usdrubIndicator);
    setupIndicator(eurusdIndicator);
    setupIndicator(jpyusdIndicator);
    setupIndicator(zarusdIndicator);

    palette.setColor(QPalette::Window, QColor(Qt::black));
    background->setAutoFillBackground(true);
    background->setPalette(palette);
    background->update();
}

// Слот, вызываемый при нажатии на кнопку Start/Stop Monitoring
void MainWindow::onStartStopButtonClicked()
{
    monitoringRunning = !monitoringRunning;

    if (monitoringRunning) {
        startButton->setText("Stop Monitoring");
        webMonitor->startMonitoring();
    } else {
        startButton->setText("Start Monitoring");
        webMonitor->stopMonitoring();
    }
}

// Слот, вызываемый при получении нового значения курса валюты от WebMonitor
void MainWindow::updateParameterValue(WebMonitor::CurrencyType currency, const QString& value)
{
    bool ok;
    double doubleValue = value.toDouble(&ok);

    //вывод ошибки
    if (!ok) {
        qDebug() << "Could not convert currency value to double.";
        return;
    }

    // Обновляем соответствующий лейбл и индикатор в зависимости от типа валюты
    switch (currency) {
    case WebMonitor::USDRUB:
        currencyValueLabel->setText("Currency Value USD/RUB: " + value);
        updateCurrencyIndicator(usdrubIndicator, doubleValue, 80, 70);
        break;
    case WebMonitor::EURUSD:
        eurusdValueLabel->setText("Currency Value EUR/USD: " + value);
        updateCurrencyIndicator(eurusdIndicator, doubleValue, 1.2, 1.0);
        break;
    case WebMonitor::JPYUSD:
        jpyusdValueLabel->setText("Currency Value JPY/USD: " + value);
        updateCurrencyIndicator(jpyusdIndicator, doubleValue, 155, 135);
        break;
    case WebMonitor::ZARUSD:
        zarusdValueLabel->setText("Currency Value ZAR/USD: " + value);
        updateCurrencyIndicator(zarusdIndicator, doubleValue, 19, 17);
        break;
    }
}

// Метод для обновления цвета индикатора
void MainWindow::updateCurrencyIndicator(QLabel* indicator, double value, double upperThreshold, double lowerThreshold) {
    QPalette palette;
    if (value > upperThreshold || value < lowerThreshold) {
        palette.setColor(QPalette::Window, QColor(Qt::red));
    } else {
        palette.setColor(QPalette::Window, QColor(Qt::green));
    }
    indicator->setAutoFillBackground(true);
    indicator->setPalette(palette);
    indicator->update();
}

// Слоты, вызываемые при нажатии на крнопки Open(курс валют)ё
void MainWindow::openYahooFinanceLink()
{
    QUrl url("https://www.finam.ru/quote/forex/usdrub/");
    QDesktopServices::openUrl(url);
}

void MainWindow::openLink1()
{
    QUrl url("https://www.finam.ru/quote/forex/eurusd/");
    QDesktopServices::openUrl(url);
}

void MainWindow::openLink2()
{
    QUrl url("https://www.finam.ru/quote/forex/usdjpy/");
    QDesktopServices::openUrl(url);
}

void MainWindow::openLink3()
{
    QUrl url("https://www.finam.ru/quote/forex/zarusd/");
    QDesktopServices::openUrl(url);
}
