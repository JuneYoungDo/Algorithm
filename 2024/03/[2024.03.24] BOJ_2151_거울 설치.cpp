//
// Created by June Young Do on 3/24/24.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'
#define MAX 99999999

int n;
int answer = MAX;
pair<int, int> startPoint, endPoint;
int visit[51][51][4];
char house[51][51];
pair<int, int> dir[4] = {{1,  0},
                         {-1, 0},
                         {0,  1},
                         {0,  -1}}; // 같은 직선 라인 = 0과 1, 2와 3 (일직선상)

pair<int, int> changeDir(int nowDir) {
    pair<int, int> ret;
    if (nowDir == 0 || nowDir == 1) {
        ret.first = 2;
        ret.second = 3;
    } else {
        ret.first = 0;
        ret.second = 1;
    }
    return ret;
}

void BFS() {
    queue<pair<pair<int, int>, int>> q; // y좌표, x좌표, 방향
    for (int i = 0; i < 4; i++) {   // 시작점에서 4방향을 모두 확인
        pair<pair<int, int>, int> tmp;
        tmp.first.first = startPoint.first;
        tmp.first.second = startPoint.second;
        tmp.second = i; // 0,1,2,3 -> 4방향을 의미
        visit[startPoint.first][startPoint.second][i] = 0;
        q.push(tmp);
    }
    while (!q.empty()) {
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int nowDir = q.front().second;
        q.pop();

        int nextY = nowY + dir[nowDir].second;
        int nextX = nowX + dir[nowDir].first;
        pair<int, int> nextDir = changeDir(nowDir);   // 거울을 만났을 때 꺾일 수 있는 2가지 방향

        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;   // 범위를 벗어난 경우
        if (house[nextY][nextX] == '*') continue;   // 벽을 만난 경우
        else if (house[nextY][nextX] == '!') {   // 거울을 설치할 수 있는 지점에서는 설치할 수 있고, 안할 수도 있음
            // 거울을 설치하는 경우 -> 두가지 방향으로 꺾이는 것을 고려
            if (visit[nextY][nextX][nextDir.first] > visit[nowY][nowX][nowDir] + 1) {
                visit[nextY][nextX][nextDir.first] = visit[nowY][nowX][nowDir] + 1;
                q.push(make_pair(make_pair(nextY, nextX), nextDir.first));
            }
            if (visit[nextY][nextX][nextDir.second] > visit[nowY][nowX][nowDir] + 1) {
                visit[nextY][nextX][nextDir.second] = visit[nowY][nowX][nowDir] + 1;
                q.push(make_pair(make_pair(nextY, nextX), nextDir.second));
            }

            // 거울 설치를 안하는 경우 -> 빛의 진행 방향이 같음
            if (visit[nextY][nextX][nowDir] > visit[nowY][nowX][nowDir]) {
                visit[nextY][nextX][nowDir] = visit[nowY][nowX][nowDir];
                q.push(make_pair(make_pair(nextY, nextX), nowDir));
            }
        } else if (house[nextY][nextX] == '.') { // 허공을 만나는 경우 -> 거울을 설치하지 않는 경우와 같음
            if (visit[nextY][nextX][nowDir] > visit[nowY][nowX][nowDir]) {
                visit[nextY][nextX][nowDir] = visit[nowY][nowX][nowDir];
                q.push(make_pair(make_pair(nextY, nextX), nowDir));
            }
        } else if (house[nextY][nextX] == '#') {  // 도착 지점을 만나는 경우
            if (visit[nextY][nextX][nowDir] > visit[nowY][nowX][nowDir]) {
                visit[nextY][nextX][nowDir] = visit[nowY][nowX][nowDir];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            house[j][i] = s[j];
            if (s[j] == '#') {
                if (!flag) {
                    startPoint.first = j;
                    startPoint.second = i;
                    flag = true;
                } else {
                    endPoint.first = j;
                    endPoint.second = i;
                }
            }
            visit[i][j][0] = visit[i][j][1] = visit[i][j][2] = visit[i][j][3] = MAX;
        }
    }

    BFS();

    for (int i = 0; i < 4; i++) { // 4가지 방향 중 가장 작은 값을 선택
        if (answer > visit[endPoint.first][endPoint.second][i]) {
            answer = visit[endPoint.first][endPoint.second][i];
        }
    }

    cout << answer << endl;

    return 0;
}