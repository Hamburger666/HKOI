#include <iostream>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;


int N;
int main() {
    cin >> N;
    forn(i, N) {
        forn(j, i + 1) {
            cout << 1 + (i * i) - j * i << " ";
        }
        cout << endl;
    }
}