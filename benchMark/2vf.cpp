#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

vector<int> a[1000000];
int b[1000000], bMark[1000000], b_size;
void way1() {
    time_t begin = clock();
    int lineNo;
    cin >> lineNo;
    forn(line, lineNo) {
        int digitNo;
        cin >> digitNo;
        forn(digit, digitNo) {
            int number;
            cin >> number;
            a[line].push_back(number);
        }
    }
    time_t end = clock();
    cout << (double) (end - begin) / CLOCKS_PER_SEC << endl;
    cout << a[10][10] << endl;
}

void way2() {
    time_t begin = clock();
    b_size = 0;
    int lineNo;
    cin >> lineNo;
    forn(line, lineNo) {
        int digitNo;
        cin >> digitNo;
        bMark[line] = b_size;
        forn(digit, digitNo) {
            int number;
            cin >> number;
            b[b_size] = number;
            b_size++;
        }
    }
    time_t end = clock();
    cout << (double) (end - begin) / CLOCKS_PER_SEC << endl;
    cout << b[100] << endl;
}

int main() {
    way2();
}