#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class QComboBox;
class QLabel;
class QLineEdit;
class QTextBrowser;
class QGridLayout;
class QSpinBox;

class window : public QMainWindow
{
    QWidget *centralWidget;
    QGridLayout* mainLayout;
    Q_OBJECT

public:
    window(QWidget *parent = 0);
    int mode, count, cost;
    int cryCount, oreCount;
    int divV, moneyV, cryV, oreV, totalV;
    int cry, ore, odd, income, after, alpha, a;
    ~window();

private slots:
    //void divClass();
    void changeMode();
    void craftCountValue();
    void cryBuyValue();
    void oreBuyValue();
    void oddValue();
    void incomeValue();
    void afterValue();

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
    //QSpinBox *div;
    QTextBrowser *calcCreate;
    QTextBrowser *calcBCry;
    QTextBrowser *calcBOre;
    QTextBrowser *calcOdd;
    QTextBrowser *calcIncome;
    QTextBrowser *calcAfter;
};

#endif // WINDOW_H
