#include <iostream>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;

long long W[3], A, B, M;

long long minues(long long a, long long b) {
    long long pending = a - b;
    while(pending < 0) {
        pending += M;
    }
    return pending;
}

long long findM(long long a, long long b, long long add, long long bound) {
    if (b >= a) {
        throw runtime_error("");
    }
    long long pending = a + add -b;
    if (pending <= bound) {
        cout << "No soulition" << endl;
        exit(0);
    }
    return pending;
}


int main() {
    forn(i, 3) {
        cin >> W[i];
    }
    if (W[0] < W[1]) {
        A = W[1] - W[0];
        if (W[1] == W[2]) {
            cout << "No solution" << endl;
        } else if (W[1] < W[2]) {
            if (A == W[2] - W[1]) {
                M = W[2] + 1;
                B = minues(W[0], A);
            } else {
                cout << "No solution" << endl;
                exit(0);
            }
        } else {
            M = findM(W[1], W[2], A, W[1]);
            B = minues(W[0], A);
        }
    } else if (W[1] < W[2]) {
        A = W[2] - W[1];
        if (W[0] == W[1]) {
            cout << "No solution" << endl;
        } else if (W[0] < W[1]) {
            if (A == W[1] - W[0]) {
                M = W[2] + 1;
                B = minues(W[0], A);
            } else {
                cout << "No solution" << endl;
                exit(0);
            }
        } else {
            M = findM(W[0], W[1], A, max(W[0], W[2]));
            B = minues(W[0], A);
        }
    } else {
        if (W[1] - W[0] == W[2] - W[1]) {
            M = W[2] + 1;
            A = minues(W[1], W[0]);
            B = minues(W[0], A);
        } else {
            cout << "No solution" << endl;
            exit(0);
        }
    }
    if (0 <= A && 0 <= B && A < M && B < M) {
        cout << A << " " << B << " " << M << endl;
    } else {
        cout << "No solution" << endl;
    }
}