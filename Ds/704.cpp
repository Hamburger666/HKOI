#include <iostream>
#define forn(i,n) for(long long i = 0; i< n; i++)
using namespace std;
typedef long long ll;

ll q[10000], ii[10000];
ll N, H, ne;
ll inn, ini;
ll i;
ll nex;
int main() {
    cin >> N >> H;
    H--;
    ne = H;
    forn(i,N) {
        cin >> q[i];
    }
    forn(i,N) {
        cin >> ii[i];
        ii[i]--;
    }
    cin >> inn >> ini;
    i = 0;
    ini--;
    if (ini == -1) {
        cout << N+1 << endl;
        cout << inn << " " << ne + 1 << endl;
        cout << -1 << endl;
    } else {
        while(i != ini) {
            ne = ii[ne];
            i++;
        }
        cout << H+1 << endl;
        cout << inn << " " << ii[ne] + 1 << endl;
        cout << ne+1 << " " << q[ne] << " " << N+1 << endl; 
    }
}