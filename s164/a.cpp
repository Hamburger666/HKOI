#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++) 
#define forr(i, a, b) for (long long i = a; i < a; i++)
using namespace std;

long long N, K;
long long D[100000];
long long blankets[100000];
int main() {
    cin >> N >> K;
    forn(i, N) {
        cin >> D[i];
    }

    long long prev = 0;
    forn(i, K) {
        prev += D[i];
    }

    forn(i, N-K) {
        blankets[i] = prev;
        prev -= D[i];
        prev += D[i+K];
    }

    blankets[N-K] = prev;

    prev = 0;

    forn(i, K) {
        prev += D[i] * (i + 1);
    }

    long long maxCost = 0;
    forn(i, N - K + 1) {
        if (prev > maxCost) {
            maxCost = prev;
        }
        prev -= blankets[i];
        prev += D[i+K] * K;
    }

    cout << maxCost << endl;
}