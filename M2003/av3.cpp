#include <iostream>
#include <string>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

// debug functions 
struct d{
    bool d=false;
    void print(string s){
        cout<<"DEBUG PRINT: "<<s;
    }
    void printl(string name,ll *l,ll n){if(d){
        print(name+": ");
        forn(i,n) cout<<l[i]<<" ";
        cout<<endl;

    }}
    void println(string name,string s){if(d){
        print(name+": "+s+"\n");
    }}
    void println(string name, ll n){if(d){
        println(name, to_string(n));
    }}
};

//-------
ll findbi(ll *l,ll n,ll left,ll right) {
    if (right-left<=1) return right;
    ll m=(left+right)/2;
    if(l[left]<=n&&n<l[m])return findbi(l,n,left,m);
    else return findbi(l,n,m,right);
}
ll N, X[100000], A[100000];
d d;
int main() {
    cin>>N;
    forn(i,N){
        cin>>X[i];
    }
    forn(i,N){
        cin>>A[i];
    }
    ll maxCost=0;
    forn(o,2){
        int m=findbi(X,0,0,N);
        d.println("m",m);
        ll xo[2][100000];
        ll ao[2][100000];
        forn(i,m){
            ll _=m-1-i;
            xo[o][_]=-X[i];
            ao[o][_]=A[i];
        }
        forn(_,N-m){
            ll i=_+m;
            xo[!o][_]=X[i];
            ao[!o][_]=A[i];
        }
        ll len[2];
        len[o]=m;
        len[!o]=N-m;
        d.printl("X",X,N);
        d.printl("A",A,N);
        d.printl("xr",xo[0],len[0]);
        d.printl("xl",xo[1],len[1]);
        d.printl("ao0",ao[0],len[0]);
        d.println("m",m);
        ll h[2][100000];
        forn(i,2)forn(j,len[i]){
            h[i][j]=max(0ll,ao[i][j]-xo[i][j]);
        }
        d.printl("h0",h[0],len[0]);
        d.printl("h1",h[1],len[1]);
        sort(h[0],h[0]+len[0]);
        ll hp[100000]={0};
        forn(i,len[1]) {
            hp[i+1]=hp[i]+h[1][i];
        }
        ll s=0;
        forn(i,len[0]){
            s+=h[0][i];
        }
        

        ll co[100001];
        ll v=0;
        ll hi=0;
        ll p=0;
        forn(i, len[0]){
            co[i]=v;
            v+=(xo[1][i]*2-p)*hi;
            while(hp[hi]<xo[1][i]*2 && hi<len[0]){
                v+=xo[1][i]*2-h[0][hi];
                hi++;
            }
            p=xo[1][i]*2;
        }
        co[len[0]]=v;
        d.printl("co", co, len[0]+1);
        forn(i,len[1]){
            ll cost=hp[i+1]+s-xo[1][i]*2*len[0]+co[i+1];
            if(cost>maxCost) maxCost=cost;
        }

    }
    cout<<maxCost<<endl;
}