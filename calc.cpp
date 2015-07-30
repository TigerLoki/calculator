#include <iostream>
using namespace std;

class Calculator
{
public:
    int choice, money, cry_std, ore_std, cry, ore, cost, div, a, total, ore_count, cry_count;
    float count;
    void Input()
    {
        cout << "Choise mode: ";
        cin >> choice;
        cout << "Input your money: ";
        cin >> money;
        cout << "Input crystall cost: ";
        cin >> cry_std;
        cry_count = 1;
        ore_count = 3;
        if (choice == 3)
        {
            cry_count = 2;
            ore_count = 8;
        }
        switch (choice)
        {
            case 1:
                count = 156;
                cout << "Input soulstone cost: ";
                cin >> ore_std;
                cry = cry_std*cry_count;
                ore = ore_std*ore_count;
                cost = 10;
                break;
            case 2:
                count = 100;
                cout << "Input spirit ore cost: ";
                cin >> ore_std;
                cry = cry_std*cry_count;
                ore = ore_std*ore_count;
                cost = 25;
                break;
            case 3:
                count = 100;
                cout << "Input spirit ore cost: ";
                cin >> ore_std;
                cry = cry_std*cry_count;
                ore = ore_std*ore_count;
                cost = 50;
                break;
        }
        Calc();
    }
    void Calc()
    {
        div = money / (cry+ore);
        total = div*count;
        int buy_cry = div*cry_count;
        int buy_ore = div*ore_count;
        float ost = money - (cry+ore)/count*total;
        float inc = (cost - (cry+ore)/count)*total;
        float after = ost + inc;
        cout << "Shots create: " << total << endl;
        cout << "Buy crystalls: " << buy_cry << endl;
        cout << "Buy ore: " <<buy_ore << endl;
        cout << "Odd: " << ost << endl;
        cout << "Income: " << inc << endl;
        cout << "Money after: " << after << endl;
    }
};
