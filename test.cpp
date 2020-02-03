#include <stdexcept>
#include <iostream>
#include <vector>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

void set4(int &b) {
    b = 90;
}

bool comp(int a, int b) {
    return (a > b);
}
int main() {
    int c[100][2];
    forn(i, 100) {
        c[0][i] = i;
    }
    sort(c[0], c[0]+100, comp);
    forn(i, 100) {
        cout << c[0][i] << endl;
    }
    
    cout << !12 << endl;
}