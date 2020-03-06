#include <iostream>
#include <algorithm>
#include <numeric>
#define forn(i,n) for(long long i=0;i<n;i++)
#define form(i,n) for(long long i=1; i<=n;i++)
using namespace std;
typedef long long ll;

ll N, M;
ll A[300000],B[300000], X[300000];
ll factors[1000001];
ll mm[1000001], mc = 0, total=0;

ll gcd(ll a, ll b){
    while(b!=0){
        ll t = b;
        b = a%b;
        a = t;
    }
    return a;
}
int main() {
    cin >> N >>M;
    forn(i,N) {
        cin>>A[i];
    }
    forn(i,M){
        cin>>B[i];
        B[i]--;
    }
    forn(i,M){
        X[i]=A[B[i]];
    }
    ll g = X[0];
    for(ll i = 1; i<M;i++){
        g = gcd(g,X[i]);
    }
    // forn(i,M) {
    //     cout << X[i] << endl;
    // }
    // cout << g<< endl;
    forn(i,M){
        factors[X[i]] = true;
    }
    form(i,100){
        for(int j = i; j <= 100; j+=i){
            if (factors[j]) {
                factors[i]=true;
                // factors[j%i]=true;
            }
        }
    }
    total+=M;
    forn(i,N){
        if(A[i]%g) total++;
    }
    // forn(i,30){
    //     cout << factors[i] << " ";
    // }
    // cout << endl;
    forn(i,N){
        // cout << "A[i]" << A[i] << endl;
        // cout << "A[i]%g " << A[i]%g << " !factors[A[i]] " << !factors[A[i]] << endl;
        if(!(A[i]%g) && !factors[A[i]]) {
            // cout << A[i] << endl;
            mm[A[i]]=true;
            mc++;
            total++;
        }
    }
    // cout << total << endl;
    if(total==N){
        cout << mc+1 << endl;
        cout << g << " <>" << endl;
        forn(i,1000000){
            if(mm[i]) cout << i << " =" << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}