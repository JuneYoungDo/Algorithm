//
// Created by June Young Do on 1/13/24.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'

int computerCnt;
int connectCnt;
vector<int> graph[101];
bool visit[101];

int bfs(int begin) {
    int cnt = 0;
    queue<int> q;
    q.push(begin);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (!visit[now]) {
            cnt++;
            visit[now] = true;
            for (int i = 0; i < graph[now].size(); i++) {
                if (!visit[graph[now][i]]) {
                    q.push(graph[now][i]);
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> computerCnt;
    cin >> connectCnt;

    for (int i = 0; i < connectCnt; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    cout << bfs(1) - 1 << endl;

    return 0;
}