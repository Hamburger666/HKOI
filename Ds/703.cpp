#include <iostream>
#define forn(i,n) for(long long i = 0; i< n; i++)
using namespace std;
typedef long long ll;


ll q[10000], ii[10000];
ll N, ne;
int main() {
    cin >> N >> ne;
    ne--;
    forn(i,N) {
        cin >> q[i];
    }
    forn(i,N) {
        cin >> ii[i];
        ii[i]--;
    }
    while (ne != -1) {
        cout << q[ne] << endl;
        ne = ii[ne];
    }
    cout << "End" << endl;
}