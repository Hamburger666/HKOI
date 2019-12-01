#include <iostream>
#include<stdexcept>
#include <limits.h>
using namespace std;


#define forn(i, n) for (int i =0; i< n; i++)
// subtask 1

class Subtask1 {
    public:
    int w2, w4, x;
    void init() {
        cin >> w2 >> w4 >> x;
        if (w2 * 2 <= w4) {
            cout << x / 2 * w2 + ((x%2) ? w2 : 0) << endl;
        } else if (w4 <= w2) {
            cout << x / 4*w4 + ((x%4) ? w4 : 0) << endl;
        } else {
            int remaining = x;
            int money = 0;
            money += remaining/4*w4;
            remaining -= remaining/4 * 4;
            if (remaining) {
                if (remaining > 2) {
                    money += w4;
                } else {
                    money += w2;
                }
            }
            cout << money << endl;
        }
    }
};

class Subtask2 {
    public:
    int w2, w4, y;
    void init() {
        cin >> w2 >> w4 >> y;
        if (w2 * 2 <= w4) {
            cout << y / w2 * 2;
        } else {
            int remaining = y;
            int wingsC = 0;
            wingsC += remaining / w4 * 4;
            remaining -= remaining / w4 * w4;
            wingsC += remaining / w2 * 2;
            cout << wingsC << endl;
        }
    }
};

class Subtask3 {
    public:
    int n4, n6, n9, x;
    int buyN(int x) {
        if (x <= 0) {
            return 0;
        }
        int one, two, three;
        one = n4 + buyN(x - 4);
        two = n6 + buyN(x - 6);
        three = n9 + buyN(x - 9);
        return (min(one, min(two, three)));
    }
    void init() {
        cin >> n4 >> n6 >> n9 >> x;
        cout << buyN(x) << endl;
    }
};

class Subtask4 {
    public:
    int n4, n6, n9, y;

    int buyN69(int y) {
        int maxCount = 0;
        forn(n6C, y/n6 + 1) {
            int n9C = (y - n6C * n6) / n9;
            int count = n6C * 6 + n9C * 9;
            if (count > maxCount) maxCount = count;
        }
        return maxCount;
    }
    int buyN(int y) { 
        int maxCount = 0;
        forn(n4C, y/n4 + 1) {
            int count = n4C * 4 + buyN69(y - n4C*n4);
            if (count > maxCount) maxCount = count;
        }
        return maxCount;
    }
    void init() {
        cin >> n4 >> n6 >> n9 >> y;
        cout << buyN(y) << endl;
    }
};

class Subtask4_recursive {
    public:
    int n4, n6, n9, y, max_nuggets[100001];

    int buyN(int y) {
        if (max_nuggets[y] != -1) {
            return max_nuggets[y];
        }
        int maxCount = 0;
        int one = 0;
        int two = 0;
        int three = 0;
        if (y - n4 >= 0) {
            one = 4 + buyN(y - n4);
        }
        if (y - n6 >= 0) {
            two = 6 + buyN(y-n6);
        }
        if (y - n9 >= 0) {
            three = 9 + buyN(y-n9);
        }
        max_nuggets[y] = max(one, max(two, three));
        return max_nuggets[y];
    }

    void init() {
        cin >> n4 >> n6 >> n9 >> y;
        forn(i, 100001) max_nuggets[i] = -1;
        cout << buyN(y) << endl;
    }
};

int main() {
    int subtaskNo;
    cin >> subtaskNo;
    if (subtaskNo == 1) {
        Subtask1 a;
        a.init();
    } else if (subtaskNo == 2) {
        Subtask2 a;
        a.init();
    } else if (subtaskNo == 3) {
        Subtask3 a;
        a.init();
    } else if (subtaskNo == 4) {
        Subtask4 a;
        a.init();
    } else {
        throw runtime_error("");
    }
}