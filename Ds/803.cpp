#include <iostream>
#define forn(i,n) for (long long i = 0; i < n; i++)
typedef long long ll; 
using namespace std;

ll N, l[100];
int main() {
    cin >> N;
    forn(i, N) {
        cin >> l[i];
    }
    cout << l[0] << endl;

    for (ll i = 1; i < N; i++) {
        ll n = l[i];
        ll insert = i;
        forn(j, i) {
            if (n < l[j]) {
                insert = j;
                break;
            }
        }
        for (ll k = i-1; k >= insert; k--) {
            l[k+1] = l[k];
        }
        l[insert] = n;
        forn(c, i+1) {
            cout << l[c] << " ";
        }
        cout << endl;
    }
}