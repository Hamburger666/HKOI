#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
int main() {
    unordered_map<ll, ll> a;
    // a[2] = 123;
    a[2]++;
    cout << a[2] << endl;
}