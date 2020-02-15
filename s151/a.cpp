#include <iostream>
using namespace std;
#define forn (i, n) for (long long i = 0; i < n; i++)
typedef unsigned long long ull;

int main() {
    ull a = (1 << 5) - 1;
    ull b = a >> 4 & 1;
    cout << b << endl;
    ull c = 0 - 1;
    cout << c << endl;
}