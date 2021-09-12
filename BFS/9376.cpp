//
// Created by June Young Do on 2021/09/07.
//

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'
#define INF 99999999

int testcase;
int h, w;
long long ans = INF;
int mapI[104][104];
bool visit[104][104];
int costS[104][104];
int costA[104][104];
int costB[104][104];
vector<pair<int, int>> v;
pair<int, int> moveM[4] = {
        {1,  0},
        {-1, 0},
        {0,  1},
        {0,  -1}
};
struct Node {
    int y, x, value;
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.value > b.value;
    }
};

void initVisit() {
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            visit[i][j] = false;
        }
    }
}

void init() {
    v.clear();
    ans = INF;
    initVisit();
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            costA[i][j] = INF;
            costB[i][j] = INF;
            costS[i][j] = INF;
        }
    }
}

bool isValidMove(int y, int x) {
    if (y < 0 || y >= h + 2 || x < 0 || x >= w + 2) return false;
    if (visit[y][x] == true)return false;
    if (mapI[y][x] == INF) return false;
    return true;
}

void bfs(int y, int x, int cost[][104]) {
    priority_queue<Node, vector<Node>, cmp> pq;
    initVisit();

    pq.push({y, x, 0});
    visit[y][x] = true;
    cost[y][x] = 0;

    while (!pq.empty()) {
        int nowY = pq.top().y;
        int nowX = pq.top().x;
        int nowValue = pq.top().value;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moveM[i].first;
            int nextX = nowX + moveM[i].second;
            int nValue = nowValue;
            if (isValidMove(nextY, nextX)) {
                if (mapI[nextY][nextX] == 1)nValue++;
                pq.push({nextY, nextX, nValue});
                visit[nextY][nextX] = true;
                cost[nextY][nextX] = nValue;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;
    while (testcase--) {
        cin >> h >> w;
        init();
        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
                    mapI[i][j] = 0;
                    continue;
                }
                char c;
                cin >> c;
                if (c == '.') {
                    mapI[i][j] = 0;
                } else if (c == '#') {
                    mapI[i][j] = 1;
                } else if (c == '*') {
                    mapI[i][j] = INF;
                } else {
                    mapI[i][j] = 3;
                    v.push_back({i, j});
                }
            }
        }

        bfs(v[0].first, v[0].second, costA);
        bfs(v[1].first, v[1].second, costB);
        bfs(0, 0, costS);

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                if (mapI[i][j] == INF)
                    continue;
                long long tmp = costS[i][j] + costA[i][j] + costB[i][j];
                if (mapI[i][j] == 1) tmp -= 2;

                ans = min(ans, tmp);
            }
        }

        cout << ans << endl;
    }


    return 0;
}
