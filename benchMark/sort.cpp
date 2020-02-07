#include <iostream>
using namespace std;

long long n[100000];

int main() {
    for (int i = 0; i < 100000; i++) {
        cin >> n[i];
    }
    sort(n, n+100000);
}
