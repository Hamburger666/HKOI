#include <iostream>
using namespace std;

bool map[20][20];
int main() {
    for (int i = 0; i < 20; i++) {
        for (int k = 0; k < 20; k++) {
            map[i][k] = true;
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int k = 0; k < 20; k++) {
            if (map[i][k]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
}
