// https://codeforces.com/contest/335/problem/B
#include <iostream>
#include <string>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

string s;

bool isP(ll i, ll length) {
    if (length == 1 || length == 0) {
        return true;
    }
    return (s[i] == s[i+length-1] && isP(i+1, length - 2));
}

int main() {
    cin >> s;
    bool is100 = false;
    ll at100;
    forn(i, (ll)s.size()-99) {
        if (isP(i, 100)) {
            is100 = true;
            at100 = i;
        }
    }
    if (is100) {
        cout << s.substr(at100, 100) << endl;
    } else {
        for (ll length = s.size(); length >= 1; length--) {
            forn(i, s.size() - length +1) {
                if (isP(i, length)) {
                    cout << s.substr(i, length) << endl;
                    return 0;
                }
            }
        }
    }
}