//
// Created by June Young Do on 2022/07/14.
//
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
#define endl '\n'

int tc;
int h, w;
int ans;
int keyList;
char building[103][103];
int visited[103][103];

int my[4] = {0, 0, 1, -1};
int mx[4] = {1, -1, 0, 0};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = keyList;
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];
            if (nextY < 0 || nextY > h + 1 || nextX < 0 || nextX > w + 1) { continue; }
            if (building[nextY][nextX] == '*') { continue; }
            if (visited[nextY][nextX] == keyList) { continue; }

            if (building[nextY][nextX] >= 65 && building[nextY][nextX] <= 90) {
                if ((keyList & (1 << (building[nextY][nextX] - 65))) == 0) { continue; }
            }
            if (building[nextY][nextX] >= 97 && building[nextY][nextX] <= 122) {
                keyList = keyList | (1 << (building[nextY][nextX] - 97));
            }
            if (building[nextY][nextX] == '$') {
                ans++;
                building[nextY][nextX] = '.';
            }
            q.push({nextY, nextX});
            visited[nextY][nextX] = keyList;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while (tc--) {

        ans = 0;
        keyList = 0;

        cin >> h >> w;
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                visited[i][j] = -10;
            }
        }
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) {
                building[i][j] = '.';
            }
        }

        for (int i = 1; i <= h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                building[i][j + 1] = s[j];
            }
        }

        string s;
        cin >> s;
        if (s != "0") {
            for (int i = 0; i < s.size(); i++) {
                keyList = keyList | (1 << (s[i] - 97));
            }
        }

        bfs(0, 0);

        cout << ans << endl;
    }
    return 0;
}
