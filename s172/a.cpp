#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i ++)
#define forr(i, a, b) for (long long i = a; i < b; i++)
using namespace std;
typedef long long ll;
#define MAX_N 100000

ll N, A[MAX_N], B[MAX_N];
bool mA[MAX_N] = {0}, mB[MAX_N] = {0};
ll c[MAX_N];

void printList(ll *list, ll size) {
    forn(i, size) {
        cout << list[i] << ", ";
    }
    cout << endl;
}
int main() {
    cin >> N;
    forn(i, N) {
        cin >> A[i];
    }
    forn(i, N) {
        cin >> B[i];
    }

    ll bi = 0;
    while(bi < N && B[bi] < A[0]) {
        bi++;
    }

    ll ai = 0;
    while(ai < N && bi < N && A[ai] <= B[N-1]) {
        if (A[ai] == B[bi]) {
            mA[ai] = true;
            mB[bi] = true;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
        ai++;
        bi++;
        while(bi < N && B[bi] < A[ai]) {
            bi++;
        }
    }

    ai = N-1;
    bi = 0;
    ll ci = 0;
    while(ai >=0 && mA[ai]) {
        ai--;
    }
    while(bi < N && mB[bi]) {
        bi++;
    }
    while(bi < N) {
        c[ci++] = A[ai] - B[bi];
        ai--;
        bi++;
        while(ai >= 0 && mA[ai]) {
            ai--;
        }
        while(bi < N && mB[bi]) {
            bi++;
        }
    }

    cout << ci << endl;
    forn(i, ci) {
        cout << c[i] << endl;
    }


}