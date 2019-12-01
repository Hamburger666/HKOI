#include <iostream>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;

long long W[3], A[2], B, M, maxW;

void findMaxM() {
    maxW = 0;
    forn(i, 3) if (W[i] > maxW) maxW = W[i];
}

int flip(int a) {
    return (a ? 0 : 1);
}

long long getM(long long a, long long b, long long add) {
    if (b >= a) {
        throw runtime_error("");
    }
    return (a + add - b);
}

long long minus_(long long in) {
    long long pending = in;
    while(pending < 0) {
        pending += M;
    }
    return pending;
}
int main() {
    forn(i, 3) cin >> W[i];
    findMaxM();
    forn(i, 2) {
        A[i] = W[i+1] - W[i];
    }        
    if ((A[0] >= 0) == (A[1] >= 0)) {
        if (A[0] == A[1]) {
            M = maxW + 1;
            A[0] = minus_(A[0]);
            B = minus_(W[0] - A[0]);
            cout << A[0] << " " << B << " " << M << endl;
        } else {
            cout << "No solution" << endl;
        }
    } else {
        int index;
        index = ((A[0] >= 0) ? 0 : 1);
        M = getM(W[flip(index)], W[flip(index) + 1], A[index]);
        if (M <= maxW) {
            cout << "No solution" << endl;
        } else {
            B = minus_(W[0] - A[index]);
            cout << A[index] << " " << B << " " << M << endl;
        }
    }
}