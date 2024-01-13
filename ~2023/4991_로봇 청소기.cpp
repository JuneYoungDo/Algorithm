//
// Created by June Young Do on 2022/07/14.
//

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
#define endl '\n'
#define INF 987654321

int w, h;
int startY, startX;
int dirtyCnt;
char room[21][21];
bool visited[21][21];
int my[4] = {0, 0, -1, 1};
int mx[4] = {1, -1, 0, 0};

vector<pair<int, int>> v;
vector<pair<int, int>> graph[11];
int dfsMin = INF;
bool dfsVisited[11];

void clearVisit() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            visited[i][j] = false;
        }
    }
}

void clearDfs() {
    v.clear();
    for (int i = 0; i < 11; i++) {
        graph[i].clear();
    }
    dfsMin = INF;
    memset(dfsVisited, false, sizeof(dfsVisited));
}

int bfs(int y, int x, int dy, int dx) {
    clearVisit();
    queue<pair<pair<int, int>, int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = true;
    while (!q.empty()) {
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int tmp = q.front().second;
        q.pop();
        if (nowY == dy && nowX == dx) {
            return tmp;
        }
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];
            if (nextY < 0 || nextX < 0 || nextY >= h || nextX >= w) { continue; }
            if (visited[nextY][nextX]) { continue; }
            if (room[nextY][nextX] == 'x') { continue; }
            q.push({{nextY, nextX}, tmp + 1});
            visited[nextY][nextX] = true;
        }
    }
    return 0;
}

void dfs(int now, int cnt, int tmp) {
    dfsVisited[now] = true;
    cnt++;
    if (cnt == dirtyCnt + 1) {
        dfsMin = min(dfsMin, tmp);
    }
    for (int i = 0; i < graph[now].size(); i++) {
        if (!dfsVisited[graph[now][i].second]) {
            dfs(graph[now][i].second, cnt, tmp + graph[now][i].first);
        }
    }
    dfsVisited[now] = false;
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        dirtyCnt = 0;
        clearVisit();
        clearDfs();

        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                room[i][j] = s[j];
                if (s[j] == 'o') {
                    startY = i;
                    startX = j;
                    v.push_back({i, j});
                }
            }
        }

        bool flag = false;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (room[i][j] == '*') {
                    v.push_back({i, j});
                    dirtyCnt++;
                    int x = bfs(i, j, startY, startX);
                    if (!x) {
                        cout << -1 << endl;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) { break; }
        }

        if (!flag) {
            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    graph[i].push_back({bfs(v[i].first, v[i].second, v[j].first, v[j].second), j});
                    graph[j].push_back({bfs(v[i].first, v[i].second, v[j].first, v[j].second), i});
                }
            }
            dfs(0, 0, 0);
            cout << dfsMin << endl;
        }

    }

    return 0;
}