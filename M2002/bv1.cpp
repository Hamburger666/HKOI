#include <iostream>
#include <bitset>
#define forn(i,n) for(long long i = 0; i< n;i++)
using namespace std;
typedef long long ll;

ll N, M, Q;
pair<ll, ll> costs[10000]; bitset<100> channels[10000], lists[20000];
int main() {
    cin >> N >> M >> Q;
    forn(i,N) {
        cin>>costs[i].first;
        costs[i].second=i;
    }
    forn(i,N){
        forn(j,M){
            bool t;
            cin>>t;
            channels[i][j]=t;
        }
    }
    forn(i,Q) {
        ll t;
        cin>>t;
        forn(j,t){
            ll k;
            cin>>k;k--;
            lists[i][k]=true;
        }
    }
    sort(costs, costs+N);
    forn(i,Q){
        bool success=false;
        forn(_,N){
            ll j=costs[_].second;
            if((channels[j]&lists[i])==lists[i]){
                cout<<costs[_].first<<endl;
                success=true;
                break;
            }
        }
        if(!success) cout<<-1<<endl;
    }
}