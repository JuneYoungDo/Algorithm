//
// Created by June Young Do on 2022/07/14.
//
#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int M, N;
int cnt;
int space[251][251];
int visited[251][251];
int my[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int mx[8] = {1, -1, -1, 1, 0, 1, -1, 0};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];
            if (visited[nextY][nextX]) { continue; }
            if (!space[nextY][nextX]) { continue; }
            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (space[i][j] == 1 && visited[i][j] == false) {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
