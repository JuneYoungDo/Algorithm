//
// Created by June Young Do on 2021/08/30.
//
#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define endl '\n'

struct moveR {
    int y, x;
};

int n, m;
int cost[101][101];
string map[101];
bool visit[101][101];
moveR movingRange[4] = {{1,  0},
                        {0,  1},
                        {-1, 0},
                        {0,  -1}};

void bfs(int y, int x) {
    visit[y][x] = true;
    queue<pair<int, int>> q;
    q.push({y, x});
    cost[y][x]=1;
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + movingRange[i].y;
            int nextX = nowX + movingRange[i].x;
            if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m) {
                if (map[nextY][nextX] == '1' && visit[nextY][nextX] == false) {
                    cost[nextY][nextX] = cost[nowY][nowX] + 1;
                    visit[nextY][nextX] = true;
                    q.push({nextY, nextX});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin>>map[i];
    }
    bfs(0,0);

    cout<<cost[n-1][m-1]<<endl;

    return 0;
}