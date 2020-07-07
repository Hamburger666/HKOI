#include <iostream>
#include <vector>
#include <queue>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define INF 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> cities[50]; // {two, distance}
ll N, M;
ll source = 0;
ll dest = 1;
ll dist[2][50];
priority_queue<pair<ll, pair<ll, bool> > > toFinalise; // {-dist, {city, 1 or two trip}}

void dijkstraCore() {
    while(!toFinalise.empty()) {    
        ll d = -toFinalise.top().first;
        ll one = toFinalise.top().second.first;
        bool u =  toFinalise.top().second.second;
        toFinalise.pop();
        if (d == dist[u][one]) {
            for (pll c : cities[one]) {
                ll two = c.first;
                ll d = c.second;
                if (u) {
                    d = d * 4 / 5;
                }
                if (d + dist[u][one] < dist[!u][two]) {
                    dist[!u][two] = d + dist[u][one];
                    toFinalise.push(make_pair(-dist[!u][two], make_pair(two, !u)));
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    forn(i, M) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        cities[a].push_back(make_pair(b, d));
        cities[b].push_back(make_pair(a, d));
    }
    forn(u, 2) {
        forn(i, N) {
            dist[u][i] = INF;
        }
    }
    dist[0][source] = 0;
    toFinalise.push(make_pair(0, make_pair(source, 0)));
    dijkstraCore();
    ll destDist[2];
    forn(u, 2) {
        destDist[u] = dist[u][dest];
    }
    cout << min(destDist[0], destDist[1]) << endl;
    forn(u, 2) {
        forn(i, N) {
            dist[u][i] = INF;
        }
    }
    forn(u, 2) {
        dist[u][dest] = destDist[u];
        toFinalise.push(make_pair(-dist[u][dest], make_pair(dest, u)));
    }
    dijkstraCore();
    cout << min(dist[0][source], dist[1][source]) << endl;
}