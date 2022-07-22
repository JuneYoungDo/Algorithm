//
// Created by June Young Do on 2022/07/22.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int N, M;
int sy, sx;
int dy, dx;
char mp[51][51];
bool visited[51][51];

int my[4] = {0, 0, 1, -1};
int mx[4] = {1, -1, 0, 0};


int countSide(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + my[i];
        int nx = x + mx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
        if (mp[ny][nx] == 'g') { cnt++; }
    }
    if (cnt > 0) { return 1; }
    else { return 0; }
}

void bfs(int y, int x) {
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    pq.push({{0, 0},
             {y, x}});
    visited[y][x] = true;

    while (!pq.empty()) {
        int nowY = pq.top().second.first;
        int nowX = pq.top().second.second;
        int nowG = pq.top().first.first;
        int sideG = pq.top().first.second;
        pq.pop();

        if (nowY == dy && nowX == dx) {
            cout << -nowG << ' ' << -sideG << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = nowY + my[i];
            int nx = nowX + mx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
            if (visited[ny][nx]) { continue; }
            if (mp[ny][nx] == 'g') {
                pq.push({{nowG - 1, sideG},
                         {ny,       nx}});
            }
            if (mp[ny][nx] == '.') {
                pq.push({{nowG, sideG - countSide(ny, nx)},
                         {ny,   nx}});
            }
            if (mp[ny][nx] == 'F') {
                pq.push({{nowG, sideG},
                         {ny,   nx}});
            }
            visited[ny][nx] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            mp[i][j] = s[j];
            if (s[j] == 'S') {
                sy = i;
                sx = j;
            }
            if (s[j] == 'F') {
                dy = i;
                dx = j;
            }
        }
    }

    bfs(sy, sx);

    return 0;
}