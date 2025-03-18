//
// Created by June Young Do on 3/18/25.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define endl '\n'

int n;
int graph[26][26];
bool visited[26][26];
vector<int> v;
int moveY[4] = {0, 0, 1, -1};
int moveX[4] = {1, -1, 0, 0};

void bfs(int y, int x) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moveY[i];
            int nextX = nowX + moveX[i];
            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && graph[nextY][nextX] && !visited[nextY][nextX]) {
                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
                cnt++;
            }
        }
    }
    v.emplace_back(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            graph[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}