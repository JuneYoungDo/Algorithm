//
// Created by June Young Do on 3/26/24.
//
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'

int n, m;
int answer;
int laboratory[65][65];     // 연구실
int copyLab[65][65];        // 연구실 구조가 매번 바뀔 것이기에 필요한 배열
bool visited[65][65];       // BFS를 위한 방문 여부
bool emptyNum[65];           // 비어있는 공간의 index
vector<pair<int, int>> emptyArea;    // emptyNum에 들어있는 번호에 해당 하는 공간
// emptyNum[0] = true 라면, virusArea[0]에는 비어있는 공간의 좌표가 들어감
vector<pair<int, int>> virusArea;
pair<int, int> moving[4] = {{1,  0},
                            {0,  1},
                            {-1, 0},
                            {0,  -1}};

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moving[i].first;
            int nextX = nowX + moving[i].second;
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;
            if (visited[nextY][nextX] || copyLab[nextY][nextX] != 0) continue;
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
            copyLab[nextY][nextX] = 2;      // 다음번 바이러스 BFS를 위해 바꿔놓는다
        }
    }
}

void makeWall() {
    // 연구실 공간 복사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyLab[i][j] = laboratory[i][j];
        }
    }

    // 새로운 벽 3개 추가
    int cnt = 0;
    for (int i = 0; i < emptyArea.size(); i++) {
        if (cnt == 3) break;
        if (emptyNum[i]) {
            copyLab[emptyArea[i].first][emptyArea[i].second] = 1;
            cnt++;
        }
    }

    // 방문 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }

    // BFS 실행
    for (int i = 0; i < virusArea.size(); i++) {
        BFS(virusArea[i].first, virusArea[i].second);
    }

    // 모든 바이러스에서 BFS 실행 후 안전한 공간 확인
    int tmpCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copyLab[i][j] == 0) tmpCnt++;
        }
    }
    if (tmpCnt > answer) answer = tmpCnt;
}

void choiceWall(int cnt) {
    // 벽을 3개 골랐을 경우 다음 과정 진행
    if (cnt == 3) {
        makeWall();
        return;
    }

    // 벽을 3개까지 고르는 과정(모든 경우의 수를 탐색)
    for (int i = 0; i < emptyArea.size(); i++) {
        if (emptyNum[i]) continue;
        emptyNum[i] = true;
        choiceWall(cnt + 1);
        emptyNum[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    // 입력을 받고, 빈 공간과 바이러스는 따로 저장해 줌
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> laboratory[i][j];
            if (laboratory[i][j] == 0) emptyArea.emplace_back(make_pair(i, j));
            else if (laboratory[i][j] == 2) virusArea.emplace_back(make_pair(i, j));
        }
    }

    // 임의의 벽 3개를 세우는 과정, 재귀적인 방법을 사용
    choiceWall(0);

    cout << answer << endl;

    return 0;
}
