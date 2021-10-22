//
// Created by June Young Do on 2021/10/2.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int n, m, h;
bool flag;
int map[101][101][101];
int day[101][101][101];
queue<pair<pair<int, int>, int>> q;
pair<pair<int, int>, int> moveM[6] = {
        {{1,  0},  0},
        {{0,  1},  0},
        {{-1, 0},  0},
        {{0,  -1}, 0},
        {{0,  0},  1},
        {{0,  0},  -1}
};

bool isValid(int y, int x, int z) {
    if (y < 0 || y >= n || x < 0 || x >= m || z < 0 || z >= h)
        return false;
    return true;
}

void bfs() {
    while (!q.empty()) {
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int nowZ = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nextY = nowY + moveM[i].first.first;
            int nextX = nowX + moveM[i].first.second;
            int nextZ = nowZ + moveM[i].second;
            if (isValid(nextY, nextX, nextZ) && map[nextY][nextX][nextZ] == 0) {
                day[nextY][nextX][nextZ] = day[nowY][nowX][nowZ] + 1;
                map[nextY][nextX][nextZ] = 1;
                q.push({{nextY, nextX}, nextZ});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                day[i][j][k] = -1;
            }
        }
    }

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 0)
                    flag = true;
                if (map[i][j][k] == 1) {
                    q.push({{i, j}, k});
                    day[i][j][k] = 0;
                }
            }
        }
    }

    if (!flag) {
        cout << 0 << endl;
        return 0;
    }

    bfs();

    int maxCnt = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j][k] == -1)
                    continue;
                else if (day[i][j][k] == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                else
                    maxCnt = max(maxCnt, day[i][j][k]);
            }
        }
    }

    cout << maxCnt << endl;

    return 0;
}