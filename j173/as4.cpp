using namespace std;
#include <iostream>
#include <string>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;


ll fib[87];
ll Q;
string larva = "010";

ll biF(ll left, ll right, ll des) {
    if (left + 1 >= right) {
        return left;
    }
    ll mid = (left + right) /2;
    if (des < fib[mid]) {
        return biF(left, mid, des);
    } else {
        return biF(mid, right, des);
    }
}

ll biF(ll des) {
    return biF(0, 89, des);
}

int main() {
    fib[0] = 1;
    fib[1] = 2;
    for (ll i = 2; i < 87; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cin >> Q;
    forn(i, Q) {
        ll left, right;
        string w;
        cin >> left >> right >> w;
        left--;
        string s(right - left, '-');
        forn(j, right - left) {
            ll k = j + left;
            while (k > 2) {
                k -= fib[biF(k)];
            }
            s[j] = larva[k];
        }
        ll ans = 0;
        forn(i, right - left - 1) {
            ans += (s.substr(i, 2) == w);
        }
        cout << ans << endl;
    }
}