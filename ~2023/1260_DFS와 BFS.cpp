//
// Created by June Young Do on 2022/07/19.
//
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'

int V, E, start;
vector<int> graph[1001];
bool visit[1001];

void DFS(int index) {
    if (visit[index] == false) {
        cout << index << ' ';
        visit[index] = true;
    }
    for (int i = 0; i < graph[index].size(); i++) {
        if (visit[graph[index][i]] == false) {
            DFS(graph[index][i]);
        }
    }
}

void BFS(int index) {
    queue<int> q;
    q.push(index);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (visit[now] == true) { continue; }
        cout << now << " ";
        for (int i = 0; i < graph[now].size(); i++) {
            if (visit[graph[now][i]] == false) {
                q.push(graph[now][i]);
                visit[graph[now][i]] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> start;

    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(start);
    cout << '\n';

    for (int i = 0; i < 1001; i++) {
        visit[i] = 0;
    }
    BFS(start);

    return 0;
}