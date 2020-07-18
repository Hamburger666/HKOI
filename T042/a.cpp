#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int ns[2097152];
ll N, M;
int main() {
    cin >> N >> M;
    forn(i, N) {
        cin >> ns[i + 1];
    }
    ll p = 1;
    ll repeastStart = -1;
    forn(i, M) {
        if (ns[p] > 0) {
            ns[p] = -ns[p];
            p = -ns[p];
        } else {
            repeastStart = p;
        }
    }
    ll c = 0;
    if (repeastStart != -1) {
        do {
            c++;
            p = -ns[p];
        } while (p != repeastStart);
        ll p = 1;
        ll i = 0;
        while(p != repeastStart) {
            p = -ns[p];
            i++;
        }
        i += (M - i) / c * c;
        while (i < M) {
            p = -ns[p];
            i++;
        }
        cout << p << endl;
    } else {
        cout << p << endl;
    }
}