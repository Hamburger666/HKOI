#include <iostream>
#include <string>
#define forn(i,n) for (long long i = 0; i < n;i++)
using namespace std;
typedef long long ll;

string N; ll s;
int main() {
    cin >> N;
    if(N[1] >= 'A') {
        s+=9*(10+N[0]-'A');
        s+=8*(10+N[1]-'A');
        forn(i, 6){
            ll x = 7-i;
            ll j = i+2;
            s+=x*(N[j]-'0');
        }
    } else {
        s+= 9*36;
        s+= 8*(10+N[0]-'A');
        forn(i, 6){
            ll x = 7-i;
            ll j = i+1;
            s+=x*(N[j]-'0');
        }
    }
    ll out = (11-s%11)%11;
    // cout << s << endl;
    string o;
    if (out<10) {
        o = to_string(out);
    } else {
        o = "A";
    }
    cout << N << '(' << o <<')' << endl;
}