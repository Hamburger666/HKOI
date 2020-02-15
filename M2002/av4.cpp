#include <iostream>
#include <bitset>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct l {
    ull a, b;
    void set(ll i, bool x) {
        if (x) {
            if (i < 64) {
                a |= (1UL << i);
            } else {
                b |= (1UL << (i-64));
            }
        } else {
            if (i < 64) {
                a &= ~(1UL << i);
            } else {
                b &= ~(1UL << (i-64));
            }
        }
    }
    bool asBool() {
        return a || b;
    }
    bool operator== (l x) {
        return ((a == x.a) && (b == x.b));
    }
};

struct c {
    ll cost; l movies;
};
bool comp(c a, c b) {
    return a.cost < b.cost;
}

l exor(l x, l y) {
    l r;
    r.a = x.a ^ y.a;
    r.b = x.b ^ y.b;
    return r;
}

l andd(l x, l y) {
    l r;
    r.a = x.a & y.a;
    r.b = x.b & y.b;
    return r;
}

ll N, M, Q;
c channels[10000]; l lists[20000];


int main() {
    cin >> N >> M >> Q;
    forn(i, N) {
        cin >> channels[i].cost;
    }
    forn(i, N) {
        forn(j, M) {
            bool t;
            cin >> t;
            channels[i].movies.set(j, t);
        }
    }
    forn(i, Q) {
        ll L;
        cin >> L;
        forn(j, L) {
            ll t;
            cin >> t;
            t--;
            lists[i].set(t, true);
        }
    }
    // bitset<64> a(channels[0].movies.a);
    // bitset<64> b(channels[0].movies.b);
    // cout << a << endl;
    // cout << b << endl;

    // bitset<64> al(lists[1].a);
    // bitset<64> bl(lists[1].b);
    // cout << al << endl;
    // cout << bl << endl;

    sort(channels, channels + N, comp);

    forn(lid, Q) {
        bool found = false;
        forn(cid, N) {
            if (andd(lists[lid], channels[cid].movies) == lists[lid]) {
                cout << channels[cid].cost << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << endl;
    }

}