#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>
#include <algorithm>
#include <functional>
#include <stack>
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
vector<ll> vc;
ll N = 5;

void next(ll& i) {
    i++;
    if (i == N) {
        i = 0;
    }
}

bool ic(vector<ll> numbers) {
    bool nsg[N];
    forn (i, N) {
        nsg[i] = false;
    }
    for (ll n : numbers) {
        nsg[n] = true;
    }
    ll i = 0;
    while(nsg[i]) {
        cout << i << endl;
        next(i);
    }
    cout << "b1" << endl;
    while(!nsg[i]) {
        cout << i << endl;
        next(i);
    }
    cout << "b2" << endl;
    ll c = 0;
    while(nsg[i]) {
        cout << i << endl;
        c++;
        next(i);
    }
    return (c == numbers.size());
}

stack<ll> m;
int main() {
    forn(i, 1000) {
        m.push(i);
    }
    while(!m.empty()) {
        cout << m.top() << " ";
        m.pop();
    }
}

