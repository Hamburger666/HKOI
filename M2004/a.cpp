#include <iostream>
#include <numeric>
#define forn(i,n) for(long long i=0;i<n;i++)
typedef long long ll;
using namespace std;

ll N, M;
ll A[300000], B[300000], BM[300000] = {0};
bool factors[1000000];
ll markedC=0, markedCs=0; ll markedM[300000] = {0};
int main() {
    cin>>N>>M;
    forn(i,N){
        cin>>A[i];
    }
    forn(i,N){
        cin>>B[i];
        B[i]--;
    }
    forn(i,M){
        forn(i,1000) {
            ll n=i+1;
            if (!factors[n] && A[B[i]]%n==0) {
                factors[n]=true;
                factors[A[B[i]]/n]=true;
            }
        }
    }
    ll gcd=1;
    forn(i,1000000){
        if(factors[i] && i>gcd) gcd=i;
    }

    forn(i,M){
        BM[B[i]]=true;
    }
    // forn(i,11){
    //     cout<<BM[i] <<" ";
    // }
    // cout << endl;
    // forn(i,10){
    //     cout<<factors[i]<<" ";
    // }
    // cout<<endl;

    forn(i,N){
        if(!BM[i]){
            if(!factors[A[i]]) {
                markedC++;
                markedCs++;
                markedM[i]=true;
            } else if(A[i]%gcd) {
                markedC++;
            }
        }
    }

    if (markedC==N-M){
        cout << markedCs+1<<endl;
        cout << gcd << " <>" << endl;
        forn(i,300000){
            if(markedM[i]) cout<<A[i] << " ="<<endl;
        }
    } else{
        cout << "IMPOSSIBLE" << endl;
    }
}