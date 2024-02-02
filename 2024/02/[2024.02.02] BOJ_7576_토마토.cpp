//
// Created by June Young Do on 2/02/24.
//
#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int M, N;
int graph[1001][1001];
queue<pair<int, int>> q;
pair<int, int> moving[4] = {{1,  0},
                            {0,  1},
                            {-1, 0},
                            {0,  -1}};

void bfs() {
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moving[i].first;
            int nextX = nowX + moving[i].second;
            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && graph[nextY][nextX] == 0) {
                graph[nextY][nextX] = graph[nowY][nowX] + 1;
                q.push({nextY, nextX});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (graph[i][j] > ans) {
                ans = graph[i][j];
            }
        }
    }

    cout << ans - 1 << endl;

    return 0;
}