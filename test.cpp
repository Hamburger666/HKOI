#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

unordered_set<int> c;
vector<int> v;
vector<int> v2;
int a[100000];
unordered_map<int, int> m;

int main() {
    time_t begin = clock();
    forn(i, 1000000) {
        m[i] = i+2;
    }
    time_t end = clock();
    cout << (double) (end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    if (m.find(500000) != m.end())  {
        cout << "True" << endl;
    }
    end = clock();
    cout << (double) (end - begin) /CLOCKS_PER_SEC << endl;
}