using namespace std;
#include <iostream>
#include <string>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;


ll fib[30];
string a, b, t;
ll Q;
vector<ll> ps[3];
int main() {
    fib[0] = 1;
    fib[1] = 2;
    for (ll i = 2; i < 30; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    a = "0";
    b = "01";
    forn(i, 28) {
        t = b + a;
        a = b;
        b = t;
    }
    ps[0].resize(fib[29]);
    ps[1].resize(fib[29]);
    ps[2].resize(fib[29]);
    forn(i, b.length() - 1) {
        ps[0][i+1] = ps[0][i] + (b.substr(i, 2) == "00");
        ps[1][i+1] = ps[1][i] + (b.substr(i, 2) == "01");
        ps[2][i+1] = ps[2][i] + (b.substr(i, 2) == "10");
    }
    cin >> Q;
    forn(i, Q) {
        ll left, right;
        string s;
        ll ans;
        cin >> left >> right >> s;
        left--;
        right--;
        if (s == "11") {
            ans = 0;
        } else {
            ll n;
            if (s == "00") {
                n = 0;
            } else if (s == "01") {
                n = 1;
            } else if (s == "10") {
                n = 2;
            }
            ans = ps[n][right] - ps[n][left];
        }
        cout << ans << endl;
    }
}