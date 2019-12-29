#include <iostream>
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

class Somenumbers {
    public:
    int a, b;
    Somenumbers() {}
    Somenumbers(int a, int b) {
        this->a = a;
        this->b = b;
    }
};

main() {
    vector<Somenumbers> myObjects;
    clock_t begin = clock();
    vector<int> myArray[2];
    forn(i, 10000) {
        myObjects.push_back(Somenumbers(i, i+1));
    }
    clock_t end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC << endl;

    begin = clock();
    forn(i, 10000) {
        myArray[0].push_back(i);
        myArray[1].push_back(i+1);
    }
    end = clock();
    cout << double(end - begin) / CLOCKS_PER_SEC << endl;

}