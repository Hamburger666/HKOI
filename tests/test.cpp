#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

struct ab {
    long long a, b;
};
int main() {

    ab c = {1, 2};
    ab d = c;
    d.a = 2;
    cout << c.a << endl;
}