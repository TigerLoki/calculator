#include "window.h"
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextBrowser>
#include <QSpinBox>
/*
 *  QLabel *textMode;
    QLabel *textMoney;
    QLabel *textCry;
    QLabel *textOre;
    QLabel *textCreate;
    QLabel *textBCry;
    QLabel *textBOre;
    QLabel *textOdd;
    QLabel *textIncome;
    QLabel *textAfter;
    QComboBox *combo;
    QLineEdit *editMoney;
    QLineEdit *editCry;
    QLineEdit *editOre;
    QTextBrowser *calcCreate;
    QTextBrowser *calcBCry;
    QTextBrowser *calcBOre;
    QTextBrowser *calcOdd;
    QTextBrowser *calcIncome;
    QTextBrowser *calcAfter;
*/


window::window(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(400, 500);
    centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );
    mainLayout = new QGridLayout( centralWidget );

    /*for test*/
    alpha = new QLineEdit;

    textMode = new QLabel("Выберите режим:",this);
    textMoney = new QLabel("Введите количество денег:",this);
    textCry = new QLabel("Введите стоимость кристалла:",this);
    textOre = new QLabel("Введите стоимость руды духа или души:",this);
    textCreate = new QLabel("Сосок получится:",this);
    textBCry = new QLabel("Нужно купить кристаллов:",this);
    textBOre = new QLabel("Нужно купить руды:",this);
    textOdd = new QLabel("Остаток:",this);
    textIncome = new QLabel("Заработок:",this);
    textAfter = new QLabel("Денег после:",this);
    selMode = new QComboBox(this);
    editMoney = new QSpinBox(this);
    editCry = new QSpinBox(this);
    editOre = new QSpinBox(this);
    calcCreate = new QTextBrowser(this);
    calcBCry = new QTextBrowser(this);
    calcBOre = new QTextBrowser(this);
    calcOdd = new QTextBrowser(this);
    calcIncome = new QTextBrowser(this);
    calcAfter = new QTextBrowser(this);

    selMode->addItem("SSD");
    selMode->addItem("NSSD");
    selMode->addItem("BSSD");

    mainLayout->addWidget(textMode);
    mainLayout->addWidget(selMode);
    mainLayout->addWidget(textMoney);
    mainLayout->addWidget(editMoney);
    mainLayout->addWidget(textCry);
    mainLayout->addWidget(editCry);
    mainLayout->addWidget(textOre);
    mainLayout->addWidget(editOre);
    mainLayout->addWidget(textCreate);
    mainLayout->addWidget(calcCreate);
    mainLayout->addWidget(textBCry);
    mainLayout->addWidget(calcBCry);
    mainLayout->addWidget(textBOre);
    mainLayout->addWidget(calcBOre);
    mainLayout->addWidget(textOdd);
    mainLayout->addWidget(calcOdd);
    mainLayout->addWidget(textIncome);
    mainLayout->addWidget(calcIncome);
    mainLayout->addWidget(textAfter);
    mainLayout->addWidget(calcAfter);

    mainLayout->addWidget(alpha);

    connect(alpha, SIGNAL(textChanged(QString)), SLOT(craftCountValue(QString)));
    connect(alpha, SIGNAL(valueChanged(QString)), editMoney, SLOT(setText(QString)));

}

void window::craftCountValue(QString str) {editMoney->setValue(str.toInt());}
void window::cryBuyValue(QString){}
void window::oreBuyValue(QString){}
void window::oddValue(QString){}
void window::incomeValue(QString){}
void window::afterValue(QString){}

window::~window()
{

}
