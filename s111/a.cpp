#include <iostream>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;


ll N, M; bool dir;
ll Np;
ll cd[201] = {0};
ll cdps[202] = {0};

ll cc(ll x, ll y) {
    if (dir) {
        return x - y + N;
    } else {
        return x;
    }
}

int main() {
    cin >> N >> M >> dir;
    forn(i, M) {
        ll x, y, s;
        cin >> x >> y >> s;
        cd[cc(x, y)] += s;
    }
    if (dir) {
        Np = N * 2 + 1;
    } else {
        Np = N+1;
    }
    forn(i, Np) { 
        cdps[i+1] = cdps[i] + cd[i];
    }
    ll c = -1;
    forn(i, Np) {
        if (cdps[i] - cdps[0] == cdps[Np] - cdps[i+1]) {
            c = i;
        }
    }
    if (c == -1) {
        cout << "OH NO" << endl;
    } else {
        if (dir) {
            cout << c - N << endl;
        } else {
            cout << c << endl;
        }
    }
}