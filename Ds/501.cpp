#include <iostream>
#include <fstream>
#define forn(i,n) for(long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll b = 0, N;
ifstream fin;
int main() {
    fin.open("account.txt");
    fin >> N;
    forn(i, N) {
        ll t;
        fin >> t;
        b += t;
    }
    cout << b << endl;
}