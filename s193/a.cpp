#include <iostream>
#include <cmath>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define forr(i, a, b) for (long long i = a; i < b; i++)
typedef long long ll;
using namespace std;

ll R, N;
ll p;
ll n2;
ll sequence[16384] = {0}; // max R to the nearest power of 2
ll sl;

void printlist(vector<ll> a) {
    for (ll n : a) {
        cout << n << " ";
    }
    cout << endl;
}

vector<ll> anti(ll n) {
    vector<ll> re;
    if (n == 1) {
        re.push_back(0);
    } else {
        ll half = n / 2;
        vector<ll> get = anti(half);
        get.resize(n);
        forn(i, half) {
            re.push_back(get[i] * 2);
        }
        forn(i, half) {
            re.push_back(get[i] * 2 + 1);
        }
    }
    return re;
}
int main() {
    cin >> R >> N;
    n2 = N;
    p = 0;
    while(n2) {
        n2 >>= 1;
        p++;
    }
    

    n2 = 1 << p;
    vector<ll> l = anti(n2);
    vector<ll> l2;

    for (ll a : l) {
        if (a < N) {
            l2.push_back(a);
        }
    }

    cout << l2[0] + 1;
    forr(i, 1, l2.size()) {
        cout << " " << l2[i] + 1;
    }
    
    cout << endl;

}