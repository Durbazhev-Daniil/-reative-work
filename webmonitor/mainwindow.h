#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "webmonitor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onStartStopButtonClicked();
    void updateParameterValue(WebMonitor::CurrencyType currency, const QString& value);
    void openYahooFinanceLink();
    void openLink1();
    void openLink2();
    void openLink3();

private:
    Ui::MainWindow *ui;
    QPushButton *startButton;
    QLabel *currencyValueLabel;
    QLabel *eurusdValueLabel;
    QLabel *jpyusdValueLabel;
    QLabel *zarusdValueLabel;

    // Индикаторы
    QLabel *usdrubIndicator;
    QLabel *eurusdIndicator;
    QLabel *jpyusdIndicator;
    QLabel *zarusdIndicator;

    QLabel *background;
    QPushButton *openLinkButton;
    QPushButton *newLinkButton1;
    QPushButton *newLinkButton2;
    QPushButton *newLinkButton3;
    WebMonitor *webMonitor;
    bool monitoringRunning = false;

    void setupUi();
    void updateCurrencyIndicator(QLabel* indicator, double value, double upperThreshold, double lowerThreshold);
};
#endif // MAINWINDOW_H
