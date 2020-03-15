#include <iostream>
#define forn(i,n) for(long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int N, D, l[2000];
int c = 0;
int main() {
    cin >> N >> D;
    forn(i,N) {
        cin >> l[i];
    }
    ll sorted = false;
    while(!sorted) {
        sorted = true;
        forn(i, N-1) {
            if ((D == 0 && l[i] > l[i+1]) || (D == 1 && l[i] < l[i+1])) {
                ll t = l[i];
                l[i] = l[i+1];
                l[i+1] = t;
                sorted = false;
                c++;
            }
        }
    }
    cout << c << endl;
    forn(i,N) {
        cout << l[i] << " ";
    }
    cout << endl;
}