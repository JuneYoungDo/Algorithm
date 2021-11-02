//
// Created by June Young Do on 2021/11/02.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int k, w, h;
int map[201][201];
bool visit[201][201][31];
pair<int, int> horseMove[8] = {
        {-2, 1},
        {-1, 2},
        {2,  1},
        {1,  2},
        {-2, -1},
        {-1, -2},
        {2,  -1},
        {1,  -2}
};
pair<int, int> monkeyMove[4] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

int bfs() {
    // y좌표, x좌표, 몇번만에 해당지점 도착했는지, 능력을 몇번 사용했는지
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0},
            {0, 0}});
    visit[0][0][0] = true;
    while (!q.empty()) {
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int nowC = q.front().second.first;
        int nowA = q.front().second.second;
        q.pop();
        if (nowY == h - 1 && nowX == w - 1) return nowC;
        if (nowA < k) {
            for (int i = 0; i < 8; i++) {
                int nextY = nowY + horseMove[i].first;
                int nextX = nowX + horseMove[i].second;
                if (nextY >= 0 && nextX >= 0 && nextY < h && nextX < w) {
                    if (map[nextY][nextX] == 0 && !visit[nextY][nextX][nowA + 1]) {
                        visit[nextY][nextX][nowA + 1] = true;
                        q.push({{nextY,    nextX},
                                {nowC + 1, nowA + 1}});
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + monkeyMove[i].first;
            int nextX = nowX + monkeyMove[i].second;
            if (nextY >= 0 && nextX >= 0 && nextY < h && nextX < w) {
                if (map[nextY][nextX] == 0 && !visit[nextY][nextX][nowA]) {
                    visit[nextY][nextX][nowA] = true;
                    q.push({{nextY,    nextX},
                            {nowC + 1, nowA}});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    cout<<bfs()<<endl;

    return 0;
}