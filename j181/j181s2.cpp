#include <iostream>
using namespace std;

int w2, w4, dollars;
int main() {
    int subtaskNo;
    cin >> subtaskNo >> w2 >> w4 >> dollars;
    if (w2 * 2 < w4) {
        cout << dollars / w2 * 2 << endl;
    } else {
        int numberOfWings = 0;
        numberOfWings += dollars / w4 * 4;
        if (dollars - dollars / w4 * w4 >= w2) {
            numberOfWings += 2;
        }
        cout << numberOfWings << endl;
    }
}