#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;


ll findbi(ll *l,ll n,ll left,ll right) {
    if (right-left<=1) return right;
    ll m=(left+right)/2;
    if(l[left]<=n&&n<l[m])return findbi(l,n,left,m);
    else return findbi(l,n,m,right);
}

struct ab {
    long long a, b;
    bool operator== (ab x) {
        return ((a == x.a) && (b == x.b));
    }
};

void pp(pair<ll, ll> p) {
    cout << p.first << ' ' << p.second << endl;
}
unordered_set<ll> s;
int main() {
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for (unordered_set<ll>::iterator i = s.begin(); i != s.end(); i++) {
        cout << *i << endl;
    }
}

