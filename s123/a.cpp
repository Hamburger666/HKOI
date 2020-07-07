#include <iostream>
#include <vector>
#include <unordered_set>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll A, B, N;
ll as[3000], bs[3000];

vector<ll> intersection(vector<ll> a, vector<ll> b) {
    unordered_set<ll> s;
    for (ll x : a) {
        s.insert(x);
    }
    vector<ll> re;
    re.reserve(min(a.size(), b.size()));
    for (ll x : b) {
        if (s.find(x) != s.end()) {
            re.push_back(x);
        }
    }
    return re;
}
int main() {
    cin >> A >> B >> N;
    forn(a, A) {
        cin >> as[a];
    }
    forn(b, B) {
        cin >> bs[b];
    }
    vector<ll> ns;
    ns.reserve(3000);
    forn(ai, A) {
        vector<ll> nsa;
        nsa.reserve(3000);
        forn(bi, B) {
            if (bs[bi] - as[ai] >= 0) {
                nsa.push_back(bs[bi] - as[ai]);
            }
        }
        if (ai == 0) {
            ns = nsa;
        } else {
            ns = intersection(ns, nsa);
        }
    }
    if (ns.size()) {
        cout << ns[0] << endl;
    } else {
        cout << "Impossible" << endl;
    }
}