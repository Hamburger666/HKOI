#include <iostream>
#include <algorithm>
#include <limits.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define forr(i, a, b) for (long long i = a; i < b; i++)
typedef long long ll;
using namespace std;

ll N, K;
ll A[500000], B[500001];

ll sumA(ll x, ll y) {
    return B[y] - B[x];
}

int main() {
    cin >> N >> K;
    forn(i, N) {
        cin >> A[i]; 
        A[i] *= 2;
    }
    sort(A, A+N);
    forn(i, N) B[i + 1] = B[i] + A[i];
    if (K==1 || K==2) {
        forn(i, K) cout << A[i]/2 << " ";
        cout << endl;
    } else if (K % 2 == 0) {
        ll bestV = LONG_MIN; ll bestI;
        forr(i, K/2, N-K/2+1) {
            ll m = (A[i]+A[i-1])/2;
            ll v = m*K - A[i-1] - sumA(0, K/2-1) - sumA(i, i+K/2);
            if (v>bestV) {
                bestV = v;
                bestI = i;
            }
        }
        forn(i, K/2-1) cout << A[i]/2 << " ";
        forr(i, bestI-1, bestI+K/2) cout << A[i]/2 << " "; 
        cout << endl;
    } else {
        ll bestV = LONG_MIN; ll bestI;
        forr(i, K/2, N-K/2) {
            ll v = A[i]*K - A[i] - sumA(0, K/2) - sumA(i+1, i+K/2+1);
            if (v > bestV) {
                bestV = v;
                bestI = i;
            }
        } 
        forn(i, K/2) cout << A[i]/2 << " ";
        forr(i, bestI, bestI+K/2+1) cout << A[i]/2 << " ";
        cout << endl;
    }
}