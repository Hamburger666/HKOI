#include <iostream>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M;
ll l[100];
int main() {
    cin >> N >> M;
    forn(i, N) {
        cin >> l[i];
    }
    forn(i, M) {
        ll r1, l1, r2, l2;
        cin >> r1 >> l1 >> r2 >> l2;
        r1--;
        r2--;
        ll i1 = r1;
        ll i2 = r2;
        ll nc = r1;
        ll nl[100];
        while(i1 < l1) {
            while((i2 < l2) && (l[i2] < l[i1])) { 
                nl[nc++] = l[i2];
                i2++;
            }
            nl[nc++] = l[i1];
            i1++;
        }
        while(i2 < l2) { 
            nl[nc++] = l[i2];
            i2++;
        }
        for (ll i = r1; i < l2; i++) {
            cout << nl[i] << " ";
            l[i] = nl[i];
        }
        cout << endl;
    }
}