#include <iostream>
#include <string>
#define forn(i,n) for(long long i = 0; i < n; i++)
#define fornt(i, n) for(size_t i = 0; i < n; i++)
typedef long long ll;
using namespace std;

string s, t;
size_t laststringends, sc, tc; ll subC, nonC;
int main() {
    cin >> s >> t;
    laststringends = 0;
    sc = s.length();
    tc = t.length();
    subC = 0;
    nonC = 0;
    if(sc >= tc) for (size_t i=0; i <=sc - tc; i++) {
        cerr << "running loop" << endl;
        if (s.substr(i, tc) == t) {
            if (i >= laststringends) {
                laststringends = i + tc;
                nonC++;
            }
            subC++;
        }
    }
    cout << subC << endl;
    cout << nonC << endl;
}