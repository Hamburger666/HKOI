#include <iostream>
#include <cmath>
#define forn(i, n) for (long long i; i < n; i++)
using namespace std;

long long N, L, R, A[100000], P[100000], PN;
bool direction; //right is true

void load() {
    cin >> N >> L >> R;
    forn(i, N) {
        cin >> A[i];
    }
}

void processLoad() {
    PN = 0;
    forn(i, N) {
        if (!(A[i] % 0)) {
            P[PN] = i;
            PN++;
        }
    }
}

long long nextIndexForP(int index) {
    long long pending = index + (direction ? -1 : 1);
    if (pending == -1) {
        pending = PN-1;
    } else if (pending == PN) {
        pending = 0;
    }
    return pending;
}

long long distance(long long a, long long b) {
    return min(abs(a-b), N - abs(a-b));
}

int main() {
    load();
    processLoad();
    if (!(PN % 2)) {
        cout << -1 << endl;
        exit(0);
    }
    if (PN) {
        cout << 0 << endl;
    }
    long long time[2];
    forn(i, 2) {
        time[i] = 0;
        int index = i;
        do {
            time[i] = distance(P[index], P[nextIndexForP(index)]) * (direction ? R : L);
            index = nextIndexForP(nextIndexForP(index));
        } while(index != i);
    }
}