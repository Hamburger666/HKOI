#include <iostream>
#include <string>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

struct bs {
    ll full, open, close;
};

string s;
bs st[2000000];
ll M;

bs combineBs(bs a, bs b) {
    bs re;
    ll t = min(a.open, b.close);
    re.full = a.full + b.full + t;
    re.open = a.open + b.open - t;
    re.close = a.close + b.close - t;
    return re;
}

void buildSt() {
    for (ll i = s.size() - 1; i > 0; i--) {
        st[i] = combineBs(st[i<<1], st[i<<1|1]);
    }
}

bs querySt(ll l, ll r) {
    bs resl, resr;
    resl.full = 0;
    resl.open = 0;
    resl.close = 0;
    resr.full = 0;
    resr.open = 0;
    resr.close = 0;
    for (l += s.size(), r += s.size(); l < r; r >>= 1, l >>= 1) {
        if (l&1) {
            resl = combineBs(resl, st[l]);
            l++;
        }
        if (r&1) {
            r--;
            resr = combineBs(st[r], resr);
        }
    }
    return combineBs(resl, resr);
}


int main() {
    cin >> s;
    forn(i, s.size()) {
        if (s[i] == '(') {
            st[i + s.size()].full = 0;
            st[i + s.size()].open = 1;
            st[i + s.size()].close = 0;
        }
        if (s[i] == ')') {
            st[i + s.size()].full = 0;
            st[i + s.size()].open = 0;
            st[i + s.size()].close = 1;
        }
    }
    buildSt();
    cin >> M;
    forn(i, M) {
        ll l, r;
        cin >> l >> r;
        l--;
        cout << querySt(l, r).full * 2 << endl;
    }
}