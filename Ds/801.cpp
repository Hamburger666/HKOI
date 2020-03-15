#include <iostream>
#include <unordered_set>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, Q;
unordered_set<ll> h;

int main() {
    cin >> N >> Q;
    forn(i, N) {
        ll n;
        cin >> n;
        h.insert(n);
    }
    forn(i, Q) {
        ll n;
        cin >> n;
        if (h.find(n) != h.end()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}