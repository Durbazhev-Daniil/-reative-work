#include "webmonitor.h"
#include <QDebug>
#include <QDomDocument>
#include <QDomNodeList>
#include <QTimer>
#include <QRegularExpression>

// Конструктор класса WebMonitor
WebMonitor::WebMonitor(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    timer = new QTimer(this);
    websiteUrl = "https://finance.yahoo.com/markets/currencies/";

    connect(timer, &QTimer::timeout, this, &WebMonitor::fetchData);
    connect(networkManager, &QNetworkAccessManager::finished, this, &WebMonitor::processReply);
}

// Деструктор класса WebMonitor
WebMonitor::~WebMonitor()
{
    delete networkManager;
    delete timer;
}

// Метод для запуска мониторинга
void WebMonitor::startMonitoring()
{
    isMonitoring = true;
    timer->start(10000);
    fetchData();
}

// Метод для остановки мониторинга
void WebMonitor::stopMonitoring()
{
    isMonitoring = false;
    timer->stop();
}

// Слот для получения данных с сайта
void WebMonitor::fetchData()
{
    if (!isMonitoring) return;

    QNetworkRequest request(websiteUrl);
    qDebug() << "Fetching URL: " << websiteUrl;
    networkManager->get(request);
}

// Слот для обработки ответа от сервера
void WebMonitor::processReply(QNetworkReply *reply)
{
    // Проверяем, произошла ли ошибка во время сетевого запроса
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();

        // Проверяем, не пустой ли ответ
        if (data.isEmpty()) {
            qDebug() << "Server returned an empty response.";
            emit parameterValueChanged(USDRUB, "Server returned an empty response");
            reply->deleteLater();
            return;
        }

        // Извлекаем значения для всех валют
        QString rubPrice = extractCurrencyValue(data, USDRUB);
        QString eurPrice = extractCurrencyValue(data, EURUSD);
        QString jpyPrice = extractCurrencyValue(data, JPYUSD);
        QString zarPrice = extractCurrencyValue(data, ZARUSD);


        // Отправляем сигналы с новыми значениями курсов валют
        if (!rubPrice.isEmpty()) {
            emit parameterValueChanged(USDRUB, rubPrice);
            qDebug() << "USD/RUB Price: " << rubPrice;
        } else {
            qDebug() << "Could not find the USD/RUB price.";
            emit parameterValueChanged(USDRUB, "Price not found");
        }

        if (!eurPrice.isEmpty()) {
            emit parameterValueChanged(EURUSD, eurPrice);
            qDebug() << "EUR/USD Price: " << eurPrice;
        } else {
            qDebug() << "Could not find the EUR/USD price.";
            emit parameterValueChanged(EURUSD, "Price not found");
        }

        if (!jpyPrice.isEmpty()) {
            emit parameterValueChanged(JPYUSD, jpyPrice);
            qDebug() << "JPY/USD Price: " << jpyPrice;
        } else {
            qDebug() << "Could not find the JPY/USD price.";
            emit parameterValueChanged(JPYUSD, "Price not found");
        }

        if (!zarPrice.isEmpty()) {
            emit parameterValueChanged(ZARUSD, zarPrice);
            qDebug() << "ZAR/USD Price: " << zarPrice;
        } else {
            qDebug() << "Could not find the ZAR/USD price.";
            emit parameterValueChanged(ZARUSD, "Price not found");
        }

        reply->deleteLater();

    } else {// Если произошла ошибка во время сетевого запроса
        qDebug() << "Error: " << reply->errorString();
        emit parameterValueChanged(USDRUB, "Error: " + reply->errorString());
        emit parameterValueChanged(EURUSD, "Error: " + reply->errorString());
        emit parameterValueChanged(JPYUSD, "Error: " + reply->errorString());
        emit parameterValueChanged(ZARUSD, "Error: " + reply->errorString());
        reply->deleteLater();
    }
}

// Метод для извлечения значения курса валюты из HTML
QString WebMonitor::extractCurrencyValue(const QByteArray& data, CurrencyType currency) {
    QString symbol;
    switch (currency) {
    case USDRUB: symbol = "RUB=X"; break;
    case EURUSD: symbol = "EURUSD=X"; break;
    case JPYUSD: symbol = "JPY=X"; break;
    case ZARUSD: symbol = "ZAR=X"; break;
    }

    QString html = QString::fromUtf8(data);
    QString pattern = "<fin-streamer[^>]*data-symbol=\"" + symbol + "\"[^>]*data-value=\"([0-9.]+)\"[^>]*>([^<]+)</fin-streamer>";
    QRegularExpression re(pattern);
    QRegularExpressionMatch match = re.match(html);

    if (match.hasMatch()) {
        return match.captured(1);
    } else {
        return QString(); // Возвращаем пустую строку, если не найдено
    }
}
