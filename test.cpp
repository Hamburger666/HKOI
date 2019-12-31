#include <iostream>
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

// vector<int> numbers[100000];
// int main() {
//     forn(i, 100000) numbers[i].push_back(0);
//     cout << "done" << endl;
// }

int ones[100] = {0};
int main() {
   int i = 0;
   forn(k, 2) {
   while (ones[i] == 0) {
       cout << i << endl;
       i++;
   }}
   cout << ones[i] << endl;
   cout << ones[100] << endl;
   cout << i << endl;
}