#include <iostream>
#define forn(i,n) for(long long i = 0; i <n;i++)
using namespace std;
typedef long long ll;

ll N, n;
bool p[10000000] = {0};
int main() {
    cin >> N;
    n = 2;
    while(n <= N) {
        cout << n << endl;
        for(ll m = n*n; m <= N; m+=n) {
            p[m] = true;
        }
        n++;
        while (p[n]) {
            n++;
        }
    } 
}