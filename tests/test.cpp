#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <vector>
#include <bitset>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;


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

vector<ll> a;
int c() {
    return g() + 4;
}
int g() {
    return c();
}

int main() {
    forn(i, 1000000) {
        int a = 2+2;
    }
    cout << c() << endl;
}

