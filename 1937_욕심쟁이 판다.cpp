//
// Created by June Young Do on 2022/07/19.
//
#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int n;
int answer;
int mp[501][501];
int dp[501][501];

int my[4] = {0, 0, -1, 1};
int mx[4] = {1, -1, 0, 0};

int dfs(int y, int x) {
    if (dp[y][x] != 0) {
        return dp[y][x];
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) { continue; }
        if (mp[y][x] >= mp[ny][nx]) { continue; }
        ans = max(dfs(ny, nx), ans);
    }

    dp[y][x] = ans + 1;
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0) {
                dfs(i, j);
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << endl;

    return 0;
}
