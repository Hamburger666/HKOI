// https://judge.hkoi.org/task/J181

#include <iostream>
#include <stdexcept>
using namespace std;

int price2, price4, numberOfWings;
int main() {
    int subtaskNo;
    cin >> subtaskNo >> price2 >> price4 >> numberOfWings;
    if (price2*2 < price4) {
        int price = 0;
        price += numberOfWings/2 * price2;
        if (numberOfWings % 2 != 0) {
            price += price2;
        }
        cout << price;
    } else {
        int price = 0;
        price += numberOfWings/4 * price4;
        if (numberOfWings % 4 == 0) {
        } else if (numberOfWings - numberOfWings/4*4 <= 2) {
            price += price2;
        } else {
            price += price4;
        }
        cout << price << endl;
    }
}
