//
// Created by June Young Do on 1/13/24.
//

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
#define endl '\n'

int N, M, V;
vector<int> edge[1001];
bool visit[1001];

void dfs(int begin) {
    if (!visit[begin]) {
        cout << begin << " ";
        visit[begin] = true;
    }
    for (int i = 0; i < edge[begin].size(); i++) {
        if (!visit[edge[begin][i]]) {
            dfs(edge[begin][i]);
        }
    }
}

void bfs(int begin) {
    queue<int> q;
    q.push(begin);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (!visit[v]) {
            cout << v << " ";
            visit[v] = true;
            for (int i = 0; i < edge[v].size(); i++) {
                if (!visit[edge[v][i]]) {
                    q.push(edge[v][i]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(V);
    memset(visit, false, sizeof(visit));
    cout << endl;
    bfs(V);

    return 0;
}