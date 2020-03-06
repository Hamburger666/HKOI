#include <iostream>
#define forn(i, n) for (long long i =0; i <n;i++)
typedef long long ll;
using namespace std;

ll l[100], N, lc;
int main() {
    cin >> N;
    ll a = 0;
    forn(i, N*N) {
        a+=i/N+1;
        l[lc++] = a;
    }
    forn(r, N) {
        forn(c, N) {
            cout << l[(N-r-1)*N+(N-c-1)] << " ";
        }
        cout << endl;
    }
}