#include <iostream>
#include <algorithm>
#include <limits>
#define forn(i, n) for(long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll K, N;
ll A[100001];
ll m[100000];

void printlist(ll *l, ll s) {
    forn(i, s) {
        cout << l[i] << ", ";
    }
    cout << endl;
}
int main() {
    cin >> N >> K;
    forn(i, N) {
        cin >> A[i];
        A[i] *= 2; // so that I don't have to deal with float. 
    }

    if (K == 1 || K == 2) {
        forn(i, K) {
            cout << A[i] / 2 << " ";
        }
        cout << endl;
    } else {

        sort(A, A + N);

        // printlist(A, N);

        ll mid2 = K/2; 
        ll mid1 = (K-1)/2;
        ll half = K - K/2;
        if (K % 2 == 0) {
            half += 1;
        }
        ll sum = 0;
        forn(i, half) {
            sum += A[i];
        }

        // cout << sum << endl;

        forn(i, N - half + 1) {
            m[i] = sum;
            sum -= A[i];
            sum += A[i + half];
        }
        // printlist(m, N);

        ll floor = 0;
        forn(i, K - half) {
            floor += A[i];
        }

        ll maxv = LONG_MIN; ll maxi;

        forn(i, N - K) {
            ll midv = (A[i + mid1] + A[i + mid2])/2;
            ll v = midv * K - floor - m[i + mid1];
            if (v > maxv) {
                maxv = v;
                maxi = i;
            }
        }

        forn(i, K - half) {
            cout << A[i] / 2 << " ";
        }

        forn(i, half) {
            cout << A[i + maxi + mid1] / 2 << " ";
        }
        cout << endl;
    }
}