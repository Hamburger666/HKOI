#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)

typedef long long ll;

ll N;
ll X[100000];
ll A[100000];
vector<ll> fallThrough[100000];
ll mid;

int main() {
    cin >> N;
    forn(i, N) {
        cin >> X[i];
    }
    forn(i, N) {
        cin >> A[i];
    }

    mid = 0;
    while(X[mid] < 0) {
        mid++;
    }
    ll As[100000];
    forn(i, N) {
        As[i] = max(0ll, A[i] - abs(X[i]) * 2);
    }

    ll maxCost = 0;
    forn(i, N - mid) {
        ll cost = 0;
        forn(j, i + 1) {
            ll k = j + mid;
            cost += As[k];
        }
        forn(i, mid) {
            cost += max(0ll, As[i] - abs(X[i] * 2));
        }
        if (cost > maxCost) {
            maxCost = cost;
        }
    }

    // forn(i, mid) {
    //     ll cost = 0;
    //     forn(j, i+1) {
    //         ll k = mid - j - 1;
    //         cost += As[k];
    //     }
    //     forn(i, N - mid) {
    //         ll k = i+mid;
    //         cost += max(0ll, As[i] - abs(X[mid - i - 1] * 2));
    //     }
    // }
    
    cout << maxCost << endl;
    
}