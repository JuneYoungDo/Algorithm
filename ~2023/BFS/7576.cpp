//
// Created by June Young Do on 2021/09/05.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int n, m;
int map[1001][1001];
queue<pair<int, int>> q;
pair<int, int> moveM[4] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

bool isValid(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m)
        return false;
    return true;
}

void bfs() {
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moveM[i].first;
            int nextX = nowX + moveM[i].second;
            if (isValid(nextY, nextX) && map[nextY][nextX] == 0) {
                map[nextY][nextX] = map[nowY][nowX] + 1;
                q.push({nextY, nextX});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    bfs();

    int maxCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            } else if (map[i][j] == -1)
                continue;
            else
                maxCnt = max(maxCnt, map[i][j]);
        }
    }
    cout << maxCnt - 1 << endl;


    return 0;
}