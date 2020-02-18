#include <iostream>
#include <algorithm>
#include <string>
#define forn(i,n) for(long long i=0;i<n;i++)
using namespace std;
typedef long long ll;

struct d {
    bool d = false;
    string dm="DEBUG PRINT: ";
    void printl(string name, ll *l, ll n){if(d) {
        cout << dm << name <<": ";
        forn(i,n){
            cout << l[i] <<" ";
        }
        cout << endl;
    }}
};
ll N, X[100000], A[100000];
d d;
ll findbi(ll *l, ll n, ll left, ll right){
    if(right-left<=1) return right;
    ll m=(left+right)/2;
    if(l[left]<=n&&n<l[m]) return findbi(l,n,left,m);
    else return findbi(l,n,m,right);
}
int main() {
    cin>>N;
    forn(i,N){
        cin>>X[i];
    }
    forn(i,N){
        cin>>A[i];
    }
    d.printl("X", X, N);
    d.printl("A", A, N);
    forn(i,N) {
        A[i]=max(0ll, A[i]-abs(X[i]));
    }
    ll maxCost=0;
    ll mid=findbi(X,0,0,N);
    // cout << mid << endl;
    forn(o,2){
        ll x[2][100000], a[2][100000], ac[2] = {0};
        ac[o] = mid;
        forn(i,mid){
            ll j = mid-1-i;
            x[o][i]=abs(X[j]);
            a[o][i]=A[j];
        }
        ac[!o]=N-mid;
        forn(i,N-mid){
            ll j=i+mid;
            x[!o][i]=abs(X[j]);
            a[!o][i]=A[j];
        }
        // move to direction 1
        sort(a[0],a[0]+ac[0]);
        ll ap[100001]; ap[0]=0;
        forn(i,ac[0]){
            ap[i+1]=ap[i]+a[0][i];
        }
        d.printl("a0",a[0],ac[0]);
        ll sum=0;
        ll neg=0;
        forn(i,ac[1]){
            ll cost=sum+a[1][i];
            while(a[0][neg]<x[1][i]*2 && neg<ac[0]){
                neg++;
            }
            cost+=(ap[ac[0]]-ap[neg])-2*x[1][i]*(ac[0]-neg);
            sum+=a[1][i];
            if (cost > maxCost) {
                maxCost = cost;
            }
        }
    }
    cout << maxCost << endl;
}