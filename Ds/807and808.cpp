#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, l[100000];
ll n = 0;

ll partision(ll left, ll right) {
    // cout << "partision on " << left << " " << right << endl;
    ll h = l[right-1]; 
    ll c = left;
    n += right - left;
    forn(_, right - left) {
        ll i = _+left;
        if (l[i]<=h) {
            ll t = l[c];
            l[c] = l[i];
            l[i] = t;
            c++;
        }
    }
    return c;
}

void quickSort(ll left, ll right) {
    if (right - left <= 1) {
        n += right - left;
        return;
    }
    ll p = partision(left, right);
    quickSort(left, p-1);
    quickSort(p, right);
}

int main() {
    cin >> N;
    forn(i,N) {
        cin >> l[i];
    }
    quickSort(0, N);
    forn(i, N) {
        cout << l[i] << " ";
    }
    cout << endl;
    cout << n << endl;
}