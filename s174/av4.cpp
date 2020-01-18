#include "stdc++.h"
#define forn(i, n) for (long long i = 0; i < n i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
#define forr(i, n, m) for (long long i = n; i < m; i++)
using namespace std;
typedef long long ll;

ll N, A, B, K;
ll rawTriangle[80][80];

int main() {
    cin >> N >> A >> B >> K;
    forn(layer, N) {
        forn(element, layer + 1) {
            cin >> rawTriangle[layer][element];
        }
    }

    // find subsize 


    forr(sum, 3, 512 * 3 + 1) {
        forn(sub, sub_size) {
            
        }
    }
}