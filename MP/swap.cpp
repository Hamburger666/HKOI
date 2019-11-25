#include <iostream>
using namespace std;

const int s = 10;
int a[s];


void add() {
    for (int i = 0; i < s; i++) {
        a[i] = i + 1;
    }
}

void swap(int x, int y) {
    int t;
    t = a[x];
    a[x] = a[y];
    a[y] = t;
}

void printA() {
    for (int i = 0; i < s; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void f(int k) {
    int i = 0;
    while (i < k / 2) {
        swap(i, k - i - 1);
        i++;
    }
}

int main() {
    add();
    f(4);
    printA();
}

