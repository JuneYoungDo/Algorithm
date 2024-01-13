//
// Created by June Young Do on 2022/07/19.
//
#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int n, m, k;
bool flag;
int mp[1001][1001];
int dist[1001][1001][11];

int my[4] = {0, 0, 1, -1};
int mx[4] = {1, -1, 0, 0};

void bfs(int cnt, int y, int x) {
    queue<pair<int, pair<int, int>>> q;
    q.push({cnt, {y, x}});
    while (!q.empty()) {
        int nowCnt = q.front().first;
        int nowY = q.front().second.first;
        int nowX = q.front().second.second;
        q.pop();
        if (nowY == n - 1 && nowX == m - 1) {
            cout << dist[nowY][nowX][nowCnt];
            flag = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) { continue; }
            int nextCnt = nowCnt + mp[nextY][nextX];
            if (nextCnt > k) { continue; }
            if (dist[nextY][nextX][nextCnt] &&
                dist[nextY][nextX][nextCnt] <= dist[nowY][nowX][nowCnt] + 1) { continue; }
            q.push({nextCnt, {nextY, nextX}});
            dist[nextY][nextX][nextCnt] = dist[nowY][nowX][nowCnt] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    dist[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '0') {
                mp[i][j] = 0;
            } else {
                mp[i][j] = 1;
            }
        }
    }

    bfs(0, 0, 0);

    if (!flag) {
        cout << -1 << endl;
    }

    return 0;
}
