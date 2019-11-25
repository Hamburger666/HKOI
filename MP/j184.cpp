// https://judge.hkoi.org/task/J184

#include <iostream>
using namespace std;

int N;
const int rock = 1;
int map[2000][6000] = {0};
int bird[2];
int steps = 0;
const int escape = 0;
const int drop = 1;
int endState;


void load() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        int col = i*3 + 2;
        for (int j = 0; j < h; j++) {
            map[j][col] = rock;
        }
    }
    bird[0] = N-1;
    bird[1] = 0;
}

int main() {
    load();
    const int right = 0;
    const int left = 1;
    const int down_to_left = 2;
    const int down_to_right = 3;
    int direction = right;
    int nextRow = N-1;
    int nextCol = 0;

    while (true) {
        if (direction == right) {
            nextRow = bird[0];
            nextCol = bird[1] + 1;
        } else if (direction == left) {
            nextRow = bird[0];
            nextCol = bird[1] - 1;
        } 
        if (direction == right || direction == left) {
            if (map[max(nextRow, 0)][min(nextCol, 3*N-1)] == rock) {
                if (direction == right) {
                    direction = down_to_left;
                } else {
                    direction = down_to_right;
                }
            } 
        } 
        if (direction == down_to_left){
            bird[0] = bird[0] - 1;
            bird[1] = bird[1];
            direction = left;
        } else if (direction == down_to_right) {
            bird[0] = bird[0] - 1;
            bird[1] = bird[1];
            direction = right;
        } else {
            bird[0] = nextRow;
            bird[1] = nextCol;
        }
        if (bird[0] < 0) {
            endState = drop;
            break;
        }
        if (bird[1] < 0) {
            endState = escape;
            break;
        }
        steps++;
    }

    if (endState == escape) {
        cout << "ESCAPE" << endl;
        cout << bird[0] + 1 << endl;
        cout << steps + 1 << endl;
    } else {
        cout << "DROP" << endl;
        cout << bird[1] + 1 << endl;
        cout << steps + 1 << endl;
    }
    return 0;
}