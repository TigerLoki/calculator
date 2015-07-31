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
    ~window();

private slots:
    void craftCountValue(QString);
    void cryBuyValue(QString);
    void oreBuyValue(QString);
    void oddValue(QString);
    void incomeValue(QString);
    void afterValue(QString);

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
    QLineEdit *alpha;
};

#endif // WINDOW_H
