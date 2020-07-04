#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define INF 1001
using namespace std;
typedef long long ll;

ll N;
vector<pair<ll, ll> > cities[1000]; 
ll source, dest;
ll dist[1000];
bool fin[1000];
ll pre[1000];
priority_queue<pair<ll, pair<ll, ll> > > toFinalise; // {dist, {from, to}}
stack<ll> path;

void dijkstra2(ll source) {
    forn(i, N) {
        dist[i] = INF;
    }
    dist[source] = 0;
    toFinalise.push(make_pair(0, make_pair(source, source)));
    while (!toFinalise.empty()) {
        pair<ll, ll> c = toFinalise.top().second;
        ll one = c.first;
        ll two = c.second;
        toFinalise.pop();
        if (!fin[one]) {
            fin[one] = true;
            pre[one] = two;
            for (pair<ll, ll> c : cities[one]) {
                ll two = c.first;
                ll d = c.second;
                if (!fin[two] && dist[one] + c.second < dist[two]) {
                    pre[two] = one;
                    dist[two] = dist[one] + c.second;
                    toFinalise.push(make_pair(dist[two], make_pair(one, two)));
                }
            }
        }
    }
}
int main() {
    cin >> N;
    cin >> source >> dest;
    source--;
    dest--;
    ll a, b, d;
    cin >> a >> b >> d;
    while(a != 0 || b != 0 || d != 0) {
        a--;
        b--;
        cities[a].push_back(make_pair(b, d));
        cities[b].push_back(make_pair(a, d));
        cin >> a >> b >> d;
    }
    dijkstra2(source);
    cout << dist[dest] << endl;
    ll k = dest;
    while (k != source) {
        path.push(k);
        k = pre[k];
    }
    cout << source + 1 << " ";
    while (!path.empty()) {
        cout << path.top() + 1 << " ";
        path.pop();
    }
    cout << endl;
}