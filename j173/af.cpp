using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;


ll fib[87];
string a, b, t;
ll Q;
vector<ll> csb[3];

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

ll countS(ll n, ll left, ll right) {
    ll i = biF(right);
    if (left == 0 && right == fib[i]) {
        return csb[n][i];
    } else {
        if (right == fib[i]) {
            i -= 1;
        }
        ll a;
        if (n == 0) {
            a = (i % 2 == 0);
        } else if (n == 1) {
            a = 0;
        } else if (n == 2) {
            a = (i % 2 != 0);
        }
        if (left >= fib[i]) {
            return countS(n, left - fib[i], right - fib[i]);
        } else {
            return countS(n, left, fib[i]) + countS(n, 0, right - fib[i]) + a;
        }
    }
}

ll tn(string s) {
    if (s == "00") {
        return 0;
    } else if (s == "01") {
        return 1;
    } else if (s == "10") {
        return 2;
    } else {
        throw runtime_error("");
    }
}

int main() {
    fib[0] = 1;
    fib[1] = 2;
    for (ll i = 2; i < 87; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    forn(i, 3) {
        csb[i].resize(87);
        csb[i][0] = 0;
    }
    csb[0][1] = 0;
    csb[1][1] = 1;
    csb[2][1] = 0;
    
    for (ll i = 2; i < 87; i++) {
        csb[0][i] = csb[0][i-1] + csb[0][i-2] + (i%2 != 0);
        csb[1][i] = csb[1][i-1] + csb[1][i-2];
        csb[2][i] = csb[2][i-1] + csb[2][i-2] + (i%2 == 0);
    }
    cin >> Q;
    forn(i, Q) {
        ll left, right; string w;
        cin >> left >> right >> w;
        left--;
        if (w == "11") {
            cout << 0 << endl;
        } else {
            cout << countS(tn(w), left, right) << endl;
        }
        
    }
}