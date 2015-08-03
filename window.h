#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class QComboBox;
class QLabel;
class QTextBrowser;
class QGridLayout;
class QSpinBox;
class QTimer;

class window : public QMainWindow
{
    QWidget *centralWidget;
    QGridLayout* mainLayout;
    Q_OBJECT

public:
    window(QWidget *parent = 0);
    int count, cost; //перменные комбобокса
    int cryCount, oreCount; //количество
    int divV, moneyV, cryV, oreV, totalV; //глобальные перменные
    int cry, ore, odd, income, after, alpha; //внутренние переменные
    ~window();

private slots:
    void changeMode();
    void craftCountValue();
    void cryBuyValue();
    void oreBuyValue();
    void oddValue();
    void incomeValue();
    void afterValue();
    void update();

private:
    QLabel *textMode;
    QLabel *textMoney;
    QLabel *textCry;
    QLabel *textOre;
    QLabel *textCreate;
    QLabel *textBCry;
    QLabel *textBOre;
    QLabel *textOdd;
    QLabel *textIncome;
    QLabel *textAfter;
    QComboBox *selMode;
    QSpinBox *editMoney;
    QSpinBox *editCry;
    QSpinBox *editOre;
    QTextBrowser *calcCreate;
    QTextBrowser *calcBCry;
    QTextBrowser *calcBOre;
    QTextBrowser *calcOdd;
    QTextBrowser *calcIncome;
    QTextBrowser *calcAfter;
    QTimer *timer;
};

#endif // WINDOW_H
