//
// Created by June Young Do on 3/13/25.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int graph[101][101];
int visited[101][101];
int n, m;

int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};


void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        int nowScore = visited[nowY][nowX];

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];
            if (nextY >= n || nextY < 0 || nextX >= m || nextX < 0 || graph[nextY][nextX] == 0 ||
                visited[nextY][nextX] != -1) {
                continue;
            }
            q.push({nextY, nextX});
            visited[nextY][nextX] = nowScore + 1;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            visited[i][j] = -1;
        }
    }

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    bfs();

    cout << visited[n - 1][m - 1] + 1 << endl;

    return 0;
}