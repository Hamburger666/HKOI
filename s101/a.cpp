#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++) 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N, M;
vector<pll> squares[2];
pll board[2][60001]; // {distance, value}
unordered_set<ll> boarders[2];

ll area(bool type, ll d) {
    if (!type) {
        return d * d * 4;
    } else {
        return d * d * 2;
    }
}

ll gp(bool type, ll x, ll y) {
    if (!type) {
        return max(abs(x), abs(y));
    } else {
        return abs(x) + abs(y);
    }
}

int main() {
    cin >> N >> M;
    forn(i, N) {
        ll d, p; char t;
        cin >> d >> p >> t;
        boarders[t - 'A'].insert(d);
        squares[t - 'A'].push_back(make_pair(d, p));
    }
    forn(u, 2) {
        sort(squares[u].begin(), squares[u].end());
        squares[u].push_back(make_pair(60000, 0));
    }
    forn(u, 2) {
        ll ic = 0;
        forn(i, 60001) {
            board[u][i] = squares[u][ic];
            if (i == squares[u][ic].first) {
                ic++;
            }
        }
    }
    ll sum = 0;
    forn(i, M) {
        ll x, y;
        cin >> x >> y;
        bool t = false;
        forn(u, 2) {
            t |= (boarders[u].find(gp(u, x, y)) != boarders[u].end());
        }
        if (!t) {
            if (area(0, board[0][gp(0, x, y)].first) > area(1, board[1][gp(1, x, y)].first)) {
                sum += board[1][gp(1, x, y)].second;
            } else{
                sum += board[0][gp(0, x, y)].second;
            }
        }
    }
    cout << sum << endl;

}