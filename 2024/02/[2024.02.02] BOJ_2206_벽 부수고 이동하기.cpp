//
// Created by June Young Do on 2/2/24.
//
#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int N, M;
int map[1002][1002];
int visited[1002][1002][2];
queue<pair<int, pair<int, int>>> q;
pair<int, int> moving[4] = {{1,  0},
                            {0,  1},
                            {-1, 0},
                            {0,  -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j] - '0';
        }
    }

    q.push({0, {0, 0}});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second.first;
        int crashed = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moving[i].first;
            int nextX = nowX + moving[i].second;
            int nowCrashed = crashed;

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && !visited[nextY][nextX][nowCrashed]) {
                if (map[nextY][nextX] == 1 && nowCrashed == 0) {
                    q.push({nextY, {nextX, 1}});
                    visited[nextY][nextX][1] = visited[nowY][nowX][crashed] + 1;
                }
                if (map[nextY][nextX] == 0) {
                    visited[nextY][nextX][crashed] = visited[nowY][nowX][crashed] + 1;
                    q.push({nextY, {nextX, crashed}});
                }
            }
        }
    }

    int ans = 99999999;
    if (ans > visited[N - 1][M - 1][1] && visited[N - 1][M - 1][1] != 0) {
        ans = visited[N - 1][M - 1][1];
    }
    if (ans > visited[N - 1][M - 1][0] && visited[N - 1][M - 1][0] != 0) {
        ans = visited[N - 1][M - 1][0];
    }
    if (ans == 99999999) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
