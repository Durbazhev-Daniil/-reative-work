#ifndef WEBMONITOR_H
#define WEBMONITOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>

class WebMonitor : public QObject
{
    Q_OBJECT

public:
    enum CurrencyType {
        USDRUB,
        EURUSD,
        JPYUSD,
        ZARUSD
    };

    WebMonitor(QObject *parent = nullptr);
    ~WebMonitor() override;

    void startMonitoring();
    void stopMonitoring();

signals:
    void parameterValueChanged(CurrencyType currency, const QString& value);

private slots:
    void fetchData();
    void processReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    QTimer *timer;
    QString websiteUrl;  // URL сайта для мониторинга
    bool isMonitoring = false;

    QString extractCurrencyValue(const QByteArray& data, CurrencyType currency);
};

#endif // WEBMONITOR_H
