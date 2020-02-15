#include <iostream>
#include <algorithm>
#include <limits.h>
#define forn(i, n) for (long long i = 0; i < n; i++) 
#define forr(i, a, b) for (long long i = a; i<b; i++)
using namespace std;
typedef long long ll;

ll N, K;
ll a[100000];
ll m[100001];

void printlist(ll *l, ll s) {
    forn(i, s) {
        cout << l[i] << ", ";
    }
    cout << endl;
}

ll sumOf(ll a, ll b) {
    return m[b] - m[a];
}
int main() {
    cin >> N >> K;
    forn(i, N) {
        cin >> a[i];
        a[i] *= 2;
    }

    if (K == 1 || K == 2) {
        forn(i, K) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        sort(a, a + N);
        if (K % 2 == 0) {

        } else {
            ll sum = 0;
            forn(i, K/2) {
                sum += a[i];
            }

            m[0] = 0;

            forn(i, N) {
                m[i + 1] = m[i] + a[i];
            }
            // printlist(m, N + 1);

            ll maxv = LONG_MIN; ll maxi;
            forr(i, K/2, N - K/2) {
                ll v = a[i] * K - sumOf(0, K/2) - K - sumOf(i + 1, i + 1 + K/2) ;
                if (v > maxv) {
                    maxv = v;
                    maxi = i;
                }
            }

            forn(i, K/2) {
                cout << a[i] / 2 << " ";
            } 

            forr(i, maxi, maxi + K/2 + 1) {
                cout << a[i] / 2 << " ";
            }
            cout << endl;
        }
    }
}