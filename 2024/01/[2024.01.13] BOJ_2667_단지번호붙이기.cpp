//
// Created by June Young Do on 1/13/24.
//

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'

int answer;
vector<int> houseCnt;

int graphSize;
int graph[26][26];
int visit[26][26];
pair<int, int> connectHouse[4] = {{1,  0},
                                  {0,  1},
                                  {-1, 0},
                                  {0,  -1}};

void bfs(int y, int x) {
    int tmpCnt = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();
        graph[nowY][nowX] = 0;
        for (int i = 0; i < 4; i++) {
            int nextY = nowY + connectHouse[i].first;
            int nextX = nowX + connectHouse[i].second;
            if (nextY < 0 || nextY >= graphSize || nextX < 0 || nextX >= graphSize || !graph[nextY][nextX]) {
                continue;
            }
            q.push({nextY, nextX});
            graph[nextY][nextX] = 0;
            tmpCnt++;
        }
    }
    houseCnt.emplace_back(tmpCnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> graphSize;
    for (int i = 0; i < graphSize; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') {
                graph[i][j] = 0;
            } else {
                graph[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphSize; j++) {
            if (graph[i][j]) {
                answer++;
                bfs(i, j);
            }
        }
    }

    sort(houseCnt.begin(), houseCnt.end());

    cout << answer << endl;
    for (int i = 0; i < houseCnt.size(); i++) {
        cout << houseCnt[i] << endl;
    }

    return 0;
}