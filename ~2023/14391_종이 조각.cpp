//
// Created by June Young Do on 2022/07/10.
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;
#define endl '\n'

int N, M;
int ans;
int mp[5][5];
int status[5][5];

void cal(int arr[5][5]) {
    int tmp = 0;
    bool visited[5][5];
    memset(visited, false, sizeof(visited));
    vector<int> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) { continue; }
            visited[i][j] = true;
            if (arr[i][j] == 1) {       // 가로인 경우
                v.push_back(mp[i][j]);
                for (int k = j + 1; k < M; k++) {
                    if (arr[i][k] == 2) { break; }
                    v.push_back(mp[i][k]);
                    visited[i][k] = true;
                }
                int tmp2 = 0;
                for (int k = 0; k < v.size(); k++) {
                    tmp2 += v[k] * pow(10, v.size() - k - 1);
                }
                tmp += tmp2;
                v.clear();
            } else {                // 세로인 경우
                v.push_back(mp[i][j]);
                for (int k = i + 1; k < N; k++) {
                    if (arr[k][j] == 1) { break; }
                    v.push_back(mp[k][j]);
                    visited[k][j] = true;
                }
                int tmp2 = 0;
                for (int k = 0; k < v.size(); k++) {
                    tmp2 += v[k] * pow(10, v.size() - k - 1);
                }
                tmp += tmp2;
                v.clear();
            }
        }
    }
    ans = max(tmp, ans);
}

void dfs(int arr[5][5], int y, int x, int cnt) {
    if (cnt == N * M) {
        cal(arr);
        return;
    }
    arr[y][x] = 1;
    int nextX = x + 1;
    int nextY = y;
    if (nextX == M) {
        nextY = y + 1;
        nextX = 0;
    }
    dfs(arr, nextY, nextX, cnt + 1);

    arr[y][x] = 2;
    nextX = x + 1;
    nextY = y;
    if (nextX == M) {
        nextY = y + 1;
        nextX = 0;
    }
    dfs(arr, nextY, nextX, cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            mp[i][j] = tmp[j] - '0';
        }
    }

    dfs(status, 0, 0, 0);

    cout << ans << endl;

    return 0;
}