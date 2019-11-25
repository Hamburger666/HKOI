// https://codeforces.com/problemset/problem/1257/B

#include <iostream>
using namespace std;
int n;
int x[10000], y[10000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            if (y[i] == 1) {
                cout << "YES" << endl;
                continue;
            } else {
                cout << "NO" << endl;
                continue;
            }
        } else if (x[i] <= 3) {
            if (y[i] <= 3) {
                cout << "YES" << endl;
                continue;
            } else {
                cout << "NO" << endl;
                continue;
            }
        } else {
            cout << "YES" << endl;
            continue;
        }
    }
    return 0;
}