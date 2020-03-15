#include <iostream>
#define forn(i,n) for(long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll AC, BC, A[100000], B[100000], c[200000];
ll ac = 0, bc = 0, cc = 0;
int main() {
    cin >> AC >> BC;
    forn(i, AC) {
        cin >> A[i];
    } 
    forn(i, BC) {
        cin >> B[i];
    }
    while(bc < BC) {
        while(A[ac] < B[bc] && ac < AC) {
            c[cc++] = A[ac];
            ac++;
        }
        c[cc++] = B[bc];
        bc++;
    } 
    while(ac < AC) {
        c[cc++] = A[ac];
        ac++;
    }

    forn(i, AC + BC) {
        cout << c[i] << " ";
    }
    cout << endl;
}