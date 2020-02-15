#include <iostream>
#include <algorithm>
#include <string.h>
#define forn(i,n) for(long long i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll N;
ll A[100000], X[100000];

struct d{
    bool d = false;
    string ds = "DEBUG PRINT: ";
    void printl(string name, ll*l,ll n){if(d){
        cout << ds;
        cout << name <<": ";
        forn(i, n){
            cout << l[i] << " ";
        }
        cout << endl;
    }}
    void println(string name,ll x){if(d) {
        cout << ds;
        cout << name << ": ";
        cout << x << endl;
    }}
};

d d;
ll sum(ll *l,ll n){
    ll sum = 0;
    forn(i,n){
        sum+=l[i];
    }
    return sum;
}
ll findbi(ll *l,ll n,ll left,ll right){
    if(right-left<=1) return right;
    ll m=(right+left)/2;
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
    d.printl("X",X,N);
    d.printl("A",A,N);
    ll mid=findbi(X,0,0,N);

    // ll base;
    // if (X[mid-1] == 0) {
    //     base = A[mid-1];
    //     A[mid-1] = 0;
    // } else {
    //     base = 0;
    // }

    d.println("mid",mid);
    ll maxCost=0;
    forn(o,2){
        ll h[2][100000];
        ll x[2][100000];
        ll len[2] = {0};
        forn(i,mid){
            ll j=mid-1-i;
            h[o][j]=max(0ll,A[i]-abs(X[i]));
            x[o][j]=abs(X[i]);
            len[o]++;
        }
        forn(i,N-mid){
            ll j=i+mid;
            h[!o][i]=max(0ll,A[j]-abs(X[j]));
            x[!o][i]=X[j];
            len[!o]++;
        }

        //always go to h[1]
        sort(h[0],h[0]+len[0]);
        ll hp[100001]; hp[0]=0;
        forn(i, len[0]){
            hp[i+1]=hp[i]+h[0][i];
        }
        d.println("o",o);
        d.printl("h0", h[0], len[0]);
        d.printl("h1", h[1], len[1]);
        d.printl("hp", hp, len[0]+1);
        ll neg=0;
        ll sum1=0;
        forn(i,len[1]) {
            d.println("sum1",sum1);
            ll cost = 0;
            cost+=h[1][i]+sum1;
            d.println("cost: 1: ", cost);
            while(h[0][neg] < x[1][i]*2&&neg<len[0]) {
                neg++;
            }
            cost+=(hp[len[0]]-hp[neg])-x[1][i]*2*(len[0]-neg);
            d.println("(hp[len[0]]-hp[neg])", (hp[len[0]]-hp[neg]));
            d.println("x[1][i]*2*(len[0]-neg)", x[1][i]*2*(len[0]-neg));
            d.println("neg",neg);
            d.println("cost: 2: ", cost);
            if (cost>maxCost) maxCost = cost;
            sum1+=h[1][i];
        }
    }
    cout << maxCost << endl;
}