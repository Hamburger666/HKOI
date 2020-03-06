#include <iostream>
#define forn(i,n) for(long long i = 0; i < n; i ++)
typedef long long ll;
using namespace std;

ll T, N;
bool p[2000000] = {0};
ll pr[2000000]; ll prc = 0;
int main() {
    cin >> T;
    for (long long i = 2; i < 2000000; i++) {
        if (!p[i]) {
            for (long long j = i * i; j < 2000000; j+=i) {
                p[j] = true;
            }
            pr[prc++] = i;
        }
    }
    forn(i,T) {
        ll n; 
        cin >> n;
        ll lower = 0;
        ll upper = prc-1;
        while(pr[lower] + pr[upper] != n*2) {
            while(pr[lower] + pr[upper] > n*2) {
                upper--;
            }
            if (pr[lower] + pr[upper] != n*2) {
                lower++;
                while(pr[lower] + pr[upper] < n*2) {
                    upper++;
                }
            }
        }
        cout << pr[lower] << " " << pr[upper] << endl;
    }
    return 0;
}