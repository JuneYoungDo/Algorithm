//
// Created by June Young Do on 2021/09/05.
//

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
#define endl '\n'

int n, m, cnt;
vector<int> v;
int map[502][502];
bool visit[502][502];
pair<int, int> moveM[4] = {{1,  0},
                           {0,  1},
                           {-1, 0},
                           {0,  -1}};


// 시작점 입력
int bfs(int startY, int startX) {
    int countSell = 0;              // 그림 크기
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visit[startY][startX] = true;
    while (!q.empty()) {
        countSell++;                // 한바퀴 돌때마다 크기++
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + moveM[i].first;
            int nextX = nowX + moveM[i].second;
            if (0 > nextY || nextY >= n || nextX < 0 || nextX >= m)         // 범위 초과
                continue;
            if (!map[nextY][nextX] || visit[nextY][nextX])                   // 방문 및 입력값 확인
                continue;
            q.push({nextY, nextX});
            visit[nextY][nextX] = true;
        }
    }
    return countSell;               // 크기 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && map[i][j])
                v.push_back(bfs(i, j));
        }
    }
    if(v.size() == 0)
        cout<< 0 << ' '<< 0 <<endl;         // 테케 1 1 0 일때 0개의 답이 나오는 경우를 고려해 주지 않아서 오류 발생했었음
    else {
        sort(v.begin(), v.end());       // 최고크기
        cout << v.size() << ' ' << v[v.size() - 1] << endl;
        // 갯수
    }
    return 0;
}