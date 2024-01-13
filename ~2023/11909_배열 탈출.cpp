//
// Created by June Young Do on 2022/07/23.
//
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
#define endl '\n'
#define INF 987654321

int N;
int maze[2223][2223];
int cost[2223][2223];
int my[2] = {0, 1};
int mx[2] = {1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = -INF;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    cost[0][0] = 0;
    while (!pq.empty()) {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int c = pq.top().first;
        pq.pop();

        if (y == N - 1 && x == N - 1) {
            cout << -cost[y][x] << endl;
            return 0;
        }

        for (int i = 0; i < 2; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            int nc = 0;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) { continue; }
            if (maze[y][x] <= maze[ny][nx]) {
                nc = -(maze[ny][nx] - maze[y][x] + 1);
            }
            if (cost[ny][nx] >= c + nc) {
                continue;
            } else {
                cost[ny][nx] = c + nc;
                pq.push({cost[ny][nx], {ny, nx}});
            }
        }
    }

    return 0;
}
