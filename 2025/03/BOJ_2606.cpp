//
// Created by June Young Do on 3/14/25.
//
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'

int answer;
int n, m;
vector<int> graph[101];
bool visit[101];

void bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            if (visit[graph[now][i]]) {
                continue;
            }
            q.push(graph[now][i]);
            visit[graph[now][i]] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        if (visit[i]) {
            answer++;
        }
    }

    cout << answer - 1 << endl;

    return 0;
}
