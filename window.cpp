#include "window.h"
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QTextBrowser>
#include <QSpinBox>
#include <QTimer>
#include <QStack>


window::window(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(250, 470);
    setWindowTitle("Калькулятор");
    centralWidget = new QWidget(this);
    this->setCentralWidget( centralWidget );
    mainLayout = new QGridLayout( centralWidget );

    textMode = new QLabel("Выберите режим:",this);
    textMoney = new QLabel("Введите количество денег:",this);
    textCry = new QLabel("Введите стоимость кристалла:",this);
    textOre = new QLabel("Введите стоимость руды духа или души:",this);
    textCreate = new QLabel("Soulshot'ов получится:",this);
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
    timer = new QTimer(this);
    //добавляю элементы в комбобокс
    selMode->addItem("SSD");
    selMode->addItem("NSSD");
    selMode->addItem("BSSD");
    //выставляю размер окошек
    selMode->setFixedSize(232, 23);
    editMoney->setFixedSize(232, 23);
    editCry->setFixedSize(232, 23);
    editOre->setFixedSize(232, 23);
    calcCreate->setFixedSize(232, 23);
    calcBCry->setFixedSize(232, 23);
    calcBOre->setFixedSize(232, 23);
    calcOdd->setFixedSize(232, 23);
    calcIncome->setFixedSize(232, 23);
    calcAfter->setFixedSize(232, 23);
    //выставляю значения для спинбокса, потому что счет идет до 100
    editMoney->setRange(0, 99999999);
    editCry->setRange(0, 99999999);
    editOre->setRange(0, 99999999);
    //добавляю виджеты на лейаут
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

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);

    connect(selMode, SIGNAL(currentIndexChanged(int)), this, SLOT(changeMode()));
    connect(editMoney, SIGNAL(valueChanged(int)), this, SLOT(craftCountValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), this, SLOT(cryBuyValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), this, SLOT(oreBuyValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), this, SLOT(oddValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), this, SLOT(incomeValue()));
    connect(editMoney, SIGNAL(valueChanged(int)), this, SLOT(afterValue()));
    connect(editCry, SIGNAL(valueChanged(int)), this, SLOT(craftCountValue()));
    connect(editCry, SIGNAL(valueChanged(int)), this, SLOT(cryBuyValue()));
    connect(editCry, SIGNAL(valueChanged(int)), this, SLOT(oreBuyValue()));
    connect(editCry, SIGNAL(valueChanged(int)), this, SLOT(oddValue()));
    connect(editCry, SIGNAL(valueChanged(int)), this, SLOT(incomeValue()));
    connect(editCry, SIGNAL(valueChanged(int)), this, SLOT(afterValue()));
    connect(editOre, SIGNAL(valueChanged(int)), this, SLOT(craftCountValue()));
    connect(editOre, SIGNAL(valueChanged(int)), this, SLOT(cryBuyValue()));
    connect(editOre, SIGNAL(valueChanged(int)), this, SLOT(oreBuyValue()));
    connect(editOre, SIGNAL(valueChanged(int)), this, SLOT(oddValue()));
    connect(editOre, SIGNAL(valueChanged(int)), this, SLOT(incomeValue()));
    connect(editOre, SIGNAL(valueChanged(int)), this, SLOT(afterValue()));

}

void window::update()
{
    window::moneyV = editMoney->value();
    window::cryV = editCry->value()*window::cryCount;
    window::oreV = editOre->value()*window::oreCount;
    if (window::cryV + window::oreV == 0)
    {
        window::divV = 0;
    }
    else
    {
        window::divV = window::moneyV / (window::cryV + window::oreV);
    }
    changeMode();
    craftCountValue();
    cryBuyValue();
    oreBuyValue();
    oddValue();
    incomeValue();
    afterValue();
}

void window::changeMode()
{
    alpha = selMode->currentIndex();
    if (alpha == 0)
    {
        window::count = 156;
        window::cost = 10;
        window::cryCount = 1;
        window::oreCount = 3;
    }
    if (alpha == 1)
    {
        window::count = 100;
        window::cost = 25;
        window::cryCount = 1;
        window::oreCount = 3;
    }

    if (alpha == 2)
    {
        window::count = 100;
        window::cost = 50;
        window::cryCount = 2;
        window::oreCount = 8;
    }
}

void window::craftCountValue()
{
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
