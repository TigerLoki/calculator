#include "window.h"
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextBrowser>
#include <QSpinBox>
#include <QString>
#include <iostream>
using namespace std;


window::window(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(400, 600);
    centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );
    mainLayout = new QGridLayout( centralWidget );

    /*for test*/
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
    selMode->setCurrentIndex(0);

    if (selMode->currentIndex() == 0)
    {
        count = 156;
        cost = 10;
        cryCount = 1;
        oreCount = 3;
    }

    editMoney->setValue(1);
    editMoney->setRange(1, 99999999);
    editCry->setValue(1);
    editCry->setRange(1, 99999999);
    editOre->setValue(1);
    editOre->setRange(1, 99999999);

    calcCreate->setText("0");
    calcBCry->setText("0");
    calcBOre->setText("0");
    calcOdd->setText("0");
    calcIncome->setText("0");
    calcAfter->setText("0");

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

    connect(selMode, SIGNAL(currentIndexChanged(int)), SLOT(changeMode()));
    connect(editMoney, SIGNAL(valueChanged(int)), SLOT(craftCountValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), SLOT(cryBuyValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), SLOT(oreBuyValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), SLOT(oddValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), SLOT(incomeValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), SLOT(afterValue()));
    connect(editCry, SIGNAL(valueChanged(int)), SLOT(craftCountValue()));
    connect(editCry, SIGNAL(valueChanged(int)), SLOT(cryBuyValue()));
    connect(editCry, SIGNAL(valueChanged(int)), SLOT(oreBuyValue()));
    connect(editCry, SIGNAL(valueChanged(int)), SLOT(oddValue()));
    connect(editCry, SIGNAL(valueChanged(int)), SLOT(incomeValue()));
    connect(editCry, SIGNAL(valueChanged(int)), SLOT(afterValue()));
    connect(editOre, SIGNAL(valueChanged(int)), SLOT(craftCountValue()));
    connect(editOre, SIGNAL(valueChanged(int)), SLOT(cryBuyValue()));
    connect(editOre, SIGNAL(valueChanged(int)), SLOT(oreBuyValue()));
    connect(editOre, SIGNAL(valueChanged(int)), SLOT(oddValue()));
    connect(editOre, SIGNAL(valueChanged(int)), SLOT(incomeValue()));
    connect(editOre, SIGNAL(valueChanged(int)), SLOT(afterValue()));


}

void window::changeMode()
{
    a = selMode->currentIndex();
    if (a == 0)
    {
        window::count = 156;
        window::cost = 10;
        window::cryCount = 1;
        window::oreCount = 3;
    }
    if (a == 1)
    {
        window::count = 100;
        window::cost = 25;
        window::cryCount = 1;
        window::oreCount = 3;
    }

    if (a == 2)
    {
        window::count = 100;
        window::cost = 50;
        window::cryCount = 2;
        window::oreCount = 8;
    }
    window::alpha = selMode->currentIndex();
}

void window::craftCountValue()
{
    window::moneyV = editMoney->value();
    window::cryV = editCry->value()*window::cryCount;
    window::oreV = editOre->value()*window::oreCount;
    window::divV = window::moneyV / (window::cryV + window::oreV);
    totalV = window::divV*window::count;
    calcCreate->setText(QString::number(totalV));
}
void window::cryBuyValue()
{
    cry = window::divV*window::cryCount;
    calcBCry->setText(QString::number(cry));
}
void window::oreBuyValue()
{
    ore = window::divV*window::oreCount;
    calcBOre->setText(QString::number(ore));
}
void window::oddValue()
{
    odd = editMoney->value() - float(window::cryV+window::oreV)/window::count*window::totalV;
    calcOdd->setText(QString::number(odd));
}
void window::incomeValue()
{
    income = (window::cost - float(window::cryV+window::oreV)/window::count)*window::totalV;
    calcIncome->setText(QString::number(income));
}
void window::afterValue()
{
    after = window::moneyV + window::income;
    calcAfter->setText(QString::number(after));
}

window::~window()
{

}
