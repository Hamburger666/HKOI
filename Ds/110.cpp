#include <iostream>
using namespace std;
string from;
string to;

int main() {
    cin >> from >> to;
    int d1, d2;
    d1 = abs(from.at(0) - to.at(0));
    d2 = abs(from.at(1) - to.at(1));
    cout << max(d1, d2) << endl;
}