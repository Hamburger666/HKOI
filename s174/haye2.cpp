//
//  s174v4.cpp
//  s174v4 - solves K > 1 and scores 79 points
//
//  Created by Haye Chan on 4/12/19.
//  Copyright © 2019 Haye Chan. All rights reserved.
//
#include <iostream>
using namespace std;
#define MAX_COST 81 * 80 / 4 * 50 * 128
#define RANGE 256

int V[80][80];
int N, A, B, K;
int best_xyz_to_sum[80][80][RANGE*3+1][3];
int min_cost_to_sum[80][80][RANGE*3+1];

void read_input() {
    int r, c;
    cin >> N >> A >> B >> K;
    for (r=0; r<N; r++) {
        for (c=0; c<=r; c++) {
            cin >> V[r][c];
        }
    }
}

int dist(int src, int dest) {
    int diff = dest - src;
    if (diff > 0) {
        return diff * A;
    } else {
        return -diff * B;
    }
}

int main() {
    int r0, c0, i, x, y, z, r, c, cost, sum, min_cost, best_sum, n_big_group = 0;
    int r0c0[3240][2];

    read_input();

    // create a list of (r0, c0)'s that denotes each "big group"
    for (r0=0; r0<min(K, N-K); r0++) {
        for (c0=0; c0<=r0; c0++) {
            r0c0[n_big_group][0] = r0;
            r0c0[n_big_group][1] = c0;
            n_big_group++;
        }
    }
    for (r0=K; r0<min(2*K-1, N-K); r0++) {
        for (c0=r0 - K + 1; c0<K; c0++) {
            r0c0[n_big_group][0] = r0;
            r0c0[n_big_group][1] = c0;
            n_big_group++;
        }
    }

    // for each <sum>, find the optimal solution for each "big group" and cache the results
    for (i=0; i<n_big_group; i++) {
        r0 = r0c0[i][0];
        c0 = r0c0[i][1];
        for (sum=3; sum<=RANGE*3; sum++) {
            min_cost_to_sum[r0][c0][sum] = MAX_COST;
        }
        // cache the cost-distance to convert the 1/3 of "subgroup" into target x, y or z
        int distance_to_target[RANGE+1][3] = {0};        // cost-distance to move all number in a subgroup into x
        for (r=r0; r<N; r+=K) {
            for (c=c0; c<=r; c+=K) {
                for (x=1; x<=RANGE; x++) {
                    distance_to_target[x][(r/K + c/K) % 3] += dist(V[r][c], x);
                }
            }
        }
        for (x=1; x<=RANGE; x++) {
            for (y=1; y<=RANGE; y++) {
                for (z=1; z<=RANGE; z++) {
                    sum = x + y + z;
                    fprintf(stderr, "x=%d y=%d z=%d sum=%d",x,y,z,sum);
                    cost = distance_to_target[x][0] + distance_to_target[y][1] + distance_to_target[z][2];
                    if (cost < min_cost_to_sum[r0][c0][sum]) {
                        min_cost_to_sum[r0][c0][sum] = cost;
                        best_xyz_to_sum[r0][c0][sum][0] = x;
                        best_xyz_to_sum[r0][c0][sum][1] = y;
                        best_xyz_to_sum[r0][c0][sum][2] = z;
                    }
                }
            }
        }
    }

    // find the sum that minimizes the total cost, i.e., sum of min_cost for each "big group"
    min_cost = MAX_COST;
    for (sum=3; sum<=RANGE*3; sum++) {
        cost = 0;
        for (i=0; i<n_big_group; i++) {
            r0 = r0c0[i][0];
            c0 = r0c0[i][1];
            cost += min_cost_to_sum[r0][c0][sum];
        }
        if (cost < min_cost) {
            min_cost = cost;
            best_sum = sum;
        }
    }
    
    // update the vertices with the best (x, y, z) solution
    for (i=0; i<n_big_group; i++) {
        r0 = r0c0[i][0];
        c0 = r0c0[i][1];
        for (r=r0; r<N; r+=K) {
            for (c=c0; c<=r; c+=K) {
                V[r][c] = best_xyz_to_sum[r0][c0][best_sum][(r/K + c/K) % 3];
            }
        }
    }

    cout << min_cost << endl;
    for (r=0; r<N; r++) {
        for (c=0; c<=r; c++) {
            cout << V[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}
