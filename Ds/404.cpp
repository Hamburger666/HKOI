#include <iostream>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M;
double f[100][100];
int main() {
    cin >> N;
    forn(r, N) {
        forn(c, N) {
            cin >> f[r][c];
        }
    }
    cin >> M;
    forn(m, M) {
        ll start, end; char type;
        cin >> start >> end >> type;
        start--;
        end--;
        if (type == 'A') {
            printf("%.1f\n", f[min(start, end)][max(start, end)]);
        } else {
            printf("%.1f\n", f[max(start, end)][min(start, end)]);
        }
    }
}